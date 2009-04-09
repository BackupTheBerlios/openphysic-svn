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

Dim xval() As Double
Dim yval() As Double

Public Function linear_interpolation_gety(ByVal x As Double) As Double
Dim xa, xb, ya, yb As Double
xa = 0
ya = 1
xb = 1
yb = 2
linear_interpolation_gety = linear_interpolation(x, xa, ya, xb, yb)
End Function

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


