VERSION 5.00
Begin VB.Form update2 
   Caption         =   "更新教师任课信息"
   ClientHeight    =   2685
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   3630
   LinkTopic       =   "Form1"
   ScaleHeight     =   2685
   ScaleWidth      =   3630
   StartUpPosition =   3  '窗口缺省
   Begin VB.TextBox nc_Text 
      Height          =   375
      Left            =   1320
      TabIndex        =   6
      Top             =   1440
      Width           =   1800
   End
   Begin VB.CommandButton Command2 
      Caption         =   "退出"
      Height          =   375
      Left            =   2040
      TabIndex        =   5
      Top             =   2160
      Width           =   975
   End
   Begin VB.TextBox t_Text 
      Height          =   375
      Left            =   1320
      TabIndex        =   2
      Top             =   240
      Width           =   1800
   End
   Begin VB.TextBox dc_Text 
      Height          =   375
      Left            =   1320
      TabIndex        =   1
      Top             =   840
      Width           =   1800
   End
   Begin VB.CommandButton Command1 
      Caption         =   "更新"
      Height          =   375
      Left            =   480
      TabIndex        =   0
      Top             =   2160
      Width           =   975
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "新课号"
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
      TabIndex        =   7
      Top             =   1560
      Width           =   720
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "旧课号"
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
      Left            =   480
      TabIndex        =   3
      Top             =   360
      Width           =   960
   End
End
Attribute VB_Name = "update2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
  Dim cn As ADODB.Connection
  Dim strCnn As String, strSQL As String
  Dim tno As String, c_old As String, c_new As String
  Dim id As Integer
  '**********获取待修改记录的教师号和课程号
  tno = Trim(t_Text.Text)
  c_old = Trim(dc_Text.Text)
  c_new = Trim(nc_Text.Text)
  '*********** 设置ODBC OLE DB数据源连接串
  strCnn = " DRIVER={SQL SERVER};SERVER=MXM;UID=sa;PWD=sa;DATABASE=jiaoxuedb"
  '*********** 创建连接对象cn
  Set cn = New ADODB.Connection
  '********* 建立到数据源的物理连接
  cn.Open strCnn
  '********** 设置查询SQL命令串：带参数t_name
  strSQL = "select cno from TC where tno='" + tno + "' and cno='" + c_old + "'"
  '********** 创建recordset对象
  Set rs = New ADODB.Recordset
  rs.CursorType = adOpenKeyset '设置游标类型为键集游标
  rs.CursorLocation = adUseClient '设置游标位置在客户端
  rs.LockType = adLockOptimistic '设置锁类型
  cn.Errors.Clear '清空错误对象
  On Error GoTo Error11  '若发生错误则转到语句：Error11
  rs.Open strSQL, cn, , , adCmdText
  If rs.EOF = False Then
     rs!cno = c_new '更新当前课程号
     id = MsgBox("成功更新课程号数据！", vbOKOnly, "更新教师授课信息")
     Set rs = Nothing   '释放recordset对象
     cn.Close  '关闭连接对象cn
     Set cn = Nothing '释放connection对象
     Exit Sub
  End If
Error11:
  id = MsgBox("更新数据失败！", vbOKOnly, "更新授课信息")
  Set rs = Nothing   '释放recordset对象
  cn.Close  '关闭连接对象cn
  Set cn = Nothing '释放connection对象
End Sub
Private Sub Command2_Click()
  End
End Sub
