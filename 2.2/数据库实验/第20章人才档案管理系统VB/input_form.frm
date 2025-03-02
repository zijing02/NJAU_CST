VERSION 5.00
Object = "{86CF1D34-0C5F-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCT2.OCX"
Begin VB.Form input_form 
   Caption         =   "人才信息管理系统"
   ClientHeight    =   10020
   ClientLeft      =   1395
   ClientTop       =   900
   ClientWidth     =   12495
   LinkTopic       =   "Form1"
   LockControls    =   -1  'True
   ScaleHeight     =   10020
   ScaleWidth      =   12495
   Begin VB.CommandButton Command5 
      Caption         =   "退出"
      Height          =   375
      Left            =   8040
      TabIndex        =   60
      Top             =   9240
      Width           =   1215
   End
   Begin VB.CommandButton Command4 
      Caption         =   "取消"
      Height          =   375
      Left            =   5880
      TabIndex        =   59
      Top             =   9240
      Width           =   1215
   End
   Begin VB.CommandButton Command3 
      Caption         =   "入库"
      Height          =   375
      Left            =   3720
      TabIndex        =   58
      Top             =   9240
      Width           =   1215
   End
   Begin VB.PictureBox Picture1 
      Height          =   7935
      Left            =   480
      ScaleHeight     =   7875
      ScaleWidth      =   11355
      TabIndex        =   0
      Top             =   960
      Width           =   11415
      Begin VB.CommandButton Command2 
         Caption         =   "删除"
         Height          =   375
         Left            =   9840
         TabIndex        =   61
         ToolTipText     =   "从最后行开始删除"
         Top             =   6360
         Width           =   1095
      End
      Begin VB.TextBox Text10 
         BackColor       =   &H00E0E0E0&
         Enabled         =   0   'False
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
         Index           =   4
         Left            =   600
         TabIndex        =   57
         Top             =   7200
         Width           =   3495
      End
      Begin VB.TextBox Text11 
         BackColor       =   &H00E0E0E0&
         Enabled         =   0   'False
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
         Index           =   4
         Left            =   4080
         TabIndex        =   56
         Top             =   7200
         Width           =   2055
      End
      Begin VB.TextBox Text12 
         BackColor       =   &H00E0E0E0&
         Enabled         =   0   'False
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
         Index           =   4
         Left            =   6120
         TabIndex        =   55
         Top             =   7200
         Width           =   3500
      End
      Begin VB.TextBox Text10 
         BackColor       =   &H00E0E0E0&
         Enabled         =   0   'False
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
         Index           =   3
         Left            =   600
         TabIndex        =   54
         Top             =   6840
         Width           =   3495
      End
      Begin VB.TextBox Text11 
         BackColor       =   &H00E0E0E0&
         Enabled         =   0   'False
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
         Index           =   3
         Left            =   4080
         TabIndex        =   53
         Top             =   6840
         Width           =   2055
      End
      Begin VB.TextBox Text12 
         BackColor       =   &H00E0E0E0&
         Enabled         =   0   'False
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
         Index           =   3
         Left            =   6120
         TabIndex        =   52
         Top             =   6840
         Width           =   3500
      End
      Begin VB.TextBox Text10 
         BackColor       =   &H00E0E0E0&
         Enabled         =   0   'False
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
         Index           =   2
         Left            =   600
         TabIndex        =   51
         Top             =   6480
         Width           =   3495
      End
      Begin VB.TextBox Text11 
         BackColor       =   &H00E0E0E0&
         Enabled         =   0   'False
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
         Index           =   2
         Left            =   4080
         TabIndex        =   50
         Top             =   6480
         Width           =   2055
      End
      Begin VB.TextBox Text12 
         BackColor       =   &H00E0E0E0&
         Enabled         =   0   'False
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
         Index           =   2
         Left            =   6120
         TabIndex        =   49
         Top             =   6480
         Width           =   3500
      End
      Begin VB.TextBox Text10 
         BackColor       =   &H00E0E0E0&
         Enabled         =   0   'False
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
         Index           =   1
         Left            =   600
         TabIndex        =   48
         Top             =   6120
         Width           =   3495
      End
      Begin VB.TextBox Text11 
         BackColor       =   &H00E0E0E0&
         Enabled         =   0   'False
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
         Index           =   1
         Left            =   4080
         TabIndex        =   47
         Top             =   6120
         Width           =   2055
      End
      Begin VB.TextBox Text12 
         BackColor       =   &H00E0E0E0&
         Enabled         =   0   'False
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
         Index           =   1
         Left            =   6120
         TabIndex        =   46
         Top             =   6120
         Width           =   3500
      End
      Begin VB.CommandButton Command1 
         Caption         =   "添加"
         Height          =   375
         Left            =   9840
         TabIndex        =   45
         Top             =   5760
         Width           =   1095
      End
      Begin VB.TextBox Text12 
         BackColor       =   &H00E0E0E0&
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
         Left            =   6120
         TabIndex        =   41
         Top             =   5760
         Width           =   3500
      End
      Begin VB.TextBox Text11 
         BackColor       =   &H00E0E0E0&
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
         Left            =   4080
         TabIndex        =   40
         Top             =   5760
         Width           =   2055
      End
      Begin VB.TextBox Text10 
         BackColor       =   &H00E0E0E0&
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
         TabIndex        =   39
         Top             =   5760
         Width           =   3495
      End
      Begin MSComCtl2.UpDown UpDown4 
         Height          =   375
         Left            =   6960
         TabIndex        =   38
         Top             =   1995
         Width           =   240
         _ExtentX        =   423
         _ExtentY        =   661
         _Version        =   393216
         Value           =   10
         BuddyControl    =   "Text9"
         BuddyDispid     =   196627
         OrigLeft        =   7200
         OrigTop         =   1995
         OrigRight       =   7440
         OrigBottom      =   2370
         Max             =   50
         SyncBuddy       =   -1  'True
         BuddyProperty   =   0
         Enabled         =   -1  'True
      End
      Begin VB.PictureBox Picture3 
         Height          =   450
         Left            =   1800
         ScaleHeight     =   390
         ScaleWidth      =   2355
         TabIndex        =   35
         Top             =   2760
         Width           =   2415
         Begin VB.OptionButton Option4 
            Caption         =   "否"
            Height          =   375
            Left            =   1440
            TabIndex        =   37
            Top             =   50
            Value           =   -1  'True
            Width           =   735
         End
         Begin VB.OptionButton Option3 
            Caption         =   "是"
            Height          =   375
            Left            =   360
            TabIndex        =   36
            Top             =   50
            Width           =   735
         End
      End
      Begin VB.PictureBox Picture2 
         Height          =   450
         Left            =   1800
         ScaleHeight     =   390
         ScaleWidth      =   2355
         TabIndex        =   32
         Top             =   2160
         Width           =   2415
         Begin VB.OptionButton Option2 
            Caption         =   "女"
            Height          =   255
            Left            =   1440
            TabIndex        =   34
            Top             =   100
            Width           =   735
         End
         Begin VB.OptionButton Option1 
            Caption         =   "男"
            Height          =   255
            Left            =   360
            TabIndex        =   33
            Top             =   100
            Value           =   -1  'True
            Width           =   735
         End
      End
      Begin VB.TextBox Text4 
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
         TabIndex        =   11
         Top             =   495
         Width           =   2415
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
         TabIndex        =   10
         Top             =   1005
         Width           =   2415
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
         TabIndex        =   9
         Top             =   3720
         Width           =   7695
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
         TabIndex        =   8
         Text            =   "10"
         Top             =   1995
         Width           =   615
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
         TabIndex        =   7
         Top             =   1500
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
         ItemData        =   "input_form.frx":0000
         Left            =   6360
         List            =   "input_form.frx":000A
         TabIndex        =   6
         Top             =   3060
         Width           =   2445
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
         ItemData        =   "input_form.frx":001E
         Left            =   1800
         List            =   "input_form.frx":003D
         TabIndex        =   5
         Top             =   1080
         Width           =   2445
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
         TabIndex        =   4
         Text            =   "2000"
         Top             =   480
         Width           =   735
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
         TabIndex        =   3
         Text            =   "1"
         Top             =   480
         Width           =   480
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
         TabIndex        =   2
         Text            =   "1"
         Top             =   480
         Width           =   480
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
         ItemData        =   "input_form.frx":0077
         Left            =   6360
         List            =   "input_form.frx":0090
         TabIndex        =   1
         Top             =   2520
         Width           =   2445
      End
      Begin MSComCtl2.UpDown UpDown2 
         Height          =   375
         Left            =   7080
         TabIndex        =   12
         Top             =   480
         Width           =   240
         _ExtentX        =   423
         _ExtentY        =   661
         _Version        =   393216
         Value           =   2000
         BuddyControl    =   "Text1"
         BuddyDispid     =   196631
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
         TabIndex        =   13
         Top             =   480
         Width           =   240
         _ExtentX        =   423
         _ExtentY        =   661
         _Version        =   393216
         Value           =   1
         BuddyControl    =   "Text2"
         BuddyDispid     =   196632
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
         TabIndex        =   14
         Top             =   480
         Width           =   270
         _ExtentX        =   423
         _ExtentY        =   661
         _Version        =   393216
         Value           =   1
         BuddyControl    =   "Text3"
         BuddyDispid     =   196633
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
      Begin VB.Label Label15 
         Alignment       =   2  'Center
         BorderStyle     =   1  'Fixed Single
         Caption         =   "出处"
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
         Left            =   6120
         TabIndex        =   44
         Top             =   5400
         Width           =   3495
      End
      Begin VB.Label Label14 
         Alignment       =   2  'Center
         BorderStyle     =   1  'Fixed Single
         Caption         =   "类别"
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
         Left            =   4080
         TabIndex        =   43
         Top             =   5400
         Width           =   2055
      End
      Begin VB.Label Label8 
         Alignment       =   2  'Center
         BorderStyle     =   1  'Fixed Single
         Caption         =   "成果名称"
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
         Left            =   600
         TabIndex        =   42
         Top             =   5400
         Width           =   3495
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
         TabIndex        =   30
         Top             =   1680
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
         TabIndex        =   29
         Top             =   1150
         Width           =   420
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
         TabIndex        =   28
         Top             =   600
         Width           =   975
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
         TabIndex        =   27
         Top             =   1080
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
         TabIndex        =   25
         Top             =   600
         Width           =   975
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
         TabIndex        =   24
         Top             =   1560
         Width           =   420
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
         TabIndex        =   23
         Top             =   2880
         Width           =   1455
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
         TabIndex        =   22
         Top             =   2100
         Width           =   840
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
         TabIndex        =   21
         Top             =   3135
         Width           =   840
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
         TabIndex        =   20
         Top             =   3720
         Width           =   420
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
         TabIndex        =   19
         Top             =   2565
         Width           =   420
      End
      Begin VB.Label Label1 
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
         TabIndex        =   18
         Top             =   1560
         Width           =   2415
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
         TabIndex        =   17
         Top             =   550
         Width           =   375
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
         TabIndex        =   16
         Top             =   555
         Width           =   375
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
         TabIndex        =   15
         Top             =   555
         Width           =   255
      End
   End
   Begin VB.Label Label34 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      Caption         =   "录入人才档案信息"
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
      Height          =   480
      Left            =   3720
      TabIndex        =   31
      Top             =   360
      Width           =   3855
   End
End
Attribute VB_Name = "input_form"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Text8_Change()

End Sub

Private Sub Combo1_Click()
   
    '======查询地区编号
    Name_Area = Trim(Combo1.Text)
    no_area
    '=====求出此人编号
    Sub_ConnectServer
    Set rs = New ADODB.Recordset
    rs.CursorType = adOpenStatic
    rs.LockType = adLockOptimistic '
    '-----------打开人才基本信息表
    rs.Open "Select * From BTab where person_ID like '" + String_Area + "%" + "'", conODBC
    Num_records = rs.RecordCount
    rs.Close
    value_num = Num_records + 1
    person_ID_tran value_num, string_num
    Label1.Caption = String_Area + string_num
    
End Sub

Private Sub Command1_Click()
  
   If Num_Archive > 0 Then
      If Text10(Num_Archive - 1).Text = "" Then
         id = MsgBox("成果名称不能空！", , "提示")
         Exit Sub
      End If
   End If
   Text10(Num_Archive).BackColor = &H80000005
   Text10(Num_Archive).Enabled = True
   Text11(Num_Archive).BackColor = &H80000005
   Text11(Num_Archive).Enabled = True
   Text12(Num_Archive).BackColor = &H80000005
   Text12(Num_Archive).Enabled = True
   Text10(Num_Archive).SetFocus
   Num_Archive = Num_Archive + 1   '成果计数
End Sub

Private Sub Command2_Click()  '从最后一个成果删除

   If Num_Archive > 0 Then
      Text10(Num_Archive).BackColor = &HE0E0E0
      Text10(Num_Archive).Enabled = False
      Text11(Num_Archive).BackColor = &HE0E0E0
      Text11(Num_Archive).Enabled = False
      Text12(Num_Archive).BackColor = &HE0E0E0
      Text12(Num_Archive).Enabled = False
      Num_Archive = Num_Archive - 1    '成果计数
      Text10(Num_Archive).SetFocus
   End If
End Sub

Private Sub Command3_Click()
  Dim Archivement(5, 3) As String
  Dim name
  
  If Text4.Text = "" Or Len(Text4.Text) > 8 Then
     MsgBox ("姓名不能空 或者不能超过４个汉字！")
     Text4.SetFocus
     Exit Sub
  End If
  If Combo1.Text = "" Then
     MsgBox ("请选择地区 ！")
     Combo1.SetFocus
     Exit Sub
  End If
  '===========取输入值
  name = Trim(Text4.Text)
  person_id = Trim(Label1.Caption)
  If Option1.Value = True Then
     sex = "男"
  Else
     sex = "女"
  End If
  If Option3.Value = True Then
     party = True
  Else
     party = False
  End If
  birth = Trim(Text1) + "-" + Trim(Text2) + "-" + Trim(Text3)
  salary = Trim(Text5.Text)
  speciality = Trim(Text6.Text)
  specialityyear = Trim(Text9.Text)
  technicaltitle = Trim(Combo2.Text)
  englishlevel = Trim(Combo3.Text)
  resume_string = Trim(Text7.Text)
  
  '============================  录入信息数据  =========================
  '=================  用ADO方式打开数据库
  'MsgBox "Opening rcgl_sys...人才管理数据库"
  Sub_ConnectServer
  conODBC.BeginTrans '事物处理开始
  Set rs = New ADODB.Recordset
  rs.CursorType = adOpenDynamic
  rs.LockType = adLockOptimistic '
  'rs.Open "Select * From BTab where person_ID like '" + "bj%" + "'", conODBC, adCmdTable
  '-----------录入人才基本情况信息
  rs.Open "Select * From BTab ", conODBC, adCmdTable
  'Num_records = rs.RecordCount
  rs.MoveLast
  rs.AddNew
  rs!person_id = Trim(person_id)
  rs!name = Trim(name)
  rs!sex = sex
  rs!party = party
  rs!birth = Trim(birth)
  If salary <> "" Then
     rs!salary = Val(Trim(salary))
  End If
  If resume_string <> "" Then
     rs!resume = Trim(resume_string)
  End If
  rs!photo = (Picture4.Picture)
  rs.Update
  rs.Close
  
  '-------------------录入人才专业情况信息
  rs.Open "Select * From STab ", conODBC, adCmdTable
  rs.MoveLast
  rs.AddNew
  rs!person_id = Trim(person_id)
  If speciality <> "" Then
     rs!speciality = Trim(speciality)
  End If
  If specialityyear <> "" Then
     rs!specialityyear = Val(specialityyear)
  End If
  If technicaltitle <> "" Then
     rs!technicaltitle = Trim(technicaltitle)
  End If
  If englishlevel <> "" Then
     rs!englishlevel = Trim(englishlevel)
  End If
  rs.Update
  rs.Close
  '--------------------录入人才成果成就信息
  rs.Open "Select * From ATab ", conODBC, adCmdTable
  rs.MoveLast
  For i = 1 To Num_Archive
      rs.AddNew
      rs!person_id = Trim(person_id)
      rs!ArchivementName = Trim(Text10(i - 1).Text)
      rs!ArchivementType = Trim(Text11(i - 1).Text)
      rs!ArchivementFrom = Trim(Text12(i - 1).Text)
      rs.MoveNext
  Next
  rs.Update
  rs.Close
  conODBC.CommitTrans '事物处理结束
  id = MsgBox("入库成功！", , "提示")
   
End Sub

Private Sub Command5_Click()
   Unload Me
   
End Sub

Private Sub Form_Load()
   Num_Archive = 0
   Me.Show
End Sub
