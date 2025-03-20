
/**
 * 作业调度线程
 */
public class JobSchedulingHandlerThread extends Thread {
    @Override
    public void run() {
        while (true) {
            SyncManager.jstLock.lock(); // 使用作业调度的专属锁
            try {
                // 等待时钟线程的信号
                SyncManager.jstCondition.await();

                // 模拟作业调度逻辑
                System.out.println("完成作业调度");


                //任务需求：
                //1. 根据时钟中断判断作业是否到达进入作业后备队列
//PCB
                //2. 根据后备队列判断是否可以生成进程，如果可以则分配进程和资源进入就绪队列（策略是后备队列满足生成进程所需要的资源需求即可创建进程放入就绪队列）

                //重要提醒，由于作业调度线程和进程调度线程并行执行，在使用就绪队列需要加锁避免同时使用就绪队列，以及自定义的一些两个线程都要用到的资源都需要加锁避免访问时出错


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
                Thread.currentThread().interrupt();
                e.printStackTrace();
            } finally {
                SyncManager.jstLock.unlock(); // 释放锁
            }
        }
    }
}
