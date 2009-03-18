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
   Begin VB.TextBox txtQout 
      Height          =   495
      Left            =   2160
      TabIndex        =   4
      Text            =   "0"
      Top             =   3480
      Width           =   1215
   End
   Begin VB.TextBox txtQin 
      Height          =   495
      Left            =   480
      TabIndex        =   3
      Text            =   "0"
      Top             =   3480
      Width           =   1215
   End
   Begin VB.CheckBox chkVider 
      Caption         =   "Vider"
      Height          =   495
      Left            =   2160
      TabIndex        =   2
      Top             =   3960
      Width           =   1215
   End
   Begin VB.CheckBox chkRemplir 
      Caption         =   "Remplir"
      Height          =   495
      Left            =   480
      TabIndex        =   1
      Top             =   3960
      Width           =   1215
   End
   Begin TestVidangeCuve.ctlCuveVidangeable ctlCuveVidangeable1 
      Height          =   2415
      Left            =   1320
      TabIndex        =   0
      Top             =   480
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
Option Explicit

Private Sub chkRemplir_Click()
If chkRemplir.Value = False Then
    ctlCuveVidangeable1.Qin = 0
Else
    ctlCuveVidangeable1.Qin = CDbl(txtQin.Text)
End If
End Sub

Private Sub ctlCuveVidangeable1_GotFocus()
If chkRemplir.Value = False Then
    ctlCuveVidangeable1.Qout = 0
Else
    ctlCuveVidangeable1.Qout = CDbl(txtQout.Text)
End If
End Sub
