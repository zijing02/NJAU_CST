VERSION 5.00
Begin VB.Form query1 
   Caption         =   "查询张彬成绩"
   ClientHeight    =   2400
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   3705
   LinkTopic       =   "Form1"
   ScaleHeight     =   2400
   ScaleWidth      =   3705
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command1 
      Caption         =   "查询"
      Height          =   375
      Left            =   1320
      TabIndex        =   2
      Top             =   1680
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
      Left            =   600
      TabIndex        =   0
      Top             =   840
      Width           =   2415
   End
   Begin VB.Label Label1 
      Caption         =   "张彬的计算机基础成绩"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   600
      TabIndex        =   1
      Top             =   480
      Width           =   2415
   End
End
Attribute VB_Name = "query1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
  Dim cn As ADODB.Connection
  Dim rs As ADODB.Recordset
  Dim strCnn As String
  
  '*********** 设置ODBC OLE DB数据源连接串
  strCnn = " DRIVER={SQL SERVER};SERVER=MXM;UID=sa;PWD=sa;DATABASE=jiaoxuedb"
  '*********** 创建连接对象cn
  Set cn = New ADODB.Connection
  '********* 建立到数据源的物理连接
  cn.Open strCnn
  '********** 创建command对象cm
  Dim cm As New ADODB.Command
  cm.ActiveConnection = cn
  '********** 给command对象添加要执行的SQL命令
  cm.CommandText = "select score from student,sc,course where student.sno=sc.sno and " + _
        "sc.cno = course.cno and student.sname='张彬' and course.cname='计算机基础'"
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

