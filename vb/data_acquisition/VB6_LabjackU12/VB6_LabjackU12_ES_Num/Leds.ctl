VERSION 5.00
Begin VB.UserControl AfficheurOctet 
   ClientHeight    =   825
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   3540
   ScaleHeight     =   825
   ScaleWidth      =   3540
   Begin Test_ES_Num_LabjackU12.Led Led1 
      Height          =   255
      Index           =   0
      Left            =   2640
      TabIndex        =   0
      Top             =   240
      Width           =   255
      _ExtentX        =   450
      _ExtentY        =   450
   End
   Begin Test_ES_Num_LabjackU12.Led Led1 
      Height          =   255
      Index           =   1
      Left            =   2280
      TabIndex        =   1
      Top             =   240
      Width           =   255
      _ExtentX        =   450
      _ExtentY        =   450
   End
   Begin Test_ES_Num_LabjackU12.Led Led1 
      Height          =   255
      Index           =   2
      Left            =   1920
      TabIndex        =   2
      Top             =   240
      Width           =   255
      _ExtentX        =   450
      _ExtentY        =   450
   End
   Begin Test_ES_Num_LabjackU12.Led Led1 
      Height          =   255
      Index           =   3
      Left            =   1560
      TabIndex        =   3
      Top             =   240
      Width           =   255
      _ExtentX        =   450
      _ExtentY        =   450
   End
   Begin Test_ES_Num_LabjackU12.Led Led1 
      Height          =   255
      Index           =   4
      Left            =   1200
      TabIndex        =   4
      Top             =   240
      Width           =   255
      _ExtentX        =   450
      _ExtentY        =   450
   End
   Begin Test_ES_Num_LabjackU12.Led Led1 
      Height          =   255
      Index           =   5
      Left            =   840
      TabIndex        =   5
      Top             =   240
      Width           =   255
      _ExtentX        =   450
      _ExtentY        =   450
   End
   Begin Test_ES_Num_LabjackU12.Led Led1 
      Height          =   255
      Index           =   6
      Left            =   480
      TabIndex        =   6
      Top             =   240
      Width           =   255
      _ExtentX        =   450
      _ExtentY        =   450
   End
   Begin Test_ES_Num_LabjackU12.Led Led1 
      Height          =   255
      Index           =   7
      Left            =   120
      TabIndex        =   7
      Top             =   240
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

Private Sub UserControl_Initialize()
    m_N = 5
        
    For i = 0 To Nbits - 1
        Led1(i).ColorOFF = &H4080& ' rouge clair
        Led1(i).ColorON = &HFF& ' rouge foncé
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
