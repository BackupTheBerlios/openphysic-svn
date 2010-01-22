VERSION 5.00
Begin VB.UserControl ctlCuveVidangeable 
   ClientHeight    =   2430
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   3705
   ScaleHeight     =   2430
   ScaleWidth      =   3705
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
      _ExtentX        =   1931
      _ExtentY        =   4048
   End
   Begin VB.Label lblLevel 
      Caption         =   "level"
      Height          =   495
      Left            =   1320
      TabIndex        =   3
      Top             =   960
      Width           =   1815
   End
   Begin VB.Label lblQout 
      Caption         =   "Qout"
      Height          =   495
      Left            =   1320
      TabIndex        =   2
      Top             =   1800
      Width           =   1935
   End
   Begin VB.Label lblQin 
      Caption         =   "Qin"
      Height          =   495
      Left            =   1320
      TabIndex        =   1
      Top             =   120
      Width           =   1935
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
'  Qin (en lecture/écriture) : débit entrant (en m^3/s)
'  Kv (en lecture/écriture) : coefficient de la vanne de vidange (0..1)
'  Qout (en lecture seule) : débit volumique sortant (en m^3/s)

Option Explicit

Const delta_t As Double = 100  ' ms

Const g As Double = 9.81
Const rho As Double = 1000 ' kg/m^3
Const S As Double = 1 ' m^2

Dim m_qin As Double
Dim m_Kv As Double

Dim m_qout As Double


Private Sub Timer1_Timer()

'Debug.Print "ok"
ctlCuve1.Level = (1 / S * (Qin - Qout)) * (delta_t / 1000#) + ctlCuve1.Level

lblQin.Caption = "Qin = " & Format(Qin, "#0.00") & " m^3/s"
lblQout.Caption = "Qout = " & Format(Qout, "#0.00") & " m^3/s"
lblLevel.Caption = "h = " & Format(ctlCuve1.Level, "###0.00") & " m"
End Sub

Private Sub UserControl_Initialize()
ctlCuve1.Level = 0.8

Timer1.Interval = delta_t
End Sub

Private Sub UserControl_Resize()
'ctlCuve1.Width = UserControl.Width
'ctlCuve1.Height = UserControl.Height
End Sub

Public Property Get Qin() As Double
Qin = m_qin
End Property

Public Property Let Qin(ByVal new_qin As Double)
m_qin = new_qin
End Property

Public Property Get Kv() As Double
Kv = m_Kv
End Property

Public Property Let Kv(ByVal new_Kv As Double)
m_Kv = new_Kv
End Property

Public Property Get Qout() As Double
m_qout = Kv * Sqr(rho * g * ctlCuve1.Level)
Qout = m_qout
If Qout <> 0 Then
    Debug.Print Qout
End If
End Property


Public Property Get Level() As Double
Level = ctlCuve1.Level
End Property

