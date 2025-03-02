VERSION 5.00
Begin VB.Form delete2 
   Caption         =   "删除教师授课信息"
   ClientHeight    =   2220
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   2865
   LinkTopic       =   "Form1"
   ScaleHeight     =   2220
   ScaleWidth      =   2865
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command2 
      Caption         =   "退出"
      Height          =   375
      Left            =   1560
      TabIndex        =   5
      Top             =   1560
      Width           =   975
   End
   Begin VB.TextBox t_Text 
      Height          =   375
      Left            =   960
      TabIndex        =   2
      Top             =   240
      Width           =   1680
   End
   Begin VB.TextBox c_Text 
      Height          =   375
      Left            =   960
      TabIndex        =   1
      Top             =   840
      Width           =   1680
   End
   Begin VB.CommandButton Command1 
      Caption         =   "删除"
      Height          =   375
      Left            =   240
      TabIndex        =   0
      Top             =   1560
      Width           =   975
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "课号"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   240
      Left            =   240
      TabIndex        =   4
      Top             =   900
      Width           =   480
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "教师号"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   240
      Left            =   240
      TabIndex        =   3
      Top             =   300
      Width           =   720
   End
End
Attribute VB_Name = "delete2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
  Dim cn As ADODB.Connection
  Dim strCnn As String, strSQL As String
  Dim tno As String, cno As String
    
  '**********获取记录学生学号，课程号
  tno = Trim(t_Text.Text)
  cno = Trim(c_Text.Text)
  '***********  使用 MS SQL Server OLD DB数据源连接
  strCnn = "Provider=SQLOLEDB;UID=sa; PWD=sa;Persist " + _
           "Security Info=false; Initial Catalog=jiaoxuedb"
  '*********** 创建连接对象cn
  Set cn = New ADODB.Connection
  cn.Open strCnn '********* 建立到数据源的物理连接
  '********** 给command对象添加要执行的SQL命令: 带参数的存储过程
  cn.Errors.Clear '清空错误对象
  On Error GoTo Error11
  strSQL = "delete from tc where tno='" + tno + "' and cno='" + cno + "'"
  cn.Execute strSQL, recordsaffected, adCmdText '**执行不返回行的execute方法
  If recordsaffected <> 0 Then
     MsgBox ("删除任课记录成功！")
  Else
     MsgBox ("删除任课记录失败！")
  End If
  cn.Close  '关闭连接对象cn
  Set cn = Nothing '释放cn对象
  Exit Sub
Error11:
  MsgBox ("删除任课记录失败！")
  cn.Close  '关闭连接对象cn
  Set cn = Nothing '释放cn对象
End Sub
Private Sub Command2_Click()
  Unload Me
End Sub
