import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class ConditionExample3 {
    private final Lock lock = new ReentrantLock();
    private final Condition condition = lock.newCondition();

    // 线程休眠
    public void threadSleep() throws InterruptedException {
        lock.lock();
        try {
            System.out.println(Thread.currentThread().getName() + " 正在等待...");
            condition.await();  // 当前线程进入等待      //Thread。wait()
            System.out.println(Thread.currentThread().getName() + " 被唤醒，继续执行...");
        } finally {
            lock.unlock();
        }
    }

    // 唤醒休眠线程
    public void threadWakeUp() {
        lock.lock();
        try {
            System.out.println(Thread.currentThread().getName() + " 唤醒等待中的线程...");
            condition.signal();  // 唤醒等待的线程      //Thread.notify()
        } finally {
            lock.unlock();
        }
    }

    public static void main(String[] args) throws InterruptedException {
        ConditionExample3 example = new ConditionExample3();

        // 线程1：进入休眠
        Thread thread1 = new Thread(() -> {
            try {
                example.threadSleep();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }, "Thread-1");

        // 线程2：唤醒线程1
        Thread thread2 = new Thread(() -> {
            try {
                Thread.sleep(3000); // 模拟一些工作
                example.threadWakeUp();  // 唤醒线程1
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }, "Thread-2");

        thread1.start();
        thread2.start();
    }
}
