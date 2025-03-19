import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

// 同步管理类，包含锁、条件变量 
public class SyncManager {
    // 共享锁
    public static final Lock pstLock = new ReentrantLock(); // 进程调度锁
    public static final Lock jstLock = new ReentrantLock(); // 作业调度锁
    public static final Lock inLock = new ReentrantLock(); // I/O 操作锁
    public static final Lock outLock = new ReentrantLock(); // I/O 操作锁

    // 一级条件变量：用于时钟线程和进程调度线程之间的同步
    public static final Lock clkLock = new ReentrantLock(); // 时钟线程的锁
    public static final Condition pstCondition = pstLock.newCondition(); // 进程调度线程的条件变量
    public static final Condition jstCondition = jstLock.newCondition(); // 作业调度线程的条件变量
    public static final Condition inputCondition = inLock.newCondition(); // 输入操作的条件变量
    public static final Condition outputCondition = outLock.newCondition(); // 输出操作的条件变量

    // 二级条件变量：用于确保其他线程在始终线程之前完成
    public static final Condition pstBeforeClk = pstLock.newCondition(); // 进程调度线程在时钟中断之前完成的条件变量
    public static final Condition jstBeforeClk = jstLock.newCondition(); // 作业调度线程在时钟中断之前完成的条件变量
    public static final Condition inputBeforeClk = inLock.newCondition(); // I/O 操作在时钟中断之前完成的条件变量
    public static final Condition outputBeforeClk = outLock.newCondition(); // I/O 操作在时钟中断之前完成的条件变量

    // 标记：用于标记其他线程是否在时钟中断之前完成
    public static boolean pstBeforeClock = false; // 标记进程调度线程是否在时钟中断之前完成
    public static boolean jstBeforeClock = false; // 标记作业调度线程是否在时钟中断之前完成
    public static boolean inputBeforeClock = false; // 标记 I/O 操作是否在时钟中断之前完成
    public static boolean outputBeforeClock = false; // 标记 I/O 操作是否在时钟中断之前完成

    // 计数器：用于统计已完成的调度线程数量
    public static int completedTasks = 0;

    // 暂停运行锁、系统运行条件变量
    public static final Lock pauseLock = new ReentrantLock();
    public static final Condition pauseCondition = pauseLock.newCondition();
    public static boolean pauseFlag = false; // 状态标志：false: 暂停 true: 继续
    public static boolean startFlag = false; // 状态标志：系统是否已经启动
}
