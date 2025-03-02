VERSION 5.00
Object = "{CDE57A40-8B86-11D0-B3C6-00A0C90AEA82}#1.0#0"; "MSDATGRD.OCX"
Begin VB.Form Set_AreaNo 
   Caption         =   "专门人才档案管理系统"
   ClientHeight    =   7170
   ClientLeft      =   3210
   ClientTop       =   2280
   ClientWidth     =   9120
   LinkTopic       =   "Form1"
   ScaleHeight     =   7170
   ScaleWidth      =   9120
   Begin VB.PictureBox Picture1 
      Height          =   5775
      Left            =   360
      ScaleHeight     =   5715
      ScaleWidth      =   8355
      TabIndex        =   1
      Top             =   960
      Width           =   8415
      Begin VB.TextBox Text2 
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
         Left            =   4440
         TabIndex        =   9
         Top             =   720
         Width           =   1935
      End
      Begin VB.CommandButton Command4 
         Caption         =   "修改"
         Height          =   375
         Left            =   6960
         TabIndex        =   8
         Top             =   3720
         Width           =   1215
      End
      Begin VB.CommandButton Command3 
         Caption         =   "删除"
         Height          =   375
         Left            =   6960
         TabIndex        =   7
         Top             =   4320
         Width           =   1215
      End
      Begin VB.CommandButton Command2 
         Caption         =   "退出"
         Height          =   375
         Left            =   6960
         TabIndex        =   6
         Top             =   4920
         Width           =   1215
      End
      Begin VB.CommandButton Command1 
         Caption         =   "添加"
         Height          =   375
         Left            =   6840
         TabIndex        =   5
         Top             =   720
         Width           =   1215
      End
      Begin VB.TextBox Text1 
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
         Left            =   1200
         TabIndex        =   3
         Top             =   720
         Width           =   1695
      End
      Begin MSDataGridLib.DataGrid DataGrid1 
         Bindings        =   "Set_AreaNo.frx":0000
         Height          =   3855
         Left            =   360
         TabIndex        =   4
         Top             =   1560
         Width           =   6255
         _ExtentX        =   11033
         _ExtentY        =   6800
         _Version        =   393216
         AllowUpdate     =   -1  'True
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
         Caption         =   "地区编号表"
         ColumnCount     =   3
         BeginProperty Column00 
            DataField       =   "Number_Serial"
            Caption         =   "   序号"
            BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
               Type            =   1
               Format          =   "0"
               HaveTrueFalseNull=   0
               FirstDayOfWeek  =   0
               FirstWeekOfYear =   0
               LCID            =   2052
               SubFormatType   =   0
            EndProperty
         EndProperty
         BeginProperty Column01 
            DataField       =   "Name_area"
            Caption         =   "   地区名"
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
            DataField       =   "No_area"
            Caption         =   "   地区编号"
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
               ColumnWidth     =   1620.284
            EndProperty
            BeginProperty Column01 
               ColumnWidth     =   1934.929
            EndProperty
            BeginProperty Column02 
               ColumnWidth     =   2369.764
            EndProperty
         EndProperty
      End
      Begin VB.Label Label3 
         AutoSize        =   -1  'True
         Caption         =   "地区编号"
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
         Left            =   3360
         TabIndex        =   10
         Top             =   840
         Width           =   960
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
      Caption         =   "设置地区编号"
      BeginProperty Font 
         Name            =   "隶书"
         Size            =   24
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000C000&
      Height          =   480
      Left            =   2760
      TabIndex        =   0
      Top             =   360
      Width           =   2970
   End
End
Attribute VB_Name = "Set_AreaNo"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command2_Click()
  Unload Me
  
End Sub

Private Sub Form_Load()
  Me.Show
End Sub
