import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class AlternatingPrint {

    private final Lock lock = new ReentrantLock();
    private final Condition condition = lock.newCondition();
    private boolean isOddTurn = true; // 标志位，表示是否该奇数线程打印

    // 定义奇数线程类
    class OddThread extends Thread {
        @Override
        public void run() {
            for (int i = 1; i <= 9; i += 2) {
                lock.lock();
                try {
                    while (!isOddTurn) {
                        condition.await(); // 等待轮到奇数线程
                    }
                    System.out.println(Thread.currentThread().getName() + " 打印: " + i);
                    Thread.sleep(1000);
                    isOddTurn = false; // 切换为偶数线程的轮次
                    condition.signal(); // 通知偶数线程
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                } finally {
                    lock.unlock();
                }
            }
        }
    }

    // 定义偶数线程类
    class EvenThread extends Thread {
        @Override
        public void run() {
            for (int i = 2; i <= 10; i += 2) {
                lock.lock();
                try {
                    while (isOddTurn) {
                        condition.await(); // 等待轮到偶数线程
                    }
                    System.out.println(Thread.currentThread().getName() + " 打印: " + i);
                    Thread.sleep(1000);
                    isOddTurn = true; // 切换为奇数线程的轮次
                    condition.signal(); // 通知奇数线程
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                } finally {
                    lock.unlock();
                }
            }
        }
    }

    public static void main(String[] args) {
        AlternatingPrint ap = new AlternatingPrint();

        // 创建奇数线程和偶数线程
        Thread oddThread = ap.new OddThread();
        Thread evenThread = ap.new EvenThread();

        // 启动线程
        oddThread.setName("奇数线程");
        evenThread.setName("偶数线程");

        oddThread.start();
        evenThread.start();
    }
}
