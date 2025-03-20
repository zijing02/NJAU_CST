public class PCB extends Job {
    private int pid;
    private int pc; // Program Counter
    private int state; // Process state

    public PCB(int jobId, int inTime, int instructionCount, int pid) {
        super(jobId, inTime, instructionCount);
        this.pid = pid;
        this.pc = 0;
        this.state = 0; // Assume 0 represents a ready state
    }
}
