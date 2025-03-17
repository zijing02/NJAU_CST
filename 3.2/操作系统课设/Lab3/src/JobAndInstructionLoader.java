import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import javax.swing.SwingUtilities;

public class JobAndInstructionLoader {
    // 疑问main中调用的原因，方便调用，其实在函数内部可以直接访问input2/文件，以防后续转C/A先这样写外面
    public String inPath = "input2/";
    public List<String> saveList = new ArrayList<>();
    public boolean isSaved = false;
    public String outPath = "output/";
    public int maxJobId = 0; // 当前已经加载作业的数量

    // 指令加载
    public ArrayList<Instruction> LoadInstructions(String filePath) throws IOException {
        ArrayList<Instruction> instructions = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 2) {
                    int id = Integer.parseInt(parts[0].trim());
                    int state = Integer.parseInt(parts[1].trim());
                    instructions.add(new Instruction(id, state));
                }
            }
        } catch (IOException e) {
            System.out.println("指令文件不存在");
            e.printStackTrace();
        }
        return instructions;
    }

    // 作业加载
    public List<Job> LoadJobs(String filePath) throws IOException {
        List<Job> jobs = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 5) {
                    int jobId = Integer.parseInt(parts[0].trim());
                    int inTime = Integer.parseInt(parts[1].trim());
                    int priority = Integer.parseInt(parts[2].trim());
                    int needA = Integer.parseInt(parts[3].trim());
                    int needB = Integer.parseInt(parts[4].trim());
                    Job job = new Job(jobId, inTime, priority, needA, needB);
                    jobs.add(job);
                }
            }
        } catch (IOException e) {
            System.out.println("作业请求文件不存在");
            e.printStackTrace();
        }
        return jobs;
    }

    // 指令以及作业路径，同时调用作业加载方法、指令加载方法
    public List<Job> LoadAllJobsAndInstructions() throws IOException {
        // 读取作业信息
        String jobsFilePath = inPath + "jobs-input.txt";
        List<Job> jobs = LoadJobs(jobsFilePath);

        for (Job job : jobs) {
            // 读取每个作业的指令信息
            String instructionFilePath = inPath + job.GetJobId() + ".txt";
            ArrayList<Instruction> instructions = LoadInstructions(instructionFilePath);
            // 将与作业关联的指令列表设置到作业对象中
            job.SetInstructions(instructions);
            job.SetInstructionCount(instructions.size());
            // 将作业加入后备队列
            OSKernel.jobQueue.add(job);
            maxJobId++;
            // 提示作业和指令加载成功
            System.out.println(
                    "作业 " + job.GetJobId() + " 加载成功，到达时间: " + job.GetInTime() + "，指令数量: " + job.GetInstructionCount());
        }
        System.out.println("\n所有作业加载完成：");

        return jobs;
    }

    // 三种指令(0，1，2)的条数分别为15，3，2，顺序自行设计，此处集中生成，如果是要随机生成，可使用概率代替
    // 同时由于是固定20条指令，就不需要在其函数参数中加参数，也不需要重载此方法
    // 若要求更新为指令数量指令，
    public ArrayList<Instruction> CreateInstructions() {
        int instructionCount = 20;
        ArrayList<Instruction> instructions = new ArrayList<>();
        double[] probabilities = { 15, 18, 20 };
        for (int i = 1; i <= instructionCount; i++) {
            int state = 0;
            for (int j = 0; j < probabilities.length; j++) {
                if (i < probabilities[j]) {
                    state = j;
                    break;
                }
            }
            // System.out.print(i + String.valueOf(state));
            instructions.add(new Instruction(i, state));
        }
        return instructions;
    }

    // 创建instructions之后，将相应的job加入到作业后备队列
    public void AddJobToBackupQueue() {
        int jobId = ++maxJobId;
        Job job = new Job(jobId, ClockInterruptHandlerThread.simulationTime, 20, CreateInstructions());
        OSKernel.jobQueue.add(job);
    }

    // 检查是否阻塞
    // 如果不在，为其创建一个新的列表
    // 如果在，添加唤醒时间
    public void CheckInputBlock(int pid, String mess) {
        if (!OSKernel.inBlock.containsKey(pid)) {
            OSKernel.inBlock.put(pid, new ArrayList<>());
        }
        OSKernel.inBlock.get(pid).add(mess);
    }

    public void CheckOutputBlock(int pid, String mess) {
        if (!OSKernel.outBlock.containsKey(pid)) {
            OSKernel.outBlock.put(pid, new ArrayList<>());
        }
        OSKernel.outBlock.get(pid).add(mess);
    }

    // 输出阻塞队列信息，两种阻塞,键盘输入、屏幕输出
    public void PrintBlockInfo() {
        // 输出键盘输入阻塞线程信息
        for (Map.Entry<Integer, List<String>> entry : OSKernel.inBlock.entrySet()) {
            // 此处使用StringBuilder来拼接字符串，避免频繁创建String对象，但好像也没啥用，其他地方都用的String
            // 此时使用StringBuilder主要是因为String不可变
            // 因为String对象是不可变的，每次拼接都会创建一个新的String对象，会消耗大量内存
            StringBuilder message = new StringBuilder();
            message.append("进程 ID：" + entry.getKey() + "/");
            for (String str : entry.getValue()) {
                message.append(str);
                message.append(",");
            }
            String mes = "BB1:[阻塞队列 1,键盘输入:" + message + "]";
            AddMessageToSaveList(mes);
            OSKernel.ui.AddInBlockMessage(mes);
        }

        // 输出屏幕输出阻塞线程信息
        for (Map.Entry<Integer, List<String>> entry : OSKernel.outBlock.entrySet()) {
            StringBuilder message = new StringBuilder();
            message.append("进程 ID：" + entry.getKey() + "/");
            for (String str : entry.getValue()) {
                message.append(str);
                message.append(",");
            }
            String mes = "BB2:[阻塞队列 2,屏幕显示:" + message + "]";
            AddMessageToSaveList(mes);
            OSKernel.ui.AddOutBlockMessage(mes);
        }
    }

    // 保存输出信息功能
    // 先将所有信息收集，之后集中向文件中写入
    public void AddMessageToSaveList(String message) {
        saveList.add(message);
    }

    public void SaveResults(int runTime) {
        String filePath = outPath + "/ProcessResults-" + runTime + "-DJFK.txt";
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
            for (String info : saveList) {
                writer.write(info);
                writer.newLine();
            }
            isSaved = true;
            // 直接写和用SwingUtilities的区别：
            // 如果方法涉及到更新 Swing 组件（例如在 UI 上显示消息），使用SwingUtilities好一点，但区别好像也不大
            SwingUtilities.invokeLater(() -> OSKernel.ui.AddJobRequestMessage("日志保存到文件: " + filePath));
        } catch (IOException e) {
            System.out.println("文件保存失败");
            e.printStackTrace();
        }
    }

    // 重新进入就绪队列，显示就绪队列中的指令
    public void PrintBackToReadyQueue(int time) {
        // 一级就绪队列
        // 后续有时间可以把这个输出显示做一个函数，每一次都占用三行太费事了
        System.out.println("     [一级就绪队列进程ID列表         剩余指令数]");
        SwingUtilities.invokeLater(() -> OSKernel.ui.AddReady1ProcessMessage("       [一级就绪队列进程ID列表         剩余指令数]"));
        AddMessageToSaveList("       [一级就绪队列进程ID列表         剩余指令数]");
        // 遍历每一个就绪队列，将其中的内容进行处理
        if (!OSKernel.readyQueue1.isEmpty()) {
            System.out.printf("%d [重新进入就绪队列1:]\n", time);
            SwingUtilities.invokeLater(() -> OSKernel.ui.AddReady1ProcessMessage(time + " [重新进入就绪队列1:]"));
            AddMessageToSaveList(time + " [重新进入就绪队列1:]");
            for (PCB pcb : OSKernel.readyQueue1) {
                System.out.printf("     [%-30d %-17d]\n", pcb.GetPid(), (pcb.GetInstructionCount() - pcb.GetPc()));
                SwingUtilities.invokeLater(() -> OSKernel.ui.AddReady1ProcessMessage(
                        "       [" + pcb.GetPid() + "                                                  "
                                + (pcb.GetInstructionCount() - pcb.GetPc()) + "]"));
                AddMessageToSaveList("       [" + pcb.GetPid() + "                                                  "
                        + (pcb.GetInstructionCount() - pcb.GetPc()) + "]");
            }
        } else {
            System.out.printf("     [无进程                          无指令]\n");
            SwingUtilities.invokeLater(
                    () -> OSKernel.ui.AddReady1ProcessMessage("       [无进程                                     无指令]"));
            AddMessageToSaveList("       [无进程                                           无指令]");
        }
        // 二级就绪队列
        System.out.printf("     [二级就绪队列进程ID列表         剩余指令数]\n");
        SwingUtilities.invokeLater(() -> OSKernel.ui.AddReady2ProcessMessage("       [二级就绪队列进程ID列表         剩余指令数]"));
        AddMessageToSaveList("       [二级就绪队列进程ID列表         剩余指令数]");
        if (!OSKernel.readyQueue2.isEmpty()) {
            System.out.printf("%d [重新进入就绪队列2:]\n", time);
            SwingUtilities.invokeLater(() -> OSKernel.ui.AddReady2ProcessMessage(time + " [重新进入就绪队列2:]"));
            AddMessageToSaveList(time + " [重新进入就绪队列2:]");
            for (PCB pcb : OSKernel.readyQueue2) {
                System.out.printf("     [%-30d %-17d]\n", pcb.GetPid(), (pcb.GetInstructionCount() - pcb.GetPc()));
                SwingUtilities.invokeLater(() -> OSKernel.ui.AddReady2ProcessMessage(
                        "       [" + pcb.GetPid() + "                                                  "
                                + (pcb.GetInstructionCount() - pcb.GetPc()) + "]"));
                AddMessageToSaveList("       [" + pcb.GetPid() + "                                                  "
                        + (pcb.GetInstructionCount() - pcb.GetPc()) + "]");
            }
        } else {
            System.out.printf("     [无进程                          无指令]\n");
            SwingUtilities.invokeLater(
                    () -> OSKernel.ui.AddReady2ProcessMessage("       [无进程                                     无指令]"));
            AddMessageToSaveList("       [无进程                                           无指令]");
        }
        // 三级就绪队列
        System.out.printf("     [三级就绪队列进程ID列表         剩余指令数]\n");
        SwingUtilities.invokeLater(() -> OSKernel.ui.AddReady3ProcessMessage("       [三级就绪队列进程ID列表         剩余指令数]"));
        AddMessageToSaveList("      [三级就绪队列进程ID列表         剩余指令数]");
        if (!OSKernel.readyQueue3.isEmpty()) {
            System.out.printf("%d [重新进入就绪队列3:]\n", time);
            SwingUtilities.invokeLater(() -> OSKernel.ui.AddReady3ProcessMessage(time + " [重新进入就绪队列3:]"));
            AddMessageToSaveList(time + " [重新进入就绪队列3:]");
            for (PCB pcb : OSKernel.readyQueue3) {
                System.out.printf("     [%-30d %-17d]\n", pcb.GetPid(), (pcb.GetInstructionCount() - pcb.GetPc()));
                SwingUtilities.invokeLater(() -> OSKernel.ui.AddReady3ProcessMessage(
                        "       [" + pcb.GetPid() + "                                                 "
                                + (pcb.GetInstructionCount() - pcb.GetPc()) + "]"));
                AddMessageToSaveList("       [" + pcb.GetPid() + "                                                  "
                        + (pcb.GetInstructionCount() - pcb.GetPc()) + "]");
            }
        } else {
            System.out.printf("     [无进程                          无指令]\n");
            SwingUtilities.invokeLater(
                    () -> OSKernel.ui.AddReady3ProcessMessage("       [无进程                                     无指令]"));
            AddMessageToSaveList("       [无进程                                           无指令]");
        }
    }

    // 将阻塞队列中的阻塞信息输出
    public void AddInfoToBlockQueue(int time) {
        System.out.printf("%d [阻塞进程:输入阻塞队列:]\n", time);
        SwingUtilities.invokeLater(() -> OSKernel.ui.AddInBlockMessage(time + " [阻塞进程:输入阻塞队列:]"));
        AddMessageToSaveList(time + " [阻塞进程:输入阻塞队列:]");
        System.out.println("     [进程ID列表]");
        SwingUtilities.invokeLater(() -> OSKernel.ui.AddInBlockMessage("       [进程ID列表]"));
        AddMessageToSaveList("       [进程ID列表]");
        if (!OSKernel.inBlockQueue.isEmpty()) {
            for (PCB pcb : OSKernel.inBlockQueue) {
                System.out.println("        [" + pcb.GetPid() + "]");
                SwingUtilities.invokeLater(() -> OSKernel.ui.AddInBlockMessage("        [" + pcb.GetPid() + "]"));
                AddMessageToSaveList("          [" + pcb.GetPid() + "]");
            }
        } else {
            System.out.println("     [无进程]");
            SwingUtilities.invokeLater(() -> OSKernel.ui.AddInBlockMessage("       [无进程]"));
            AddMessageToSaveList("       [无进程]");
        }
        System.out.printf("%d [阻塞进程:输出阻塞队列:]\n", time);
        SwingUtilities.invokeLater(() -> OSKernel.ui.AddOutBlockMessage(time + " [阻塞进程:输出阻塞队列:]"));
        AddMessageToSaveList(time + " [阻塞进程:输出阻塞队列:]");
        System.out.println("     [进程ID列表]");
        SwingUtilities.invokeLater(() -> OSKernel.ui.AddOutBlockMessage("       [进程ID列表]"));
        AddMessageToSaveList("       [进程ID列表]");
        if (!OSKernel.outBlockQueue.isEmpty()) {
            for (PCB pcb : OSKernel.outBlockQueue) {
                System.out.println("        [" + pcb.GetPid() + "]");
                SwingUtilities.invokeLater(() -> OSKernel.ui.AddOutBlockMessage("          [" + pcb.GetPid() + "]"));
                AddMessageToSaveList("          [" + pcb.GetPid() + "]");
            }
        } else {
            System.out.println("     [无进程]");
            SwingUtilities.invokeLater(() -> OSKernel.ui.AddOutBlockMessage("       [无进程]"));
            AddMessageToSaveList("       [无进程]");
        }
        System.out.flush();
    }
}
