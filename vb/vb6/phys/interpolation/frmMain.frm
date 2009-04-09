VERSION 5.00
Begin VB.Form lblY 
   Caption         =   "Interpolation"
   ClientHeight    =   1965
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   5970
   LinkTopic       =   "Form1"
   ScaleHeight     =   1965
   ScaleWidth      =   5970
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox txtY 
      Height          =   495
      Left            =   480
      TabIndex        =   4
      Text            =   "0"
      Top             =   1200
      Width           =   1215
   End
   Begin VB.CommandButton cmInterpolerY 
      Caption         =   "&Interpoler (y donné)"
      Height          =   495
      Left            =   1920
      TabIndex        =   3
      Top             =   1200
      Width           =   1935
   End
   Begin VB.CommandButton cmdInterpolerX 
      Caption         =   "&Interpoler (x donné)"
      Height          =   495
      Left            =   1920
      TabIndex        =   1
      Top             =   240
      Width           =   1935
   End
   Begin VB.TextBox txtX 
      Height          =   495
      Left            =   480
      TabIndex        =   0
      Text            =   "0"
      Top             =   240
      Width           =   1215
   End
   Begin VB.Label Label2 
      Caption         =   "y="
      Height          =   735
      Left            =   480
      TabIndex        =   7
      Top             =   960
      Width           =   495
   End
   Begin VB.Label Label1 
      Caption         =   "x="
      Height          =   495
      Left            =   480
      TabIndex        =   6
      Top             =   0
      Width           =   495
   End
   Begin VB.Label lblX 
      Height          =   495
      Left            =   4320
      TabIndex        =   5
      Top             =   1200
      Width           =   1215
   End
   Begin VB.Label lblY 
      Height          =   495
      Left            =   4320
      TabIndex        =   2
      Top             =   240
      Width           =   1215
   End
End
Attribute VB_Name = "lblY"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub cmdInterpolerX_Click()
lblY.Caption = CStr(linear_interpolation_gety(CDbl(txtX.Text)))
End Sub

Private Sub cmInterpolerY_Click()
lblX.Caption = CStr(linear_interpolation_getx(CDbl(txtY.Text)))
End Sub
