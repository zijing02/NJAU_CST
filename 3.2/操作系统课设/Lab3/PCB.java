import java.util.ArrayList;

public class PCB extends Job {
    public PCB(int jobId, int inTime, int needA, int needB, int instructionCount, ArrayList<Instruction> instructions) {
        super(jobId, inTime, 0, needA, needB, instructionCount, instructions);
        this.pid = jobId;
        this.needA = needA;
        this.needB = needB;
        this.pc = 0;
        this.state = 0;
        this.startAddress = 0;
        this.createTime = 0;
        this.finishTime = 0;
        this.timeSlice = 0;
        this.countPC = 0;
    }

    private int pid;
    private int pc; // 程序计数器
    private int state; // 进程状态 0: 就绪 1: 运行 -1: 阻塞
    private int startAddress; // 进程的起始物理地址
    private int needA; // 需要的外部设备A
    private int needB; // 需要的外部设备B
    private int createTime; // 进程的创建时间
    private int finishTime; // 进程的结束时间
    private int timeSlice; // 时间片
    private int countPC; // 记录进程执行的指令数
    public ArrayList<Integer> readQueue = new ArrayList<>();// 存放该进程每次进入就绪队列的时刻

    public int GetPid() {
        return pid;
    }

    public void SetPid(int pid) {
        this.pid = pid;
    }

    public int GetPc() {
        return pc;
    }

    public void SetPc(int pc) {
        this.pc = pc;
    }

    public int GetState() {
        return state;
    }

    public void SetState(int state) {
        this.state = state;
    }

    public int GetStartAddress() {
        return startAddress;
    }

    public void SetStartAddress(int startAddress) {
        this.startAddress = startAddress;
    }

    public int GetNeedA() {
        return needA;
    }

    public int GetNeedB() {
        return needB;
    }

    public int GetCreateTime(){
        return createTime;
    }

    public void SetCreateTime(int createTime) {
        this.createTime = createTime;
    }

    public int GetFinishTime() {
        return finishTime;
    }

    public void SetFinishTime(int finishTime) {
        this.finishTime = finishTime;
    }

    public int GetTimeSlice() {
        return timeSlice;
    }

    public void SetTimeSlice(int timeSlice) {
        this.timeSlice = timeSlice;
    }

    public int GetCount() {
        return countPC;
    }

    public void INCCount() {
        countPC++;
    }

    public int GetCalculateNum() {
        int size = 0;
        for (Instruction instruction : super.GetInstructions()) {
            if (instruction.getState() == 0) {
                size++;
            }
        }
        return size * 100;
    }

    public int GetInstructionState() {
        if (this.pc < this.GetInstructionCount()) {
            return this.GetInstructions().get(this.pc).getState();
        } else if (this.pc >= this.GetInstructionCount()) {
            System.out.println("PC越界");
            return -1;
        }
        return -1;
    }

    public String GetInstructionStateToString() {
        if (this.pc >= super.GetInstructionCount()) {
            return "";
        }
        switch (this.GetInstructionState()) {
            case 0:
                return "用户态计算类指令";
            case 1:
                return "键盘输入";
            case 2:
                return "屏幕输出";
        }
        return "";
    }
}
