VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsInterpolation"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Enum InterpolationMode
Linear
End Enum

Dim m_interpolation_mode As InterpolationMode

Dim m_x() As Double
Dim m_y() As Double
Dim m_size As Integer

Private Sub Class_Initialize()
m_size = 0
m_interpolation_mode = InterpolationMode.Linear
End Sub

Public Function linear_interpolation_gety(ByVal x As Double) As Double
Dim xa, xb, ya, yb As Double
xa = 0
ya = 1
xb = 1
yb = 2
linear_interpolation_gety = linear_interpolation(x, xa, ya, xb, yb)
End Function

Public Property Let add_values(ByVal x As Double, ByVal y As Double)
m_size = m_size + 1

ReDim Preserve m_x(0 To m_size - 1)
ReDim Preserve m_y(0 To m_size - 1)

m_x(m_size - 1) = x
m_y(m_size - 1) = y
End Property

Public Function linear_interpolation_getx(ByVal y As Double) As Double
Dim xa, xb, ya, yb As Double
xa = 0
ya = 1
xb = 1
yb = 2
linear_interpolation_getx = linear_interpolation(y, ya, xa, yb, xb)
End Function


Public Function linear_interpolation(ByVal x As Double, ByVal xa As Double, ByVal ya As Double, ByVal xb As Double, ByVal yb As Double) As Double
linear_interpolation = (yb - ya) / (xb - xa) * (x - xa) + ya
End Function

Public Sub Test()
Debug.Print "Test"
Dim i As Integer
For i = 0 To m_size - 1
    Debug.Print m_x(i) & " " & m_y(i)
Next i
End Sub


