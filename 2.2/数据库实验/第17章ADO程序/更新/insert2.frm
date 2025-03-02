VERSION 5.00
Begin VB.Form insert2 
   Caption         =   "插入教师任课信息"
   ClientHeight    =   2055
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   3270
   LinkTopic       =   "Form1"
   ScaleHeight     =   2055
   ScaleWidth      =   3270
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command2 
      Caption         =   "退出"
      Height          =   375
      Left            =   1800
      TabIndex        =   5
      Top             =   1560
      Width           =   975
   End
   Begin VB.TextBox t_Text 
      Height          =   375
      Left            =   1080
      TabIndex        =   2
      Top             =   240
      Width           =   1800
   End
   Begin VB.TextBox c_Text 
      Height          =   375
      Left            =   1080
      TabIndex        =   1
      Top             =   840
      Width           =   1800
   End
   Begin VB.CommandButton Command1 
      Caption         =   "入库"
      Height          =   375
      Left            =   480
      TabIndex        =   0
      Top             =   1560
      Width           =   975
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "课程号"
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
      Top             =   960
      Width           =   720
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
      Width           =   960
   End
End
Attribute VB_Name = "insert2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
  Dim cn As ADODB.Connection
  Dim strCnn As String, strSQL As String
  Dim tno As String, cno As String
  Dim id
  '**********获取待插入记录的教师号和课程号
  tno = Trim(t_Text.Text)
  cno = Trim(c_Text.Text)
  '*********** 设置ODBC OLE DB数据源连接串
  strCnn = " DRIVER={SQL SERVER};SERVER=MXM;UID=sa;PWD=sa;DATABASE=jiaoxuedb"
  '*********** 创建连接对象cn
  Set cn = New ADODB.Connection
  '********* 建立到数据源的物理连接
  cn.Open strCnn
  '********** 设置查询SQL命令串：带参数t_name
  strSQL = "select * from Tc"
  '********** 创建recordset对象
  Set rs = New ADODB.Recordset
  rs.CursorType = adOpenDynamic '设置游标类型为动态
  rs.CursorLocation = adUseClient '设置游标位置在客户端
  rs.LockType = adOpenDynamic
  cn.Errors.Clear '清空错误对象
  On Error GoTo Error11  '若发生错误则转到语句：Error11
  rs.Open strSQL, cn, , , adCmdText
  rs.AddNew '在rs对象中插入一新行
  rs!tno = tno '给新行增加一个字段tno
  rs!cno = cno '给新行再增加一个字段cno
  rs.Update '********** 提交对rs的操作
Error11:
  If cn.Errors.Count = 0 Then '判断是否有错误发生
     id = MsgBox("成功插入数据！", vbOKOnly, "插入教师授课信息")
  Else
     id = MsgBox("插入数据失败！", vbOKOnly, "插入教师授课信息")
  End If
  Set rs = Nothing   '释放recordset对象
  cn.Close  '关闭连接对象cn
  Set cn = Nothing '释放connection对象
End Sub
Private Sub Command2_Click()
  Unload Me
End Sub
