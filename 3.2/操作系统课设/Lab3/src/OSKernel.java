import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.concurrent.LinkedBlockingQueue;

public class OSKernel {
    public static UI ui = new UI(); // 图形化界面
    public static CPU cpu = new CPU(ui); // CPU
    public static JobAndInstructionLoader loader = new JobAndInstructionLoader(); // 作业和指令加载器
    public static Memory memory = new Memory(new MMU(), ui); // 内存
    public static final int timeSlice1 = 1; // 时间片1
    public static final int timeSlice2 = 2; // 时间片2
    public static final int timeSlice3 = 4; // 时间片3
    public static int totalProcess = 0;
    public static LinkedList<Job> jobQueue = new LinkedList<>(); // 后备队列，用于存放备份的作业
    public static LinkedList<PCB> pcbQueue = new LinkedList<>(); // 进程缓冲区队列
    public static LinkedBlockingQueue<PCB> waitQueue = new LinkedBlockingQueue<>(); // 无法满足需求的等待队列，线程安全队列
    public static LinkedList<PCB> readyQueue1 = new LinkedList<>(); // 一级就绪队列
    public static LinkedList<PCB> readyQueue2 = new LinkedList<>(); // 二级就绪队列
    public static LinkedList<PCB> readyQueue3 = new LinkedList<>(); // 三级就绪队列
    public static LinkedList<PCB> inBlockQueue = new LinkedList<>(); // 进程输入阻塞队列
    public static LinkedList<PCB> outBlockQueue = new LinkedList<>(); // 进程输出阻塞队列
    public static Map<Integer, List<String>> inBlock = new HashMap<>(); // 输入阻塞队列
    public static Map<Integer, List<String>> outBlock = new HashMap<>(); // 输出阻塞队列
    public static Device deviceA = new Device(2); // 设备 A 2个
    public static Device deviceB = new Device(1); // 设备 B 1个

    public static boolean CheckEmpty() {
        // 当所有队列都为空时，返回 true，供后续判断
        if (ClockInterruptHandlerThread.GetCurrentTime() != 0 && OSKernel.jobQueue.isEmpty() && pcbQueue.isEmpty()
                && readyQueue1.isEmpty() && readyQueue2.isEmpty() && readyQueue3.isEmpty() && inBlockQueue.isEmpty()
                && outBlockQueue.isEmpty() && waitQueue.isEmpty()) {

            return true;
        }
        return false;
    }
}
