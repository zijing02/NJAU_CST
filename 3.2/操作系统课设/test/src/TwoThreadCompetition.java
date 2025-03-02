import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class TwoThreadCompetition {

    // 共享的计数器
    private int counter = 0;

    // 用 ReentrantLock 控制对共享资源的访问
    private final Lock lock = new ReentrantLock();

    // 竞争计数器的线程类
    class CompetingThread extends Thread {

        public CompetingThread(String name) {
            this.setName(name);
        }

        @Override
        public void run() {
            for (int i = 0; i < 5; i++) {
                try {
                    // 尝试获取锁
                    System.out.println(Thread.currentThread().getName() + " 尝试获取锁...");
                    lock.lock();  // 获取锁
                    System.out.println(Thread.currentThread().getName() + " 获取到锁!");

                    // 打印计数器的当前值并增加
                    System.out.println(Thread.currentThread().getName() + " 当前计数器值: " + counter);
                    counter++;
                    System.out.println(Thread.currentThread().getName() + " 将计数器加1, 新的计数器值: " + counter);

                    // 休眠1秒，模拟工作处理
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                } finally {
                    // 确保锁被释放
                    System.out.println(Thread.currentThread().getName() + " 释放锁!");
                    lock.unlock();
                }

                // 模拟每个循环的处理间隔
                try {
                    Thread.sleep(500); // 500毫秒的休眠，方便观察调试
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            }
        }
    }

    public static void main(String[] args) {
        TwoThreadCompetition example = new TwoThreadCompetition();

        // 创建并启动两个线程
        Thread thread1 = example.new CompetingThread("线程1");
        Thread thread2 = example.new CompetingThread("线程2");

        thread1.start();
        thread2.start();

        try {
            thread1.join();  // 等待线程1完成
            thread2.join();  // 等待线程2完成
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
