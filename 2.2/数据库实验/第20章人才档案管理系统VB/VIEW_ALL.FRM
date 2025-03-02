VERSION 5.00
Object = "{5E9E78A0-531B-11CF-91F6-C2863C385E30}#1.0#0"; "MSFLXGRD.OCX"
Begin VB.Form view_all 
   Caption         =   "人才信息管理系统"
   ClientHeight    =   9330
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   11880
   LinkTopic       =   "Form1"
   ScaleHeight     =   9330
   ScaleWidth      =   11880
   StartUpPosition =   2  '屏幕中心
   Begin VB.TextBox Text1 
      Height          =   3255
      Left            =   360
      Locked          =   -1  'True
      MultiLine       =   -1  'True
      ScrollBars      =   2  'Vertical
      TabIndex        =   4
      Text            =   "view_all.frx":0000
      Top             =   5520
      Width           =   9735
   End
   Begin VB.CommandButton Command1 
      Caption         =   "退出"
      Height          =   375
      Left            =   6600
      TabIndex        =   2
      Top             =   4920
      Width           =   975
   End
   Begin VB.CommandButton Command2 
      Caption         =   "详细资料"
      Height          =   375
      Left            =   4320
      TabIndex        =   1
      Top             =   4920
      Width           =   975
   End
   Begin MSFlexGridLib.MSFlexGrid MSFlexGrid1 
      Height          =   3375
      Left            =   360
      TabIndex        =   3
      Top             =   1200
      Width           =   9735
      _ExtentX        =   17171
      _ExtentY        =   5953
      _Version        =   393216
      Rows            =   20
      Cols            =   5
      BackColor       =   16777215
      ForeColor       =   16711680
      ForeColorFixed  =   4210752
      BackColorSel    =   4210816
      ForeColorSel    =   0
      FocusRect       =   0
      HighLight       =   2
      SelectionMode   =   1
      MergeCells      =   1
      AllowUserResizing=   1
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
   Begin VB.Label Label3 
      Caption         =   "Label3"
      BeginProperty Font 
         Name            =   "楷体_GB2312"
         Size            =   15
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   495
      Left            =   360
      TabIndex        =   6
      Top             =   5040
      Width           =   1335
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      Caption         =   "工作简历"
      BeginProperty Font 
         Name            =   "楷体_GB2312"
         Size            =   15.75
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   375
      Left            =   2040
      TabIndex        =   5
      Top             =   5040
      Width           =   1575
   End
   Begin VB.Line Line1 
      BorderWidth     =   2
      X1              =   240
      X2              =   10200
      Y1              =   840
      Y2              =   840
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      Caption         =   "人才信息表"
      BeginProperty Font 
         Name            =   "隶书"
         Size            =   21.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000040C0&
      Height          =   435
      Left            =   5280
      TabIndex        =   0
      Top             =   240
      Width           =   2265
   End
End
Attribute VB_Name = "view_all"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
   Unload Me
   
End Sub

Private Sub Command2_Click()
   
   
   MSFlexGrid1.Col = 1
   person_id = Trim(MSFlexGrid1.Text)
   
   '========改变窗体大小
   Me.Height = Screen.Height
   If Me.Top <> 0 Then
      Me.Top = 0
      Command2.Top = Command2.Top * 2
      Command1.Top = Command2.Top
   End If
   '========显示选择记录的照片和简历
   Set rs = New ADODB.Recordset
   'rs.CursorType = adOpenStatic
   'rs.LockType = adLockOptimistic '
   '-----------读人才基本信息表: 显示照片、简历
   rs.Open "Select * From BTab  where Person_ID='" + person_id + "'", conODBC
   'declare @pl varbinary(16)
   'rs.Open "Select @pl=textptr(resume) From BTab  where Person_ID='" + Person_ID + "'", conODBC
   If IsNull(rs!resume) Then
      Text1.Text = ""
   Else
      Text1.Text = Trim(rs!resume)
   End If
   If IsNull(rs!name) Then
      Label3.Caption = ""
   Else
      Label3.Caption = Trim(rs!name)
   End If
   Text1.Visible = True
   Label2.Visible = True
   Label3.Visible = True
  
End Sub

Private Sub Form_Load()
  Dim rs As Recordset
  
  
  Label1.Left = (Screen.Width - Label1.Width) / 2
  Text1.Visible = False
  Label2.Visible = False
  Label3.Visible = False
  
  '=================连接数据库
  Line1.X1 = 0
  Line1.Y1 = 850
  Line1.X2 = Screen.Width
  Line1.Y2 = 850
  Me.Width = Screen.Width
  Me.Height = Screen.Height / 2
  MSFlexGrid1.Width = Me.Width - 800
  MSFlexGrid1.RowHeight(0) = 500
  'MSFlexGrid1.RowHeight(1) = 400
   MSFlexGrid1.FormatString = "^序号   |^编号       |^姓名      |^性别  |^出生日期      |^工资      |^党员  |^专业          |^专业年限 |^职称       |^英语水平      "
  '=================  用ADO方式打开数据库
  'MsgBox "Opening rcgl_sys...人才管理数据库"
  Sub_ConnectServer
  'conODBC.BeginTrans '事物处理开始
  Set rs = New ADODB.Recordset
  rs.CursorType = adOpenStatic
  rs.LockType = adLockOptimistic '
  'rs.Open "Select * From ViewClientOrderReturnInfo where ClieID='" + ID_Client + "'", conODBC
  '-----------读人才基本信息表
  rs.Open "Select * From BTab ", conODBC
  
  Num_records = rs.RecordCount
  rs.MoveFirst
  For i = 1 To Num_records
      MSFlexGrid1.Row = i
      MSFlexGrid1.Col = 0
      MSFlexGrid1.Text = i
      MSFlexGrid1.Col = 1
      MSFlexGrid1.Text = rs!person_id
      MSFlexGrid1.Col = 2
      If IsNull(rs!name) Then
         MSFlexGrid1.Text = ""
      Else
         MSFlexGrid1.Text = Trim(rs!name)
      End If
      MSFlexGrid1.Col = 3
      If IsNull(rs!sex) Then
         MSFlexGrid1.Text = ""
      Else
         MSFlexGrid1.Text = Trim(rs!sex)
      End If
      MSFlexGrid1.Col = 4
      If IsNull(rs!birth) Then
         MSFlexGrid1.Text = ""
      Else
         MSFlexGrid1.Text = Trim(rs!birth)
      End If
      MSFlexGrid1.Col = 5
      If IsNull(rs!salary) Then
         MSFlexGrid1.Text = ""
      Else
         MSFlexGrid1.Text = Trim(rs!salary)
      End If
      MSFlexGrid1.Col = 6
      If rs!party = True Then
         MSFlexGrid1.Text = "是"
      Else
         MSFlexGrid1.Text = "否"
      End If
      rs.MoveNext
   Next
   rs.Close
   'conODBC.Close
   '-----------读人才专业信息表
   rs.Open "Select * From STab ", conODBC
   Num_records = rs.RecordCount
   rs.MoveFirst
   For i = 1 To Num_records
      MSFlexGrid1.Row = i
      MSFlexGrid1.Col = 7
      If IsNull(rs!speciality) Then
         MSFlexGrid1.Text = ""
      Else
         MSFlexGrid1.Text = Trim(rs!speciality)
      End If
      MSFlexGrid1.Col = 8
      If IsNull(rs!specialityyear) Then
         MSFlexGrid1.Text = ""
      Else
         MSFlexGrid1.Text = Trim(rs!specialityyear)
      End If
      MSFlexGrid1.Col = 9
      If IsNull(rs!technicaltitle) Then
         MSFlexGrid1.Text = ""
      Else
         MSFlexGrid1.Text = Trim(rs!technicaltitle)
      End If
      MSFlexGrid1.Col = 10
      If IsNull(rs!englishlevel) Then
         MSFlexGrid1.Text = ""
      Else
         MSFlexGrid1.Text = Trim(rs!englishlevel)
      End If
      
      rs.MoveNext
   Next
   rs.Close
   'conODBC.Close
   Me.Show
   MSFlexGrid1.HighLight = flexHighlightWithFocus
   MSFlexGrid1.FocusRect = flexFocusheave
   MSFlexGrid1.Row = 1
   Old_Row = 1
   For i = 1 To 10
       MSFlexGrid1.Col = i
       MSFlexGrid1.CellBackColor = vbYellow
   Next

   Me.Show
End Sub

Private Sub MSFlexGrid1_Click()
    Dim no_row As Integer
    
    no_row = MSFlexGrid1.RowSel
       
    MSFlexGrid1.Row = Old_Row
    For i = 1 To 10
        MSFlexGrid1.Col = i
        MSFlexGrid1.CellBackColor = vbWhite
    Next
    Old_Row = no_row
    MSFlexGrid1.Row = no_row
    For i = 1 To 10
        MSFlexGrid1.Col = i
        MSFlexGrid1.CellBackColor = vbYellow
    Next
    
End Sub
