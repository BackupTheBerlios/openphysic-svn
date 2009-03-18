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
   Begin VB.TextBox txtKv 
      Height          =   495
      Left            =   480
      TabIndex        =   4
      Text            =   "0"
      Top             =   4560
      Width           =   1215
   End
   Begin VB.TextBox txtQin 
      Height          =   495
      Left            =   480
      TabIndex        =   3
      Text            =   "0"
      Top             =   1080
      Width           =   1215
   End
   Begin VB.CheckBox chkVider 
      Caption         =   "Vider"
      Height          =   495
      Left            =   480
      TabIndex        =   2
      Top             =   5040
      Width           =   1215
   End
   Begin VB.CheckBox chkRemplir 
      Caption         =   "Remplir"
      Height          =   495
      Left            =   480
      TabIndex        =   1
      Top             =   1560
      Width           =   1215
   End
   Begin TestVidangeCuve.ctlCuveVidangeable ctlCuveVidangeable1 
      Height          =   2415
      Left            =   2400
      TabIndex        =   0
      Top             =   1800
      Width           =   1335
      _extentx        =   2355
      _extenty        =   4260
   End
   Begin VB.Label Label2 
      Caption         =   "Vanne vidange Kv=0..1"
      Height          =   375
      Left            =   480
      TabIndex        =   6
      Top             =   4080
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "Débit volumique entrant"
      Height          =   375
      Left            =   480
      TabIndex        =   5
      Top             =   600
      Width           =   1215
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

Private Sub chkVider_Click()
If chkRemplir.Value = False Then
    ctlCuveVidangeable1.Kv = 0
Else
    ctlCuveVidangeable1.Kv = CDbl(txtKv.Text)
End If
End Sub

Private Sub Form_Load()
chkRemplir_Click
chkVider_Click
End Sub
