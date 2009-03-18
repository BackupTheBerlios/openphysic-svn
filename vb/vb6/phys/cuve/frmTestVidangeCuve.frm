VERSION 5.00
Begin VB.Form frmTestVidangeCuve 
   Caption         =   "Test cuve vidangeable"
   ClientHeight    =   6180
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   5895
   LinkTopic       =   "Form1"
   ScaleHeight     =   6180
   ScaleWidth      =   5895
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdTest 
      Caption         =   "Tester"
      Height          =   495
      Left            =   3120
      TabIndex        =   7
      Top             =   4440
      Width           =   1215
   End
   Begin VB.TextBox txtKv 
      Height          =   495
      Left            =   480
      TabIndex        =   4
      Text            =   "0,5"
      Top             =   4560
      Width           =   1215
   End
   Begin VB.TextBox txtQin 
      Height          =   495
      Left            =   480
      TabIndex        =   3
      Text            =   "0,05"
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
      Height          =   2295
      Left            =   2400
      TabIndex        =   0
      Top             =   1800
      Width           =   3015
      _ExtentX        =   5318
      _ExtentY        =   4048
   End
   Begin VB.Label lblTest 
      Height          =   495
      Left            =   2760
      TabIndex        =   8
      Top             =   5040
      Width           =   1935
   End
   Begin VB.Label Label2 
      Caption         =   "Vanne vidange Kv=0 (fermée) ... 1 (ouverte)"
      Height          =   615
      Left            =   480
      TabIndex        =   6
      Top             =   3840
      Width           =   1095
   End
   Begin VB.Label Label1 
      Caption         =   "Qin Débit volumique entrant (m^3/s)"
      Height          =   375
      Left            =   480
      TabIndex        =   5
      Top             =   600
      Width           =   1455
   End
End
Attribute VB_Name = "frmTestVidangeCuve"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub chkRemplir_Click()
If chkRemplir.Value = 0 Then
    ctlCuveVidangeable1.Qin = 0
Else
    txtQin_Change
End If
End Sub

Private Sub chkVider_Click()
If chkVider.Value = 0 Then
    ctlCuveVidangeable1.Kv = 0
Else
    txtKv_Change
End If
End Sub

Private Sub cmdTest_Click()
'lblTest.Caption = ctlCuveVidangeable1.Level
'lblTest.Caption = ctlCuveVidangeable1.Kv
lblTest.Caption = ctlCuveVidangeable1.Qout
End Sub

Private Sub Form_Load()
chkRemplir_Click
chkVider_Click
End Sub

Private Sub Label1_Click()

End Sub

Private Sub txtKv_Change()
ctlCuveVidangeable1.Kv = CDbl(txtKv.Text)
End Sub

Private Sub txtQin_Change()
ctlCuveVidangeable1.Qin = CDbl(txtQin.Text)
End Sub
