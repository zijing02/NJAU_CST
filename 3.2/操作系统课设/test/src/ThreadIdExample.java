class MyThread extends Thread {
    @Override
    public void run() {
        // 打印当前线程的 ID、名称、状态和优先级
        System.out.println("子线程 ID: " + Thread.currentThread().getId());
        System.out.println("子线程名称: " + Thread.currentThread().getName());
        System.out.println("子线程状态: " + Thread.currentThread().getState());
        System.out.println("子线程优先级: " + Thread.currentThread().getPriority());

        // 进行一些操作
        try {
            System.out.println("子线程正在执行操作...");
            Thread.sleep(2000);  // 模拟操作
            System.out.println("子线程操作完成");
        } catch (InterruptedException e) {
            System.out.println("子线程被中断");
        }
    }
}

public class ThreadIdExample {
    public static void main(String[] args) {
        // 打印主线程的 ID、名称、状态和优先级
        System.out.println("主线程 ID: " + Thread.currentThread().getId());
        System.out.println("主线程名称: " + Thread.currentThread().getName());
        System.out.println("主线程状态: " + Thread.currentThread().getState());
        System.out.println("主线程优先级: " + Thread.currentThread().getPriority());

        // 创建并启动子线程
        Thread thread = new MyThread();
        thread.start();  // 启动子线程

        // 主线程继续执行其他操作
        try {
            System.out.println("主线程正在执行操作...");
            Thread.sleep(1000);  // 模拟操作
            System.out.println("主线程操作完成");
        } catch (InterruptedException e) {
            System.out.println("主线程被中断");
        }

        // 主线程等待子线程完成
        try {
            thread.join();  // 等待子线程完成
        } catch (InterruptedException e) {
            System.out.println("主线程等待子线程完成时被中断");
        }

        System.out.println("主线程结束");
    }
}
