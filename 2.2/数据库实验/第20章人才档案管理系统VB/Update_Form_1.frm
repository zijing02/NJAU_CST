VERSION 5.00
Object = "{CDE57A40-8B86-11D0-B3C6-00A0C90AEA82}#1.0#0"; "MSDATGRD.OCX"
Begin VB.Form Update_Form_1 
   Caption         =   "人才档案信息管理系统"
   ClientHeight    =   6060
   ClientLeft      =   3390
   ClientTop       =   2775
   ClientWidth     =   8580
   LinkTopic       =   "Form1"
   ScaleHeight     =   6060
   ScaleWidth      =   8580
   Begin VB.CommandButton Command2 
      Caption         =   "退出"
      Height          =   375
      Left            =   4800
      TabIndex        =   4
      Top             =   5280
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Caption         =   "修改"
      Height          =   375
      Left            =   2640
      TabIndex        =   3
      Top             =   5280
      Width           =   975
   End
   Begin MSDataGridLib.DataGrid DataGrid1 
      Bindings        =   "Update_Form_1.frx":0000
      Height          =   2655
      Left            =   1200
      TabIndex        =   0
      Top             =   2160
      Width           =   6135
      _ExtentX        =   10821
      _ExtentY        =   4683
      _Version        =   393216
      AllowUpdate     =   0   'False
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
      DataMember      =   "Command1"
      Caption         =   "人才编号表"
      ColumnCount     =   3
      BeginProperty Column00 
         DataField       =   "Person_ID"
         Caption         =   "    编号"
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
         Caption         =   "     姓名"
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
         Caption         =   "  性别"
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
            ColumnWidth     =   1934.929
         EndProperty
         BeginProperty Column01 
            ColumnWidth     =   2129.953
         EndProperty
         BeginProperty Column02 
            Alignment       =   3
         EndProperty
      EndProperty
   End
   Begin VB.Label Label2 
      Caption         =   "选择要修改的记录"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   14.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00C00000&
      Height          =   375
      Left            =   1200
      TabIndex        =   2
      Top             =   1800
      Width           =   2415
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      Caption         =   "修改人才信息"
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
      Left            =   2910
      TabIndex        =   1
      Top             =   480
      Width           =   2715
   End
   Begin VB.Line Line1 
      BorderWidth     =   2
      X1              =   240
      X2              =   8280
      Y1              =   1080
      Y2              =   1080
   End
End
Attribute VB_Name = "Update_Form_1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()

'------------获取要修改的记录编号
   DataGrid1.Col = 0
   ID_Person = DataGrid1.Text
   
   Load Update_Form_2
End Sub

Private Sub Command2_Click()
   Unload Me
End Sub

Private Sub Form_Load()
   Me.Show
End Sub
