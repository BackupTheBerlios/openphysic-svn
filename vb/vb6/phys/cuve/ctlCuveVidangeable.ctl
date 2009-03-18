VERSION 5.00
Begin VB.UserControl ctlCuveVidangeable 
   ClientHeight    =   2430
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   1230
   ScaleHeight     =   2430
   ScaleWidth      =   1230
   Begin TestVidangeCuve.ctlCuve ctlCuve1 
      Height          =   2295
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   1095
      _ExtentX        =   1931
      _ExtentY        =   4048
   End
End
Attribute VB_Name = "ctlCuveVidangeable"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Sub UserControl_Initialize()
ctlCuve1.Level = 0.8
End Sub

Private Sub UserControl_Resize()
ctlCuve1.Width = UserControl.Width
ctlCuve1.Height = UserControl.Height
End Sub
