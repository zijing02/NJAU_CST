import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.SwingConstants;
import javax.swing.SwingUtilities;
import javax.swing.border.LineBorder;

public class UI extends JFrame {
    JPanel clockPanel = new JPanel(new GridLayout(2, 1));
    JTextArea clockContent = new JTextArea();
    JPanel jobRequestPanel = new JPanel();
    JTextArea jobRequestContent = new JTextArea(5, 20);
    JPanel blockPanel = new JPanel();
    JTextArea blockContent = new JTextArea(5, 20);
    JPanel inputBlockPanel = new JPanel(new BorderLayout());
    JTextArea inputBlockContent = new JTextArea();
    JPanel outputBlockPanel = new JPanel(new BorderLayout());
    JTextArea outputBlockContent = new JTextArea();
    JPanel memoryPanel = new JPanel(new GridLayout(4, 3));
    JPanel memoryGrid = new JPanel(new GridLayout(4, 3));
    JPanel bufferAPanel = new JPanel();
    JTextArea bufferAContent = new JTextArea(5, 20);
    JPanel bufferBPanel = new JPanel();
    JTextArea bufferBContent = new JTextArea(5, 20);
    JPanel readyProcessPanel = new JPanel();
    JTextArea readyProcessContent = new JTextArea(5, 20);
    JPanel runningProcessPanel = new JPanel();
    JTextArea runningProcessContent = new JTextArea(5, 20);
    public ArrayList<String> jobRequests = new ArrayList<>();

    public UI() {
        setTitle("操作系统仿真界面");
        setSize(1020, 820);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.fill = GridBagConstraints.BOTH;
        gbc.insets = new Insets(5, 5, 5, 5);
        // double base = 0.165;
        // 如果后续需要变成小数，将gbc.weightx=gbc.gridwidth;gbc.weighty=gbc.gridheight;全部*base

        // 时钟显示区
        clockPanel.setBorder(new LineBorder(Color.BLACK));
        clockPanel.setLayout(new BorderLayout());

        JLabel clockLabel = new JLabel("时钟显示区", SwingConstants.CENTER);
        clockPanel.add(clockLabel, BorderLayout.NORTH);
        clockContent.setFont(new Font(clockContent.getFont().getName(), Font.PLAIN, 20));
        clockContent.setEditable(false);
        clockPanel.add(clockContent, BorderLayout.CENTER);

        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.gridwidth = 2;
        gbc.gridheight = 1;
        gbc.weightx = gbc.gridwidth;
        gbc.weighty = gbc.gridheight;
        add(clockPanel, gbc);

        // 作业请求区
        jobRequestPanel.setBorder(new LineBorder(Color.BLACK));
        jobRequestPanel.setLayout(new BorderLayout());

        JLabel jobRequestLabel = new JLabel("作业请求区", SwingConstants.CENTER);
        jobRequestPanel.add(jobRequestLabel, BorderLayout.NORTH);
        // setLineWrap(true); //文字换行
        // setWrapStyleWord(true); //换行不断词
        jobRequestContent.setEditable(false);

        JScrollPane scrollPaneJobRequest = new JScrollPane(jobRequestContent);
        scrollPaneJobRequest.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        scrollPaneJobRequest.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        jobRequestPanel.add(scrollPaneJobRequest, BorderLayout.CENTER);

        gbc.gridx = 0;
        gbc.gridy = 1;
        gbc.gridwidth = 2;
        gbc.gridheight = 2;
        gbc.weightx = gbc.gridwidth;
        gbc.weighty = gbc.gridheight;
        add(jobRequestPanel, gbc);

        // 进程阻塞区
        blockPanel.setBorder(new LineBorder(Color.BLACK));
        blockPanel.setLayout(new BorderLayout());

        JLabel blockLabel = new JLabel("进程阻塞区", SwingConstants.CENTER);
        blockPanel.add(blockLabel, BorderLayout.NORTH);
        blockPanel.setBorder(new LineBorder(Color.BLACK));
        JPanel blockPanelCenter = new JPanel(new GridLayout(1, 2));
        blockPanelCenter.setBorder(new LineBorder(Color.BLACK));

        // 输入阻塞区
        inputBlockPanel.setBorder(new LineBorder(Color.BLACK));
        JLabel inputBlockLabel = new JLabel("输入阻塞区", SwingConstants.CENTER);
        inputBlockPanel.add(inputBlockLabel, BorderLayout.NORTH);
        inputBlockContent.setEditable(false);

        JScrollPane scrollPaneInputBlock = new JScrollPane(inputBlockContent);
        scrollPaneInputBlock.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        scrollPaneInputBlock.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        inputBlockPanel.add(scrollPaneInputBlock, BorderLayout.CENTER);

        // 输出阻塞区
        outputBlockPanel.setBorder(new LineBorder(Color.BLACK));
        JLabel outputBlockLabel = new JLabel("输出阻塞区", SwingConstants.CENTER);
        outputBlockPanel.add(outputBlockLabel, BorderLayout.NORTH);
        outputBlockContent.setEditable(false);

        JScrollPane scrollPaneOutputBlock = new JScrollPane(outputBlockContent);
        scrollPaneOutputBlock.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        scrollPaneOutputBlock.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        outputBlockPanel.add(scrollPaneOutputBlock, BorderLayout.CENTER);

        // // 将输入阻塞区和输出阻塞区添加到blockPanel
        blockPanelCenter.add(inputBlockPanel, BorderLayout.WEST);
        blockPanelCenter.add(outputBlockPanel, BorderLayout.EAST);
        blockPanel.add(blockPanelCenter, BorderLayout.CENTER);

        gbc.gridx = 0;
        gbc.gridy = 3;
        gbc.gridwidth = 2;
        gbc.gridheight = 3;
        gbc.weightx = gbc.gridwidth;
        gbc.weighty = gbc.gridheight;
        add(blockPanel, gbc);

        // 内存区
        memoryPanel.setBorder(new LineBorder(Color.BLACK));
        memoryPanel.setLayout(new BorderLayout());

        JLabel memoryLabel = new JLabel("内存显示区", SwingConstants.CENTER);
        memoryPanel.add(memoryLabel, BorderLayout.NORTH);
        // for (int i = 1; i <= 12; i++) {
        // JPanel blockPanelInMemory = new JPanel();
        // blockPanelInMemory.setBackground(Color.GREEN); // 初始颜色为绿色
        // memoryGrid.add(blockPanelInMemory);
        // blockPanelInMemory.setBorder(new LineBorder(Color.BLACK)); // 添加边框
        // if (i >= 11) {
        // continue;
        // }
        // blockPanelInMemory.add(new JLabel(String.valueOf(i)));
        // }
        JScrollPane scrollPaneMemory = new JScrollPane(memoryGrid);
        scrollPaneMemory.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        scrollPaneMemory.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        memoryPanel.add(scrollPaneMemory, BorderLayout.CENTER);

        gbc.gridx = 2;
        gbc.gridy = 0;
        gbc.gridwidth = 2;
        gbc.gridheight = 4;
        gbc.weightx = gbc.gridwidth;
        gbc.weighty = gbc.gridheight;
        add(memoryPanel, gbc);

        // 四个按钮
        JButton executeButton = new JButton("执行");

        gbc.gridx = 2;
        gbc.gridy = 4;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        gbc.weightx = gbc.gridwidth;
        gbc.weighty = gbc.gridheight;
        add(executeButton, gbc);

        JButton pauseButton = new JButton("暂停");

        gbc.gridx = 3;
        gbc.gridy = 4;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        gbc.weightx = gbc.gridwidth;
        gbc.weighty = gbc.gridheight;
        add(pauseButton, gbc);

        JButton timeButton = new JButton("实时");

        gbc.gridx = 2;
        gbc.gridy = 5;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        gbc.weightx = gbc.gridwidth;
        gbc.weighty = gbc.gridheight;
        add(timeButton, gbc);

        JButton saveButton = new JButton("保存");

        gbc.gridx = 3;
        gbc.gridy = 5;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        gbc.weightx = gbc.gridwidth;
        gbc.weighty = gbc.gridheight;
        add(saveButton, gbc);

        // 进程就绪区
        readyProcessPanel.setBorder(new LineBorder(Color.BLACK));
        readyProcessPanel.setLayout(new BorderLayout());

        JLabel readyProcessLabel = new JLabel("进程就绪区", SwingConstants.CENTER);
        readyProcessPanel.add(readyProcessLabel, BorderLayout.NORTH);
        readyProcessContent.setEditable(false);

        JScrollPane scrollPaneReadyProcess = new JScrollPane(readyProcessContent);
        scrollPaneReadyProcess.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        scrollPaneReadyProcess.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        readyProcessPanel.add(scrollPaneReadyProcess, BorderLayout.CENTER);

        gbc.gridx = 4;
        gbc.gridy = 0;
        gbc.gridwidth = 2;
        gbc.gridheight = 4;
        gbc.weightx = gbc.gridwidth;
        gbc.weighty = gbc.gridheight;
        add(readyProcessPanel, gbc);

        // 进程运行区
        runningProcessPanel.setBorder(new LineBorder(Color.BLACK));
        runningProcessPanel.setLayout(new BorderLayout());

        JLabel runningProcessLabel = new JLabel("进程运行区", SwingConstants.CENTER);
        runningProcessPanel.add(runningProcessLabel, BorderLayout.NORTH);
        runningProcessContent.setEditable(false);

        JScrollPane scrollPaneRunningProcess = new JScrollPane(runningProcessContent);
        scrollPaneRunningProcess.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        scrollPaneRunningProcess.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        runningProcessPanel.add(scrollPaneRunningProcess, BorderLayout.CENTER);

        gbc.gridx = 4;
        gbc.gridy = 4;
        gbc.gridwidth = 2;
        gbc.gridheight = 2;
        gbc.weightx = gbc.gridwidth;
        gbc.weighty = gbc.gridheight;
        add(runningProcessPanel, gbc);

        // 添加窗口监听器，窗口关闭直接保存
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                if (!OSKernel.loader.isSaved || !OSKernel.CheckEmpty()) {
                    OSKernel.loader.SaveResults(ClockInterruptHandlerThread.GetCurrentTime());
                }
                System.exit(0);
            }
        });

        // 四个按钮的功能
        executeButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (SyncManager.pauseFlag) {
                    SyncManager.pauseLock.lock();
                    try {
                        SyncManager.pauseFlag = false; // 恢复执行状态
                        SyncManager.pauseCondition.signalAll(); // 通知所有线程恢复执行
                        System.out.println("系统已恢复");
                    } finally {
                        SyncManager.pauseLock.unlock();
                    }
                } else if (!SyncManager.startFlag) {
                    try {
                        System.out.print("尝试启动");
                        ProcessSchedulingHandlerThread processSchedulingHandlerThread = new ProcessSchedulingHandlerThread(
                                OSKernel.ui);
                        InputBlockThread inputBlockThread = new InputBlockThread();
                        OutputBlockThread OutputBlockThread = new OutputBlockThread();
                        JobSchedulingHandlerThread jobSchedulingHandlerThread = new JobSchedulingHandlerThread(
                                OSKernel.ui);
                        ClockInterruptHandlerThread clockInterruptHandlerThread = new ClockInterruptHandlerThread(
                                OSKernel.ui);
                        processSchedulingHandlerThread.start();
                        jobSchedulingHandlerThread.start();
                        inputBlockThread.start();
                        OutputBlockThread.start();
                        Thread.sleep(1000);
                        clockInterruptHandlerThread.start();
                        System.out.print("启动成功");
                    } catch (InterruptedException e1) {
                        System.out.print("启动失败");
                        throw new RuntimeException(e1);
                    }
                    SyncManager.startFlag = true;
                }
            }
        });

        pauseButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                SyncManager.pauseLock.lock();
                try {
                    SyncManager.pauseFlag = true;
                    System.out.println("系统已暂停");
                } finally {
                    SyncManager.pauseLock.unlock();
                }
            }
        });

        timeButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    OSKernel.loader.AddJobToBackupQueue();
                } catch (Exception e1) {
                    System.out.println(ClockInterruptHandlerThread.GetCurrentTime() + " [随机添加作业失败]");
                    AddJobRequestMessage(ClockInterruptHandlerThread.GetCurrentTime() + " [随机添加作业失败]");
                }
            }
        });

        saveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (OSKernel.CheckEmpty())
                    OSKernel.loader.SaveResults(ClockInterruptHandlerThread.GetCurrentTime());
                else {
                    System.out.println(ClockInterruptHandlerThread.GetCurrentTime() + " [系统中还有作业没有做完]");
                    AddJobRequestMessage(ClockInterruptHandlerThread.GetCurrentTime() + " [系统中还有作业没有做完]");
                }
            }
        });
    }

    // 更新时间
    public void SetTime(int time) {
        SwingUtilities.invokeLater(() -> clockContent.setText("\n当前时间: \n" + time + "s"));
    }

    // 更新作业请求区
    public void AddJobRequestMessage(String message) {
        jobRequestContent.append(message + "\n");

    }

    public void AddJobRequestMessage() {
        for (String job : jobRequests) {
            jobRequestContent.append(job + "\n");
        }
    }

    public void AddJobRequest(String job) {
        jobRequests.add(job);
        AddJobRequestMessage();
    }

    // 更新进程阻塞区
    public void AddInBlockMessage(String message) {
        inputBlockContent.append(message + "\n");
    }

    public void AddOutBlockMessage(String message) {
        outputBlockContent.append(message + "\n");
    }

    public void UpdateMemoryStatus(ArrayList<MemoryBlock> memoryBlocks) {
        for (int i = 0; i < memoryBlocks.size(); i++) {
            MemoryBlock block = memoryBlocks.get(i);
            JPanel blockPanelInMemory;
            if (memoryGrid.getComponentCount() > i) {
                blockPanelInMemory = (JPanel) memoryGrid.getComponent(i);
            } else {
                blockPanelInMemory = new JPanel();
                memoryGrid.add(blockPanelInMemory);
            }
            if (block.IsTakenUp()) {
                blockPanelInMemory.setBackground(Color.RED);
            } else {
                blockPanelInMemory.setBackground(Color.GREEN);
            }
            blockPanelInMemory.removeAll();
            blockPanelInMemory.add(new JLabel(String.valueOf(block.GetBlockID() + 1)));
        }
        memoryPanel.revalidate();
        memoryPanel.repaint();
    }

    // 更新进程就绪区
    public void AddReadyProcessMessage(String message) {
        readyProcessContent.append(message + "\n");
    }

    // 更新进程运行区
    public void AddRunningProcessMessage(String message) {
        runningProcessContent.append(message + "\n");
    }

    // 显示界面
    public void createAndShowGUI() {
        setVisible(true);
    }
}
