VERSION 5.00
Begin VB.Form update1 
   Caption         =   "更新学生成绩信息"
   ClientHeight    =   2775
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   3570
   LinkTopic       =   "Form1"
   ScaleHeight     =   2775
   ScaleWidth      =   3570
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command2 
      Caption         =   "退出"
      Height          =   375
      Left            =   1920
      TabIndex        =   7
      Top             =   2160
      Width           =   975
   End
   Begin VB.TextBox s_Text 
      Height          =   375
      Left            =   1080
      TabIndex        =   4
      Top             =   240
      Width           =   1800
   End
   Begin VB.TextBox c_Text 
      Height          =   375
      Left            =   1080
      TabIndex        =   3
      Top             =   840
      Width           =   1800
   End
   Begin VB.CommandButton Command1 
      Caption         =   "更新"
      Height          =   375
      Left            =   600
      TabIndex        =   2
      Top             =   2160
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
      Left            =   1080
      TabIndex        =   0
      Top             =   1440
      Width           =   1800
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
      Left            =   480
      TabIndex        =   6
      Top             =   960
      Width           =   480
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "学号"
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
      Top             =   300
      Width           =   480
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
      Left            =   480
      TabIndex        =   1
      Top             =   1560
      Width           =   480
   End
End
Attribute VB_Name = "update1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
  Dim cn As ADODB.Connection
  Dim strCnn As String
  Dim sno As String, cno As String
  Dim sc_score As Integer
    
  '**********获取记录学生学号，课程号
  sno = Trim(s_Text.Text)
  cno = Trim(c_Text.Text)
  sc_score = Val(score_Text.Text)
  '*********** 设置ODBC OLE DB数据源连接串
  'strCnn = " DRIVER={SQL SERVER};SERVER=MXM;UID=sa;PWD=sa;DATABASE=jiaoxuedb"
  strCnn = "Provider=SQLOLEDB;UID=sa; PWD=sa;Persist " + _
           "Security Info=false; Initial Catalog=jiaoxuedb"
  '*********** 创建连接对象cn
  Set cn = New ADODB.Connection
  cn.Open strCnn '********* 建立到数据源的物理连接
  '********** 创建command对象cm
  Dim cm As New ADODB.Command
  cm.ActiveConnection = cn
  '********** 给command对象添加要执行的SQL命令: 带参数的存储过程
  cn.Errors.Clear '清空错误对象
  On Error GoTo Error11
  cm.CommandText = "update_score"
  Set prm = cm.CreateParameter("sno", adChar, adParamInput, 6, sno)
  cm.Parameters.Append prm
  Set prm = cm.CreateParameter("cno", adChar, adParamInput, 5, cno)
  cm.Parameters.Append prm
  Set prm = cm.CreateParameter("score", adTinyInt, adParamInput, , sc_score)
  cm.Parameters.Append prm
  '********** 给command对象要执行的SQL命令的类型：SQL文本
  cm.CommandType = adCmdStoredProc
  cm.Execute '********** 执行不返回行的command命令
Error11:
  If cn.Errors.Count = 0 Then
     MsgBox ("成绩更新成功！")
  Else
     MsgBox ("成绩更新成功！") '失败
  End If
  cn.Close  '关闭连接对象cn
  Set cn = Nothing '释放cn对象
End Sub

Private Sub Command2_Click()
  Unload Me
End Sub

Private Sub Form_Load()
   Me.Show
   
End Sub
