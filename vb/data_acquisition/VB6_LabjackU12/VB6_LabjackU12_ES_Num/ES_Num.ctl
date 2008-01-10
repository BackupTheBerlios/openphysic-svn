VERSION 5.00
Begin VB.UserControl ES_Num 
   BackStyle       =   0  'Transparent
   ClientHeight    =   2730
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   5880
   ScaleHeight     =   2730
   ScaleWidth      =   5880
   Begin VB.Timer Timer1 
      Left            =   1920
      Top             =   1920
   End
   Begin VB.Frame fraEntréesSortiesNumériques 
      BackColor       =   &H00C0FFFF&
      Caption         =   "Entrées/Sorties numériques"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1815
      Left            =   0
      TabIndex        =   5
      Top             =   0
      Width           =   5175
      Begin VB.Frame fraPortA 
         Appearance      =   0  'Flat
         BackColor       =   &H00C0E0FF&
         Caption         =   "Port A"
         ForeColor       =   &H80000008&
         Height          =   615
         Left            =   120
         TabIndex        =   7
         Top             =   240
         Width           =   4935
         Begin VB.TextBox txtPort 
            Alignment       =   1  'Right Justify
            BackColor       =   &H00C0C0FF&
            Height          =   285
            Index           =   0
            Left            =   1560
            TabIndex        =   1
            Text            =   "0"
            Top             =   240
            Width           =   375
         End
         Begin VB.ComboBox cboPort_ES 
            BackColor       =   &H00FFFFFF&
            Height          =   315
            Index           =   0
            ItemData        =   "ES_Num.ctx":0000
            Left            =   120
            List            =   "ES_Num.ctx":0002
            TabIndex        =   0
            Text            =   "Ecriture Port A"
            Top             =   240
            Width           =   1455
         End
         Begin Test_ES_Num_LabjackU12.AfficheurOctet AfficheurOctet1 
            Height          =   375
            Index           =   0
            Left            =   2040
            TabIndex        =   2
            Top             =   240
            Width           =   2775
            _ExtentX        =   4895
            _ExtentY        =   661
            ColorON         =   255
            ColorOFF        =   16512
         End
      End
      Begin VB.Frame fraPortC 
         Appearance      =   0  'Flat
         BackColor       =   &H00C0E0FF&
         Caption         =   "Port C"
         ForeColor       =   &H80000008&
         Height          =   615
         Left            =   120
         TabIndex        =   6
         Top             =   960
         Width           =   4935
         Begin VB.TextBox txtPort 
            Alignment       =   1  'Right Justify
            BackColor       =   &H00C0FFC0&
            Height          =   285
            Index           =   1
            Left            =   1560
            TabIndex        =   4
            Text            =   "0"
            Top             =   240
            Width           =   375
         End
         Begin VB.ComboBox cboPort_ES 
            Height          =   315
            Index           =   1
            Left            =   120
            TabIndex        =   3
            Text            =   "Lecture Port C"
            Top             =   240
            Width           =   1455
         End
         Begin Test_ES_Num_LabjackU12.AfficheurOctet AfficheurOctet1 
            Height          =   255
            Index           =   1
            Left            =   2040
            TabIndex        =   8
            Top             =   240
            Width           =   2775
            _ExtentX        =   4895
            _ExtentY        =   450
         End
      End
   End
End
Attribute VB_Name = "ES_Num"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
' ToDo

' Objet VB6 permettant le contrôle d'une carte
' entrée/sortie numériques (8 bits * 2 ports)
' LabjackU12

' Sébastien CELLES
' IUT de Poitiers
' Génie Thermique et Energie

' Propriétés
'  Mode(i) : Ecriture (0) ou Lecture (1)
'  Port(i) : valeur à sur le port (en décimal)

Option Explicit

Dim i As Integer

Const nb_ports = 2 ' nb de ports (de 0 à nb_ports-1)

Dim m_port(nb_ports - 1) As Byte ' 8 bits (contenu de chaque port)

Enum EMode
    Lecture
    Ecriture
End Enum
Dim m_mode(nb_ports - 1) As EMode ' mode de chaque port (False=écriture ; True=Lecture)

Private Sub initialise_ports()
    initialise_port (0)
    initialise_port (1)
End Sub

Private Sub initialise_port(voie As Byte)

End Sub

Public Property Let Port(voie As Byte, ByVal val As Byte)
    m_port(voie) = val
    txtPort(voie).Text = m_port(voie)
    PropertyChanged "Port"
End Property

Public Property Get Port(voie As Byte) As Byte
    Port = m_port(voie)
End Property

Public Property Let Mode(voie As Byte, ByVal new_mode As EMode)
    m_mode(voie) = new_mode
    cboPort_ES(voie).ListIndex = new_mode
    If m_mode(voie) = EMode.Ecriture Then
        txtPort(voie).Locked = False
    Else ' Lecture
        txtPort(voie).Locked = True
    End If
    PropertyChanged "Mode"
End Property

Public Property Get Mode(voie As Byte) As EMode
    Mode = m_mode(voie)
End Property

Private Sub cboPort_ES_Click(Index As Integer)
    Dim voie As Byte
    voie = Index
    Mode(voie) = cboPort_ES(Index).ListIndex
End Sub

Private Sub txtPort_Change(Index As Integer)
    Dim N As Byte
    If IsNumeric(txtPort(Index).Text) Then
        N = txtPort(Index).Text
    Else
        N = 0
        txtPort(Index).Text = CStr(N)
    End If
    
    AfficheurOctet1(Index).N = N
End Sub

Private Sub UserControl_Initialize()
    '  Initialise la liste
    cboPort_ES(0).AddItem "Lecture Port A"
    cboPort_ES(0).AddItem "Ecriture Port A"
    
    cboPort_ES(1).AddItem "Lecture Port C"
    cboPort_ES(1).AddItem "Ecriture Port C"
    
    Mode(0) = EMode.Ecriture
    Mode(1) = EMode.Lecture

    initialise_ports
    
    Timer1.Interval = 10
    Timer1.Enabled = True

End Sub



' Traitement des erreurs
Private Sub Erreur(msg As String)
    Debug.Print msg
End Sub



' Partie spécifique à la carte
