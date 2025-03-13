import javax.swing.SwingUtilities;

public class ClockInterruptHandlerThread extends Thread {

    public UI ui; // 图形化界面
    public static int simulationTime = 0; // 当前模拟时间
    public static int milliseconds = 100; // 每次时钟流逝的时间（毫秒）

    public ClockInterruptHandlerThread(UI ui) {
        this.ui = ui;
    }

    @Override
    public void run() {
        // 持续运行线程，模拟时钟的周期性中断
        while (true) {
            // 检查此处系统是否暂停
            // 获取系统暂停锁
            SyncManager.pauseLock.lock(); 
            try {
                // 如果状态为暂停，则等待
                while (SyncManager.pauseFlag) {
                    SyncManager.pauseCondition.await(); // 等待
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            } finally {
                SyncManager.pauseLock.unlock(); // 释放锁
            }

            // 时钟线程获取所有的锁，以保证同步
            SyncManager.jstLock.lock();
            SyncManager.pstLock.lock();
            SyncManager.ioLock.lock();
            try {
                // 若不是时钟线程后启动，会造成时间不连续，甚至于死锁问题
                // 在实验二中出现过此问题，当时是使用两次加锁实现
                if (!SyncManager.jstBeforeClock)
                SyncManager.jstBeforeClk.await();
                SyncManager.jstBeforeClock = false;

                if (!SyncManager.pstBeforeClock)
                    SyncManager.pstBeforeClk.await();
                SyncManager.pstBeforeClock = false;

                if (!SyncManager.inputBeforeClock)
                    SyncManager.inputBeforeClk.await();
                SyncManager.inputBeforeClock = false;

                if (!SyncManager.outputBeforeClock)
                SyncManager.outputBeforeClk.await();
                SyncManager.outputBeforeClock = false;

                SimulateTimePassing(milliseconds);
                SwingUtilities.invokeLater(() -> ui.SetTime(simulationTime));
                
                //更新界面后唤醒所有进程进行工作
                SyncManager.jstCondition.signal();
                SyncManager.pstCondition.signal();
                SyncManager.inputCondition.signal();
                SyncManager.outputCondition.signal();

            } catch (InterruptedException e) {
                e.printStackTrace();
            } finally {
                SyncManager.jstLock.unlock();
                SyncManager.pstLock.unlock();
                SyncManager.ioLock.unlock();
            }
        }
    }

    public static int GetCurrentTime() {
        return simulationTime;
    }

    public static void SimulateTimePassing(int milliseconds) {
        try {
            Thread.sleep(milliseconds); // 模拟时间流逝
            simulationTime++; // 增加模拟时间
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
