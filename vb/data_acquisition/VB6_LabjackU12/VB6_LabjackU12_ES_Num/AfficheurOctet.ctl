VERSION 5.00
Begin VB.UserControl AfficheurOctet 
   ClientHeight    =   1830
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   4695
   ScaleHeight     =   1830
   ScaleWidth      =   4695
   Begin Test_ES_Num_LabjackU12.Led Led1 
      Height          =   255
      Index           =   0
      Left            =   2520
      TabIndex        =   0
      Top             =   0
      Width           =   255
      _ExtentX        =   450
      _ExtentY        =   450
   End
   Begin Test_ES_Num_LabjackU12.Led Led1 
      Height          =   255
      Index           =   1
      Left            =   2160
      TabIndex        =   1
      Top             =   0
      Width           =   255
      _ExtentX        =   450
      _ExtentY        =   450
   End
   Begin Test_ES_Num_LabjackU12.Led Led1 
      Height          =   255
      Index           =   2
      Left            =   1800
      TabIndex        =   2
      Top             =   0
      Width           =   255
      _ExtentX        =   450
      _ExtentY        =   450
   End
   Begin Test_ES_Num_LabjackU12.Led Led1 
      Height          =   255
      Index           =   3
      Left            =   1440
      TabIndex        =   3
      Top             =   0
      Width           =   255
      _ExtentX        =   450
      _ExtentY        =   450
   End
   Begin Test_ES_Num_LabjackU12.Led Led1 
      Height          =   255
      Index           =   4
      Left            =   1080
      TabIndex        =   4
      Top             =   0
      Width           =   255
      _ExtentX        =   450
      _ExtentY        =   450
   End
   Begin Test_ES_Num_LabjackU12.Led Led1 
      Height          =   255
      Index           =   5
      Left            =   720
      TabIndex        =   5
      Top             =   0
      Width           =   255
      _ExtentX        =   450
      _ExtentY        =   450
   End
   Begin Test_ES_Num_LabjackU12.Led Led1 
      Height          =   255
      Index           =   6
      Left            =   360
      TabIndex        =   6
      Top             =   0
      Width           =   255
      _ExtentX        =   450
      _ExtentY        =   450
   End
   Begin Test_ES_Num_LabjackU12.Led Led1 
      Height          =   255
      Index           =   7
      Left            =   0
      TabIndex        =   7
      Top             =   0
      Width           =   255
      _ExtentX        =   450
      _ExtentY        =   450
   End
End
Attribute VB_Name = "AfficheurOctet"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Const Nbits = 8

Dim m_N As Byte ' nb à afficher (sur 8 bits)

Dim i As Integer

' couleur de toutes les leds
Dim m_ColorOFF As ColorConstants
Dim m_ColorON As ColorConstants

Private Sub UserControl_Initialize()
    m_N = 0
    
    m_ColorOFF = &H4080& ' rouge foncé
    m_ColorON = &HFF& ' rouge clair
        
    For i = 0 To Nbits - 1
        Led1(i).ColorOFF = m_ColorOFF
        Led1(i).ColorON = m_ColorON
    Next i
    
    afficher
End Sub

Private Sub éteindre_toutes()
    For i = 0 To Nbits - 1
        Led1(i).éteindre
    Next i
End Sub

Private Sub allumer_toutes()
    For i = 0 To Nbits - 1
        Led1(i).allumer
    Next i
End Sub

Public Property Let N(num As Byte)
    m_N = N
    afficher
End Property

Public Property Get N() As Byte
    N = m_N
End Property

Private Sub afficher()
    For i = Nbits - 1 To 0 Step -1
        If m_N >= 2 ^ i Then ' bit à 1
            Led1(i).allumer
        Else ' bit à 0
            Led1(i).éteindre
        End If
    Next i
End Sub


Public Property Let ColorON(color As ColorConstants)
    m_ColorON = color
End Property

Public Property Get ColorON() As ColorConstants
    ColorON = m_ColorON
End Property

Public Property Let ColorOFF(color As ColorConstants)
    m_ColorOFF = color
End Property

Public Property Get ColorOFF() As ColorConstants
    ColorOFF = m_ColorOFF
End Property

