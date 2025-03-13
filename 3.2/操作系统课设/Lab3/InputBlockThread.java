import javax.swing.*;

public class InputBlockThread extends Thread {
        public int count_i = 0;
        public int count_o = 0;
        public static final int INTime = 2;// 处理一个IO的时间

        @Override
        public void run() {
                while (true) {
                        SyncManager.ioLock.lock();
                        try {
                                SyncManager.inputBeforeClock = true;
                                SyncManager.inputBeforeClk.signal();
                                SyncManager.inputCondition.await();
                                ALL_IO();
                        } catch (InterruptedException e) {
                                e.printStackTrace();
                        } finally {
                                SyncManager.ioLock.unlock();
                        }
                }
        }

        // All_IO()函数中偷懒，inputBlock和outputBlock中都写一遍，这样可以减少相应锁的争夺
        public void ALL_IO() {
                if (!OSKernel.inBlockQueue.isEmpty()) {
                        PCB pcb = OSKernel.inBlockQueue.peek();
                        count_i++;
                        if (count_i == INTime) {
                                OSKernel.inBlockQueue.remove(pcb);
                                OSKernel.loader.CheckInputBlock(pcb.GetPid(),
                                                ("唤醒时间：" + ClockInterruptHandlerThread.GetCurrentTime()));
                                int pc = pcb.GetPc();
                                System.out.println(ClockInterruptHandlerThread.GetCurrentTime() + " [IO操作：进程"
                                                + pcb.GetPid() + "的第"
                                                + (pcb.GetPc() + 1) + "条指令" + pcb.GetInstructionStateToString()
                                                + "执行完成]");
                                SwingUtilities.invokeLater(() -> OSKernel.ui
                                                .AddInBlockMessage(ClockInterruptHandlerThread.GetCurrentTime()
                                                                + " [IO操作：进程" + pcb.GetPid()
                                                                + "的第" + (pcb.GetPc() + 1) + "条指令"
                                                                + pcb.GetInstructionStateToString() + "执行完成]"));
                                OSKernel.loader
                                                .AddMessageToSaveList(ClockInterruptHandlerThread.GetCurrentTime()
                                                                + " [IO操作：进程" + pcb.GetPid()
                                                                + "的第" + (pcb.GetPc() + 1) + "条指令"
                                                                + pcb.GetInstructionStateToString() + "执行完成]");
                                pc++;

                                if (pc >= pcb.GetInstructionCount()) {
                                        pcb.SetFinishTime(ClockInterruptHandlerThread.GetCurrentTime());
                                        pcb.SetState(-1);
                                        OSKernel.memory.ReleaseMemory(pcb);
                                        System.out.println(ClockInterruptHandlerThread.GetCurrentTime() + " [终止进程：进程"
                                                        + pcb.GetPid()
                                                        + "执行结束" + "一共耗时：" + (pcb.GetFinishTime() - pcb.GetInTime())
                                                        + "。内存释放成功]");
                                        SwingUtilities.invokeLater(() -> OSKernel.ui
                                                        .AddInBlockMessage(ClockInterruptHandlerThread.GetCurrentTime()
                                                                        + " [终止进程：进程" + pcb.GetPid()
                                                                        + "执行结束" + "一共耗时："
                                                                        + (pcb.GetFinishTime() - pcb.GetInTime())
                                                                        + "内存释放成功]"));
                                        OSKernel.loader.AddMessageToSaveList(ClockInterruptHandlerThread.GetCurrentTime()
                                                        + " [终止进程：进程"
                                                        + pcb.GetPid() + "执行结束" + "一共耗时："
                                                        + (pcb.GetFinishTime() - pcb.GetInTime()) + "。内存释放成功]");
                                        OSKernel.loader.PrintBlockInfo();
                                }

                                else if (pc < pcb.GetInstructionCount()) {
                                        pcb.SetPc(pc);
                                        BackToReadyQueue(pcb);
                                }
                                count_i = 0;
                        }

                }
                if (!OSKernel.outBlockQueue.isEmpty()) {

                        PCB pcb = OSKernel.outBlockQueue.peek();
                        count_o++;
                        if (count_o == INTime) {
                                OSKernel.outBlockQueue.remove(pcb);
                                OSKernel.loader.CheckOutputBlock(pcb.GetPid(),
                                                ("唤醒时间：" + ClockInterruptHandlerThread.GetCurrentTime()));
                                int pc = pcb.GetPc();
                                System.out.println(ClockInterruptHandlerThread.GetCurrentTime() + " [IO操作：进程"
                                                + pcb.GetPid() + "的第"
                                                + (pcb.GetPc() + 1) + "条指令" + pcb.GetInstructionStateToString()
                                                + "执行完成]");
                                SwingUtilities.invokeLater(() -> OSKernel.ui
                                                .AddInBlockMessage(ClockInterruptHandlerThread.GetCurrentTime()
                                                                + " [IO操作：进程" + pcb.GetPid()
                                                                + "的第" + (pcb.GetPc() + 1) + "条指令"
                                                                + pcb.GetInstructionStateToString() + "执行完成]"));
                                OSKernel.loader
                                                .AddMessageToSaveList(ClockInterruptHandlerThread.GetCurrentTime()
                                                                + " [IO操作：进程" + pcb.GetPid()
                                                                + "的第" + (pcb.GetPc() + 1) + "条指令"
                                                                + pcb.GetInstructionStateToString() + "执行完成]");
                                pc++;

                                if (pc >= pcb.GetInstructionCount()) {
                                        pcb.SetFinishTime(ClockInterruptHandlerThread.GetCurrentTime());
                                        pcb.SetState(-1);
                                        OSKernel.memory.ReleaseMemory(pcb);
                                        System.out.println(ClockInterruptHandlerThread.GetCurrentTime() + " [终止进程：进程"
                                                        + pcb.GetPid()
                                                        + "执行结束" + "一共耗时：" + (pcb.GetFinishTime() - pcb.GetInTime())
                                                        + "。内存释放成功]");
                                        SwingUtilities.invokeLater(() -> OSKernel.ui
                                                        .AddInBlockMessage(ClockInterruptHandlerThread.GetCurrentTime()
                                                                        + " [终止进程：进程" + pcb.GetPid()
                                                                        + "执行结束" + "一共耗时："
                                                                        + (pcb.GetFinishTime() - pcb.GetInTime())
                                                                        + "内存释放成功]"));
                                        OSKernel.loader.AddMessageToSaveList(ClockInterruptHandlerThread.GetCurrentTime()
                                                        + " [终止进程：进程"
                                                        + pcb.GetPid() + "执行结束" + "一共耗时："
                                                        + (pcb.GetFinishTime() - pcb.GetInTime()) + "。内存释放成功]");
                                        OSKernel.loader.PrintBlockInfo();
                                }

                                else if (pc < pcb.GetInstructionCount()) {
                                        pcb.SetPc(pc);
                                        BackToReadyQueue(pcb);
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
                                System.out.println(ClockInterruptHandlerThread.GetCurrentTime() + " [唤醒进程：进程"
                                                + pcb.GetPid()
                                                + " 再次进入就绪队列1,待执行指令条数：" + (pcb.GetInstructionCount() - pcb.GetPc())
                                                + "]");
                                SwingUtilities.invokeLater(() -> OSKernel.ui
                                                .AddInBlockMessage(ClockInterruptHandlerThread.GetCurrentTime()
                                                                + " [唤醒进程：进程" + pcb.GetPid()
                                                                + " 再次进入就绪队列1,待执行指令条数："
                                                                + (pcb.GetInstructionCount() - pcb.GetPc()) + "]"));
                                OSKernel.loader.AddMessageToSaveList(
                                                ClockInterruptHandlerThread.GetCurrentTime() + " [唤醒进程：进程"
                                                                + pcb.GetPid() + " 再次进入就绪队列1,待执行指令条数："
                                                                + (pcb.GetInstructionCount() - pcb.GetPc()) + "]");
                                OSKernel.loader.InitReadyQueue(ClockInterruptHandlerThread.GetCurrentTime());// 打印重新回到就绪队列的PCB信息
                                break;
                        case 2:
                                OSKernel.readyQueue2.add(pcb);
                                pcb.readQueue.add(ClockInterruptHandlerThread.GetCurrentTime());// 设置再次进入就绪队列的时间
                                System.out.println(ClockInterruptHandlerThread.GetCurrentTime() + " [唤醒进程：进程"
                                                + pcb.GetPid()
                                                + " 再次进入就绪队列2,待执行指令条数：" + (pcb.GetInstructionCount() - pcb.GetPc())
                                                + "]");
                                SwingUtilities.invokeLater(() -> OSKernel.ui
                                                .AddInBlockMessage(ClockInterruptHandlerThread.GetCurrentTime()
                                                                + " [唤醒进程：进程" + pcb.GetPid()
                                                                + " 再次进入就绪队列2,待执行指令条数："
                                                                + (pcb.GetInstructionCount() - pcb.GetPc()) + "]"));
                                OSKernel.loader.AddMessageToSaveList(
                                                ClockInterruptHandlerThread.GetCurrentTime() + " [唤醒进程：进程"
                                                                + pcb.GetPid() + " 再次进入就绪队列2,待执行指令条数："
                                                                + (pcb.GetInstructionCount() - pcb.GetPc()) + "]");
                                OSKernel.loader.InitReadyQueue(ClockInterruptHandlerThread.GetCurrentTime());
                                break;
                        case 4:
                                OSKernel.readyQueue3.add(pcb);
                                pcb.readQueue.add(ClockInterruptHandlerThread.GetCurrentTime());// 设置再次进入就绪队列的时间
                                System.out.println(ClockInterruptHandlerThread.GetCurrentTime() + " [唤醒进程：进程"
                                                + pcb.GetPid()
                                                + " 再次进入就绪队列3,待执行指令条数：" + (pcb.GetInstructionCount() - pcb.GetPc())
                                                + "]");
                                SwingUtilities.invokeLater(() -> OSKernel.ui
                                                .AddInBlockMessage(ClockInterruptHandlerThread.GetCurrentTime()
                                                                + " [唤醒进程：进程" + pcb.GetPid()
                                                                + " 再次进入就绪队列3,待执行指令条数："
                                                                + (pcb.GetInstructionCount() - pcb.GetPc()) + "]"));
                                OSKernel.loader.AddMessageToSaveList(
                                                ClockInterruptHandlerThread.GetCurrentTime() + " [唤醒进程：进程"
                                                                + pcb.GetPid() + " 再次进入就绪队列3,待执行指令条数："
                                                                + (pcb.GetInstructionCount() - pcb.GetPc()) + "]");
                                OSKernel.loader.InitReadyQueue(ClockInterruptHandlerThread.GetCurrentTime());
                                break;
                }
        }

}
