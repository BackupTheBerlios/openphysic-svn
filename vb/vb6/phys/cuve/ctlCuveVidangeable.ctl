VERSION 5.00
Begin VB.UserControl ctlCuveVidangeable 
   BackColor       =   &H00FFFFFF&
   ClientHeight    =   5370
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   8490
   ScaleHeight     =   5370
   ScaleWidth      =   8490
   Begin VB.Timer Timer1 
      Left            =   5520
      Top             =   0
   End
   Begin TestVidangeCuve.ctlCuve ctlCuve1 
      Height          =   2895
      Left            =   2160
      TabIndex        =   0
      Top             =   960
      Width           =   1215
      _extentx        =   2143
      _extenty        =   5106
   End
   Begin VB.Label lblGeom 
      Alignment       =   2  'Center
      BackColor       =   &H00FFFFFF&
      Caption         =   "Label2"
      Height          =   975
      Left            =   600
      TabIndex        =   12
      Top             =   2160
      Width           =   1455
   End
   Begin VB.Label lblPelec 
      BackColor       =   &H00FFFFFF&
      Caption         =   "Pelec"
      Height          =   495
      Left            =   600
      TabIndex        =   11
      Top             =   3720
      Width           =   1335
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackColor       =   &H00FFFFFF&
      Caption         =   "Simulation d'une cuve"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   0
      TabIndex        =   10
      Top             =   4560
      Width           =   6255
   End
   Begin VB.Label lblTair 
      Alignment       =   2  'Center
      BackColor       =   &H00FFFFFF&
      Caption         =   "Tair"
      Height          =   375
      Left            =   1680
      TabIndex        =   9
      Top             =   0
      Width           =   2415
   End
   Begin VB.Label lblQin2 
      BackColor       =   &H00FFFFFF&
      Caption         =   "Qin"
      Height          =   255
      Left            =   3480
      TabIndex        =   8
      Top             =   480
      Width           =   1815
   End
   Begin VB.Label lblTin2 
      BackColor       =   &H00FFFFFF&
      Caption         =   "Tin"
      Height          =   375
      Left            =   3480
      TabIndex        =   7
      Top             =   720
      Width           =   1815
   End
   Begin VB.Label lblTout 
      BackColor       =   &H00FFFFFF&
      Caption         =   "Tout"
      Height          =   495
      Left            =   3600
      TabIndex        =   6
      Top             =   3840
      Width           =   2415
   End
   Begin VB.Label lblTemp 
      BackColor       =   &H00FFFFFF&
      Caption         =   "T"
      Height          =   375
      Left            =   3600
      TabIndex        =   5
      Top             =   2400
      Width           =   2415
   End
   Begin VB.Label lblTin1 
      BackColor       =   &H00FFFFFF&
      Caption         =   "Tin"
      Height          =   495
      Left            =   840
      TabIndex        =   4
      Top             =   720
      Width           =   1815
   End
   Begin VB.Label lblLevel 
      BackColor       =   &H00FFFFFF&
      Caption         =   "level"
      Height          =   375
      Left            =   3600
      TabIndex        =   3
      Top             =   2040
      Width           =   2415
   End
   Begin VB.Label lblQout 
      BackColor       =   &H00FFFFFF&
      Caption         =   "Qout"
      Height          =   495
      Left            =   3600
      TabIndex        =   2
      Top             =   3600
      Width           =   2415
   End
   Begin VB.Label lblQin1 
      BackColor       =   &H00FFFFFF&
      Caption         =   "Qin"
      Height          =   495
      Left            =   840
      TabIndex        =   1
      Top             =   480
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
Dim m_Tin(1 To input_nb) As Double

Dim m_Kv As Double

Dim m_qvout As Double

Dim m_m As Double ' masse


Dim m_cp As Double

Dim m_e As Double ' energie
Dim m_Pelec As Double ' puissance électrique


Dim m_temp_air As Double ' temperature de l'air entourant la cuve (pour convection)
Dim m_U As Double ' coeff d'echange en W.K^-1

Private Sub UserControl_Initialize()
ctlCuve1.Level = 0.5
m_m = (ctlCuve1.Level * ctlCuve1.Surface) * rho

Timer1.Interval = delta_t

m_Tin(1) = 10

m_cp = 4186#  ' capacité thermique massique à pression constant (J.K^-1.kg^-1)
m_e = rho * m_cp * ctlCuve1.Temp

m_temp_air = 20
m_U = 20000
End Sub

Private Sub Timer1_Timer()

'Debug.Print "ok"

' Bilan de masse
' ==============
' dm/dt = rho * (Qvin - Qvout)
' m = rho * V
' rho = cst => simplif par rho => bilan de volume
m_m = (rho * (Qvin(1) - Qvout)) * (delta_t / 1000#) + m_m
ctlCuve1.Volume = m_m / rho
'ctlCuve1.Volume = (Qvin - Qvout) * (delta_t / 1000#) + ctlCuve1.Volume
'ctlCuve1.Level = (1 / S * (Qin - Qout)) * (delta_t / 1000#) + ctlCuve1.Level


' Bilan d'énergie
' ===============
' dE/dt = rho*Qvin*cp*deltaT+Pelec
If ctlCuve1.Volume <> 0 Then
    m_e = (rho * Qvin(1) * m_cp * (m_Tin(1) - ctlCuve1.Temp) + m_Pelec + m_U * (m_temp_air - ctlCuve1.Temp)) / ctlCuve1.Volume * (delta_t / 1000#) + m_e
    ctlCuve1.Temp = m_e / (rho * m_cp)
Else
    If Qvin(1) <> 0 Or Qvin(2) <> 0 Then
        m_e = rho * m_cp * (Qvin(1) * m_Tin(1) + Qvin(2) * m_Tin(2)) / (Qvin(1) + Qvin(2)) ' to fix qvin2
        ctlCuve1.Temp = m_e / (rho * m_cp)
    Else
        m_e = rho * m_cp * m_temp_air
        ctlCuve1.Temp = m_e / (rho * m_cp) 'ctlCuve1.TempAir
    End If
End If

' Affichage
' =========
lblQin1.Caption = "Qv_in(1) = " & Format(Qvin(1), "#0.00") & " m^3/s"
lblTin1.Caption = "Tin(1) = " & Format(Tin(1), "##0.0") & " °C"

lblQin2.Caption = "Qv_in(2) = " & Format(Qvin(2), "#0.00") & " m^3/s" ' tofix
lblTin2.Caption = "Tin(2) = " & Format(Tin(2), "##0.0") & " °C" ' tofix

lblLevel.Caption = "h = " & Format(ctlCuve1.Level, "###0.00") & " m" & " ; V=" & Format(ctlCuve1.Volume, "###0.00") & " m^3"
lblTemp.Caption = "T = " & Format(ctlCuve1.Temp, "##0.0") & " °C"

lblQout.Caption = "Qv_out = " & Format(Qvout, "#0.00") & " m^3/s"
lblTout.Caption = "Tout = " & Format(ctlCuve1.Temp, "##0.0") & " °C"

lblTair.Caption = "Tair = " & Format(m_temp_air, "##0.0") & " °C" & " ; U=" & Format(m_U, "####0") & " W/K"

lblPelec.Caption = "Pelec = " & Format(m_Pelec, "####0") & " W"

lblGeom.Caption = "S = " & ctlCuve1.Surface & " m^2" & vbCrLf _
    & "Vmin = " & ctlCuve1.VolumeMin & " m^3" & vbCrLf _
    & "Vmax = " & ctlCuve1.VolumeMax & " m^3"
    
End Sub

Private Sub UserControl_Resize()
'ctlCuve1.Width = UserControl.Width
'ctlCuve1.Height = UserControl.Height
End Sub

Public Property Get Qvin(ByVal index As Byte) As Double
Qvin = m_qvin(index)
End Property

Public Property Let Qvin(ByVal index As Byte, ByVal new_qvin As Double)
m_qvin(index) = new_qvin
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


Public Property Get Tin(ByVal index As Byte) As Double
Tin = m_Tin(index)
End Property

Public Property Let Tin(ByVal index As Byte, ByVal new_Tin As Double)
m_Tin(index) = new_Tin
End Property

Public Property Get Pelec() As Double
Pelec = m_Pelec
End Property

Public Property Let Pelec(ByVal new_Pelec As Double)
m_Pelec = new_Pelec
End Property


Public Property Get U() As Double
U = m_U
End Property

Public Property Let U(ByVal new_U As Double)
m_U = new_U
End Property


Public Property Get Tair() As Double
Tair = m_temp_air
End Property

Public Property Let Tair(ByVal new_Tair As Double)
m_temp_air = new_Tair
End Property
