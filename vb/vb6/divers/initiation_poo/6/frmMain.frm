VERSION 5.00
Begin VB.Form frmMain 
   BackColor       =   &H8000000E&
   Caption         =   "Form1"
   ClientHeight    =   4275
   ClientLeft      =   120
   ClientTop       =   420
   ClientWidth     =   6780
   LinkTopic       =   "Form1"
   ScaleHeight     =   4275
   ScaleWidth      =   6780
   StartUpPosition =   3  'Windows Default
   Begin POO.Bouton Bouton1 
      Height          =   975
      Left            =   720
      TabIndex        =   1
      Top             =   480
      Width           =   975
      _extentx        =   1720
      _extenty        =   1720
   End
   Begin VB.CheckBox chkEtatBouton 
      Caption         =   "Etat du bouton"
      Height          =   495
      Left            =   3720
      TabIndex        =   0
      Top             =   360
      Width           =   1215
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Bouton1_ChangementEtat()
If Bouton1.Etat Then
    chkEtatLed.Value = 1
Else
    chkEtatLed.Value = 0
End If
End Sub

Private Sub Form_Load()

End Sub

