import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class JobandInstructionLoader {

    /**
     * 从文件中读取指令
     *
     * @param filePath 指令文件路径
     * @return 指令列表
     * @throws IOException 读取文件时发生的异常
     */
    public static List<Instruction> loadInstructions(String filePath) throws IOException {
        List<Instruction> instructions = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 2) {
                    int id = Integer.parseInt(parts[0].trim());
                    int state = Integer.parseInt(parts[1].trim());
                    Instruction instruction = new Instruction(id, state);
                    instructions.add(instruction);
                }
            }
        }
        return instructions;
    }

    /**
     * 从作业请求文件中读取作业信息
     *
     * @param filePath 作业请求文件路径
     * @return 作业信息列表
     * @throws IOException 读取文件时发生的异常
     */
    public static List<Job> loadJobs(String filePath) throws IOException {
        List<Job> jobs = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 3) {
                    int jobId = Integer.parseInt(parts[0].trim());
                    int inTime = Integer.parseInt(parts[1].trim());
                    int instructionCount = Integer.parseInt(parts[2].trim());
                    Job job = new Job(jobId, inTime, instructionCount);
                    jobs.add(job);

                }
            }
        }
        return jobs;
    }


    /**
     * 封装的加载作业和指令的方法
     *
     * @param jobsFilePath           作业文件路径
     * @param instructionsFolderPath 指令文件夹路径
     * @return jobs 包含所有作业的列表
     * @throws IOException 读取文件时发生的异常
     */
    public static List<Job> loadAllJobsAndInstructions(String jobsFilePath, String instructionsFolderPath) throws IOException {
        // 读取作业信息
        List<Job> jobs = loadJobs(jobsFilePath);

        for (Job job : jobs) {
            // 读取每个作业的指令信息
            String instructionFilePath = instructionsFolderPath + job.getJobId() + ".txt";
            List<Instruction> instructions = loadInstructions(instructionFilePath);
            job.setInstructions(instructions);

            // 提示作业和指令加载成功
            System.out.println("作业 " + job.getJobId() + " 加载成功，到达时间: " + job.getInTime() + "，指令数量: " + job.getInstructionCount());
            for (Instruction instruction : instructions) {
                System.out.println("指令 " + instruction.getId() + " 加载成功，状态: " + instruction.getStateDescription());
            }
        }
        return jobs;
    }
}
