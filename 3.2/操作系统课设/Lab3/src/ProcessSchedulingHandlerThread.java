import javax.swing.SwingUtilities;

public class ProcessSchedulingHandlerThread extends Thread {
    public UI ui;
    private int timeSlice = 2; // 当前时间片
    public boolean timeSliceIsUsed = true; // 是否使用完时间片

    public ProcessSchedulingHandlerThread(UI ui) {
        this.ui = ui;
    }

    @Override
    public void run() {
        // 持续运行线程，模拟进程调度
        while (true) {
            // 获取锁，确保线程同步
            SyncManager.pstLock.lock(); // 获取锁
            try {
                SyncManager.pstBeforeClock = true; // 标记进程调度线程在时钟中断之前完成
                SyncManager.pstBeforeClk.signal();
                // 等待作业调度线程的信号
                SyncManager.pstCondition.await();
                Schedule();
                System.out.println("完成进程调度");
                // 增加已完成调度线程的计数
                SyncManager.completedTasks++;

            } catch (InterruptedException e) {
                // 捕获异常，如果线程被中断，则打印异常信息
                // 请在此处处理线程中断异常
                Thread.currentThread().interrupt();
                e.printStackTrace();
            } finally {
                // 释放锁，允许其他线程访问共享资源
                SyncManager.pstLock.unlock(); // 释放锁
            }
        }
    }

    public void Schedule() {
        CheckWaitQueue();
        // 第一次使用while时造成了死锁，不知道为什么
        if (!OSKernel.pcbQueue.isEmpty()) {
            for (int i = 0; i < OSKernel.pcbQueue.size(); i++) {
                if (AbleToCreatePCB(OSKernel.pcbQueue.peek())) {
                    PCB pcb = OSKernel.pcbQueue.poll();
                    String message = ClockInterruptHandlerThread.GetCurrentTime() + " [创建进程：进程" + pcb.GetPid()
                            + "分配内存成功，内存块起始地址为：" + pcb.GetStartAddress() + "内存大小为：" + pcb.GetCalculateNum()
                            + "B,进入就绪队列1,待执行指令条数为：" + (pcb.GetInstructionCount() - pcb.GetPc()) + "]";
                    System.out.println(message);
                    SwingUtilities.invokeLater(() -> ui.AddReadyProcessMessage(message));
                    OSKernel.loader.AddMessageToSaveList(message);
                }
                else{
                    PCB pcb = OSKernel.pcbQueue.poll();
                    OSKernel.waitQueue.add(pcb);
                }
            }
        }
        MFQ();
        if (OSKernel.readyQueue1.isEmpty() && OSKernel.readyQueue2.isEmpty() && OSKernel.readyQueue3.isEmpty()) {
            String message = ClockInterruptHandlerThread.GetCurrentTime() + " [CPU空闲]";
            System.out.println(message);
            SwingUtilities.invokeLater(
                    () -> ui.AddRunningProcessMessage(message));
            OSKernel.loader.AddMessageToSaveList(message);
        }
    }

    public boolean AbleToCreatePCB(PCB pcb) {
        if (OSKernel.memory.CheckTotalNum() > 12) {
            String message = ClockInterruptHandlerThread.GetCurrentTime() + " [无法为作业 " + pcb.GetPid() + "创建进程 "
                    + "系统最大并发进程数已经达到12!]";
            System.out.println(message);
            SwingUtilities.invokeLater(() -> OSKernel.ui.AddReadyProcessMessage(message));
            OSKernel.loader.AddMessageToSaveList(message);
            return false;
        }
        if (OSKernel.deviceA.AbleToAllocate(pcb.GetNeedA())) {
            String message = ClockInterruptHandlerThread.GetCurrentTime() + " [无法为作业 " +
                    pcb.GetPid() + "创建进程 "
                    + "外部设备 A 已满!]";
            System.out.println(message);
            SwingUtilities.invokeLater(() -> OSKernel.ui.AddReadyProcessMessage(message));
            OSKernel.loader.AddMessageToSaveList(message);
            return false;
        }
        if (OSKernel.deviceB.AbleToAllocate(pcb.GetNeedB())) {
            String message = ClockInterruptHandlerThread.GetCurrentTime() + " [无法为作业 " +
                    pcb.GetPid() + "创建进程 "
                    + "外部设备 B 已满!]";
            System.out.println(message);
            SwingUtilities.invokeLater(() -> OSKernel.ui.AddReadyProcessMessage(message));
            OSKernel.loader.AddMessageToSaveList(message);
            return false;
        } else {
            if (OSKernel.memory.AllocateMemory(pcb)) {
                OSKernel.readyQueue1.add(pcb);
                pcb.SetState(0);
                pcb.SetTimeSlice(OSKernel.timeSlice1);
                pcb.readQueue.add(ClockInterruptHandlerThread.GetCurrentTime());
                pcb.SetCreateTime(ClockInterruptHandlerThread.GetCurrentTime());
                return true;
            } else {
                String message = ClockInterruptHandlerThread.GetCurrentTime() + " [该时刻，无法找到合适的连续来为内存块装配作业"
                        + pcb.GetPid() + "分配]";
                System.out.println(message);
                SwingUtilities.invokeLater(() -> OSKernel.ui.AddReadyProcessMessage(message));
                OSKernel.loader.AddMessageToSaveList(message);
                return false;
            }
        }
    }

    public void CheckWaitQueue() {
        int totalA = OSKernel.deviceA.GetTotalNumber();
        int totalB = OSKernel.deviceB.GetTotalNumber();
        if (OSKernel.waitQueue.isEmpty())
            return;
        for (PCB pcb : OSKernel.waitQueue) {
            if (totalA >= pcb.GetNeedA() && totalB >= pcb.GetNeedB()) {
                totalA -= pcb.GetNeedA();
                totalB -= pcb.GetNeedB();
                OSKernel.pcbQueue.addFirst(pcb);
                OSKernel.waitQueue.remove(pcb);
            }
        }
    }

    public void MFQ() {
        while (!OSKernel.readyQueue1.isEmpty() || !OSKernel.readyQueue2.isEmpty() || !OSKernel.readyQueue3.isEmpty()) {
            if (ChooseReadyQueue() == -1) {
                System.out.println("所有队列都为空，无法调度进程");
                return;
            }
            switch (ChooseReadyQueue()) {
                case 1: {
                    OSKernel.cpu.SetCurrentProcess(OSKernel.readyQueue1.peek());
                    break;
                }
                case 2: {
                    OSKernel.cpu.SetCurrentProcess(OSKernel.readyQueue2.peek());
                    break;
                }
                case 4: {
                    OSKernel.cpu.SetCurrentProcess(OSKernel.readyQueue3.peek());
                    break;
                }
                default: {
                    OSKernel.cpu.SetPsw(-1);
                    break;
                }
            }
            if (OSKernel.cpu.GetCurrentProcess() == null) {
                System.out.println("当前没有进程在运行");
                return;
            }
            OSKernel.cpu.RunProcess();
            if (OSKernel.cpu.GetPsw() == 0) {
                FinishPCB(OSKernel.cpu.GetCurrentProcess());
                CheckWaitQueue();
                break;
            }
            if (OSKernel.cpu.GetPsw() == 1)
                timeSliceIsUsed = true;
        }
    }

    private int ChooseReadyQueue() {
        if (timeSliceIsUsed) {
            if (!OSKernel.readyQueue1.isEmpty()) {
                timeSlice = OSKernel.timeSlice1;
                return timeSlice;
            } else if (!OSKernel.readyQueue2.isEmpty()) {
                timeSlice = OSKernel.timeSlice2;
                return timeSlice;
            } else if (!OSKernel.readyQueue3.isEmpty()) {
                timeSlice = OSKernel.timeSlice3;
                return timeSlice;
            }
        } else {
            if (!OSKernel.readyQueue1.isEmpty()) {
                return timeSlice;
            } else if (!OSKernel.readyQueue2.isEmpty()) {
                return timeSlice;
            } else if (!OSKernel.readyQueue3.isEmpty()) {
                return timeSlice;
            }
        }
        return -1; // 如果所有队列都为空，返回 -1
    }

    private boolean FinishPCB(PCB pcb) {
        if (pcb.GetPc() >= pcb.GetInstructionCount()) {
            pcb.SetFinishTime(ClockInterruptHandlerThread.GetCurrentTime());
            pcb.SetState(-1);
            OSKernel.memory.ReleaseMemory(pcb);
            String message = ClockInterruptHandlerThread.GetCurrentTime() + " [终止进程：进程" + pcb.GetPid() + " 执行结束,"
                    + "一共耗时："
                    + (pcb.GetFinishTime() - pcb.GetInTime()) + "。内存释放成功]";
            System.out.println(message);
            SwingUtilities.invokeLater(() -> OSKernel.ui.AddRunningProcessMessage(message));
            OSKernel.loader.AddMessageToSaveList(message);
            switch (pcb.GetTimeSlice()) {
                case 1: {
                    OSKernel.readyQueue1.remove(pcb);
                    break;
                }
                case 2: {
                    OSKernel.readyQueue2.remove(pcb);
                    break;
                }
                case 4: {
                    OSKernel.readyQueue3.remove(pcb);
                    break;
                }
            }
            OSKernel.loader.PrintBlockInfo();
            return true;
        }
        TimeSliceUsedUP();
        return false;
    }

    private void TimeSliceUsedUP() {
        if (OSKernel.cpu.GetCurrentProcess().GetCount() == 1) {
            timeSliceIsUsed = true;
            ChangeToLowGrade(OSKernel.cpu.GetCurrentProcess());
        } else if (OSKernel.cpu.GetCurrentProcess().GetCount() == 3) {
            timeSliceIsUsed = true;
            ChangeToLowGrade(OSKernel.cpu.GetCurrentProcess());
        } else if (OSKernel.cpu.GetCurrentProcess().GetCount() > 3) {
            int count = OSKernel.cpu.GetCurrentProcess().GetCount() - 3;
            timeSliceIsUsed = count % OSKernel.timeSlice3 == 0;
            if (timeSliceIsUsed)
                ChangeToLowGrade(OSKernel.cpu.GetCurrentProcess());
        } else
            timeSliceIsUsed = false;
    }

    // 将进程降级到下一优先级队列
    private void ChangeToLowGrade(PCB pcb) {
        if (OSKernel.readyQueue1.contains(pcb)) {
            // 从一级队列降到二级队列
            OSKernel.readyQueue1.remove(pcb);
            OSKernel.readyQueue2.add(pcb);
            String message = ClockInterruptHandlerThread.GetCurrentTime() + " [进程" + pcb.GetPid() + " 降级到二级队列]";
            System.out.println(message);
            SwingUtilities.invokeLater(() -> ui.AddReadyProcessMessage(message));
            pcb.SetTimeSlice(OSKernel.timeSlice2);
            OSKernel.loader.AddMessageToSaveList(message);
        } else if (OSKernel.readyQueue2.contains(pcb)) {
            // 从二级队列降到三级队列
            OSKernel.readyQueue2.remove(pcb);
            OSKernel.readyQueue3.add(pcb);
            String message = ClockInterruptHandlerThread.GetCurrentTime() + " [进程" + pcb.GetPid() + " 降级到三级队列]";
            System.out.println(message);
            SwingUtilities.invokeLater(() -> ui.AddReadyProcessMessage(message));
            pcb.SetTimeSlice(OSKernel.timeSlice3);
            OSKernel.loader.AddMessageToSaveList(message);
        } else {
            // 在三级队列中继续执行
            OSKernel.readyQueue3.remove(pcb);
            OSKernel.readyQueue3.add(pcb);
            String message = ClockInterruptHandlerThread.GetCurrentTime() + " [进程" + pcb.GetPid()
                    + " 保持在三级队列中,但是重新加入队列尾部]";
            System.out.println(message);
            SwingUtilities.invokeLater(() -> ui.AddReadyProcessMessage(message));
            pcb.SetTimeSlice(OSKernel.timeSlice3);
            OSKernel.loader.AddMessageToSaveList(message);
        }
    }
}
