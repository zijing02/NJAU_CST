VERSION 5.00
Begin VB.Form query3 
   Caption         =   "查询教师张雪所任课程"
   ClientHeight    =   2805
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   3705
   LinkTopic       =   "Form1"
   ScaleHeight     =   2805
   ScaleWidth      =   3705
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command2 
      Caption         =   "退出"
      Height          =   375
      Left            =   2280
      TabIndex        =   3
      Top             =   2160
      Width           =   975
   End
   Begin VB.ListBox List1 
      Height          =   1140
      Left            =   600
      TabIndex        =   2
      Top             =   720
      Width           =   2415
   End
   Begin VB.CommandButton Command1 
      Caption         =   "查询"
      Height          =   375
      Left            =   360
      TabIndex        =   1
      Top             =   2160
      Width           =   975
   End
   Begin VB.Label Label1 
      Caption         =   "教师张雪所任课程"
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
      Left            =   840
      TabIndex        =   0
      Top             =   360
      Width           =   2175
   End
End
Attribute VB_Name = "query3"
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
  '********** 设置查询SQL命令串
  strSQL = "select cname from tc,teacher,course where teacher.tno=tc.tno and " + _
        "tc.cno=course.cno and teacher.tname='张雪'"
  '********** 创建recordset对象
  Set rs = New ADODB.Recordset
  rs.CursorType = adOpenStatic '设置游标类型为静态
  rs.CursorLocation = adUseClient '设置游标位置在客户端
  Set rs = cn.Execute(strSQL) '在连接对象cn上执行SQL命令strSQL，返回的记录集赋给rs
  Do While rs.EOF = False '判断指针是否指向结束
     List1.AddItem rs!cname  '从rs对象中取出课程名并放入列表框中显示出来
     rs.MoveNext '记录指针下移一个记录
  Loop
  Set rs = Nothing   '释放recordset对象
  cn.Close  '关闭连接对象cn
  Set cn = Nothing '释放connection对象
End Sub

Private Sub Command2_Click()
  Unload Me
End Sub
