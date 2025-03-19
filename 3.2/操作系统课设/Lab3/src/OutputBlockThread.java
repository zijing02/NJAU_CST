import javax.swing.SwingUtilities;

public class OutputBlockThread extends Thread {
        public int outCount = 0;
        public static final int outTime = 3;

        @Override
        public void run() {
                while (true) {
                        SyncManager.outLock.lock();
                        try {
                                SyncManager.outputBeforeClock = true;
                                SyncManager.outputBeforeClk.signal();
                                SyncManager.outputCondition.await();

                                ALL_IO();
                        } catch (InterruptedException e) {
                                e.printStackTrace();
                        } finally {
                                SyncManager.outLock.unlock();
                        }
                }
        }

        public void ALL_IO() {
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
                                                + (pcb.GetPc() + 1) + "条指令" + pcb.StateToString()
                                                + "执行完成]";
                                System.out.println(message);
                                SwingUtilities.invokeLater(() -> OSKernel.ui.AddOutBlockMessage(message));
                                OSKernel.loader.AddMessageToSaveList(message);
                                pc++;
                                if (pc >= pcb.GetInstructionCount()) {
                                        pcb.SetFinishTime(ClockInterruptHandlerThread.GetCurrentTime());
                                        pcb.SetState(-1);
                                        OSKernel.memory.ReleaseMemory(pcb);
                                        String message2 = ClockInterruptHandlerThread.GetCurrentTime() + " [终止进程"
                                                        + pcb.GetPid() + "，结束时间："
                                                        + ClockInterruptHandlerThread.GetCurrentTime() + " 请求时间,"
                                                        + pcb.GetInTime() + "，总耗时："
                                                        + (pcb.GetFinishTime() - pcb.GetCreateTime()) + "]";
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
