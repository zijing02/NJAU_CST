# 此项目为2022级计算机科学与技术*jhy*教授的操作系统课程设计最终提交项目
为实现操作系统仿真程序，共设计18个大类，如下图所示，图中箭头表示箭头目的类被箭头源头类使用（如遇交叉线，以直线不转向为准），其中由于OSKernel、PCB类被所有其他类使用，遂未画使用箭头，特在此说明。对于此18个类，可以简要按一下类别分类：线程控制类、CPU核心类、作业加载及显示类、内存类。

## 线程控制类：包含ClockInterruptHandlerThread、InputBlockThread、JobSchedulingHandlerThread、OutputBlockThread、ProcessSchedulingHandlerThread、SyncManager类。
&emsp;&emsp;在系统中，为了保证各个线程之间的同步关系，必须保证其他线程先拿到锁，之后释放锁并等待时钟线程拿到所有的锁对时间进行操作后唤醒所有的线程，未确保其他线程在ClockInterruptHandlerThread线程之前拿到锁，在SyncManager中设计了四把锁，这三把锁分别为进程调度锁、作业调度锁、输入操作锁、输出操作锁，每一把锁都有两个条件变量。对于每一个线程还额外设计了一个标志变量，标志是否在时钟之前拿到锁，8个条件变量配合四个标志变量可大概率降低死锁的出现并保证系统的正常运行。此外，还有一把暂停锁，仅含有一个条件变量，可实现系统暂停功能。
&emsp;&emsp;在ClockInterruptHandlerThread类中，包含了当前系统的时间simulationTime以及对时间的操作函数SimulateTimePassing()，同时可以通过设置milliseconds以控制系统的运行速度.
&emsp;&emsp;在InputBlockThread、OutputBlockThread类中模拟实现系统输入输出的操作，为了实现处理输入需要两秒，输出需要三秒，在线程内部分别设计了inTime和outTIme来记录进程进入阻塞的时间，由ALL_IO函数判断时间是否达到。在线程内部还实现了重回就绪队列的函数。
&emsp;&emsp;在JobSchedulingHandlerThread类中，定义了JobRequest()实现了从后备作业队列中每隔两秒读取一次的逻辑。
&emsp;&emsp;在ProcessSchedulingHandlerThread类中，主要实现了三级反馈就绪队列的算法逻辑，实现线程的调度，包括进入就绪队列MFQ3()，进入等待队列CheckWaitQueue()，进程降级到低级就绪队列ChangeToLowGrade()，释放资源FinishPCB()等函数。

## 线程控制类：CPU核心类：包含OSKernel、CPU两个类。
&emsp;&emsp;OSKernel中包含了系统使用的所有变量如就绪队列、等待队列、阻塞队列、文件加载器等，还定义了一个检查空的函数CheckEmpty()，检测系统是否空闲。
&emsp;&emsp;CPU类中包含了pc程序计数器、ir指令寄存器，pswCPU状态，定义了runProcess()函数可根据当前正要执行的指令的状态将其所在的进程pcb加入到相应的队列中，还定义了CPU_PRO()和CPU_REC()用于实现CPU中断的现场保护和恢复。

## 线程控制类：外部类：包含Main、UI、Job、Instruction、JobAndInstructionLoader、PCB六个类。
&emsp;&emsp;JobAndInstructionLoader中包含了从外部加载作业、指令LoadAllJobsAndInstructions()，实时创建指令CreateInstructions()，保存日志到指定文件夹SaveResults()的函数等。
&emsp;&emsp;Job、Instruction、PCB则为JobAndInstructionLoader以及其他类提供基础的作业指令、进程信息，如作业ID，指令类型等。其中，PCB类继承自Job类，同时增加了有关于进程的独有信息如时间片、物理地址、进程状态等，还可通过PCB中的函数获取当前pcb中含有的指令及指令状态、指令所需要的空间等。
UI是此次系统仿真的可视化界面，将所有的信息输出到屏幕中。

## 线程控制类：内存类：包含Memory、MemoryBlock、MMU、Device四个类
&emsp;&emsp;MemoryBlock、MMU、Device为内存块的信息以及外部设备信息，供Memory调用。
&emsp;&emsp;在Memory类中，为了实现最佳分区算法，定义并维护一个二维的HashMap，将空闲块起始地址与从这个地址开始的连续块个数相联系，在AllocateMemory()中只需对此进行查找即可找到是否有一个适合的块去分配。同时在Memory中还定义了ReleaseMemory()方法，用于在进程结束是释放内存以及外部设备。


