VERSION 5.00
Begin VB.Form frmMain 
   Caption         =   "Algo"
   ClientHeight    =   2415
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8295
   LinkTopic       =   "Form1"
   ScaleHeight     =   2415
   ScaleWidth      =   8295
   StartUpPosition =   3  'Windows Default
   Begin VB.ListBox List3 
      Height          =   2205
      Left            =   5880
      TabIndex        =   3
      Top             =   120
      Width           =   2295
   End
   Begin VB.ListBox List2 
      Height          =   2205
      Left            =   3480
      TabIndex        =   2
      Top             =   120
      Width           =   2295
   End
   Begin VB.CommandButton cmdDo 
      Caption         =   "Calculer"
      Height          =   2175
      Left            =   2520
      TabIndex        =   1
      Top             =   120
      Width           =   855
   End
   Begin VB.ListBox List1 
      Height          =   2205
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   2295
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim tabl() As Double
Const N As Integer = 20

Private Sub Form_Load()
List1.Clear
List2.Clear
List3.Clear

Randomize

ReDim tabl(N)

Dim i As Integer
Dim val As Double
For i = 1 To N
    val = Rnd
    List1.AddItem val
Next i
End Sub

Private Sub cmdDo_Click()
List3.AddItem "Max=" & max(tabl, N)
'List3.AddItem "Min=" & min(tabl, N)
'List3.AddItem "Moy=" & mean(tabl, N)
End Sub

Public Function max(ByRef tabl, ByVal s As Double) As Double
Dim i As Integer
Dim nmax As Double
nmax = tabl(1)
For i = 1 To N
    If tabl(i) >= nmax Then
        Debug.Print tabl(i)
        nmax = tabl(i)
    End If
Next i
max = nmax
End Function

Public Function min(ByRef tabl() As Double, ByVal s As Double) As Double
Dim i As Integer
Dim nmin As Double
nmin = tabl(1)
For i = 1 To N
    If tabl(i) <= nmin Then
        nmin = tabl(i)
    End If
Next i
min = nmin
End Function


Public Function mean(ByRef tabl, ByVal s As Double) As Double

End Function
