VERSION 5.00
Object = "{E46BCC02-8469-11D5-B00B-00008654A834}#1.0#0"; "ljackuwx.ocx"
Begin VB.UserControl ES_Num 
   BackStyle       =   0  'Transparent
   ClientHeight    =   2730
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   5880
   ScaleHeight     =   2730
   ScaleWidth      =   5880
   Begin LJACKUWXLib.Ljackuwx Ljackuwx1 
      Height          =   375
      Left            =   3240
      TabIndex        =   9
      Top             =   2040
      Visible         =   0   'False
      Width           =   1095
      _Version        =   65536
      _ExtentX        =   1931
      _ExtentY        =   661
      _StockProps     =   0
   End
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
            Left            =   120
            Style           =   2  'Dropdown List
            TabIndex        =   0
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
            Style           =   2  'Dropdown List
            TabIndex        =   3
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
'  Port(i) : valeur présente sur le port (en décimal)

Option Explicit

Const nb_ports = 2 ' nb de ports (de 0 à nb_ports-1)

Dim m_port(nb_ports - 1) As Byte ' 8 bits (contenu de chaque port)

Enum EMode
    Lecture
    Ecriture
End Enum
Dim m_mode(nb_ports - 1) As EMode ' mode de chaque port (False=écriture ; True=Lecture)



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
        'txtPort(voie).Locked = True
        txtPort(voie).Enabled = True
    Else ' Lecture
        'txtPort(voie).Locked = False
        txtPort(voie).Enabled = False
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

Private Sub Timer1_Timer()
    Dim i As Byte
    For i = 0 To nb_ports - 1
        If m_mode(i) = EMode.Lecture Then
            'lire_données (i)
            txtPort(i).Text = m_port(i)
            ' lance l'évenement change
        Else ' Ecriture
            écrire_données i, m_port(i)
        End If
        AfficheurOctet1(i).N = m_port(i)
    Next i
End Sub

Private Sub txtPort_Change(Index As Integer)
    Dim N As Byte
    If IsNumeric(txtPort(Index).Text) Then
        If txtPort(Index).Text > 255 Then
            N = 255
            txtPort(Index).Text = CStr(N)
        ElseIf txtPort(Index).Text < 0 Then
            N = 0
            txtPort(Index).Text = CStr(N)
        Else
            N = CByte(txtPort(Index).Text)
        End If
    Else ' non numerique
        N = 0
        txtPort(Index).Text = CStr(N)
    End If
    
    txtPort(Index).SelStart = Len(txtPort(Index).Text)
    If N = 0 Or Len(txtPort(Index).Text) = 3 Then
        txtPort_GotFocus (Index)
    End If
    
    m_port(Index) = N
End Sub

Private Sub txtPort_Click(Index As Integer)
    txtPort_GotFocus (Index)
End Sub

Private Sub txtPort_GotFocus(Index As Integer)
    'Debug.Print "GotFocus"
    With txtPort(Index)
        .SelStart = 0
        .SelLength = Len(.Text)
    End With
End Sub

Private Sub txtPort_KeyPress(Index As Integer, KeyAscii As Integer)
    'Debug.Print KeyAscii
    If (KeyAscii < 48 Or KeyAscii > 57) And KeyAscii <> 8 Then
        KeyAscii = 0
    End If
End Sub

Private Sub UserControl_Initialize()
    '  Initialise la liste
    cboPort_ES(0).AddItem "Lecture Port A"
    cboPort_ES(0).AddItem "Ecriture Port A"
    
    cboPort_ES(1).AddItem "Lecture Port C"
    cboPort_ES(1).AddItem "Ecriture Port C"
    
    'Mode(0) = EMode.Ecriture
    'Mode(1) = EMode.Lecture

    initialise_ports
    
    Timer1.Interval = 10
    Timer1.Enabled = True

End Sub


' Initialise les propriétés
'(lorsqu'on place un contrôle utilisateur sur une feuille)
Private Sub UserControl_InitProperties()
    'Debug.Print "InitProperties"
    Mode(0) = EMode.Ecriture
    Mode(1) = EMode.Lecture
End Sub

' Chargement des propriétés par défault
Private Sub UserControl_ReadProperties(PropBag As PropertyBag)
    'Debug.Print "ReadProperties"
    Mode(0) = PropBag.ReadProperty("Mode", EMode.Ecriture)
    Mode(1) = PropBag.ReadProperty("Mode", EMode.Lecture)
    'maj_combo

    'Timer1.Interval = 10
    'Timer1.Enabled = True

End Sub

' Sauvegarde des propriétés
Private Sub UserControl_WriteProperties(PropBag As PropertyBag)
    'Debug.Print "WriteProperties"
    Call PropBag.WriteProperty("Mode", m_mode(0), EMode.Ecriture)
    Call PropBag.WriteProperty("Mode", m_mode(1), EMode.Lecture)
End Sub




' Traitement des erreurs
Private Sub Erreur(msg As String)
    Debug.Print msg
End Sub



' Partie spécifique à la carte
Private Sub initialise_ports()
    Dim i As Byte
    For i = 0 To nb_ports - 1
        initialise_port (i)
    Next i
End Sub

Private Sub initialise_port(voie As Byte)

End Sub

Private Sub lire_données(voie As Byte)
    'm_port(voie) = 20 + voie
    
    'Ljackuwx1
    Dim lngErrorcode As Long
    Dim lngIDNum As Long
    Dim lngDemo As Long
    Dim lngUpdateDigital As Long
    Dim lngTrisD As Long
    Dim lngTrisIO As Long
    Dim lngStateD As Long
    Dim lngStateIO As Long
    Dim dblCount As Double
    Dim sngAnalogOut0 As Single
    Dim sngAnalogOut1 As Single
    
    lngIDNum = -1
    lngDemo = 0
    lngUpdateDigital = 1
    lngTrisD = 0
    lngStateD = 0
    'lngTrisIO = 0 'chkTris0 + (chkTris1 * (2 ^ 1)) + (chkTris2 * (2 ^ 2)) + (chkTris3 * (2 ^ 3))
    'lngStateIO = 0 'chkSet0 + (chkSet1 * (2 ^ 1)) + (chkSet2 * (2 ^ 2)) + (chkSet3 * (2 ^ 3))
    'lngTrisIO = 0
    'lngStateIO = 0 'chkSet0 + (chkSet1 * (2 ^ 1)) + (chkSet2 * (2 ^ 2)) + (chkSet3 * (2 ^ 3))
    sngAnalogOut0 = 0
    sngAnalogOut1 = 0
    'lngErrorcode = Ljackuwx1.AOUpdateX(lngIDNum, lngDemo, lngTrisD, _
    '    lngTrisIO, lngStateD, lngStateIO, lngUpdateDigital, _
    '    0, dblCount, sngAnalogOut0, sngAnalogOut1)
        
    'm_port(voie) = lngStateIO ' ???????????
        
    If lngErrorcode <> 0 Then
        Erreur (Ljackuwx1.GetErrorStringX(lngErrorcode))
    End If
End Sub

Private Sub écrire_données(voie As Byte, data As Byte)
    Debug.Print "Sortie de " + CStr(data) + " sur " + CStr(voie)
    
    'Ljackuwx1
    Dim lngErrorcode As Long
    Dim lngIDNum As Long
    Dim lngDemo As Long
    Dim lngUpdateDigital As Long
    Dim lngTrisD As Long
    Dim lngTrisIO As Long
    Dim lngStateD As Long
    Dim lngStateIO As Long
    Dim dblCount As Double
    Dim sngAnalogOut0 As Single
    Dim sngAnalogOut1 As Single
    
    lngIDNum = -1
    lngDemo = 0
    lngUpdateDigital = 1
    lngTrisD = 0
    lngStateD = 0
    lngTrisIO = &HF  '15  '15 '255 '15 '&HFF ' 8 bits à 1 '0 ' ?
    lngStateIO = CLng(data) ' ?
    sngAnalogOut0 = 0
    sngAnalogOut1 = 0
    
    

    'lngErrorcode = Ljackuwx1.AOUpdateX(lngIDNum, lngDemo, lngTrisD, _
    '    lngTrisIO, lngStateD, lngStateIO, lngUpdateDigital, _
    '    0, dblCount, sngAnalogOut0, sngAnalogOut1)
        
    lngErrorcode = Ljackuwx1.AOUpdateX(lngIDNum, lngDemo, lngTrisD, _
        lngTrisIO, lngStateD, lngStateIO, lngUpdateDigital, _
        0, dblCount, sngAnalogOut0, sngAnalogOut1)
    
    'Debug.Print "Sortie de " + CStr(data) + " sur " + CStr(voie)
        
    'lngErrorcode = Ljackuwx1.AOUpdateX(CLng(-1), CLng(0), CLng(0), _
    '    CLng(15), CLng(0), CLng(15), CLng(1), _
    '    CLng(0), CDbl(0), CSng(0), CSng(0))
    
    If lngErrorcode <> 0 Then
        Erreur (Ljackuwx1.GetErrorStringX(lngErrorcode))
    End If
End Sub
