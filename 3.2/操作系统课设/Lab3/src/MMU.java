import java.util.HashMap;

public class MMU {
    public HashMap<Integer, Integer> address = new HashMap<>();
    // 起始物理地址：0
    public static final int baseAddress = 0;

    // 地址转换：一个进程占用内存大小=该进程中用户态计算操作指令个数*100B
    public int AddressTransformer(PCB pcb) {
        return (pcb.GetStartAddress() + baseAddress + pcb.GetCount() * 100);
    }
}
