import java.util.ArrayList;

public class Job {
    private int jobId; // 作业的唯一标识符
    private int inTime; // 作业进入系统的时间
    private int priority; // 进程优先级，默认全为0，也没用上
    private int needA; // 需要A
    private int needB; // 需要B
    private int instructionCount; // 作业包含的指令数量
    private ArrayList<Instruction> instructions; // 与作业关联的指令列表

    public Job(int jobId, int inTime, int priority, int needA, int needB) {
        this.jobId = jobId;
        this.inTime = inTime;
        this.priority = priority;
        this.needA = needA;
        this.needB = needB;
    }

    public Job(int jobId, int inTime, int instructionCount, ArrayList<Instruction> instructions) {
        this.jobId = jobId;
        this.inTime = inTime;
        this.instructionCount = instructionCount;
        this.instructions = instructions;
        System.out.println("作业 " + jobId + " 读入成功，到达时间: " + inTime + "，指令数量: " + instructionCount); // 每加载一个作业时打印
    }

    public Job(int jobId, int inTime, int priority, int needA, int needB, int instructionCount,
            ArrayList<Instruction> instructions) {
        this.jobId = jobId;
        this.inTime = inTime;
        this.priority = priority;
        this.needA = needA;
        this.needB = needB;
        this.instructionCount = instructionCount;
        this.instructions = instructions;
    }

    public int GetJobId() {
        return jobId;
    }

    public int GetInTime() {
        return inTime;
    }

    public int GetNeedA() {
        return needA;
    }

    public int GetNeedB() {
        return needB;
    }

    public int GetPriority() {
        return priority;
    }

    public int GetInstructionCount() {
        return instructionCount;
    }

    public void SetInstructionCount(int count) {
        this.instructionCount = count;
    }

    public void DecInstructionCount() {
        this.instructionCount--;
    }

    public ArrayList<Instruction> GetInstructions() {
        return instructions;
    }

    public void SetInstructions(ArrayList<Instruction> instructions) {
        this.instructions = instructions;
    }

    @Override
    public String toString() {
        return jobId + "," + inTime + "," + instructionCount;
    }
}