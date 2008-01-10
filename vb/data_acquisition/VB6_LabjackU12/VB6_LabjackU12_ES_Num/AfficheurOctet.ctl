VERSION 5.00
Begin VB.UserControl AfficheurOctet 
   BackStyle       =   0  'Transparent
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
' Afficheur 8 bits
' ================

' propriétés
'  ColorON : couleur de toutes les LED allumées
'  ColorOFF : couleur de toutes les LED éteintes
'  N : nombre à afficher / nombre affiché

Option Explicit

Const Nbits = 8

Dim m_N As Byte ' nb à afficher (sur 8 bits)

Dim i As Integer

' couleur de toutes les leds
Dim m_ColorOFF As OLE_COLOR
Dim m_ColorON As OLE_COLOR

' Couleur par défault
'Const m_def_ColorOFF = &H4080& ' rouge foncé
'Const m_def_ColorON = &HFF& ' rouge clair
Const m_def_ColorOFF = &H8000& ' vert foncé
Const m_def_ColorON = &HFF00& ' vert clair

Private Sub UserControl_Initialize()
    For i = 0 To Nbits - 1
        Led1(i).ColorOFF = m_def_ColorOFF
        Led1(i).ColorON = m_def_ColorON
    Next i
    afficher
End Sub

Private Sub éteindre_toutes()
    For i = 0 To Nbits - 1
        Led1(i).éteindre
    Next i
    afficher
End Sub

Private Sub allumer_toutes()
    For i = 0 To Nbits - 1
        Led1(i).allumer
    Next i
    afficher
End Sub

Public Property Let N(num As Byte)
    m_N = num
    PropertyChanged N
    afficher
End Property

Public Property Get N() As Byte
    N = m_N
End Property

Private Sub afficher()
    Dim N As Byte
    N = m_N ' copie afin de ne pas modifier la valeur de m_N
    For i = Nbits - 1 To 0 Step -1
        If N >= 2 ^ i Then ' bit à 1
            N = N - 2 ^ i
            Led1(i).allumer
        Else ' bit à 0
            Led1(i).éteindre
        End If
    Next i
End Sub


Public Property Let ColorON(new_color As OLE_COLOR)
    m_ColorON = new_color
    PropertyChanged ColorON
    afficher
End Property

Public Property Get ColorON() As OLE_COLOR
    ColorON = m_ColorON
End Property

Public Property Let ColorOFF(new_color As OLE_COLOR)
    m_ColorOFF = new_color
    PropertyChanged ColorOFF
    afficher
End Property

Public Property Get ColorOFF() As OLE_COLOR
    ColorOFF = m_ColorOFF
End Property


' Initialise les propriétés
'(lorsqu'on place un contrôle utilisateur sur une feuille)
Private Sub UserControl_InitProperties()
    m_ColorON = m_def_ColorON
    m_ColorOFF = m_def_ColorOFF
End Sub

' Chargement des propriétés par défault
Private Sub UserControl_ReadProperties(PropBag As PropertyBag)
    m_ColorON = PropBag.ReadProperty("ColorON", m_def_ColorON)
    m_ColorOFF = PropBag.ReadProperty("ColorOFF", m_def_ColorOFF)
End Sub

' Sauvegarde des propriétés
Private Sub UserControl_WriteProperties(PropBag As PropertyBag)
    Call PropBag.WriteProperty("ColorON", m_ColorON, m_def_ColorON)
    Call PropBag.WriteProperty("ColorOFF", m_ColorOFF, m_def_ColorOFF)
End Sub

