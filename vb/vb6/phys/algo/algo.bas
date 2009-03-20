Attribute VB_Name = "modAlgo"
Option Explicit

Public Function max(ByRef t() As Double) As Double
Dim i As Integer
Dim nmax As Double
nmax = t(1)
For i = LBound(t) To UBound(t)
    If t(i) >= nmax Then
        nmax = t(i)
    End If
Next i
max = nmax
End Function

Public Function min(ByRef t() As Double) As Double
Dim i As Integer
Dim nmin As Double
nmin = t(1)
For i = LBound(t) To UBound(t)
    If t(i) <= nmin Then
        nmin = t(i)
    End If
Next i
min = nmin
End Function


Public Function sum(ByRef t() As Double) As Double
Dim i As Integer
sum = 0
For i = LBound(t) To UBound(t)
    sum = sum + t(i)
Next i
End Function

Public Function mean(ByRef t() As Double) As Double
mean = sum(t()) / (UBound(t) + 1)
End Function

'Public Function add(ByRef t1() As Double, ByRef t2() As Double) As Double()
'add =
'End Function

'Public Function substract(ByRef t1() As Double, ByRef t2() As Double) As Double()
'End Function

'Public Function multiply(ByRef t1() As Double, ByRef t2() As Double) As Double()
'End Function

'Public Function divide(ByRef t1() As Double, ByRef t2() As Double) As Double()
'End Function


'Public Function power(ByRef t() As Double) As Double
'mean = sum(t()) / (UBound(t) + 1)
'End Function

'Public Function square()
'End Function

' rms (root mean square)
'Public Function rms(ByRef t() As Double, ByVal s As Integer) As Double

'End Function

' fft

