import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) {

        //此部分为第一次实验完成内容，功能为系统启动前预先加载作业
        String jobsFilePath = "input/jobs-input.txt";
        String instructionsFolderPath = "input/";

        try {
            // 调用加载作业和指令的封装方法，并获取返回的作业列表
            List<Job> jobs = JobandInstructionLoader.loadAllJobsAndInstructions(jobsFilePath, instructionsFolderPath);

            System.out.println("\n所有作业加载完成：");
            for (Job job : jobs) {
                System.out.println("作业ID: " + job.getJobId() + ", 到达时间: " + job.getInTime() + ", 指令数量: " + job.getInstructionCount());
            }
        } catch (IOException e) {
            System.err.println("加载作业和指令时出错: " + e.getMessage());
            e.printStackTrace();
        }


        // 此部分为第二次实验，时钟线程和调度线程的依次执行
        Thread processSchedulingHandlerThread = new ProcessSchedulingHandlerThread();
        processSchedulingHandlerThread.start();

        // 确保时钟中断线程和作业请求线程启动后再启动进程调度线程
        try {
            Thread.sleep(100); // 确保前两个线程有时间启动
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // 启动时钟中断线程
        Thread clockInterruptHandlerThread = new ClockInterruptHandlerThread();
        clockInterruptHandlerThread.start();
    }
}
