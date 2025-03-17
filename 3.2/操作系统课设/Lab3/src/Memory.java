import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import javax.swing.SwingUtilities;

public class Memory {
    public UI ui; // 图形化界面
    public MMU mmu = new MMU();// 转换器
    public static final int memorySize = 100; // 10个物理块，每个1000B，占用10个存储单元，此处为了省事直接换成处理100个小物理块，每个小物理块100B
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
            MemoryBlock tmpMemoryBlock = new MemoryBlock(false, 0, 0, i);
            tmpMemoryBlock.SetTakenUp(false);
            memoryBlock.add(tmpMemoryBlock);
        }
    }

    // 刷新映射，每一次内存改变都需要刷新
    public void RefreshReflectMap() {
        reflectMap.clear();
        int startAddress = -1;
        int freeBlock = 0;
        // 刷新每一块内存
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
        // 在所有的块中进行寻找，最小的适合当前pcb的块
        for (Map.Entry<Integer, Integer> entry : reflectMap.entrySet()) {
            int startAddress = entry.getKey();
            int freeBlocks = entry.getValue();
            if (freeBlocks >= neededBlock && freeBlocks < bestFitBlockSize) {
                bestFitStartAddress = startAddress;
                bestFitBlockSize = freeBlocks;
            }
        }
        // 找到内存进行分配
        if (bestFitStartAddress != -1) {
            OSKernel.totalProcess++;
            pcb.SetPid(OSKernel.totalProcess);
            int blockId = bestFitStartAddress / MemoryBlock.blockSize;
            if (bestFitStartAddress % MemoryBlock.blockSize > 0)
                blockId++;
            int remainingSize = pcb.GetCalculateNum();
            for (int i = blockId; i < blockId + neededBlock; i++) {
                memoryBlock.get(i).SetTakenUp(true);
                memoryBlock.get(i).SetPid(pcb.GetPid());
                memoryBlock.get(i).SetJid(pcb.GetJobId());
                // 完全占有、部分占有，在块大小为1000B是有用，100B就没啥用了
                if (remainingSize >= MemoryBlock.blockSize) {
                    memoryBlock.get(i).SetOccupiedSize(MemoryBlock.blockSize);
                    remainingSize -= MemoryBlock.blockSize;
                } else {
                    memoryBlock.get(i).SetOccupiedSize(remainingSize);
                    remainingSize = 0;
                }
                if (remainingSize == 0) {
                    pcb.SetStartAddress(blockId * MemoryBlock.blockSize);
                    mmu.address.put(pcb.GetPid(), pcb.GetStartAddress());
                }
            }
            OSKernel.deviceA.Use(pcb.GetNeedA());
            OSKernel.deviceB.Use(pcb.GetNeedB());
            RefreshReflectMap();
            SwingUtilities.invokeLater(() -> {
                ui.UpdateMemoryStatus(memoryBlock);
            });
            return true;
        }
        return false;
    }

    // 释放内存，同时释放设备
    // 只有当进程结束时才进行释放，释放内存的时候把设备占用也释放
    public void ReleaseMemory(PCB pcb) {
        if (pcb.GetState() == -1) {
            int startPhysicalAddress = pcb.GetStartAddress();
            int blockNumber = pcb.GetCalculateNum() / MemoryBlock.blockSize;
            if (pcb.GetCalculateNum() % MemoryBlock.blockSize != 0) {
                blockNumber++;
            }
            // 遍历进程所占有的所有块进行操作
            for (int i = 0; i < blockNumber; i++) {
                int blockId = (startPhysicalAddress / MemoryBlock.blockSize) + i;
                MemoryBlock block = memoryBlock.get(blockId);
                block.SetTakenUp(false);
                block.SetOccupiedSize(0);
                block.SetPid(0);
                block.SetJid(0);
            }
            OSKernel.deviceA.Release(pcb.GetNeedA());
            OSKernel.deviceB.Release(pcb.GetNeedB());
            RefreshReflectMap();
            SwingUtilities.invokeLater(() -> {
                ui.UpdateMemoryStatus(memoryBlock);
            });
        }
    }
}
