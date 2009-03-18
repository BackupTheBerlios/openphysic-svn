VERSION 5.00
Begin VB.UserControl ctlCuve 
   ClientHeight    =   3600
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   3495
   ScaleHeight     =   3600
   ScaleWidth      =   3495
   Begin VB.PictureBox Picture1 
      Height          =   495
      Left            =   0
      ScaleHeight     =   435
      ScaleWidth      =   1155
      TabIndex        =   0
      Top             =   0
      Width           =   1215
   End
End
Attribute VB_Name = "ctlCuve"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
' Tank user control
' =================

' Contrôle utilisateur représentant une cuve contenant un liquide

' Sébastien CELLES
' IUT de Poitiers
' Département Génie Thermique et Energie
' s.celles at gmail.com


' Propriétés
'  Level (en lecture/écriture) : niveau de la cuve (S=1m^2)

' Evènements
'  LevelChanged : changement de la valeur à l'entrée du procédé

Option Explicit

Dim m_color As Long ' couleur liquide

Dim m_level As Double ' niveau liquide
Dim m_level_min As Double ' niveau min (0)
Dim m_level_max As Double ' niveau max


Public Event LevelChanged() ' changement de niveau


Private Sub UserControl_Initialize()
m_level_min = 0#
m_level_max = 1#
m_level = 0

m_color = vbBlue
End Sub

Private Sub UserControl_Resize()
Picture1.Width = UserControl.Width
Picture1.Height = UserControl.Height

UserControl_InitializePictureBox
End Sub

Private Sub UserControl_InitializePictureBox()
Picture1.ScaleMode = 0
Picture1.ScaleWidth = 1
Picture1.ScaleLeft = 0
Picture1.ScaleHeight = -(m_level_max - m_level_min)
Picture1.ScaleTop = m_level_max
End Sub


Private Sub Picture1_Paint()

Picture1.Cls

'Picture1.Line (0, m_level_min)-(1, m_level_max)

Picture1.ForeColor = m_color
Picture1.FillStyle = 0
Picture1.FillColor = m_color

Picture1.Line (0, 0)-(1, m_level), , B

End Sub

Public Property Get Level() As Double
Level = m_level
End Property

Public Property Let Level(ByVal new_level As Double)
m_level = new_level
RaiseEvent LevelChanged
Picture1_Paint
End Property

