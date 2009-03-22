VERSION 5.00
Begin VB.Form frmTestFit 
   Caption         =   "Test fitting"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
End
Attribute VB_Name = "frmTestFit"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim x(0 To 2) As Double
Dim y(0 To 2) As Double

Private Sub Form_Load()
x(0) = 0
y(0) = 1
x(1) = 1
y(1) = 2
x(2) = 2
y(2) = 3.01

Dim a As Double
Dim b As Double
Dim r As Double
a = 0
b = 0
linear_fit x, y, a, b, r

Debug.Print "y=" & a & "*x+" & b & " ; " & "r=" & r
End Sub
