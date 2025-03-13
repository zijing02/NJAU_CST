import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

public class OSKernel {
    public static UI ui = new UI(); // 图形化界面
    public static CPU cpu = new CPU(ui); // CPU
    public static JobAndInstructionLoader loader = new JobAndInstructionLoader(); // 作业和指令加载器
    public static Memory memory = new Memory(new MMU(), ui); // 内存
    public static final int timeSlice1 = 1; // 时间片1
    public static final int timeSlice2 = 2; // 时间片2
    public static final int timeSlice3 = 4; // 时间片3
    public static Queue<Job> jobQueue = new LinkedList<>(); // 后备队列，用于存放备份的作业
    public static Queue<PCB> pcbQueue = new LinkedList<>(); // 进程缓冲区队列
    public static Queue<PCB> waitQueue = new LinkedList<>(); // 无法满足需求的等待队列
    public static Queue<PCB> readyQueue1 = new LinkedList<>(); // 一级就绪队列
    public static Queue<PCB> readyQueue2 = new LinkedList<>(); // 二级就绪队列
    public static Queue<PCB> readyQueue3 = new LinkedList<>(); // 三级就绪队列
    public static Queue<PCB> inBlockQueue = new LinkedList<>(); // 进程输入阻塞队列
    public static Queue<PCB> outBlockQueue = new LinkedList<>(); // 进程输出阻塞队列
    public static Map<Integer, List<String>> inBlock = new HashMap<>(); // 输入阻塞队列
    public static Map<Integer, List<String>> outBlock = new HashMap<>(); // 输出阻塞队列
    public static Device deviceA = new Device(2); // 设备 A 的最大容量为 2
    public static Device deviceB = new Device(1); // 设备 B 的最大容量为 1

    public static boolean CheckEmpty() {
        // 当所有队列都为空时，返回 true
        if (OSKernel.jobQueue.isEmpty() && ClockInterruptHandlerThread.GetCurrentTime() != 0
                && jobQueue.isEmpty() && readyQueue3.isEmpty() && readyQueue2.isEmpty() && readyQueue1.isEmpty()
                && inBlockQueue.isEmpty() && outBlockQueue.isEmpty())
            return true;
        return false;
    }
}
