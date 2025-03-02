VERSION 5.00
Begin VB.Form query2 
   Caption         =   "查询学生成绩"
   ClientHeight    =   3000
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4530
   LinkTopic       =   "Form1"
   ScaleHeight     =   3000
   ScaleWidth      =   4530
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command2 
      Caption         =   "结束"
      Height          =   375
      Left            =   2880
      TabIndex        =   7
      Top             =   2280
      Width           =   975
   End
   Begin VB.TextBox s_Text 
      Height          =   375
      Left            =   1560
      TabIndex        =   4
      Top             =   360
      Width           =   2295
   End
   Begin VB.TextBox c_Text 
      Height          =   375
      Left            =   1560
      TabIndex        =   3
      Top             =   960
      Width           =   2295
   End
   Begin VB.CommandButton Command1 
      Caption         =   "查询"
      Height          =   375
      Left            =   840
      TabIndex        =   2
      Top             =   2280
      Width           =   975
   End
   Begin VB.TextBox score_Text 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   14.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   405
      Left            =   1560
      TabIndex        =   0
      Top             =   1560
      Width           =   2295
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "课程名"
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
      Left            =   720
      TabIndex        =   6
      Top             =   1080
      Width           =   720
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "学生姓名"
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
      Left            =   480
      TabIndex        =   5
      Top             =   420
      Width           =   960
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "成绩"
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
      Left            =   960
      TabIndex        =   1
      Top             =   1680
      Width           =   480
   End
End
Attribute VB_Name = "query2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
  Dim cn As ADODB.Connection
  Dim rs As ADODB.Recordset
  Dim strCnn As String
  Dim sname As String, cname As String
  
  '**********获取学生姓名，课程名
  sname = Trim(s_Text.Text)
  cname = Trim(c_Text.Text)
  '*********** 设置ODBC OLE DB数据源连接串
  strCnn = " DRIVER={SQL SERVER};SERVER=zhangbenshan;UID=sa;PWD=sa;DATABASE=jiaoxuedb"
  '*********** 创建连接对象cn
  Set cn = New ADODB.Connection
  '********* 建立到数据源的物理连接
  cn.Open strCnn
  '********** 创建command对象cm
  Dim cm As New ADODB.Command
  cm.ActiveConnection = cn
  '********** 给command对象添加要执行的 带参数 的SQL命令
  cm.CommandText = "select score from student,sc,course where student.sno=sc.sno and " + _
    "sc.cno = course.cno and student.sname='" + sname + "' and course.cname='" + cname + "'"
  '********** 给command对象要执行的SQL命令的类型：SQL文本
  cm.CommandType = adCmdText
  cm.CommandTimeout = 15
  '********** 执行command命令
  Set rs = cm.Execute(1, 1, 1)
  If rs.EOF = False Then  '******若返回的记录不为空
     score_Text.Text = Str(rs!score) '从rs对象中取出成绩值并放入文本框中显示出来
  End If
  Set rs = Nothing   '释放rs对象
  cn.Close  '关闭连接对象cn
  Set cn = Nothing '释放cn对象
End Sub

Private Sub Command2_Click()
  Unload Me
End Sub
