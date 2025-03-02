VERSION 5.00
Object = "{86CF1D34-0C5F-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCT2.OCX"
Object = "{CDE57A40-8B86-11D0-B3C6-00A0C90AEA82}#1.0#0"; "MSDATGRD.OCX"
Begin VB.Form Query_ByName_2 
   Caption         =   "信息检索"
   ClientHeight    =   9225
   ClientLeft      =   1635
   ClientTop       =   1515
   ClientWidth     =   12420
   LinkTopic       =   "Form1"
   ScaleHeight     =   9225
   ScaleWidth      =   12420
   Begin VB.PictureBox Picture1 
      Height          =   7935
      Left            =   480
      ScaleHeight     =   7875
      ScaleWidth      =   11355
      TabIndex        =   0
      Top             =   960
      Width           =   11415
      Begin VB.CommandButton Command1 
         Caption         =   "退出"
         Height          =   375
         Left            =   9960
         TabIndex        =   41
         ToolTipText     =   "从最后行开始删除"
         Top             =   7080
         Width           =   1095
      End
      Begin VB.CommandButton Command3 
         Caption         =   "返回"
         Height          =   375
         Left            =   9960
         TabIndex        =   39
         ToolTipText     =   "从最后行开始删除"
         Top             =   6120
         Width           =   1095
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
         ItemData        =   "Query_ByName_2.frx":0000
         Left            =   6360
         List            =   "Query_ByName_2.frx":0019
         TabIndex        =   18
         Top             =   2520
         Width           =   2445
      End
      Begin VB.TextBox Text3 
         Alignment       =   2  'Center
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
         Left            =   8640
         TabIndex        =   17
         Text            =   "1"
         Top             =   480
         Width           =   480
      End
      Begin VB.TextBox Text2 
         Alignment       =   2  'Center
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
         Left            =   7680
         TabIndex        =   16
         Text            =   "1"
         Top             =   480
         Width           =   480
      End
      Begin VB.TextBox Text1 
         Alignment       =   2  'Center
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
         Left            =   6360
         TabIndex        =   15
         Text            =   "2000"
         Top             =   480
         Width           =   735
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
         ItemData        =   "Query_ByName_2.frx":0051
         Left            =   1800
         List            =   "Query_ByName_2.frx":0070
         TabIndex        =   14
         Top             =   1080
         Width           =   2445
      End
      Begin VB.ComboBox Combo3 
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
         ItemData        =   "Query_ByName_2.frx":00AA
         Left            =   6360
         List            =   "Query_ByName_2.frx":00B4
         TabIndex        =   13
         Top             =   3060
         Width           =   2445
      End
      Begin VB.TextBox Text6 
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
         Left            =   6360
         TabIndex        =   12
         Top             =   1500
         Width           =   2445
      End
      Begin VB.TextBox Text9 
         Alignment       =   2  'Center
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
         Left            =   6360
         TabIndex        =   11
         Text            =   "10"
         Top             =   1995
         Width           =   615
      End
      Begin VB.TextBox Text7 
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   1335
         Left            =   1800
         MultiLine       =   -1  'True
         TabIndex        =   10
         Top             =   3720
         Width           =   7695
      End
      Begin VB.TextBox Text5 
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
         Left            =   6360
         TabIndex        =   9
         Top             =   1005
         Width           =   2415
      End
      Begin VB.TextBox name_Text 
         DataMember      =   "Command1"
         DataSource      =   "Update_Form_DataEnvironment"
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
         Left            =   1800
         TabIndex        =   8
         Top             =   495
         Width           =   2415
      End
      Begin VB.PictureBox Picture2 
         Height          =   450
         Left            =   1800
         ScaleHeight     =   390
         ScaleWidth      =   2355
         TabIndex        =   5
         Top             =   2160
         Width           =   2415
         Begin VB.OptionButton Option1 
            Caption         =   "男"
            Height          =   255
            Left            =   360
            TabIndex        =   7
            Top             =   100
            Value           =   -1  'True
            Width           =   735
         End
         Begin VB.OptionButton Option2 
            Caption         =   "女"
            Height          =   255
            Left            =   1440
            TabIndex        =   6
            Top             =   100
            Width           =   735
         End
      End
      Begin VB.PictureBox Picture3 
         Height          =   450
         Left            =   1800
         ScaleHeight     =   390
         ScaleWidth      =   2355
         TabIndex        =   2
         Top             =   2760
         Width           =   2415
         Begin VB.OptionButton Option3 
            Caption         =   "是"
            Height          =   375
            Left            =   360
            TabIndex        =   4
            Top             =   50
            Width           =   735
         End
         Begin VB.OptionButton Option4 
            Caption         =   "否"
            Height          =   375
            Left            =   1440
            TabIndex        =   3
            Top             =   50
            Value           =   -1  'True
            Width           =   735
         End
      End
      Begin MSComCtl2.UpDown UpDown4 
         Height          =   375
         Left            =   6960
         TabIndex        =   1
         Top             =   1995
         Width           =   240
         _ExtentX        =   476
         _ExtentY        =   661
         _Version        =   393216
         Value           =   10
         BuddyControl    =   "Combo3"
         BuddyDispid     =   196616
         OrigLeft        =   7200
         OrigTop         =   1995
         OrigRight       =   7440
         OrigBottom      =   2370
         Max             =   50
         SyncBuddy       =   -1  'True
         BuddyProperty   =   0
         Enabled         =   -1  'True
      End
      Begin MSComCtl2.UpDown UpDown2 
         Height          =   375
         Left            =   7080
         TabIndex        =   19
         Top             =   480
         Width           =   240
         _ExtentX        =   476
         _ExtentY        =   661
         _Version        =   393216
         Value           =   2000
         BuddyControl    =   "Text3"
         BuddyDispid     =   196612
         OrigLeft        =   7080
         OrigTop         =   480
         OrigRight       =   7350
         OrigBottom      =   855
         Max             =   2050
         Min             =   1980
         SyncBuddy       =   -1  'True
         BuddyProperty   =   0
         Enabled         =   -1  'True
      End
      Begin MSComCtl2.UpDown UpDown1 
         Height          =   375
         Left            =   8160
         TabIndex        =   20
         Top             =   480
         Width           =   240
         _ExtentX        =   476
         _ExtentY        =   661
         _Version        =   393216
         Value           =   1
         BuddyControl    =   "Combo2"
         BuddyDispid     =   196611
         OrigLeft        =   8160
         OrigTop         =   480
         OrigRight       =   8430
         OrigBottom      =   855
         Max             =   12
         Min             =   1
         SyncBuddy       =   -1  'True
         BuddyProperty   =   0
         Enabled         =   -1  'True
      End
      Begin MSComCtl2.UpDown UpDown3 
         Height          =   375
         Left            =   9120
         TabIndex        =   21
         Top             =   480
         Width           =   270
         _ExtentX        =   476
         _ExtentY        =   661
         _Version        =   393216
         Value           =   1
         BuddyControl    =   "UpDown2"
         BuddyDispid     =   196645
         OrigLeft        =   9720
         OrigTop         =   1080
         OrigRight       =   9990
         OrigBottom      =   1455
         Max             =   31
         Min             =   1
         SyncBuddy       =   -1  'True
         BuddyProperty   =   0
         Enabled         =   -1  'True
      End
      Begin MSDataGridLib.DataGrid DataGrid1 
         Height          =   2415
         Left            =   1800
         TabIndex        =   40
         Top             =   5280
         Width           =   7695
         _ExtentX        =   13573
         _ExtentY        =   4260
         _Version        =   393216
         AllowUpdate     =   0   'False
         Enabled         =   -1  'True
         ColumnHeaders   =   -1  'True
         HeadLines       =   1
         RowHeight       =   18
         FormatLocked    =   -1  'True
         BeginProperty HeadFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "宋体"
            Size            =   14.25
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "宋体"
            Size            =   12
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ColumnCount     =   3
         BeginProperty Column00 
            DataField       =   "Person_ID"
            Caption         =   "    成果名称"
            BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
               Type            =   0
               Format          =   ""
               HaveTrueFalseNull=   0
               FirstDayOfWeek  =   0
               FirstWeekOfYear =   0
               LCID            =   2052
               SubFormatType   =   0
            EndProperty
         EndProperty
         BeginProperty Column01 
            DataField       =   "Name"
            Caption         =   "  类别"
            BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
               Type            =   0
               Format          =   ""
               HaveTrueFalseNull=   0
               FirstDayOfWeek  =   0
               FirstWeekOfYear =   0
               LCID            =   2052
               SubFormatType   =   0
            EndProperty
         EndProperty
         BeginProperty Column02 
            DataField       =   "Sex"
            Caption         =   "  出处"
            BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
               Type            =   0
               Format          =   ""
               HaveTrueFalseNull=   0
               FirstDayOfWeek  =   0
               FirstWeekOfYear =   0
               LCID            =   2052
               SubFormatType   =   0
            EndProperty
         EndProperty
         SplitCount      =   1
         BeginProperty Split0 
            ScrollBars      =   2
            BeginProperty Column00 
               Alignment       =   2
               ColumnWidth     =   3060.284
            EndProperty
            BeginProperty Column01 
               ColumnWidth     =   1214.929
            EndProperty
            BeginProperty Column02 
               Alignment       =   3
               ColumnWidth     =   2954.835
            EndProperty
         EndProperty
      End
      Begin VB.Label Label6 
         Caption         =   "日"
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
         Index           =   2
         Left            =   9390
         TabIndex        =   37
         Top             =   555
         Width           =   255
      End
      Begin VB.Label Label6 
         Caption         =   "月"
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
         Index           =   1
         Left            =   8400
         TabIndex        =   36
         Top             =   555
         Width           =   375
      End
      Begin VB.Label Label6 
         Caption         =   "年"
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
         Index           =   6
         Left            =   7400
         TabIndex        =   35
         Top             =   550
         Width           =   375
      End
      Begin VB.Label AreaNo_LabLe 
         Alignment       =   2  'Center
         BorderStyle     =   1  'Fixed Single
         Caption         =   "编号显示"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   14.25
            Charset         =   134
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H000000C0&
         Height          =   375
         Left            =   1800
         TabIndex        =   34
         Top             =   1560
         Width           =   2415
      End
      Begin VB.Label Label16 
         Alignment       =   1  'Right Justify
         AutoSize        =   -1  'True
         Caption         =   "职称"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Left            =   5835
         TabIndex        =   33
         Top             =   2565
         Width           =   420
      End
      Begin VB.Label Label13 
         Alignment       =   1  'Right Justify
         AutoSize        =   -1  'True
         Caption         =   "简历"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Left            =   1275
         TabIndex        =   32
         Top             =   3720
         Width           =   420
      End
      Begin VB.Label Label12 
         Alignment       =   1  'Right Justify
         AutoSize        =   -1  'True
         Caption         =   "英语水平"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Left            =   5415
         TabIndex        =   31
         Top             =   3135
         Width           =   840
      End
      Begin VB.Label Label11 
         Alignment       =   1  'Right Justify
         AutoSize        =   -1  'True
         Caption         =   "专业年限"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Left            =   5415
         TabIndex        =   30
         Top             =   2100
         Width           =   840
      End
      Begin VB.Label Label10 
         Alignment       =   1  'Right Justify
         Caption         =   "党员否"
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
         Left            =   240
         TabIndex        =   29
         Top             =   2880
         Width           =   1455
      End
      Begin VB.Label Label9 
         Alignment       =   1  'Right Justify
         AutoSize        =   -1  'True
         Caption         =   "专业"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Left            =   5835
         TabIndex        =   28
         Top             =   1560
         Width           =   420
      End
      Begin VB.Label Label7 
         Alignment       =   1  'Right Justify
         Caption         =   "姓名"
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
         Left            =   720
         TabIndex        =   27
         Top             =   600
         Width           =   975
      End
      Begin VB.Label Label6 
         Alignment       =   1  'Right Justify
         Caption         =   "性别"
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
         Index           =   0
         Left            =   600
         TabIndex        =   26
         Top             =   2280
         Width           =   1095
      End
      Begin VB.Label Label5 
         Alignment       =   1  'Right Justify
         Caption         =   "工资现状"
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
         Left            =   5280
         TabIndex        =   25
         Top             =   1080
         Width           =   975
      End
      Begin VB.Label Label4 
         Alignment       =   1  'Right Justify
         Caption         =   "出生日期"
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
         Left            =   5280
         TabIndex        =   24
         Top             =   600
         Width           =   975
      End
      Begin VB.Label Label3 
         Alignment       =   1  'Right Justify
         AutoSize        =   -1  'True
         Caption         =   "地点"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Left            =   1275
         TabIndex        =   23
         Top             =   1150
         Width           =   420
      End
      Begin VB.Label Label2 
         Alignment       =   1  'Right Justify
         Caption         =   "编号"
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
         Left            =   720
         TabIndex        =   22
         Top             =   1680
         Width           =   975
      End
   End
   Begin VB.Label Label_Caption 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      Caption         =   "档案信息"
      BeginProperty Font 
         Name            =   "隶书"
         Size            =   24
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000C0&
      Height          =   495
      Left            =   4800
      TabIndex        =   38
      Top             =   360
      Width           =   1935
   End
End
Attribute VB_Name = "Query_ByName_2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
  Unload Me
End Sub

Private Sub Command3_Click()
   Unload Me
   Load Query_ByName_1
End Sub

Private Sub Form_Load()
    Dim strSQL As String
    
    
    Sub_ConnectServer
    '================== 读Person_IP的“人才基本信息表”记录
   Set rs = New ADODB.Recordset
   rs.CursorType = adOpenDynamic
   rs.LockType = adLockOptimistic '
   '-----------录入人才基本情况信息
   'strSQL = "select * from BTab,STab where BTab.Person_ID=Stab.Person_ID and Btab.Person_ID='" + Trim(ID_Person) + "'"
   strSQL = "select * from BTab where BTab.Name='" + Trim(ByName) + "'"
   rs.Open strSQL, conODBC, adCmdTable
   'num_records = rs.RecordCount
   If rs.EOF And rs.BOF Then
      id = MsgBox("没有查到记录！", , "提示")
      Exit Sub
   Else
      name_Text.Text = rs!name
      AreaNo_LabLe.Caption = rs!Person_ID
  End If
  rs.Close
  Set rs = Nothing
  conODBC.Close
  '=========================
  Label_Caption = ByName + Label_Caption
  Me.Show
End Sub

    
    
    
