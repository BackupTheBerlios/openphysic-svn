VERSION 5.00
Begin VB.UserControl ctlCuveVidangeable 
   ClientHeight    =   2430
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   1230
   ScaleHeight     =   2430
   ScaleWidth      =   1230
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
End
Attribute VB_Name = "ctlCuveVidangeable"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
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
End Sub

Private Sub UserControl_Initialize()
ctlCuve1.Level = 0.8

Timer1.Interval = delta_t
End Sub

Private Sub UserControl_Resize()
ctlCuve1.Width = UserControl.Width
ctlCuve1.Height = UserControl.Height
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
m_qout = Sqr(rho * g * ctlCuve1.Level)
Qout = m_qout
End Property

