VERSION 5.00
Begin VB.Form frmTestVidangeCuve 
   Caption         =   "Test cuve vidangeable"
   ClientHeight    =   6180
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7290
   LinkTopic       =   "Form1"
   ScaleHeight     =   6180
   ScaleWidth      =   7290
   StartUpPosition =   3  'Windows Default
   Begin VB.CheckBox chkVider 
      Caption         =   "Vider"
      Height          =   495
      Left            =   2040
      TabIndex        =   2
      Top             =   2880
      Width           =   1215
   End
   Begin VB.CheckBox chkRemplir 
      Caption         =   "Remplir"
      Height          =   495
      Left            =   600
      TabIndex        =   1
      Top             =   2880
      Width           =   1215
   End
   Begin VB.Timer Timer1 
      Left            =   4440
      Top             =   3840
   End
   Begin TestVidangeCuve.ctlCuveVidangeable ctlCuveVidangeable1 
      Height          =   2415
      Left            =   5040
      TabIndex        =   0
      Top             =   840
      Width           =   1335
      _ExtentX        =   2355
      _ExtentY        =   4260
   End
End
Attribute VB_Name = "frmTestVidangeCuve"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
