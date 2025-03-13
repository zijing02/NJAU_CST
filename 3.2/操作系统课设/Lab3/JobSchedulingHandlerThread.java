// 作业调度线程

import javax.swing.SwingUtilities;

public class JobSchedulingHandlerThread extends Thread {
    public UI ui; // 图形化界面

    public JobSchedulingHandlerThread(UI ui) {
        this.ui = ui;
    }

    @Override
    public void run() {
        while (true) {
            SyncManager.jstLock.lock(); // 使用作业调度的专属锁
            try {
                // 等待时钟线程的信号
                SyncManager.jstBeforeClock = true;
                SyncManager.jstBeforeClk.signal();
                SyncManager.jstCondition.await();

                // 模拟作业调度逻辑
                System.out.println("完成作业调度");

                JobRequest();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                e.printStackTrace();
            } finally {
                SyncManager.jstLock.unlock(); // 释放锁
            }
        }
    }

    // 查询判断是否有作业请求
    // 每2秒查询是否有作业
    // 如果作业缓冲区不为空，就为其创建相应的PCB并加入到PCB队列中等待执行
    private void JobRequest() {
        if (ClockInterruptHandlerThread.GetCurrentTime() % 2 == 0) {
            if (!OSKernel.jobQueue.isEmpty()) {
                for (int i = 0; i < OSKernel.jobQueue.size(); i++) {
                    if (OSKernel.jobQueue.peek().GetInTime() <= ClockInterruptHandlerThread.GetCurrentTime()) {
                        Job tempJob = OSKernel.jobQueue.poll();
                        PCB pcb = new PCB(tempJob.GetJobId(), tempJob.GetInTime(),tempJob.GetNeedA(),tempJob.GetNeedB(), tempJob.GetInstructionCount(),
                                tempJob.GetInstructions());
                        OSKernel.pcbQueue.add(pcb);
                        String message = tempJob.GetInTime() + " [新增作业: 作业" + tempJob.GetJobId() + "]";
                        System.out.println(message);
                        SwingUtilities.invokeLater(() -> ui.AddJobRequestMessage(message));
                        OSKernel.loader.AddMessageToSaveList(message);
                    }
                }
            }
        }
    }
}
