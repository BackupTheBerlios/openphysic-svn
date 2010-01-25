VERSION 5.00
Begin VB.UserControl ctlCuveVidangeable 
   ClientHeight    =   4470
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   8490
   ScaleHeight     =   4470
   ScaleWidth      =   8490
   Begin VB.Timer Timer1 
      Left            =   720
      Top             =   1800
   End
   Begin TestVidangeCuve.ctlCuve ctlCuve1 
      Height          =   2895
      Left            =   2160
      TabIndex        =   0
      Top             =   480
      Width           =   1215
      _ExtentX        =   2143
      _ExtentY        =   5106
   End
   Begin VB.Label lblQin2 
      Caption         =   "Qin"
      Height          =   255
      Left            =   3480
      TabIndex        =   8
      Top             =   0
      Width           =   1815
   End
   Begin VB.Label lblTin2 
      Caption         =   "Tin"
      Height          =   375
      Left            =   3480
      TabIndex        =   7
      Top             =   240
      Width           =   1815
   End
   Begin VB.Label lblTout 
      Caption         =   "Tout"
      Height          =   495
      Left            =   3600
      TabIndex        =   6
      Top             =   3360
      Width           =   2415
   End
   Begin VB.Label lblTemp 
      Caption         =   "T"
      Height          =   375
      Left            =   3600
      TabIndex        =   5
      Top             =   1920
      Width           =   2415
   End
   Begin VB.Label lblTin1 
      Caption         =   "Tin"
      Height          =   495
      Left            =   840
      TabIndex        =   4
      Top             =   240
      Width           =   1815
   End
   Begin VB.Label lblLevel 
      Caption         =   "level"
      Height          =   375
      Left            =   3600
      TabIndex        =   3
      Top             =   1560
      Width           =   2415
   End
   Begin VB.Label lblQout 
      Caption         =   "Qout"
      Height          =   495
      Left            =   3600
      TabIndex        =   2
      Top             =   3120
      Width           =   2415
   End
   Begin VB.Label lblQin1 
      Caption         =   "Qin"
      Height          =   495
      Left            =   840
      TabIndex        =   1
      Top             =   0
      Width           =   1815
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

Const input_nb As Integer = 2

Dim m_qvin(1 To input_nb) As Double
Dim m_Kv(1 To input_nb) As Double

Dim m_qvout As Double

Dim m_m As Double ' masse

Dim m_Tin(1 To input_nb) As Double

Dim m_cp As Double

Dim m_e As Double ' energie
Dim m_Pelec As Double ' puissance électrique

Private Sub UserControl_Initialize()
ctlCuve1.Level = 0.8
m_m = (ctlCuve1.Level * ctlCuve1.Surface) * rho

Timer1.Interval = delta_t

m_Tin(1) = 50

m_cp = 4186#  ' capacité thermique massique à pression constant (J.K^-1.kg^-1)
m_e = rho * m_cp * ctlCuve1.Temp
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
If ctlCuve1.Volume <> 0 Then
    m_e = (rho * Qvin * m_cp * (m_Tin(1) - ctlCuve1.Temp) + m_Pelec) / ctlCuve1.Volume * (delta_t / 1000#) + m_e
    ctlCuve1.Temp = m_e / (rho * m_cp)
Else
    m_e = rho * m_cp * m_Tin(1)
    ctlCuve1.Temp = m_e / (rho * m_cp) 'ctlCuve1.TempAir
End If

' Affichage
' =========
lblQin1.Caption = "Qv_in(1) = " & Format(Qvin, "#0.00") & " m^3/s"
lblTin1.Caption = "Tin(1) = " & Format(Tin, "##0.0") & " °C"

lblQin2.Caption = "Qv_in(2) = " & Format(0, "#0.00") & " m^3/s"
lblTin2.Caption = "Tin(2) = " & Format(0, "##0.0") & " °C"

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
Qvin = m_qvin(1)
End Property

Public Property Let Qvin(ByVal new_qvin As Double)
m_qvin(1) = new_qvin
End Property

Public Property Get Kv() As Double
Kv = m_Kv(1)
End Property

Public Property Let Kv(ByVal new_Kv As Double)
m_Kv(1) = new_Kv
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
Tin = m_Tin(1)
End Property

Public Property Let Tin(ByVal new_Tin As Double)
m_Tin(1) = new_Tin
End Property
