import javax.swing.SwingUtilities;

public class ClockInterruptHandlerThread extends Thread {

    public UI ui; // 图形化界面
    public static int simulationTime = 0; // 当前模拟时间
    public static int milliseconds = 1000; // 每次时钟流逝的时间（毫秒）

    public ClockInterruptHandlerThread(UI ui) {
        this.ui = ui;
    }

    @Override
    public void run() {
        while (true) {
            // 每次时钟线程运行都检测一次暂停
            SyncManager.pauseLock.lock();
            try {
                while (SyncManager.pauseFlag) {
                    SyncManager.pauseCondition.await();
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            } finally {
                SyncManager.pauseLock.unlock();
            }

            // 时钟线程获取锁，准备启动
            SyncManager.jstLock.lock();
            SyncManager.pstLock.lock();
            SyncManager.ioLock.lock();
            try {
                // 此处需要确保其他线程在时钟线程前能获取到资源，否则会像实验二一样出现死锁
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

                // 更新时间
                SimulateTimePassing(milliseconds);
                SwingUtilities.invokeLater(() -> ui.SetTime(simulationTime));

                // 唤醒其他线程
                SyncManager.jstCondition.signal();
                SyncManager.pstCondition.signal();
                SyncManager.inputCondition.signal();
                SyncManager.outputCondition.signal();

            } catch (InterruptedException e) {
                e.printStackTrace();
            } finally {
                // 释放锁
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
            Thread.sleep(milliseconds);
            simulationTime++;
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
