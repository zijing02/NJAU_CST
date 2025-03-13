import javax.swing.*;

public class OutputBlockThread extends Thread {
    public int count_i = 0;
    public int count_o = 0;
    public static final int outTime = 3;// 处理一个IO的时间

    @Override
    public void run() {
        while (true) { // 无限循环
            SyncManager.ioLock.lock(); // 获取锁，确保线程安全
            try {
                SyncManager.outputBeforeClock = true;
                SyncManager.outputBeforeClk.signal();
                SyncManager.outputCondition.await();

                ALL_IO();// 处理所有类型IO的逻辑
            } catch (InterruptedException e) {
                e.printStackTrace(); // 处理异常
            } finally {
                SyncManager.ioLock.unlock(); // 释放锁
            }
        }
    }

    public void ALL_IO() {
        if (!OSKernel.outBlockQueue.isEmpty()) {
            PCB pcb = OSKernel.outBlockQueue.peek();
            count_i++;
            if (count_i == outTime) {
                OSKernel.outBlockQueue.remove(pcb);// 如果IO操作执行完成，从IO阻塞队列中弹出
                OSKernel.loader.CheckInputBlock(pcb.GetPid(), ("唤醒时间：" + ClockInterruptHandlerThread.GetCurrentTime()));// 记录离开输入阻塞队列的时间和对应的进程ID
                int pc = pcb.GetPc();
                System.out.println(ClockInterruptHandlerThread.GetCurrentTime() + " [IO操作：进程" + pcb.GetPid() + "的第"
                        + (pcb.GetPc() + 1) + "条指令" + pcb.GetInstructionStateToString() + "执行完成]");
                SwingUtilities.invokeLater(() -> OSKernel.ui
                        .AddOutBlockMessage(ClockInterruptHandlerThread.GetCurrentTime() + " [IO操作：进程" + pcb.GetPid()
                                + "的第" + (pcb.GetPc() + 1) + "条指令" + pcb.GetInstructionStateToString() + "执行完成]"));
                OSKernel.loader
                        .AddMessageToSaveList(ClockInterruptHandlerThread.GetCurrentTime() + " [IO操作：进程" + pcb.GetPid()
                                + "的第" + (pcb.GetPc() + 1) + "条指令" + pcb.GetInstructionStateToString() + "执行完成]");
                pc++;

                if (pc >= pcb.GetInstructionCount())// 如果进程执行结束
                {
                    pcb.SetFinishTime(ClockInterruptHandlerThread.GetCurrentTime());
                    pcb.SetState(-1);
                    OSKernel.memory.ReleaseMemory(pcb);// 释放内存
                    System.out.println(ClockInterruptHandlerThread.GetCurrentTime() + " [终止进程：进程" + pcb.GetPid()
                            + "执行结束" + "一共耗时：" + (pcb.GetFinishTime() - pcb.GetInTime()) + "。内存释放成功]");
                    SwingUtilities.invokeLater(() -> OSKernel.ui
                            .AddOutBlockMessage(ClockInterruptHandlerThread.GetCurrentTime() + " [终止进程：进程" + pcb.GetPid()
                                    + "执行结束" + "一共耗时：" + (pcb.GetFinishTime() - pcb.GetInTime()) + "内存释放成功]"));
                    OSKernel.loader.AddMessageToSaveList(ClockInterruptHandlerThread.GetCurrentTime() + " [终止进程：进程"
                            + pcb.GetPid() + "执行结束" + "一共耗时：" + (pcb.GetFinishTime() - pcb.GetInTime()) + "。内存释放成功]");
                    OSKernel.loader.PrintBlockInfo();// 进程结束打印进程的状态信息
                }

                else if (pc < pcb.GetInstructionCount()) // 如果进程还没有结束
                {
                    pcb.SetPc(pc);
                    BackToReadyQueue(pcb);// 重回就绪队列
                }
                count_i = 0;
            }

        }

        if (!OSKernel.outBlockQueue.isEmpty()) {

            PCB pcb = OSKernel.outBlockQueue.peek();
            count_o++;
            if (count_o == outTime) {
                OSKernel.outBlockQueue.remove(pcb);// 如果IO操作执行完成，从IO阻塞队列中弹出
                OSKernel.loader.CheckOutputBlock(pcb.GetPid(), ("唤醒时间：" + ClockInterruptHandlerThread.GetCurrentTime()));// 记录离开输出阻塞队列的时间和对应进程ID
                int pc = pcb.GetPc();
                System.out.println(ClockInterruptHandlerThread.GetCurrentTime() + " [IO操作：进程" + pcb.GetPid() + "的第"
                        + (pcb.GetPc() + 1) + "条指令" + pcb.GetInstructionStateToString() + "执行完成]");
                SwingUtilities.invokeLater(() -> OSKernel.ui
                        .AddOutBlockMessage(ClockInterruptHandlerThread.GetCurrentTime() + " [IO操作：进程" + pcb.GetPid()
                                + "的第" + (pcb.GetPc() + 1) + "条指令" + pcb.GetInstructionStateToString() + "执行完成]"));
                OSKernel.loader
                        .AddMessageToSaveList(ClockInterruptHandlerThread.GetCurrentTime() + " [IO操作：进程" + pcb.GetPid()
                                + "的第" + (pcb.GetPc() + 1) + "条指令" + pcb.GetInstructionStateToString() + "执行完成]");
                pc++;

                if (pc >= pcb.GetInstructionCount())// 如果进程执行结束
                {
                    pcb.SetFinishTime(ClockInterruptHandlerThread.GetCurrentTime());
                    pcb.SetState(-1);
                    OSKernel.memory.ReleaseMemory(pcb);
                    System.out.println(ClockInterruptHandlerThread.GetCurrentTime() + " [终止进程：进程" + pcb.GetPid()
                            + "执行结束" + "一共耗时：" + (pcb.GetFinishTime() - pcb.GetInTime()) + "。内存释放成功]");
                    SwingUtilities.invokeLater(() -> OSKernel.ui
                            .AddOutBlockMessage(ClockInterruptHandlerThread.GetCurrentTime() + " [终止进程：进程" + pcb.GetPid()
                                    + "执行结束" + "一共耗时：" + (pcb.GetFinishTime() - pcb.GetInTime()) + "内存释放成功]"));
                    OSKernel.loader.AddMessageToSaveList(ClockInterruptHandlerThread.GetCurrentTime() + " [终止进程：进程"
                            + pcb.GetPid() + "执行结束" + "一共耗时：" + (pcb.GetFinishTime() - pcb.GetInTime()) + "。内存释放成功]");
                    OSKernel.loader.PrintBlockInfo();// 进程结束打印进程的状态信息
                }

                else if (pc < pcb.GetInstructionCount()) // 如果进程还没有结束
                {
                    pcb.SetPc(pc);
                    BackToReadyQueue(pcb);// 重回就绪队列
                }
                count_o = 0;
            }

        }
    }

    public void BackToReadyQueue(PCB pcb) {
        switch (pcb.GetTimeSlice()) {
            case 1:
                OSKernel.readyQueue1.add(pcb);
                pcb.readQueue.add(ClockInterruptHandlerThread.GetCurrentTime());// 设置再次进入就绪队列的时间
                System.out.println(ClockInterruptHandlerThread.GetCurrentTime() + " [唤醒进程：进程" + pcb.GetPid()
                        + " 再次进入就绪队列1,待执行指令条数：" + (pcb.GetInstructionCount() - pcb.GetPc()) + "]");
                SwingUtilities.invokeLater(() -> OSKernel.ui
                        .AddOutBlockMessage(ClockInterruptHandlerThread.GetCurrentTime() + " [唤醒进程：进程" + pcb.GetPid()
                                + " 再次进入就绪队列1,待执行指令条数：" + (pcb.GetInstructionCount() - pcb.GetPc()) + "]"));
                OSKernel.loader.AddMessageToSaveList(ClockInterruptHandlerThread.GetCurrentTime() + " [唤醒进程：进程"
                        + pcb.GetPid() + " 再次进入就绪队列1,待执行指令条数：" + (pcb.GetInstructionCount() - pcb.GetPc()) + "]");
                OSKernel.loader.InitReadyQueue(ClockInterruptHandlerThread.GetCurrentTime());// 打印重新回到就绪队列的PCB信息
                break;
            case 2:
                OSKernel.readyQueue2.add(pcb);
                pcb.readQueue.add(ClockInterruptHandlerThread.GetCurrentTime());// 设置再次进入就绪队列的时间
                System.out.println(ClockInterruptHandlerThread.GetCurrentTime() + " [唤醒进程：进程" + pcb.GetPid()
                        + " 再次进入就绪队列2,待执行指令条数：" + (pcb.GetInstructionCount() - pcb.GetPc()) + "]");
                SwingUtilities.invokeLater(() -> OSKernel.ui
                        .AddOutBlockMessage(ClockInterruptHandlerThread.GetCurrentTime() + " [唤醒进程：进程" + pcb.GetPid()
                                + " 再次进入就绪队列2,待执行指令条数：" + (pcb.GetInstructionCount() - pcb.GetPc()) + "]"));
                OSKernel.loader.AddMessageToSaveList(ClockInterruptHandlerThread.GetCurrentTime() + " [唤醒进程：进程"
                        + pcb.GetPid() + " 再次进入就绪队列2,待执行指令条数：" + (pcb.GetInstructionCount() - pcb.GetPc()) + "]");
                OSKernel.loader.InitReadyQueue(ClockInterruptHandlerThread.GetCurrentTime());
                break;
            case 4:
                OSKernel.readyQueue3.add(pcb);
                pcb.readQueue.add(ClockInterruptHandlerThread.GetCurrentTime());// 设置再次进入就绪队列的时间
                System.out.println(ClockInterruptHandlerThread.GetCurrentTime() + " [唤醒进程：进程" + pcb.GetPid()
                        + " 再次进入就绪队列3,待执行指令条数：" + (pcb.GetInstructionCount() - pcb.GetPc()) + "]");
                SwingUtilities.invokeLater(() -> OSKernel.ui
                        .AddOutBlockMessage(ClockInterruptHandlerThread.GetCurrentTime() + " [唤醒进程：进程" + pcb.GetPid()
                                + " 再次进入就绪队列3,待执行指令条数：" + (pcb.GetInstructionCount() - pcb.GetPc()) + "]"));
                OSKernel.loader.AddMessageToSaveList(ClockInterruptHandlerThread.GetCurrentTime() + " [唤醒进程：进程"
                        + pcb.GetPid() + " 再次进入就绪队列3,待执行指令条数：" + (pcb.GetInstructionCount() - pcb.GetPc()) + "]");
                OSKernel.loader.InitReadyQueue(ClockInterruptHandlerThread.GetCurrentTime());
                break;
        }
    }

}
