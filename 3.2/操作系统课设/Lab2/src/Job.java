import java.util.List;

public class Job {
    private int jobId;               // 作业的唯一标识符
    private int inTime;              // 作业进入系统的时间
    private int instructionCount;    // 作业包含的指令数量
    private List<Instruction> instructions; // 与作业关联的指令列表

    public Job(int jobId, int inTime, int instructionCount) {
        this.jobId = jobId;
        this.inTime = inTime;
        this.instructionCount = instructionCount;
        System.out.println("作业 " + jobId + " 读入成功，到达时间: " + inTime + "，指令数量: " + instructionCount);  // 每加载一个作业时打印
    }

    public int getJobId() {
        return jobId;
    }

    public int getInTime() {
        return inTime;
    }

    public int getInstructionCount() {
        return instructionCount;
    }

    public void decInstructionCount() {
        this.instructionCount--;
    }

    public List<Instruction> getInstructions() {
        return instructions;
    }

    public void setInstructions(List<Instruction> instructions) {
        this.instructions = instructions;
    }

    @Override
    public String toString() {
        return jobId + "," + inTime + "," + instructionCount;
    }
}