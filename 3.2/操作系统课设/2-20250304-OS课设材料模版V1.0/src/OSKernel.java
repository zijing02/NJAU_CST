import java.util.Queue;
import java.util.LinkedList;



public class OSKernel {

    // 后备队列，用于存放备份的作业
    public static Queue<Job> backupQueue;
    // 就绪队列，用于存放已准备好执行的进程
    public static Queue<PCB> readyQueue;

}
