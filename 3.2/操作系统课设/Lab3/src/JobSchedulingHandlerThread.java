import java.util.Comparator;
import java.util.PriorityQueue;

import javax.swing.SwingUtilities;

public class JobSchedulingHandlerThread extends Thread {
    public UI ui; // 图形化界面

    public JobSchedulingHandlerThread(UI ui) {
        this.ui = ui;
    }

    @Override
    public void run() {
        while (true) {
            SyncManager.jstLock.lock();
            try {
                SyncManager.jstBeforeClock = true;
                SyncManager.jstBeforeClk.signal();
                SyncManager.jstCondition.await();

                System.out.println("完成作业调度");

                JobRequest();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                e.printStackTrace();
            } finally {
                SyncManager.jstLock.unlock();
            }
        }
    }

    // 查询判断是否有作业请求
    // 每2秒查询是否有作业
    // 如果作业缓冲区不为空，就为其创建相应的PCB并加入到PCB队列中等待执行
    private void JobRequest() {
        if (ClockInterruptHandlerThread.GetCurrentTime() % 2 == 0) {
            if (!OSKernel.jobQueue.isEmpty()) {
                PriorityQueue<Job> sortedJobQueue = new PriorityQueue<>(Comparator.comparingInt(Job::GetInTime));
                sortedJobQueue.addAll(OSKernel.jobQueue);

                while (!sortedJobQueue.isEmpty()
                        && sortedJobQueue.peek().GetInTime() <= ClockInterruptHandlerThread.GetCurrentTime()) {
                    Job tempJob = sortedJobQueue.poll();
                    if (OSKernel.jobQueue.contains(tempJob)) {
                        OSKernel.jobQueue.remove(tempJob);
                    }
                    PCB pcb = new PCB(tempJob.GetJobId(), tempJob.GetInTime(), tempJob.GetNeedA(),
                            tempJob.GetNeedB(), tempJob.GetInstructionCount(),
                            tempJob.GetInstructions());
                    OSKernel.pcbQueue.add(pcb);
                    String message = tempJob.GetInTime() + " [新增作业: 作业" + tempJob.GetJobId() + " 请求时间"
                            + tempJob.GetInTime() + " 指令数量" + tempJob.GetInstructionCount() + " 需要A"
                            + tempJob.GetNeedA() + " 需要B" + tempJob.GetNeedB() + "]";
                    System.out.println(message);
                    SwingUtilities.invokeLater(() -> ui.AddJobRequestMessage(message));
                    OSKernel.loader.AddMessageToSaveList(message);
                }
            }

        }
    }
}
