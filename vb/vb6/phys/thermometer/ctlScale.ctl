VERSION 5.00
Begin VB.UserControl ctlScale 
   ClientHeight    =   3855
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   6195
   ScaleHeight     =   3855
   ScaleWidth      =   6195
End
Attribute VB_Name = "ctlScale"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Dim m_min As Double
Dim m_max As Double

Enum ScaleDirection
Normal
Inverted
End Enum
Dim m_inverted As Boolean

Enum ScaleType
Linear
Log
End Enum
Dim m_scaletype As ScaleType

Dim m_major_tick_color As Long
Dim m_minor_tick_color As Long
Dim m_text_color As Long

Enum Direction
HorizontalTop
HorizontalBottom
VerticalLeft
VerticalRight
End Enum
Dim m_direction As Direction

Enum TickType
MinMax
Major
MajorAndMinor
End Enum
Dim m_ticktype As TickType

Enum TextType
MinMax
Major
End Enum
Dim m_texttype As TextType

Private Sub UserControl_Initialize()
m_min = 0
m_max = 100

m_major_tick_color = vbBlack
m_minor_tick_color = vbBlack
m_text_color = vbBlack

m_scaletype = ScaleType.Linear
m_inverted = ScaleDirection.Normal
m_direction = HorizontalTop
m_ticktype = MajorAndMinor
m_texttype = Major
End Sub

Private Sub UserControl_Paint()
'Line (0, 0)-(Width, Height) ' diag

If m_direction = HorizontalTop Then
'Debug.Print "ok"
ScaleMode = 0
ScaleWidth = m_max - m_min
ScaleLeft = -m_min
ScaleHeight = Height
ScaleTop = 0
Line (m_min, 0)-(m_max, 0)
End If
End Sub
