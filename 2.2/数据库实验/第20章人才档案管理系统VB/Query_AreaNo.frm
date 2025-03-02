VERSION 5.00
Object = "{5E9E78A0-531B-11CF-91F6-C2863C385E30}#1.0#0"; "MSFLXGRD.OCX"
Begin VB.Form Query_AreaNo 
   Caption         =   "专门人才档案管理系统"
   ClientHeight    =   6450
   ClientLeft      =   3030
   ClientTop       =   2220
   ClientWidth     =   9330
   LinkTopic       =   "Form1"
   ScaleHeight     =   6450
   ScaleWidth      =   9330
   Begin VB.PictureBox Picture1 
      Height          =   5055
      Left            =   600
      ScaleHeight     =   4995
      ScaleWidth      =   7995
      TabIndex        =   0
      Top             =   960
      Width           =   8055
      Begin MSFlexGridLib.MSFlexGrid MSFlexGrid1 
         Height          =   2895
         Left            =   360
         TabIndex        =   6
         Top             =   1800
         Width           =   5895
         _ExtentX        =   10398
         _ExtentY        =   5106
         _Version        =   393216
         Rows            =   20
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "宋体"
            Size            =   12
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
      End
      Begin VB.ComboBox Combo1 
         DataField       =   "Name_area"
         DataMember      =   "name_area"
         DataSource      =   "select name_area from areatab"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   330
         ItemData        =   "Query_AreaNo.frx":0000
         Left            =   1200
         List            =   "Query_AreaNo.frx":0002
         TabIndex        =   4
         Text            =   "所有地区"
         Top             =   795
         Width           =   2895
      End
      Begin VB.CommandButton Command2 
         Caption         =   "退出"
         Height          =   375
         Left            =   6480
         TabIndex        =   1
         Top             =   4320
         Width           =   1215
      End
      Begin VB.Label Label3 
         AutoSize        =   -1  'True
         Caption         =   "地区编号名"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   14.25
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H000000C0&
         Height          =   285
         Left            =   2400
         TabIndex        =   5
         Top             =   1440
         Width           =   1425
      End
      Begin VB.Label Label2 
         AutoSize        =   -1  'True
         Caption         =   "地区名"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   12
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00400000&
         Height          =   240
         Left            =   360
         TabIndex        =   2
         Top             =   840
         Width           =   720
      End
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "查询地区编号"
      BeginProperty Font 
         Name            =   "隶书"
         Size            =   24
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF00FF&
      Height          =   480
      Left            =   3000
      TabIndex        =   3
      Top             =   480
      Width           =   2970
   End
End
Attribute VB_Name = "Query_AreaNo"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Combo1_Click()
  
   Sub_ConnectServer
   '--连接地区编号表
   '================== 读“地区编号表”记录
   Set cmd = New adodb.Command
   Set rs = New adodb.Recordset
   cmd.ActiveConnection = conODBC
   cmd.CommandType = CommandTypeEnum.adCmdText
   cmd.CommandText = "select * from AreaTab where Name_area like ?"
   If Trim(Combo1.Text) = Trim(Combo1.List(0)) Then
      Set rs = cmd.Execute(, "%", adodb.CommandTypeEnum.adCmdText)
   Else
      Set rs = cmd.Execute(, Trim(Combo1.Text)) 'adodb.CommandTypeEnum.adCmdText)
   End If
   'num_records = rs.RecordCount
   If rs.EOF Then
      id = MsgBox("此地区没有编号！", , "提示")
      Combo1.SetFocus
      Exit Sub
   Else
     MSFlexGrid1.Rows = 1
     While Not rs.EOF
           MSFlexGrid1.AddItem rs!Number_serial & Chr(9) & rs!Name_Area _
                     & Chr(9) & rs!no_area   '增加表格行内容
          rs.MoveNext
      Wend
  End If
  rs.Close

End Sub

Private Sub Command2_Click()
   Unload Me
End Sub

Private Sub Form_Load()
   
   Combo1.AddItem "所有地区"
   MSFlexGrid1.FormatString = "^  序号   |^     地区名      |^    地区编号      "
   Sub_ConnectServer
   '--给地区名列表框添项目
   conODBC.BeginTrans '事物处理开始
      '================== 读“地区编号表”记录
      Set rs = New adodb.Recordset
      rs.CursorType = adOpenStatic
      rs.LockType = adLockOptimistic '
      rs.Open "Select  Name_Area From AreaTab ", conODBC
      num_records = rs.RecordCount
      If num_records <> 0 Then
         rs.MoveFirst
         While Not rs.EOF
            Combo1.AddItem (Trim(rs!Name_Area))
            rs.MoveNext
         Wend
      End If
   conODBC.CommitTrans '事物处理结束
   rs.Close
   Me.Show
End Sub

