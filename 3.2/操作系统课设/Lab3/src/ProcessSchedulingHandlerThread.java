import javax.swing.SwingUtilities;

public class ProcessSchedulingHandlerThread extends Thread {
    public UI ui;
    private int timeSlice = 2; // 当前时间片
    public boolean timeSliceIsUsed = true; // 是否使用完时间片
    private int countFree = 0;

    public ProcessSchedulingHandlerThread(UI ui) {
        this.ui = ui;
    }

    @Override
    public void run() {
        while (true) {
            SyncManager.pstLock.lock();
            try {
                SyncManager.pstBeforeClock = true;
                SyncManager.pstBeforeClk.signal();
                // 等待作业调度线程的信号
                SyncManager.pstCondition.await();
                Schedule();
                System.out.println("完成进程调度");
                // 增加已完成调度线程的计数
                SyncManager.completedTasks++;

            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                e.printStackTrace();
            } finally {
                SyncManager.pstLock.unlock();
            }
        }
    }

    public void Schedule() {
        CheckWaitQueue();
        // 第一次使用while时造成了死锁，不知道为什么
        if (!OSKernel.pcbQueue.isEmpty()) {
            for (int i = 0; i < OSKernel.pcbQueue.size(); i++) {
                // 能够进入就绪队列，输出进入信息
                if (AbleToInReadyQueue(OSKernel.pcbQueue.peek())) {
                    PCB pcb = OSKernel.pcbQueue.poll();
                    // 总进程ID加1，原来的做法是将作业id赋值给进程id，但作业并不是一进来就产生进程，所以在此将进程id修改
                    String message = ClockInterruptHandlerThread.GetCurrentTime() + " [创建进程：进程" + pcb.GetPid()
                            + "分配内存成功，内存块起始地址为：" + pcb.GetStartAddress() + "内存大小为：" + pcb.GetCalculateNum()
                            + "B,进入就绪队列1,待执行指令条数为：" + (pcb.GetInstructionCount() - pcb.GetPc()) + "]";
                    System.out.println(message);
                    SwingUtilities.invokeLater(() -> ui.AddReady1ProcessMessage(message));
                    OSKernel.loader.AddMessageToSaveList(message);
                }
                // 不能就加入等待队列
                else {
                    PCB pcb = OSKernel.pcbQueue.poll();
                    OSKernel.waitQueue.add(pcb);
                }
            }
        }
        MFQ3();
        // 就绪队列为空，输出空闲信息
        // 问题，在有作业时还会输出，调试不出来，可能是因为线程不同步问题
        // CPU空闲和系统空闲不一样，只要相应的队列中没有新进程，CPU就是空闲，系统则要所有队列为空
        if (ClockInterruptHandlerThread.simulationTime != 0 && OSKernel.readyQueue1.isEmpty()
                && OSKernel.readyQueue2.isEmpty() && OSKernel.readyQueue3.isEmpty()
                && OSKernel.inBlockQueue.isEmpty() && OSKernel.outBlockQueue.isEmpty()) {
            String message = ClockInterruptHandlerThread.GetCurrentTime() + " [CPU空闲]";
            countFree++;
            if (countFree <= 3) {
                System.out.println(message);
                SwingUtilities.invokeLater(() -> ui.AddRunningProcessMessage(message));
                OSKernel.loader.AddMessageToSaveList(message);
            }
            if (countFree <= 1) {
                OSKernel.loader.SaveResults(ClockInterruptHandlerThread.GetCurrentTime());
            }
        } else {
            countFree = 0;
        }
    }

    public boolean AbleToInReadyQueue(PCB pcb) {
        // 系统并发进程数不满足
        if (OSKernel.outBlockQueue.size() +
                OSKernel.readyQueue1.size() +
                OSKernel.readyQueue2.size() +
                OSKernel.readyQueue3.size() > 12) {
            String message = ClockInterruptHandlerThread.GetCurrentTime() + " [无法为作业 " + pcb.GetPid() + "创建进程 "
                    + "系统最大并发进程数已经达到12!]";
            System.out.println(message);
            SwingUtilities.invokeLater(() -> OSKernel.ui.AddReady1ProcessMessage(message));
            OSKernel.loader.AddMessageToSaveList(message);
            return false;
        }
        // 设备A不满足
        if (OSKernel.deviceA.AbleToAllocate(pcb.GetNeedA())) {
            String message = ClockInterruptHandlerThread.GetCurrentTime() + " [无法为作业 " +
                    pcb.GetPid() + "创建进程 "
                    + "外部设备 A 已满!]";
            System.out.println(message);
            SwingUtilities.invokeLater(() -> OSKernel.ui.AddReady1ProcessMessage(message));
            OSKernel.loader.AddMessageToSaveList(message);
            return false;
        }
        // 设备B不满足
        if (OSKernel.deviceB.AbleToAllocate(pcb.GetNeedB())) {
            String message = ClockInterruptHandlerThread.GetCurrentTime() + " [无法为作业 " +
                    pcb.GetPid() + "创建进程 "
                    + "外部设备 B 已满!]";
            System.out.println(message);
            SwingUtilities.invokeLater(() -> OSKernel.ui.AddReady1ProcessMessage(message));
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
            }
            // 内存不足
            else {
                String message = ClockInterruptHandlerThread.GetCurrentTime() + " [该时刻，无法找到合适的连续来为内存块装配作业"
                        + pcb.GetPid() + "分配]";
                System.out.println(message);
                SwingUtilities.invokeLater(() -> OSKernel.ui.AddReady1ProcessMessage(message));
                OSKernel.loader.AddMessageToSaveList(message);
                return false;
            }
        }
    }

    // 检查等待队列，如果外设满足就返回pcb队列头部
    // 不直接进入就绪队列是因为偷懒，少写判断几行代码，进入pcb队列头部之后也是立即判断
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

    // 多级反馈队列
    // 根据时间片判断是否进行调度
    public void MFQ3() {
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
            // cpu空闲，但不能继续在这一秒钟空闲，需要跳出
            if (OSKernel.cpu.GetPsw() == 0) {
                FinishPCB(OSKernel.cpu.GetCurrentProcess());
                CheckWaitQueue();
                break;
            }
            if (OSKernel.cpu.GetPsw() == 1)
                timeSliceIsUsed = true;
        }
    }

    // 根据时间片选择就绪队列的具体逻辑
    // 一开始根据当前时间篇是否用尽去判断，但在运行时出现问题：运行完七个作业后点击实时按钮无反应，调试发现是时间片返回的问题
    private int ChooseReadyQueue() {
        // if (timeSliceIsUsed) {
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
        // }
        // // 此处需要返回
        // else {
        // if (!OSKernel.readyQueue1.isEmpty()) {
        // return 1;
        // } else if (!OSKernel.readyQueue2.isEmpty()) {
        // return 2;
        // } else if (!OSKernel.readyQueue3.isEmpty()) {
        // return 4;
        // }
        // }
        return -1;
    }

    // 进程结束，释放资源
    private boolean FinishPCB(PCB pcb) {
        if (pcb.GetPc() >= pcb.GetInstructionCount()) {
            pcb.SetFinishTime(ClockInterruptHandlerThread.GetCurrentTime());
            pcb.SetState(-1);
            OSKernel.memory.ReleaseMemory(pcb);
            String message = ClockInterruptHandlerThread.GetCurrentTime() + " [结束进程，结束时间："
                    + ClockInterruptHandlerThread.GetCurrentTime() + " 进程" + pcb.GetPid() + " 进入时间," + pcb.GetInTime()
                    + "总耗时：" + (pcb.GetFinishTime() - pcb.GetInTime()) + "]";
            if (OSKernel.readyQueue3.contains(pcb)) {
                OSKernel.readyQueue3.remove(pcb);
            }
            OSKernel.loader.PrintBackToReadyQueue(ClockInterruptHandlerThread.GetCurrentTime());
            System.out.println(message);
            SwingUtilities.invokeLater(() -> OSKernel.ui.AddRunningProcessMessage(message));
            OSKernel.loader.AddMessageToSaveList(message);
            // 根据时间片选择从哪一个就绪队列中移除
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

    // 时间片是否使用完，并根据此选择降级
    private void TimeSliceUsedUP() {
        // 在就绪队列1中运行了一次
        if (OSKernel.cpu.GetCurrentProcess().GetCount() == 1) {
            timeSliceIsUsed = true;
            ChangeToLowGrade(OSKernel.cpu.GetCurrentProcess());
        }
        // 在就绪队列1和就绪队列2中各运行一次
        else if (OSKernel.cpu.GetCurrentProcess().GetCount() == 3) {
            timeSliceIsUsed = true;
            ChangeToLowGrade(OSKernel.cpu.GetCurrentProcess());
        }
        // 一直在就绪队列3中
        else if (OSKernel.cpu.GetCurrentProcess().GetCount() > 3) {
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
            SwingUtilities.invokeLater(() -> ui.AddReady1ProcessMessage(message));
            SwingUtilities.invokeLater(() -> ui.AddReady2ProcessMessage(message));
            pcb.SetTimeSlice(OSKernel.timeSlice2);
            OSKernel.loader.AddMessageToSaveList(message);
        } else if (OSKernel.readyQueue2.contains(pcb)) {
            // 从二级队列降到三级队列
            OSKernel.readyQueue2.remove(pcb);
            OSKernel.readyQueue3.add(pcb);
            String message = ClockInterruptHandlerThread.GetCurrentTime() + " [进程" + pcb.GetPid() + " 降级到三级队列]";
            System.out.println(message);
            SwingUtilities.invokeLater(() -> ui.AddReady2ProcessMessage(message));
            SwingUtilities.invokeLater(() -> ui.AddReady3ProcessMessage(message));
            pcb.SetTimeSlice(OSKernel.timeSlice3);
            OSKernel.loader.AddMessageToSaveList(message);
        } else {
            // 在三级队列中继续执行
            OSKernel.readyQueue3.remove(pcb);
            OSKernel.readyQueue3.add(pcb);
            String message = ClockInterruptHandlerThread.GetCurrentTime() + " [进程" + pcb.GetPid()
                    + " 保持在三级队列中,但是重新加入队列尾部]";
            System.out.println(message);
            SwingUtilities.invokeLater(() -> ui.AddReady3ProcessMessage(message));
            pcb.SetTimeSlice(OSKernel.timeSlice3);
            OSKernel.loader.AddMessageToSaveList(message);
        }
    }
}
