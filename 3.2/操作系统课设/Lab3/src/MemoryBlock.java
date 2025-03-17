public class MemoryBlock {
    private int blockID;// 每一个物理块的id
    private int pid; // 占用块的进程id
    private int jid; // 占用块的作业id
    private int occupiedSize; // 占用块的大小
    public static int blockSize = 100; // 块大小
    private boolean takenUp; // 是否被占用

    public MemoryBlock(boolean takenUp, int pid, int jid, int blockID) {
        this.takenUp = takenUp;
        this.pid = pid;
        this.jid = jid;
        this.blockID = blockID;
    }

    public int GetBlockID() {
        return blockID;
    }

    public void SetBlockID(int blockID) {
        this.blockID = blockID;
    }

    public int GetPid() {
        return pid;
    }

    public void SetPid(int pid) {
        this.pid = pid;
    }

    
    public int GetJid() {
        return jid;
    }

    public void SetJid(int jid) {
        this.jid = jid;
    }

    public int GetOccupiedSize() {
        return occupiedSize;
    }

    public void SetOccupiedSize(int occupiedSize) {
        this.occupiedSize = occupiedSize;
    }

    public boolean IsTakenUp() {
        return takenUp;
    }

    public void SetTakenUp(boolean takenUp) {
        this.takenUp = takenUp;
    }

    public int GetBlockSize() {
        return blockSize;
    }

    public void SetBlockSize(int blockSize) {
        MemoryBlock.blockSize = blockSize;
    }
}