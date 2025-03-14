import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        try{
            OSKernel.loader.LoadAllJobsAndInstructions();
        }catch (IOException e) {
            System.out.println("作业加载失败，请检查！");
            throw new RuntimeException(e);
        }
        
        OSKernel.ui.setVisible(true);
    }
}
