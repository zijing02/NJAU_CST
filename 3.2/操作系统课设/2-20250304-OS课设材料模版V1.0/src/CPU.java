import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class CPU {
    private int pc; // 程序计数器
    private int ir; // 指令寄存器
    private int psw; // 程序状态字
    private Map<String, Integer> registerBackup; // 寄存器备份，用于进程切换时保存寄存器状态
    private static CPU instance = null; // 单例模式实例
    public static Process currentProcess; // 当前正在执行的进程
    public static int instructionPointer; // 当前进程的指令指针

    // 私有构造函数，防止外部实例化
    private CPU() {
        this.pc = 0;
        this.ir = 0;
        this.psw = 0;
        this.registerBackup = new HashMap<>();
        currentProcess = null;
        instructionPointer = 0;
    }

    public void runProcess() {

    }
    //CPU现场保护
    private CPU_PRO() {

    }

    //CPU现场恢复
    private CPU_REC() {

    }
}
