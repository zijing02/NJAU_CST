import java.io.*;
import java.util.*;


/**
 *  程序入口
 */
public class Main {
    public static void main(String[] args) {
        String jobsFilePath = "input/jobs-input.txt";
        String instructionsFolderPath = "input/";

        try {
            // 调用加载作业和指令的封装方法，并获取返回的作业列表
            List<Job> jobs = JobAndInstructionLoader.loadAllJobsAndInstructions(jobsFilePath, instructionsFolderPath);

            System.out.println("\n所有作业加载完成：");
            for (Job job : jobs) {
                System.out.println("作业ID: " + job.getJobId() + ", 到达时间: " + job.getInTime() + ", 指令数量: " + job.getInstructionCount());
            }
        } catch (IOException e) {
            System.err.println("加载作业和指令时出错: " + e.getMessage());
            e.printStackTrace();
        }
        Scanner scan = new Scanner(System.in);
        System.out.println("等待接收结束：");
        String str1 = scan.next();
        System.out.println("程序结束");
    }
}
