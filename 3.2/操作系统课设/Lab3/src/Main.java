import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        OSKernel.loader.LoadAllJobsAndInstructions();
        OSKernel.ui.setVisible(true);
    }
}
