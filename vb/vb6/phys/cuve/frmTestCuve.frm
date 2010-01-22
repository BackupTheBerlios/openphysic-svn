VERSION 5.00
Begin VB.Form frmTestCuve 
   Caption         =   "Test cuve"
   ClientHeight    =   6645
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8430
   LinkTopic       =   "Form1"
   ScaleHeight     =   6645
   ScaleWidth      =   8430
   StartUpPosition =   3  'Windows Default
   Begin TestCuve.ctlCuve ctlCuve1 
      Height          =   3615
      Left            =   4920
      TabIndex        =   4
      Top             =   240
      Width           =   2295
      _ExtentX        =   4048
      _ExtentY        =   6376
   End
   Begin VB.TextBox txtLevel 
      Height          =   495
      Left            =   1920
      TabIndex        =   2
      Text            =   "0"
      Top             =   1200
      Width           =   1215
   End
   Begin VB.CommandButton cmdTester 
      Caption         =   "Test"
      Height          =   495
      Left            =   1920
      TabIndex        =   0
      Top             =   1920
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "Niveau de la cuve (de 0 à 1m)"
      Height          =   495
      Left            =   1920
      TabIndex        =   3
      Top             =   720
      Width           =   1215
   End
   Begin VB.Label lblLevel 
      Height          =   495
      Left            =   1920
      TabIndex        =   1
      Top             =   2640
      Width           =   1215
   End
End
Attribute VB_Name = "frmTestCuve"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit


Private Sub cmdTester_Click()
ctlCuve1.Level = CDbl(txtLevel.Text)
lblLevel.Caption = ctlCuve1.Level
End Sub

