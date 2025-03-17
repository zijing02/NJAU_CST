import javax.swing.SwingUtilities;

public class OutputBlockThread extends Thread {
        public int inputCount = 0;
        public int outCount = 0;
        public static final int intTime = 2;
        public static final int outTime = 3;

        @Override
        public void run() {
                while (true) {
                        SyncManager.ioLock.lock();
                        try {
                                SyncManager.outputBeforeClock = true;
                                SyncManager.outputBeforeClk.signal();
                                SyncManager.outputCondition.await();

                                ALL_IO();
                        } catch (InterruptedException e) {
                                e.printStackTrace();
                        } finally {
                                SyncManager.ioLock.unlock();
                        }
                }
        }

        public void ALL_IO() {
                // if (!OSKernel.inBlockQueue.isEmpty()) {
                // PCB pcb = OSKernel.inBlockQueue.peek();
                // inputCount++;
                // if (inputCount == intTime) {
                // OSKernel.inBlockQueue.remove(pcb);
                // OSKernel.loader.CheckInputBlock(pcb.GetPid(),
                // ("唤醒时间：" + ClockInterruptHandlerThread.GetCurrentTime()));
                // int pc = pcb.GetPc();
                // String message = ClockInterruptHandlerThread.GetCurrentTime() + " [IO操作：进程"
                // + pcb.GetPid() + "的第"
                // + (pcb.GetPc() + 1) + "条指令" + pcb.GetInstructionStateToString()
                // + "执行完成]";
                // System.out.println(message);
                // SwingUtilities.invokeLater(() -> OSKernel.ui.AddOutBlockMessage(message));
                // OSKernel.loader.AddMessageToSaveList(message);
                // pc++;
                // if (pc >= pcb.GetInstructionCount()) {
                // pcb.SetFinishTime(ClockInterruptHandlerThread.GetCurrentTime());
                // pcb.SetState(-1);
                // OSKernel.memory.ReleaseMemory(pcb);
                // String message2 = ClockInterruptHandlerThread.GetCurrentTime() +
                // " [结束进程，结束时间：" +
                // ClockInterruptHandlerThread.GetCurrentTime() + " 进程" + pcb.GetPid() + "
                // 进入时间," + pcb.GetInTime() + "总耗时：" + (pcb.GetFinishTime() - pcb.GetInTime()) +
                // "]";
                // System.out.println(message2);
                // SwingUtilities.invokeLater(() -> OSKernel.ui.AddOutBlockMessage(message2));
                // OSKernel.loader.AddMessageToSaveList(message2);
                // OSKernel.loader.PrintBlockInfo();
                // } else if (pc < pcb.GetInstructionCount()) {
                // pcb.SetPc(pc);
                // BackToReadyQueue(pcb);
                // }
                // inputCount = 0;
                // }
                // }
                if (!OSKernel.outBlockQueue.isEmpty()) {
                        PCB pcb = OSKernel.outBlockQueue.peek();
                        outCount++;
                        if (outCount == outTime) {
                                OSKernel.outBlockQueue.remove(pcb);
                                OSKernel.loader.CheckOutputBlock(pcb.GetPid(),
                                                ("唤醒时间：" + ClockInterruptHandlerThread.GetCurrentTime()));
                                int pc = pcb.GetPc();
                                String message = ClockInterruptHandlerThread.GetCurrentTime() + " [IO操作：进程"
                                                + pcb.GetPid() + "的第"
                                                + (pcb.GetPc() + 1) + "条指令" + pcb.GetInstructionStateToString()
                                                + "执行完成]";
                                System.out.println(message);
                                SwingUtilities.invokeLater(() -> OSKernel.ui.AddOutBlockMessage(message));
                                OSKernel.loader.AddMessageToSaveList(message);
                                pc++;
                                if (pc >= pcb.GetInstructionCount()) {
                                        pcb.SetFinishTime(ClockInterruptHandlerThread.GetCurrentTime());
                                        pcb.SetState(-1);
                                        OSKernel.memory.ReleaseMemory(pcb);
                                        String message2 = ClockInterruptHandlerThread.GetCurrentTime() + " [结束进程，结束时间："
                                                        + ClockInterruptHandlerThread.GetCurrentTime() + " 进程"
                                                        + pcb.GetPid() + " 进入时间," + pcb.GetInTime() + "总耗时："
                                                        + (pcb.GetFinishTime() - pcb.GetInTime()) + "]";
                                        if (OSKernel.readyQueue3.contains(pcb)) {
                                                OSKernel.readyQueue3.remove(pcb);
                                        }
                                        OSKernel.loader.PrintBackToReadyQueue(
                                                        ClockInterruptHandlerThread.GetCurrentTime());
                                        System.out.println(message2);
                                        SwingUtilities.invokeLater(
                                                        () -> OSKernel.ui.AddRunningProcessMessage(message2));
                                        OSKernel.loader.AddMessageToSaveList(message2);
                                        OSKernel.loader.PrintBlockInfo();
                                } else if (pc < pcb.GetInstructionCount()) {
                                        pcb.SetPc(pc);
                                        BackToReadyQueue(pcb);
                                }
                                outCount = 0;
                        }
                }
        }

        public void BackToReadyQueue(PCB pcb) {
                String message;
                switch (pcb.GetTimeSlice()) {
                        case 1:
                                OSKernel.readyQueue1.add(pcb);
                                pcb.readQueue.add(ClockInterruptHandlerThread.GetCurrentTime());
                                message = ClockInterruptHandlerThread.GetCurrentTime() + " [唤醒进程：进程"
                                                + pcb.GetPid()
                                                + " 再次进入就绪队列1,待执行指令条数：" + (pcb.GetInstructionCount() - pcb.GetPc())
                                                + "]";
                                System.out.println(message);
                                SwingUtilities.invokeLater(() -> OSKernel.ui
                                                .AddOutBlockMessage(message));
                                OSKernel.loader.AddMessageToSaveList(message);
                                OSKernel.loader.PrintBackToReadyQueue(ClockInterruptHandlerThread.GetCurrentTime());
                                break;
                        case 2:
                                OSKernel.readyQueue2.add(pcb);
                                pcb.readQueue.add(ClockInterruptHandlerThread.GetCurrentTime());
                                message = ClockInterruptHandlerThread.GetCurrentTime() + " [唤醒进程：进程"
                                                + pcb.GetPid()
                                                + " 再次进入就绪队列2,待执行指令条数：" + (pcb.GetInstructionCount() - pcb.GetPc())
                                                + "]";
                                System.out.println(message);
                                SwingUtilities.invokeLater(() -> OSKernel.ui.AddOutBlockMessage(message));
                                OSKernel.loader.AddMessageToSaveList(message);
                                OSKernel.loader.PrintBackToReadyQueue(ClockInterruptHandlerThread.GetCurrentTime());
                                break;
                        case 4:
                                OSKernel.readyQueue3.add(pcb);
                                pcb.readQueue.add(ClockInterruptHandlerThread.GetCurrentTime());
                                message = ClockInterruptHandlerThread.GetCurrentTime() + " [唤醒进程：进程"
                                                + pcb.GetPid()
                                                + " 再次进入就绪队列3,待执行指令条数：" + (pcb.GetInstructionCount() - pcb.GetPc())
                                                + "]";
                                System.out.println(message);
                                SwingUtilities.invokeLater(() -> OSKernel.ui.AddOutBlockMessage(message));
                                OSKernel.loader.AddMessageToSaveList(message);
                                OSKernel.loader.PrintBackToReadyQueue(ClockInterruptHandlerThread.GetCurrentTime());
                                break;
                }
        }
}
