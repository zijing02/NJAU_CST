public class ClockInterruptHandlerThread extends Thread {

    // 共享时间变量，模拟系统的时钟
    public static int simulationTime = 0;  // 当前模拟时间
    public static int milliseconds = 1; // 每次时钟流逝的时间（毫秒）

    @Override
    public void run() {
        // 持续运行线程，模拟时钟的周期性中断
        while (true) {
            // 获取锁，确保线程同步
            // 请在此处获取锁，确保其他线程不能同时访问共享资源
            SyncManager.lock.lock();

            try {

                // 模拟时间流逝：每次调用模拟时间增加
                // 请在此处实现模拟时间流逝的逻辑，使系统时间每经过 `milliseconds` 毫秒就增加
                simulateTimePassing(milliseconds);

                // 打印当前时间（时钟），格式为：[当前时间]:[CLK]
                // 请在此处输出当前的模拟时间
                System.out.println(getCurrentTime() + ":[CLK]");

                // *** 提示：在这里模拟作业的判定 ***
                // 请在此处检查是否有新的作业到达（本次实验暂不实现）


                // 发出时钟中断通知，通知进程调度线程进行调度
                // 请在此处实现条件变量的通知，使进程调度线程能够得到唤醒
                SyncManager.pstCondition.signal();

                // 等待下一个时钟中断的信号
                // 请在此处实现条件变量的等待，使时钟线程等待下一个时钟周期信号
                SyncManager.clkCondition.await();
                SyncManager.lock.lock();

            } catch (InterruptedException e) {
                // 捕获异常，如果线程被中断，则打印异常信息
                e.printStackTrace();
            } finally {
                // 释放锁，允许其他线程访问共享资源
                // 请在此处释放锁
                SyncManager.lock.unlock();
            }
        }
    }

    // 获取当前的模拟时间
    // 请在此处返回当前的模拟时间
    public static int getCurrentTime() {
        return simulationTime;
    }

    // 模拟时间流逝
    // 每次流逝 `milliseconds` 毫秒，增加系统的模拟时间
    // 请在此处实现模拟时间流逝的逻辑
    public static void simulateTimePassing(int milliseconds) {
        try {
            // 使当前线程睡眠 `milliseconds` 毫秒，模拟时间的流逝
            // 请在此处让线程休眠 `milliseconds` 毫秒，模拟时间的流逝
            Thread.sleep(milliseconds);

            // 每次流逝时间，增加模拟的当前时间
            // 请在此处增加模拟时间的值
            simulationTime ++;
        } catch (InterruptedException e) {
            // 捕获异常，如果线程被中断，则打印异常信息
            e.printStackTrace();
        }
    }
}
