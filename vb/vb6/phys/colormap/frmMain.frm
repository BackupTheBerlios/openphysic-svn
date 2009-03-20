VERSION 5.00
Begin VB.Form frmMain 
   Caption         =   "Test ColorMap"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   3480
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   3480
   StartUpPosition =   3  'Windows Default
   Begin VB.PictureBox Picture1 
      Height          =   2655
      Left            =   1320
      ScaleHeight     =   2595
      ScaleWidth      =   675
      TabIndex        =   0
      Top             =   240
      Width           =   735
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim colormap As clsColorMap

Private Sub Form_Load()
Picture1.ScaleMode = 0
Picture1.ScaleWidth = 1
Picture1.ScaleLeft = 0
Picture1.ScaleHeight = -1
Picture1.ScaleTop = 1

Set colormap = New clsColorMap
End Sub

Private Sub Picture1_Paint()
'Picture1.Line (0, 0)-(1, 1)

'colormap.colorAt(0,vbWhite)
'colormap.colorAt(1.,vbWhite)

Picture1.DrawWidth = 1

Dim x As Double
Const pas As Double = 0.001
For x = 0 To 1 + pas Step pas
    Picture1.ForeColor = colormap.colorAt(x)
    Picture1.Line (0, x)-(1, x)
    'Debug.Print x
Next x

End Sub
