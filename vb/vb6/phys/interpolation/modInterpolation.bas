Attribute VB_Name = "modInterpolation"
Option Explicit

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

