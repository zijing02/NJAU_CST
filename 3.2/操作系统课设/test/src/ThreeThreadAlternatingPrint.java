import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class ThreeThreadAlternatingPrint {

    private final Lock lock = new ReentrantLock();
    private final Condition condition1 = lock.newCondition();
    private final Condition condition2 = lock.newCondition();
    private final Condition condition3 = lock.newCondition();
    private int turn = 1; // 1 -> 线程1, 2 -> 线程2, 3 -> 线程3

    // 线程1类
    class Thread1 extends Thread {
        @Override
        public void run() {
            for (int i = 1; i <= 9; i += 3) {
                lock.lock();
                try {
                    while (turn != 1) {
                        condition1.await(); // 线程1等待
                    }
                    System.out.println(Thread.currentThread().getName() + " 打印: " + i);
                    Thread.sleep(1000);
                    turn = 2; // 切换到线程2
                    condition2.signal(); // 唤醒线程2
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                } finally {
                    lock.unlock();
                }
            }
        }
    }

    // 线程2类
    class Thread2 extends Thread {
        @Override
        public void run() {
            for (int i = 2; i <= 10; i += 3) {
                lock.lock();
                try {
                    while (turn != 2) {
                        condition2.await(); // 线程2等待
                    }
                    System.out.println(Thread.currentThread().getName() + " 打印: " + i);
                    Thread.sleep(1000);
                    turn = 3; // 切换到线程3
                    condition3.signal(); // 唤醒线程3
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                } finally {
                    lock.unlock();
                }
            }
        }
    }

    // 线程3类
    class Thread3 extends Thread {
        @Override
        public void run() {
            for (int i = 3; i <= 11; i += 3) {
                lock.lock();
                try {
                    while (turn != 3) {
                        condition3.await(); // 线程3等待
                    }
                    System.out.println(Thread.currentThread().getName() + " 打印: " + i);
                    Thread.sleep(1000);
                    turn = 1; // 切换到线程1
                    condition1.signal(); // 唤醒线程1
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                } finally {
                    lock.unlock();
                }
            }
        }
    }

    public static void main(String[] args) {
        ThreeThreadAlternatingPrint alternatingPrint = new ThreeThreadAlternatingPrint();

        // 创建并启动三个线程
        Thread thread1 = alternatingPrint.new Thread1();
        Thread thread2 = alternatingPrint.new Thread2();
        Thread thread3 = alternatingPrint.new Thread3();

        thread1.setName("线程1");
        thread2.setName("线程2");
        thread3.setName("线程3");

        thread1.start();
        thread2.start();
        thread3.start();
    }
}
