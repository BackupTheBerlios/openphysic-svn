VERSION 5.00
Begin VB.UserControl ctlThermometer 
   ClientHeight    =   3600
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   255
   ScaleHeight     =   3600
   ScaleWidth      =   255
End
Attribute VB_Name = "ctlThermometer"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Dim m_color As Long

Dim m_t_min As Double
Dim m_t_max As Double
Dim m_t As Double

Private Sub UserControl_Initialize()
m_color = vbRed

m_t_min = 0
m_t_max = 100
m_t = 75

BackColor = &H909090 'vbWhite
End Sub

Private Sub UserControl_Paint()
Cls


'Line (0, 0)-(1, 1)

Line (0, 0)-(1, m_t / (m_t_max - m_t_min)), , B

ForeColor = m_color
FillStyle = 0
FillColor = m_color
Line (0, 0)-(1, m_t / (m_t_max - m_t_min)), , B

End Sub

Private Sub UserControl_Resize()
UserControl.ScaleMode = 0
UserControl.ScaleWidth = 1
UserControl.ScaleLeft = 0
UserControl.ScaleHeight = -1
UserControl.ScaleTop = 1
End Sub
