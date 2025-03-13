import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import javax.swing.SwingUtilities;

public class Memory {
    public UI ui; // 图形化界面
    public MMU mmu = new MMU();// 转换器
    public static final int memorySize = 10; // 10个物理块，每个1000B，占用10个存储单元
    public ArrayList<MemoryBlock> memoryBlock = new ArrayList<>(); // 物理块分配情况列表
    public HashMap<Integer, Integer> reflectMap = new HashMap<>();// 内存中起始物理地址和连续空间块的的映射

    public Memory(MMU mmu, UI ui) {
        this.InitBlock();
        this.RefreshReflectMap();
        this.mmu = mmu;
        this.ui = ui;
    }

    public void InitBlock() {
        for (int i = 0; i < Memory.memorySize; i++) {
            MemoryBlock tmpMemoryBlock = new MemoryBlock(false, 0, i);
            tmpMemoryBlock.SetTakenUp(false);
            memoryBlock.add(tmpMemoryBlock);
        }
    }

    // 刷新映射，每一次内存改变都需要刷新
    public void RefreshReflectMap() {
        reflectMap.clear();
        int startAddress = -1;
        int freeBlock = 0;

        for (int i = 0; i < memoryBlock.size(); i++) {
            MemoryBlock block = memoryBlock.get(i);
            if (!block.IsTakenUp()) {
                if (startAddress == -1) {
                    startAddress = block.GetBlockID() * MemoryBlock.blockSize;
                }
                freeBlock++;
            } else {
                if (freeBlock > 0) {
                    reflectMap.put(startAddress, freeBlock);
                }
                startAddress = -1;
                freeBlock = 0;
            }
        }
        if (freeBlock > 0) {
            reflectMap.put(startAddress, freeBlock);
        }
    }

    // 分配内存
    // 最佳适配算法
    public boolean AllocateMemory(PCB pcb) {
        int calculateNum = pcb.GetCalculateNum();
        int neededBlock = calculateNum / MemoryBlock.blockSize;
        int bestFitStartAddress = -1;
        int bestFitBlockSize = Integer.MAX_VALUE;
        if (calculateNum % MemoryBlock.blockSize != 0) {
            neededBlock++;
        }
        for (Map.Entry<Integer, Integer> entry : reflectMap.entrySet()) {
            int startAddress = entry.getKey();
            int freeBlocks = entry.getValue();

            if (freeBlocks >= neededBlock && freeBlocks < bestFitBlockSize) {
                bestFitStartAddress = startAddress;
                bestFitBlockSize = freeBlocks;
            }
        }
        if (bestFitStartAddress != -1) {
            int block_id = bestFitStartAddress / MemoryBlock.blockSize;
            if (bestFitStartAddress % MemoryBlock.blockSize > 0)
                block_id++;
            int remainingSize = pcb.GetCalculateNum();
            for (int i = block_id; i < block_id + neededBlock; i++) {
                memoryBlock.get(i).SetTakenUp(true);
                memoryBlock.get(i).SetPid(pcb.GetPid());
                if (remainingSize >= MemoryBlock.blockSize) {
                    memoryBlock.get(i).SetOccupiedSize(MemoryBlock.blockSize);
                    remainingSize -= MemoryBlock.blockSize;
                } else {
                    memoryBlock.get(i).SetOccupiedSize(remainingSize);
                    remainingSize = 0;
                }
                if (remainingSize == 0) {
                    pcb.SetStartAddress(block_id * MemoryBlock.blockSize);
                    mmu.address.put(pcb.GetPid(), pcb.GetStartAddress());
                }
            }
            RefreshReflectMap();
            SwingUtilities.invokeLater(() -> {
                ui.UpdateMemoryStatus(memoryBlock);
            });
            return true;
        }
        return false;
    }

    // 释放内存
    // 只有当进程结束时才进行释放
    public void ReleaseMemory(PCB pcb) {
        if (pcb.GetState() == -1) {
            int startPhysicalAddress = pcb.GetStartAddress();
            int blockNumber = pcb.GetCalculateNum() / MemoryBlock.blockSize;
            if (pcb.GetCalculateNum() % MemoryBlock.blockSize > 0) {
                blockNumber++;
            }
            for (int i = 0; i < blockNumber; i++) {
                int block_id = (startPhysicalAddress / MemoryBlock.blockSize) + i;
                MemoryBlock block = memoryBlock.get(block_id);
                block.SetTakenUp(false);
                block.SetOccupiedSize(0);
                block.SetPid(0);
            }
            RefreshReflectMap();
            SwingUtilities.invokeLater(() -> {
                ui.UpdateMemoryStatus(memoryBlock);
            });
        }
    }

    // 获取当前系统中并发的进程数目，要求是不能大于12
    public int CheckTotalNum() {
        return (OSKernel.outBlockQueue.size() +
                OSKernel.readyQueue1.size() +
                OSKernel.readyQueue2.size() +
                OSKernel.readyQueue3.size() +
                OSKernel.outBlock.size());
    }
}
