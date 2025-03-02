import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class JobAndInstructionLoader {

    /**
     * 从文件中读取指令
     *
     * @param filePath 指令文件路径
     * @return 指令列表
     * @throws IOException 读取文件时发生的异常
     */
    public static List<Instruction> loadInstructions(String filePath) throws IOException {
        // 需要在这里实现读取指令文件的逻辑
        // 1. 使用 BufferedReader 来读取文件。
        // 2. 每读取一行后，按照逗号分隔获取指令的 ID 和状态。
        // 3. 使用这些信息创建一个新的 Instruction 对象，并将其添加到指令列表中。
        // 4. 最后返回指令列表。

        List<Instruction> instructions = new ArrayList<>();
        // 完成文件读取并填充 instructions 列表
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 2) {
                    int id = Integer.parseInt(parts[0]);
                    int status = Integer.parseInt(parts[1]);
                    Instruction instruction = new Instruction(id, status);
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
        // 需要在这里实现读取作业文件的逻辑

        // 1. 使用 BufferedReader 来读取文件。
        // 2. 每读取一行后，按照逗号分隔获取作业的 ID、到达时间和指令数量。
        // 3. 使用这些信息创建一个新的 Job 对象，并将其添加到作业列表中。
        // 4. 最后返回作业列表。

        List<Job> jobs = new ArrayList<>();
        // 完成文件读取并填充 jobs 列表
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 3) {
                    int id = Integer.parseInt(parts[0].trim());
                    int arrivalTime = Integer.parseInt(parts[1].trim());
                    int instructionCount = Integer.parseInt(parts[2].trim());
                    Job job = new Job(id, arrivalTime, instructionCount);
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
     * @return 包含所有作业的列表
     * @throws IOException 读取文件时发生的异常
     */
    public static List<Job> loadAllJobsAndInstructions(String jobsFilePath, String instructionsFolderPath) throws IOException {


        // 1. 首先调用 loadJobs() 方法读取作业信息。
        // 2. 对于每个作业，使用其 jobId 来构建指令文件的路径。
        // 3. 调用 loadInstructions() 方法读取每个作业的指令。
        // 4. 将每个作业的指令列表设置到相应的作业对象中。
        // 5. 打印每个作业和指令的加载信息。
        List<Job> jobs = loadJobs(jobsFilePath);
        for(Job job : jobs) {
            String instructionFilePath = instructionsFolderPath + job.getJobId() + ".txt";
            System.out.println();
            List<Instruction> instructions = loadInstructions(instructionFilePath);
        }
        return jobs;
        // 返回加载的所有作业列表
    }
}
