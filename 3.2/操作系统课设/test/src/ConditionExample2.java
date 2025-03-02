import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class ConditionExample2 {
    private final Lock lock = new ReentrantLock();//多线程的锁
    private final Condition condition = lock.newCondition();//休息室

    // 线程休眠
    public void threadWait() throws InterruptedException {
        lock.lock(); // 获取锁
        try {
            System.out.println(Thread.currentThread().getName() + " 进入休眠...");
            condition.await(); // 线程进入等待，直到被唤醒          进入等待状态，会释放拥有的锁
            System.out.println(Thread.currentThread().getName() + " 被唤醒，继续执行...");
        } finally {
            lock.unlock(); // 释放锁
        }
    }

    // 启动休眠示例
    public static void main(String[] args) throws InterruptedException {
        ConditionExample2 example = new ConditionExample2();

        // 创建一个线程来执行休眠操作
        Thread thread = new Thread(() -> {
            try {
                example.threadWait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }, "Thread-1");

        thread.start();

        // 主线程睡眠 3 秒后唤醒子线程
        Thread.sleep(3000);
        example.wakeUp(); // 唤醒线程
    }

    // 唤醒休眠中的线程
    public void wakeUp() {
        lock.lock(); // 获取锁
        try {
            System.out.println("唤醒线程...");
            condition.signal(); // 唤醒线程
        } finally {
            lock.unlock(); // 释放锁
        }
    }
}
