VERSION 5.00
Begin VB.Form main_Form 
   Caption         =   "数据库更新操作"
   ClientHeight    =   4350
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7665
   LinkTopic       =   "Form1"
   ScaleHeight     =   4350
   ScaleWidth      =   7665
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command4 
      Caption         =   "退出"
      Height          =   495
      Left            =   5760
      TabIndex        =   3
      Top             =   3480
      Width           =   1215
   End
   Begin VB.CommandButton Command3 
      Caption         =   "删除课程记录"
      Height          =   495
      Left            =   1920
      TabIndex        =   2
      Top             =   2520
      Width           =   2895
   End
   Begin VB.CommandButton Command2 
      Caption         =   "修改学生成绩"
      Height          =   495
      Left            =   1920
      TabIndex        =   1
      Top             =   1560
      Width           =   2895
   End
   Begin VB.CommandButton Command1 
      Caption         =   "插入学生成绩记录"
      Height          =   495
      Left            =   1920
      TabIndex        =   0
      Top             =   720
      Width           =   2775
   End
End
Attribute VB_Name = "main_Form"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
  Load insert1
End Sub

Private Sub Command2_Click()
  Load update1
End Sub


Private Sub Command3_Click()

  Load delete1
End Sub

Private Sub Command4_Click()
  Unload Me
End Sub
