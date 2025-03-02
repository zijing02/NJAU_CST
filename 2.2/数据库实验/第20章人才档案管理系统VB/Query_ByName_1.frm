VERSION 5.00
Begin VB.Form Query_ByName_1 
   Caption         =   "信息检索"
   ClientHeight    =   4440
   ClientLeft      =   3480
   ClientTop       =   3585
   ClientWidth     =   8265
   LinkTopic       =   "Form1"
   ScaleHeight     =   4440
   ScaleWidth      =   8265
   Begin VB.CommandButton Command2 
      Caption         =   "退出"
      Height          =   375
      Left            =   4680
      TabIndex        =   5
      Top             =   3600
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "确定"
      Height          =   375
      Left            =   2280
      TabIndex        =   4
      Top             =   3600
      Width           =   1215
   End
   Begin VB.PictureBox Picture1 
      Height          =   1815
      Left            =   1440
      ScaleHeight     =   1755
      ScaleWidth      =   5355
      TabIndex        =   0
      Top             =   1080
      Width           =   5415
      Begin VB.TextBox ByName_Text 
         Height          =   375
         Left            =   960
         TabIndex        =   3
         Top             =   360
         Width           =   3015
      End
      Begin VB.Label Label2 
         Caption         =   "姓名"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   12
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   300
         Left            =   480
         TabIndex        =   2
         Top             =   400
         Width           =   615
      End
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "信息检索"
      BeginProperty Font 
         Name            =   "楷体_GB2312"
         Size            =   21.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   495
      Left            =   2520
      TabIndex        =   1
      Top             =   600
      Width           =   3255
   End
End
Attribute VB_Name = "Query_ByName_1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
  ByName = ByName_Text.Text
  Unload Me
  Load Query_ByName_2
  
End Sub

Private Sub Command2_Click()
  Unload Me
End Sub

Private Sub Form_Load()
   Me.Show
End Sub
