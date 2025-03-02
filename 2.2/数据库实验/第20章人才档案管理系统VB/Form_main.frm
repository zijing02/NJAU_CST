VERSION 5.00
Begin VB.Form Form_main 
   Caption         =   "专门人才档案管理系统"
   ClientHeight    =   6450
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   12960
   LinkTopic       =   "Form1"
   ScaleHeight     =   6450
   ScaleWidth      =   12960
   WindowState     =   2  'Maximized
   Begin VB.PictureBox Picture1 
      Height          =   495
      Left            =   0
      ScaleHeight     =   435
      ScaleWidth      =   15435
      TabIndex        =   0
      Top             =   -360
      Width           =   15500
   End
   Begin VB.Label Label5 
      AutoSize        =   -1  'True
      Caption         =   "2005年1月"
      BeginProperty Font 
         Name            =   "楷体_GB2312"
         Size            =   15
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000000&
      Height          =   300
      Left            =   6840
      TabIndex        =   5
      Top             =   6000
      Width           =   1350
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "人才档案信息管理系统"
      BeginProperty Font 
         Name            =   "隶书"
         Size            =   42
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   840
      Left            =   3315
      TabIndex        =   4
      Top             =   1980
      Width           =   8415
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "人才档案信息管理系统"
      BeginProperty Font 
         Name            =   "隶书"
         Size            =   42
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00008080&
      Height          =   840
      Left            =   3360
      TabIndex        =   3
      Top             =   1920
      Width           =   8415
   End
   Begin VB.Label Label3 
      Alignment       =   2  'Center
      Caption         =   "版本    V 1.0"
      BeginProperty Font 
         Name            =   "幼圆"
         Size            =   15
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   300
      Left            =   6510
      TabIndex        =   2
      Top             =   3720
      Width           =   2145
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "编制  江南大学太湖学院    计算机系"
      BeginProperty Font 
         Name            =   "楷体_GB2312"
         Size            =   15
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00800000&
      Height          =   300
      Left            =   5160
      TabIndex        =   1
      Top             =   4800
      Width           =   5100
   End
   Begin VB.Menu Set_system 
      Caption         =   "   系统&S"
      NegotiatePosition=   2  'Middle
      Begin VB.Menu Set_NameUser 
         Caption         =   "设置用户帐号"
      End
      Begin VB.Menu Query_Nameuser 
         Caption         =   "查询用户帐号"
      End
      Begin VB.Menu x6 
         Caption         =   "-"
      End
      Begin VB.Menu Set_AreaNo_menu 
         Caption         =   "设置地区编号"
      End
      Begin VB.Menu Query_AreaNo_Menu 
         Caption         =   "查询地区编号"
      End
      Begin VB.Menu x9 
         Caption         =   "-"
      End
   End
   Begin VB.Menu Query 
      Caption         =   "   查询&Q"
      Begin VB.Menu ViewAll 
         Caption         =   "浏览"
         Shortcut        =   ^V
      End
      Begin VB.Menu x1 
         Caption         =   "-"
      End
      Begin VB.Menu ByName 
         Caption         =   "按姓名"
      End
      Begin VB.Menu ByNumber 
         Caption         =   "按编号"
      End
      Begin VB.Menu ByTechnicalityTitle 
         Caption         =   "按职称"
      End
      Begin VB.Menu x2 
         Caption         =   "-"
      End
      Begin VB.Menu ByArea 
         Caption         =   "按地区"
      End
      Begin VB.Menu x5 
         Caption         =   "-"
      End
      Begin VB.Menu MoreSelect 
         Caption         =   "复合条件"
      End
   End
   Begin VB.Menu Manager 
      Caption         =   "   管理&M"
      Begin VB.Menu In_information 
         Caption         =   "登记"
      End
      Begin VB.Menu x3 
         Caption         =   "-"
      End
      Begin VB.Menu Modify 
         Caption         =   "修改"
      End
      Begin VB.Menu x4 
         Caption         =   "-"
      End
      Begin VB.Menu Delele 
         Caption         =   "删除"
      End
   End
   Begin VB.Menu Tool 
      Caption         =   "   工具&T"
      Begin VB.Menu Statistic 
         Caption         =   "统计"
      End
      Begin VB.Menu x7 
         Caption         =   "-"
      End
      Begin VB.Menu Report 
         Caption         =   "报表"
      End
   End
   Begin VB.Menu Help 
      Caption         =   "   帮助&H"
      Begin VB.Menu Notes_Option 
         Caption         =   "操作说明"
      End
      Begin VB.Menu x8 
         Caption         =   "-"
      End
      Begin VB.Menu About 
         Caption         =   "关于"
      End
   End
   Begin VB.Menu Quit 
      Caption         =   "   退出&U"
   End
End
Attribute VB_Name = "Form_main"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub ByName_Click()
  Load Query_ByName_1
End Sub

Private Sub Form_Load()
   Me.Show
End Sub

Private Sub In_information_Click()
  Load input_form
End Sub


Private Sub Modify_Click()
   Load Update_Form_1
   
End Sub

Private Sub MoreSelect_Click()
  Load Query_Info_MoreCondition
End Sub

Private Sub Query_AreaNo_Menu_Click()
    Load Query_AreaNo
End Sub

Private Sub Quit_Click()
  Unload Me
End Sub


Private Sub Set_AreaNo_menu_Click()
   Load Set_AreaNo
End Sub

Private Sub ViewAll_Click()
   Load view_all
End Sub
