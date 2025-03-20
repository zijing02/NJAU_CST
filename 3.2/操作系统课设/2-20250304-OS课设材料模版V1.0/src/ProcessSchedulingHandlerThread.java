import java.util.Random;

public class ProcessSchedulingHandlerThread extends Thread {

    //时间片
    public static int timeSlice = 0;

    @Override
    public void run() {
        // 持续运行线程，模拟进程调度
        while (true) {
            // 获取锁，确保线程同步
            SyncManager.pstLock .lock(); // 获取锁
            try {
                // 等待作业调度线程的信号
                SyncManager.pstCondition.await();


                //任务需求：
                // 1.根据策略是否进行进程调度（1.判断当前CPU进程是否为空，为空调度。2. 时间片为0则进行调度分配时间片。3.判断是否有更高优先级的进程，采用的是可剥夺的多级反馈队列。进程调度完成分配时间片）

                // 2.CPU执行.进程状态应该从就绪态（Ready）转换到运行态（Running）。（1.进程执行完毕则转到终止态（Terminated），并初始化时间片为0。2.时间片归0则重新放入就绪队列。）

                //重要提醒，由于作业调度线程和进程调度线程并行执行，在使用就绪队列需要加锁避免同时使用就绪队列，以及自定义的一些两个线程都要用到的资源都需要加锁避免访问时出错

                // 模拟进程调度完成后的输出
                System.out.println("完成进程调度");

                // 增加已完成调度线程的计数
                SyncManager.completedTasks++;

                // 检查是否所有调度线程都完成
                if (SyncManager.completedTasks == 2) {
                    SyncManager.completedTasks = 0;  // 重置计数器
                    SyncManager.clkLock.lock(); // 获取锁
                    SyncManager.clkCondition.signal();  // 唤醒时钟线程
                    SyncManager.clkLock.unlock(); // 释放锁
                }

            } catch (InterruptedException e) {
                // 捕获异常，如果线程被中断，则打印异常信息
                // 请在此处处理线程中断异常
                Thread.currentThread().interrupt();
                e.printStackTrace();
            } finally {
                // 释放锁，允许其他线程访问共享资源
                SyncManager.pstLock .unlock(); // 释放锁
            }
        }
    }
}
