VERSION 5.00
Begin VB.Form Form_head 
   Caption         =   "专门人才档案管理系统"
   ClientHeight    =   4440
   ClientLeft      =   3210
   ClientTop       =   3195
   ClientWidth     =   7905
   LinkTopic       =   "Form1"
   Picture         =   "Form_head.frx":0000
   ScaleHeight     =   4440
   ScaleWidth      =   7905
   Begin VB.CommandButton Command2 
      Caption         =   "退出"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   10.5
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   4320
      TabIndex        =   9
      Top             =   3600
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "确定"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   10.5
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   2280
      TabIndex        =   8
      Top             =   3600
      Width           =   1215
   End
   Begin VB.TextBox Text2 
      BeginProperty Font 
         Name            =   "System"
         Size            =   12
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      IMEMode         =   3  'DISABLE
      Left            =   2640
      PasswordChar    =   "*"
      TabIndex        =   6
      Top             =   2880
      Width           =   2655
   End
   Begin VB.TextBox Text1 
      BeginProperty Font 
         Name            =   "System"
         Size            =   12
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   2640
      TabIndex        =   4
      Top             =   2280
      Width           =   2655
   End
   Begin VB.Label Label6 
      AutoSize        =   -1  'True
      Caption         =   "口令"
      BeginProperty Font 
         Name            =   "System"
         Size            =   12
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   240
      Left            =   2040
      TabIndex        =   7
      Top             =   2925
      Width           =   480
   End
   Begin VB.Label Label5 
      AutoSize        =   -1  'True
      Caption         =   "用户名"
      BeginProperty Font 
         Name            =   "System"
         Size            =   12
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   240
      Left            =   1800
      TabIndex        =   5
      Top             =   2325
      Width           =   720
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "编制  江南大学计算机系"
      BeginProperty Font 
         Name            =   "楷体_GB2312"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   240
      Left            =   1920
      TabIndex        =   3
      Top             =   1680
      Width           =   2640
   End
   Begin VB.Label Label3 
      Alignment       =   2  'Center
      Caption         =   "版本    V 1.0"
      BeginProperty Font 
         Name            =   "幼圆"
         Size            =   12
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   300
      Left            =   2505
      TabIndex        =   2
      Top             =   1080
      Width           =   2145
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "人才档案管理"
      BeginProperty Font 
         Name            =   "隶书"
         Size            =   26.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00008080&
      Height          =   525
      Left            =   2040
      TabIndex        =   1
      Top             =   255
      Width           =   3255
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      Caption         =   "人才档案管理"
      BeginProperty Font 
         Name            =   "隶书"
         Size            =   26.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   525
      Left            =   2040
      TabIndex        =   0
      Top             =   240
      Width           =   3255
   End
End
Attribute VB_Name = "Form_head"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
  Dim name_user
  Dim password_user
  
  If Text1.Text = "" Then
     id = MsgBox("请输入用户名！", , "提示")
     Exit Sub
  Else
     name_user = Trim(Text1.Text)
  End If
  If Text2.Text = "" Then
     id = MsgBox("请输入口令！", , "提示")
     Exit Sub
  Else
     password_user = Trim(Text2.Text)
  End If
  
  '=================  用ADO方式打开数据库
  'MsgBox "Opening rcgl_sys...人才管理数据库"
  Sub_ConnectServer
  'conODBC.BeginTrans '事物处理开始
  Set rs = New ADODB.Recordset
  rs.CursorType = adOpenStatic
  rs.LockType = adLockOptimistic '
  'rs.Open "Select * From ViewClientOrderReturnInfo where ClieID='" + ID_Client + "'", conODBC
  '-----------读系统用户表
  rs.Open "Select * From UserTab where 用户名='" + name_user + "'", conODBC
  Num_records = rs.RecordCount
  If Num_records = 0 Then
     id = MsgBox("用户名不正确，请重新输入！", , "")
     rs.Close
     Text1.SetFocus
     Exit Sub
  Else
     If Trim(rs!口令) <> Trim(password_user) Then
        id = MsgBox("口令不正确，请重新输入！", , "")
        rs.Close
        Text2.SetFocus
        Exit Sub
     End If
  End If
  rs.Close
  Unload Me
  Load Form_main
End Sub

Private Sub Command2_Click()
   Unload Me
End Sub

Private Sub Form_Load()
   Me.Show
   Text1.SetFocus
End Sub

Private Sub Text2_KeyPress(KeyAscii As Integer)
    If KeyAscii = 13 Then
       Command1_Click
       Exit Sub
    End If
End Sub
