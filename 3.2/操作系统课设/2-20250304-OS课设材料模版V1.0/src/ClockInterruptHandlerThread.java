import java.util.Random;

public class ClockInterruptHandlerThread extends Thread {

    // 共享时间变量，模拟系统的时钟
    public static int simulationTime = 0;  // 当前模拟时间
    public static int milliseconds = 1000; // 每次时钟流逝的时间（毫秒）

    @Override
    public void run() {
        // 持续运行线程，模拟时钟的周期性中断
        while (true) {
            // 获取锁，确保线程同步
            SyncManager.clkLock.lock(); // 获取锁
            try {

                simulateTimePassing(milliseconds);

                // 打印当前时间（时钟），格式为：[当前时间]:[CLK]
                // 请在此处输出当前的模拟时间
                System.out.println(getCurrentTime() + ":[CLK]");


                // 唤醒作业调度和进程调度线程
                // 允许作业调度和进程调度并行运行
                SyncManager.jstLock.lock();
                SyncManager.pstLock.lock();
                try {
                    SyncManager.jstCondition.signal();
                    SyncManager.pstCondition.signal();
                } finally {
                    SyncManager.jstLock.unlock();
                    SyncManager.pstLock.unlock();
                }

                // 等待进程调度线程完成
                SyncManager.clkCondition.await();

            } catch (InterruptedException e) {
                // 捕获异常，如果线程被中断，则打印异常信息
                e.printStackTrace();
            } finally {
                SyncManager.clkLock.unlock(); // 释放锁
            }
        }
    }

    // 获取当前的模拟时间
    // 请在此处返回当前的模拟时间
    public static int getCurrentTime() {
        return simulationTime;
    }

    public static void simulateTimePassing(int milliseconds) {
        try {
            Thread.sleep(milliseconds); // 模拟时间流逝
            simulationTime++; // 增加模拟时间
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
