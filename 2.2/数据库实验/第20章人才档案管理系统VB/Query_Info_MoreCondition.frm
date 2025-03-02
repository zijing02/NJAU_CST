VERSION 5.00
Object = "{5E9E78A0-531B-11CF-91F6-C2863C385E30}#1.0#0"; "MSFLXGRD.OCX"
Begin VB.Form Query_Info_MoreCondition 
   Caption         =   "专门人才信息管理系统"
   ClientHeight    =   7320
   ClientLeft      =   4020
   ClientTop       =   3570
   ClientWidth     =   9975
   LinkTopic       =   "Form1"
   ScaleHeight     =   7320
   ScaleWidth      =   9975
   Begin VB.CommandButton Command2 
      Caption         =   "退出"
      Height          =   375
      Left            =   7680
      TabIndex        =   13
      Top             =   2160
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "查询"
      Height          =   375
      Left            =   7680
      TabIndex        =   12
      Top             =   1440
      Width           =   1215
   End
   Begin VB.PictureBox Picture1 
      Height          =   6135
      Left            =   360
      ScaleHeight     =   6075
      ScaleWidth      =   9195
      TabIndex        =   0
      Top             =   720
      Width           =   9255
      Begin VB.OptionButton Option2 
         Caption         =   "或"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H000000C0&
         Height          =   255
         Left            =   2280
         TabIndex        =   10
         Top             =   1320
         Width           =   855
      End
      Begin VB.OptionButton Option1 
         Caption         =   "与"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H000000C0&
         Height          =   255
         Left            =   1200
         TabIndex        =   9
         Top             =   1320
         Value           =   -1  'True
         Width           =   855
      End
      Begin VB.TextBox Text2 
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
         Left            =   3960
         TabIndex        =   6
         Text            =   "男"
         Top             =   1800
         Width           =   2535
      End
      Begin VB.ComboBox Combo2 
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
         ItemData        =   "Query_Info_MoreCondition.frx":0000
         Left            =   1200
         List            =   "Query_Info_MoreCondition.frx":0013
         TabIndex        =   5
         Text            =   "性别"
         Top             =   1800
         Width           =   2175
      End
      Begin VB.TextBox Text1 
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
         Left            =   3960
         TabIndex        =   4
         Text            =   "北京"
         Top             =   720
         Width           =   2535
      End
      Begin VB.ComboBox Combo1 
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
         ItemData        =   "Query_Info_MoreCondition.frx":0035
         Left            =   1200
         List            =   "Query_Info_MoreCondition.frx":0048
         TabIndex        =   2
         Text            =   "地区"
         Top             =   720
         Width           =   2175
      End
      Begin MSFlexGridLib.MSFlexGrid MSFlexGrid1 
         Height          =   2895
         Left            =   240
         TabIndex        =   14
         Top             =   3000
         Width           =   8655
         _ExtentX        =   15266
         _ExtentY        =   5106
         _Version        =   393216
         Rows            =   20
         Cols            =   10
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
      Begin VB.Label Label6 
         AutoSize        =   -1  'True
         Caption         =   "查询结果"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   15
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00FF0000&
         Height          =   300
         Left            =   3720
         TabIndex        =   15
         Top             =   2640
         Width           =   1200
      End
      Begin VB.Label Label5 
         AutoSize        =   -1  'True
         Caption         =   "条件2"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00800000&
         Height          =   210
         Left            =   600
         TabIndex        =   8
         Top             =   1845
         Width           =   525
      End
      Begin VB.Label Label4 
         AutoSize        =   -1  'True
         Caption         =   "条件1"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00800000&
         Height          =   210
         Left            =   600
         TabIndex        =   7
         Top             =   795
         Width           =   525
      End
      Begin VB.Label Label2 
         AutoSize        =   -1  'True
         Caption         =   "值"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00800000&
         Height          =   210
         Left            =   3645
         TabIndex        =   3
         Top             =   1875
         Width           =   210
      End
      Begin VB.Label Label1 
         AutoSize        =   -1  'True
         Caption         =   "值"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00800000&
         Height          =   210
         Left            =   3645
         TabIndex        =   1
         Top             =   795
         Width           =   210
      End
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "查询人才档案信息"
      BeginProperty Font 
         Name            =   "隶书"
         Size            =   21.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000080&
      Height          =   435
      Left            =   3000
      TabIndex        =   11
      Top             =   240
      Width           =   3600
   End
End
Attribute VB_Name = "Query_Info_MoreCondition"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
   Dim value1_input, value2_input
   Dim condition1_input, condition2_input
   Dim log_input

   '====== 判断条件是否合理
   If Trim(Combo1.Text) = Trim(Combo2.Text) And Option1.Value = True Then
      id = MsgBox("同一个条件不能同时取两个值，请重新选择！", , "提示")
      Combo1.SetFocus
      Exit Sub
   End If
   If Trim(Combo1.Text) = "" Or Trim(Text1.Text) = "" Then
      id = MsgBox("请选择条件1或输入其值！", , "提示")
      Combo1.SetFocus
      Exit Sub
   End If
   If Trim(Combo2.Text) <> "" And Trim(Text2.Text) = "" Then
      id = MsgBox("请输入条件2的值！", , "提示")
      Text2.SetFocus
      Exit Sub
   End If
   '========整理输入条件
   condition1_input = Switch(Trim(Combo1.Text) = "地区", "Person_ID", Trim(Combo1.Text) _
               = "姓名", "Name", Trim(Combo1.Text) = "性别", "Sex", Trim(Combo1.Text) _
               = "职称", "TechnicalTitle")
   value1_input = Trim(Text1.Text)
   If Trim(Combo1.Text) = "地区" Then
      Name_Area = Trim(Text1.Text)
      no_area
      'Sum_People
      'person_ID_tran Sum_People_Area, string_num
      value1_input = Trim(String_Area) '+ Trim(string_num)
   End If
   If Trim(Combo1.Text) = "工资" Then
      value1_input = Val(Text1.Text)
   End If
   condition2_input = Switch(Trim(Combo2.Text) = "地区", "Person_ID", Trim(Combo2.Text) _
               = "姓名", "Name", Trim(Combo2.Text) = "性别", "Sex", Trim(Combo2.Text) _
               = "职称", "TechnicalTitle")
   value2_input = Trim(Text2.Text)
   If Trim(Combo2.Text) = "地区" Then
      Name_Area = Trim(Text2.Text)
      no_area
      value2_input = Trim(String_Area)
   End If
   If Trim(Combo2.Text) = "工资" Then
      value2_input = Val(Text2.Text)
   End If
   If Option1.Value = True Then
      log_input = "and"
   Else
      log_input = "or"
   End If
   Sub_ConnectServer
   '================== 读“人才基本信息表”记录
   Set cmd = New ADODB.Command
   Set rs = New ADODB.Recordset
   Set param = New ADODB.Parameter
   cmd.CommandType = CommandTypeEnum.adCmdText
   'cmd.CommandText = "select * from BTab,STab where BTab.Person_ID=Stab.Person_ID and Btab." + condition1_input + "  like ?  " + _
    '                log_input + "  " + condition2_input + " like ? "
   cmd.CommandText = "select * from BTab where " + condition1_input + "  like ?  " + _
                    log_input + "  " + condition2_input + " like ? "
  
   Set param = cmd.CreateParameter(condition1_input, adVarChar, adParamInput, 10)
   cmd.Parameters.Append (param)
   Set para = cmd.CreateParameter(condition2_input, adVarChar, adParamInput, 10)
   cmd.Parameters.Append (para)
   cmd.Parameters(0).Value = "%" + value1_input + "%"
   cmd.Parameters(1).Value = "%" + value2_input + "%"
   cmd.ActiveConnection = conODBC
   Set rs = cmd.Execute()
   'Set rs = cmd.Execute(, Trim(Combo1.Text)) 'adodb.CommandTypeEnum.adCmdText)
   'num_records = rs.RecordCount
   If rs.EOF And rs.BOF Then
      id = MsgBox("没有查到记录！", , "提示")
      Combo1.SetFocus
      Exit Sub
   Else
     MSFlexGrid1.Rows = 1
     While Not rs.EOF
           MSFlexGrid1.AddItem rs!Person_ID & Chr(9) & rs!name _
                     & Chr(9) & rs!sex   '增加表格行内容
          rs.MoveNext
      Wend
  End If
  rs.Close

End Sub

Private Sub Command2_Click()
  Unload Me
End Sub

Private Sub Form_Load()
  Me.Show
End Sub
