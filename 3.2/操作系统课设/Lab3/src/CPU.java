import javax.swing.SwingUtilities;

public class CPU {
    private int pc; // 程序计数器
    private int ir; // 指令寄存器
    private int psw; // 程序状态字 0: 用户态 1: 核心态 -1: 空闲
    public UI ui; // 图形化界面
    // private CPU instance = null; // 单例模式实例，不知道啥么用，也没有依赖注入，要单例干啥
    public PCB currentProcess; // 当前正在执行的进程
    public int instructionPointer; // 当前进程的指令指针

    // 私有构造函数，防止外部实例化，不理解这一段为什么要是私有的，改成共有以从外部传入初始参数
    // 可能一开始的设计是为了从外部用函数访问，偷懒，直接改成共有
    public CPU(UI ui) {
        this.pc = 0;
        this.ir = 0;
        this.psw = -1;
        this.ui = ui;
        currentProcess = null;
        instructionPointer = 0;
    }

    public int GetPc() {
        return pc;
    }

    public void SetPc(int pc) {
        this.pc = pc;
    }

    public int GetIr() {
        return ir;
    }

    public void SetIr(int ir) {
        this.ir = ir;
    }

    public int GetPsw() {
        return this.psw;
    }

    public void SetPsw(int psw) {
        this.psw = psw;
    }

    public PCB GetCurrentProcess() {
        return this.currentProcess;
    }

    public void SetCurrentProcess(PCB currentProcess) {
        this.currentProcess = currentProcess;
    }

    // 获取当前线程状态，决定是计算还是阻塞
    public void RunProcess() {
        if (GetCurrentProcess() == null) {
            System.out.println("当前没有进程在运行");
            return;
        }
        int currentPC = this.GetCurrentProcess().GetPc();
        int irState = this.GetCurrentProcess().GetInstructionState();
        // 对当前pc进行赋值
        pc = currentPC;
        // 计算类指令，要求是不能中断，相当于直接运行跳过
        if (irState == 0) {
            SetPsw(0);
            this.GetCurrentProcess().INCCount();
            String message = ClockInterruptHandlerThread.GetCurrentTime() + " [运行进程：进程"
                    + this.GetCurrentProcess().GetPid() + " 的第" + (currentPC + 1) + "条指令，计算类指令，编号为0，物理地址为："
                    + OSKernel.memory.mmu.AddressTransformer(this.GetCurrentProcess()) + "数据大小100B]";
            System.out.println(message);
            SwingUtilities.invokeLater(() -> ui.AddRunningProcessMessage(message));
            OSKernel.loader.AddMessageToSaveList(message);
            currentPC++;
            this.GetCurrentProcess().SetPc(currentPC);
            psw = 0;
        }
        // 键盘输入类指令
        // 输入阻塞，检测到输入阻塞就将其加入OSKernel中的输入阻塞队列中
        else if (irState == 1) {
            SetPsw(1);
            PCB pcb = this.GetCurrentProcess();
            // 根据当前的时间片将对应就绪队列中的内容移除
            switch (pcb.GetTimeSlice()) {
                case 1:
                    OSKernel.readyQueue1.remove(pcb);
                    break;
                case 2:
                    OSKernel.readyQueue2.remove(pcb);
                    break;
                case 4:
                    OSKernel.readyQueue3.remove(pcb);
                    break;
            }
            OSKernel.inBlockQueue.add(pcb);
            OSKernel.loader.CheckInputBlock(pcb.GetPid(),
                    ("请求时间：" + ClockInterruptHandlerThread.GetCurrentTime()));
            String message = ClockInterruptHandlerThread.GetCurrentTime() + " [阻塞进程：进程" + pcb.GetPid()
                    + "进入输入阻塞队列，开始调度下一个进程]";
            System.out.println(message);
            SwingUtilities.invokeLater(() -> ui.AddRunningProcessMessage(message));
            OSKernel.loader.AddMessageToSaveList(message);
            OSKernel.loader.AddInfoToBlockQueue(ClockInterruptHandlerThread.GetCurrentTime());
            psw = 1;
        }
        // 屏幕输出类指令
        // 输出阻塞，检测到输入阻塞就将其加入OSKernel中的输出阻塞队列中
        else {
            SetPsw(1);
            PCB pcb = this.GetCurrentProcess();
            switch (pcb.GetTimeSlice()) {
                case 1:
                    OSKernel.readyQueue1.remove(pcb);
                    break;
                case 2:
                    OSKernel.readyQueue2.remove(pcb);
                    break;
                case 4:
                    OSKernel.readyQueue3.remove(pcb);
                    break;
            }
            OSKernel.outBlockQueue.add(pcb);
            OSKernel.loader.CheckOutputBlock(pcb.GetPid(),
                    ("请求时间：" + ClockInterruptHandlerThread.GetCurrentTime()));
            String message = ClockInterruptHandlerThread.GetCurrentTime() + " [阻塞进程：进程" + pcb.GetPid()
                    + "进入输出阻塞队列,开始调度下一个进程]";
            System.out.println(message);
            SwingUtilities.invokeLater(() -> ui.AddRunningProcessMessage(message));
            OSKernel.loader.AddMessageToSaveList(message);
            OSKernel.loader.AddInfoToBlockQueue(ClockInterruptHandlerThread.GetCurrentTime());
            psw = 1;
        }
    }

    // 保护和恢复在实际中仅通过SetPsw实现，直接调用，所以这俩函数没用上
    // CPU现场保护
    public void CPU_PRO() {
        pc = 0;
        SetPsw(1);
    }

    // CPU现场恢复
    public void CPU_REC() {

    }
}
