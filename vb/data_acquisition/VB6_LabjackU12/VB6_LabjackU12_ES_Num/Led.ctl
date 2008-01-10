VERSION 5.00
Begin VB.UserControl Led 
   ClientHeight    =   3600
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   4800
   ScaleHeight     =   3600
   ScaleWidth      =   4800
   Begin VB.Shape shaLed 
      BackColor       =   &H00004080&
      BackStyle       =   1  'Opaque
      Height          =   255
      Left            =   0
      Shape           =   3  'Circle
      Top             =   0
      Width           =   255
   End
End
Attribute VB_Name = "Led"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
' Diode électroluminescente DEL
' =============================

' Méthodes
'  allumer : allume la LED
'  éteindre : éteint la LED
'  inverser : inverse l'état de la LED

' Propriétés
'  ColorON : couleur lorsque la LED est allumée
'  ColorOFF : couleur lorsque la LED est éteinte

' ToDo : Color = ColorON et calcul automatique de ColorOFF

Option Explicit

Dim m_ColorON As ColorConstants
Dim m_ColorOFF As ColorConstants

Dim m_Etat As Boolean ' True=allumée False=éteinte

Private Sub UserControl_Initialize()
    'ColorOFF = &H4080& ' rouge foncé
    'ColorON = &HFF& ' rouge clair
    
    'ColorOFF = &H8000& ' vert foncé
    'ColorON = &HFF00& ' vert clair
    
    éteindre ' DEL initialement éteinte
    'allumer ' DEL initialement allumée
    
    afficher
End Sub


Public Property Let ColorON(color As ColorConstants)
    m_ColorON = color
End Property

Public Property Get ColorON() As ColorConstants
    ColorON = m_ColorON
End Property

Public Property Let ColorOFF(color As ColorConstants)
    m_ColorOFF = color
End Property

Public Property Get ColorOFF() As ColorConstants
    ColorOFF = m_ColorOFF
End Property

Public Sub allumer()
    m_Etat = True
    
    afficher
End Sub

Public Sub éteindre()
    m_Etat = False
    
    afficher
End Sub

Public Sub inverser()
    m_Etat = Not m_Etat
    
    afficher
End Sub

Private Sub UserControl_Resize()
    shaLed.Width = Width
    shaLed.Height = Height
End Sub

Private Sub afficher()
    If m_Etat Then
        shaLed.BackColor = m_ColorON
    Else
        shaLed.BackColor = m_ColorOFF
    End If
End Sub
