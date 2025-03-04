 .text
#################################################################################
#本程序实现（字节地址0x200，字地址0x80）开始的8个字单元的降序排序,此程序可在mars mips仿真器中运行,运行时请将Mars Setting中的Memory Configuration设置为Compact，data at address 0
#中断服务程序1将字地址0x88开始的8个字数据累加1
#中断服务程序2将字地址0x90开始的8个字数据累加2
##################################################################################
 .text
sort_init:
 addi $sp,$sp,1024  #$sp init
 addi $s0,$0,-1
 addi $s1,$0,0
 sw $s0,512($s1)
 addi $s0,$s0,1
 addi $s1,$s1,4
 sw $s0,512($s1)
 addi $s0,$s0,1
 addi $s1,$s1,4
 sw $s0,512($s1)
 addi $s0,$s0,1
 addi $s1,$s1,4
 sw $s0,512($s1)
 addi $s0,$s0,1
 addi $s1,$s1,4
 sw $s0,512($s1)
 addi $s0,$s0,1
 addi $s1,$s1,4
 sw $s0,512($s1)
 addi $s0,$s0,1
 addi $s1,$s1,4
 sw $s0,512($s1)
 addi $s0,$s0,1
 addi $s1,$s1,4
 sw $s0,512($s1)
 
 add $s0,$zero,0   
 addi $s1,$zero,28   #排序区间
sort_loop:
 lw $s3,512($s0)     
 lw $s4,512($s1)
 slt $t0,$s3,$s4
 beq $t0,$0,sort_next   #降序排序
 sw $s3, 512($s1)
 sw $s4, 512($s0)   
sort_next:
 addi $s1, $s1, -4   
 beq $s0, $s1,  sort_next1  
 beq $0,$0,sort_loop
sort_next1:
 addi $s0,$s0,4
 addi $s1,$zero,28
 beq $s0, $s1, ProgramEnd
 beq $0,$0,sort_loop
ProgramEnd:
 beq $0,$0,ProgramEnd  #死循环
  
IntProgram1:
  addi $sp,$sp,8    #push registers  需要保留哪些寄存器？ 中断程序用到的寄存器
  sw $s0,0($sp)
  sw $s1,4($sp)

  addi $s1,$0,0x240
  lw $s0,($s1)
  addi $s0,$s0,1
  sw $s0,($s1)
  sw $s0,4($s1)
  sw $s0,8($s1)
  sw $s0,12($s1)
  sw $s0,16($s1)
  sw $s0,20($s1)
  sw $s0,24($s1)
  sw $s0,28($s1)
  lw $s1,4($sp)   #pop registers
  lw $s0,0($sp)
  addi $sp,$sp,-8
  eret
IntProgram2:
  addi $sp,$sp,8    #push registers  需要保留哪些寄存器？ 中断程序用到的寄存器
  sw $s0,0($sp)
  sw $s1,4($sp)

  addi $s1,$0,0x280
  lw $s0,($s1)
  addi $s0,$s0,-1
  sw $s0,($s1)
  sw $s0,4($s1)
  sw $s0,8($s1)
  sw $s0,12($s1)
  sw $s0,16($s1)
  sw $s0,20($s1)
  sw $s0,24($s1)
  sw $s0,28($s1)
  
  lw $s1,4($sp)   #pop registers
  lw $s0,0($sp)
  addi $sp,$sp,-8
  eret

