
import java.util.HashMap;
import java.util.Map;

/**
 * Instruction类表示一个指令，包含其ID和状态。
 * 状态描述通过静态映射进行管理。
 */
public class Instruction {
    private int id;                    // 指令的唯一标识符
    private int state;                 // 指令的状态
    private static final Map<Integer, String> stateDescriptions = new HashMap<>(); // 状态描述的静态映射

    // 静态代码块，用于初始化状态描述映射，不同的数字代表了指令不同的状态，可根据不同等级进行自定义
    static {
        stateDescriptions.put(0, "计算");   // 状态0表示计算
        stateDescriptions.put(1, "I/O操作"); // 状态1表示I/O操作
    }

    /**
     * 构造一个Instruction对象，包含指定的ID和状态。
     *
     * @param id    指令的唯一标识符
     * @param state 指令的状态
     */
    public Instruction(int id, int state) {
        this.id = id;          // 用提供的id初始化id字段
        this.state = state;    // 用提供的state初始化state字段
        System.out.println("指令 " + id + " 加载成功，状态: " + getStateDescription());  // 每加载一个指令时打印
    }

    /**
     * 获取指令的唯一标识符。
     *
     * @return 指令的唯一标识符
     */
    public int getId() {
        return id;
    }

    /**
     * 获取指令的状态。
     *
     * @return 指令的状态
     */
    public int getState() {
        return state;
    }

    /**
     * 获取指令状态的描述。
     *
     * @return 指令状态的描述字符串
     */
    public String getStateDescription() {
        return stateDescriptions.getOrDefault(state, "未知状态"); // 返回状态描述，如果状态不存在则返回"未知状态"
    }

    /**
     * 返回指令的字符串表示形式，格式为"id,状态描述"。
     *
     * @return 指令的字符串表示形式
     */
    @Override
    public String toString() {
        return id + "," + getStateDescription();
    }
}
