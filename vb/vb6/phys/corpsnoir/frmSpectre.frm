VERSION 5.00
Begin VB.Form frmSpectre 
   Caption         =   "Form1"
   ClientHeight    =   7470
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   11220
   LinkTopic       =   "Form1"
   ScaleHeight     =   7470
   ScaleWidth      =   11220
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdTracer 
      Caption         =   "Tracer"
      Height          =   615
      Left            =   8640
      TabIndex        =   3
      Top             =   1680
      Width           =   1935
   End
   Begin VB.TextBox txtT 
      Height          =   615
      Left            =   8640
      TabIndex        =   1
      Text            =   "10000"
      Top             =   600
      Width           =   1935
   End
   Begin VB.PictureBox Picture1 
      BackColor       =   &H00FFFFFF&
      Height          =   6735
      Left            =   240
      ScaleHeight     =   6675
      ScaleWidth      =   7515
      TabIndex        =   0
      Top             =   240
      Width           =   7575
   End
   Begin VB.Label Label1 
      Caption         =   "T"
      Height          =   495
      Left            =   8640
      TabIndex        =   2
      Top             =   120
      Width           =   1935
   End
End
Attribute VB_Name = "frmSpectre"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Const pi As Double = 3.1416
Const h As Double = 6.6256E-34
Const c0 As Double = 299790000#
Const kB As Double = 1.3807E-23
Const e As Double = 2.71828

Public Function Elambda(ByVal lambda As Double, ByVal T As Double)
' calcule la densite d'energie associee a un corps noir
' qui est porte a une temperature T
'   lambda   longueur d'onde [m]  (vecteur)
'   T   temperature [K] (scalaire)
'   E   intensite
    Elambda = 8 * pi * h * c0 / (lambda ^ 5) / (e ^ (h * c0 / (kB * T * lambda)) - 1)
    ' ToFix pb de dépassement
End Function

Private Sub cmdTracer_Click()
    Dim lambda As Double
    Const lambda_min As Double = 0.00000001
    Const lambda_max As Double = 0.000002
    Const lambda_step As Double = 0.00000001
    
    Dim T As Double
    Dim i As Integer
    
    T = txtT.Text

    Picture1.ScaleMode = 0  'Mode utilisateur
    Picture1.ScaleWidth = 0.000002 'Axe X vers la droite
    Picture1.ScaleLeft = 0 'Origine de l'axe des  ordonnées (X=0 à gauche)
    Picture1.ScaleHeight = -20000000# 'Axe Y vers le haut (signe -)
    Picture1.ScaleTop = 20000000# 'Origine de l'axe des abscisses (Y=5 milieu de zone)
    Picture1.DrawWidth = 1 'Epaisseur des traits et points
    Picture1.ForeColor = vbRed  'couleur des traits et points

    'Picture1.Line (0, 0)-(0.000002, 20000000#)
    'For lambda = 0.0000000001 To 0.000002 Step 0.00000001
    For lambda = lambda_min To lambda_max Step lambda_step
        i = i + 1
        'Picture1.PSet (lambda, Elambda(lambda, T))
        Picture1.Line (lambda, Elambda(lambda, T))-(lambda + lambda_step, Elambda(lambda + lambda_step, T))
    Next lambda
End Sub
