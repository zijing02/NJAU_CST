import java.util.HashMap;

public class MMU {
    public HashMap<Integer, Integer> address = new HashMap<>();
    // 内存分配的映射表，用于存放进程的pid和物理地址的映射关系
    // 起始物理地址：0
    public static final int Baseaddress = 0;

    public int AddressTransformer(PCB pcb) {
        return (pcb.GetStartAddress() + Baseaddress + pcb.GetCount() * 100);
    }
}
