import javax.swing.SwingUtilities;

public class ClockInterruptHandlerThread extends Thread {

    public UI ui; // 图形化界面
    public static int simulationTime = 0; // 当前模拟时间
    public static int milliseconds = 10; // 每次时钟流逝的时间（毫秒）

    public ClockInterruptHandlerThread(UI ui) {
        this.ui = ui;
    }

    @Override
    public void run() {
        while (true) {
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

            SyncManager.jstLock.lock();
            SyncManager.pstLock.lock();
            SyncManager.ioLock.lock();
            try {
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
            Thread.sleep(milliseconds); 
            simulationTime++;
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
