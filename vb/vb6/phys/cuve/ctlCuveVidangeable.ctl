VERSION 5.00
Begin VB.UserControl ctlCuveVidangeable 
   ClientHeight    =   2430
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   3975
   ScaleHeight     =   2430
   ScaleWidth      =   3975
   Begin VB.Timer Timer1 
      Left            =   0
      Top             =   960
   End
   Begin TestVidangeCuve.ctlCuve ctlCuve1 
      Height          =   2295
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   1095
      _extentx        =   1931
      _extenty        =   4048
   End
   Begin VB.Label lblTout 
      Caption         =   "Tout"
      Height          =   495
      Left            =   1320
      TabIndex        =   6
      Top             =   2040
      Width           =   2415
   End
   Begin VB.Label lblTemp 
      Caption         =   "T"
      Height          =   495
      Left            =   1320
      TabIndex        =   5
      Top             =   1200
      Width           =   2415
   End
   Begin VB.Label lblTin 
      Caption         =   "Tin"
      Height          =   495
      Left            =   1320
      TabIndex        =   4
      Top             =   240
      Width           =   2415
   End
   Begin VB.Label lblLevel 
      Caption         =   "level"
      Height          =   495
      Left            =   1320
      TabIndex        =   3
      Top             =   960
      Width           =   2415
   End
   Begin VB.Label lblQout 
      Caption         =   "Qout"
      Height          =   495
      Left            =   1320
      TabIndex        =   2
      Top             =   1800
      Width           =   2415
   End
   Begin VB.Label lblQin 
      Caption         =   "Qin"
      Height          =   495
      Left            =   1320
      TabIndex        =   1
      Top             =   0
      Width           =   2415
   End
End
Attribute VB_Name = "ctlCuveVidangeable"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
' Simulateur de cuve
' ==================

' Contrôle utilisateur simulant une cuve contenant un liquide
' ce contrôle simule la variation du niveau dans la cuve
' lorsqu'on la remplit ou lorsqu'on la vidange

' Sébastien CELLES
' IUT de Poitiers
' Département Génie Thermique et Energie
' s.celles at gmail.com


' Propriétés
'  Level (en lecture seule) : niveau de la cuve (S=1m^2)
'  Qin (en lecture/écriture) : débit volumique entrant (en m^3/s)
'  Kv (en lecture/écriture) : coefficient de la vanne de vidange (0..1)
'  Qout (en lecture seule) : débit volumique sortant (en m^3/s)

Option Explicit

Const delta_t As Double = 100  ' ms

Const G As Double = 9.81
Const rho As Double = 1000 ' kg/m^3
Const S As Double = 1 ' m^2

Dim m_qvin As Double
Dim m_Kv As Double

Dim m_qvout As Double

Dim m_m As Double ' masse

Dim m_Tin As Double

Dim m_cp As Double

Dim m_e As Double ' energie

Private Sub UserControl_Initialize()
ctlCuve1.Level = 0.8
m_m = (ctlCuve1.Level * ctlCuve1.Surface) * rho

Timer1.Interval = delta_t

m_Tin = 50

m_cp = 4186#  ' capacité thermique massique à pression constant (J.K^-1.kg^-1)
m_e = rho * ctlCuve1.Volume * m_cp * ctlCuve1.Temp
End Sub

Private Sub Timer1_Timer()

'Debug.Print "ok"

' Bilan de masse
' ==============
' dm/dt = rho * (Qvin - Qvout)
' m = rho * V
' rho = cst => simplif par rho => bilan de volume
m_m = (rho * (Qvin - Qvout)) * (delta_t / 1000#) + m_m
ctlCuve1.Volume = m_m / rho
'ctlCuve1.Volume = (Qvin - Qvout) * (delta_t / 1000#) + ctlCuve1.Volume
'ctlCuve1.Level = (1 / S * (Qin - Qout)) * (delta_t / 1000#) + ctlCuve1.Level


' Bilan d'énergie
' ===============
' dE/dt = rho*Qvin*cp*deltaT+Pelec


' Affichage
' =========
lblQin.Caption = "Qv_in = " & Format(Qvin, "#0.00") & " m^3/s"
lblTin.Caption = "Tin = " & Format(Tin, "##0.0") & " °C"

lblLevel.Caption = "h = " & Format(ctlCuve1.Level, "###0.00") & " m" & " ; V=" & Format(ctlCuve1.Volume, "###0.00") & " m^3"
lblTemp.Caption = "T = " & Format(ctlCuve1.Temp, "##0.0") & " °C"

lblQout.Caption = "Qv_out = " & Format(Qvout, "#0.00") & " m^3/s"
lblTout.Caption = "Tout = " & Format(ctlCuve1.Temp, "##0.0") & " °C"
End Sub

Private Sub UserControl_Resize()
'ctlCuve1.Width = UserControl.Width
'ctlCuve1.Height = UserControl.Height
End Sub

Public Property Get Qvin() As Double
Qvin = m_qvin
End Property

Public Property Let Qvin(ByVal new_qvin As Double)
m_qvin = new_qvin
End Property

Public Property Get Kv() As Double
Kv = m_Kv
End Property

Public Property Let Kv(ByVal new_Kv As Double)
m_Kv = new_Kv
End Property

Public Property Get Qvout() As Double
m_qvout = Kv * Sqr(rho * G * ctlCuve1.Level)
Qvout = m_qvout
'If Qout <> 0 Then
'    Debug.Print Qout
'End If
End Property


Public Property Get Level() As Double
Level = ctlCuve1.Level
End Property


Public Property Get Tin() As Double
Tin = m_Tin
End Property

Public Property Let Tin(ByVal new_Tin As Double)
m_Tin = new_Tin
End Property
