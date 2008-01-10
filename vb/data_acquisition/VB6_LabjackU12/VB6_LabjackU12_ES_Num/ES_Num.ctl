VERSION 5.00
Begin VB.UserControl ES_Num 
   ClientHeight    =   5745
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   6735
   ScaleHeight     =   5745
   ScaleWidth      =   6735
   Begin Test_ES_Num_LabjackU12.AfficheurOctet AfficheurOctet1 
      Height          =   615
      Index           =   0
      Left            =   1080
      TabIndex        =   7
      Top             =   1800
      Width           =   4215
      _ExtentX        =   6800
      _ExtentY        =   873
   End
   Begin VB.Timer Timer1 
      Left            =   3840
      Top             =   2280
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
      Height          =   1695
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   5175
      Begin VB.Frame fraPortA 
         Appearance      =   0  'Flat
         BackColor       =   &H00C0E0FF&
         Caption         =   "Port A"
         ForeColor       =   &H80000008&
         Height          =   615
         Left            =   120
         TabIndex        =   4
         Top             =   240
         Width           =   4935
         Begin VB.TextBox txtPort 
            Alignment       =   1  'Right Justify
            BackColor       =   &H00C0C0FF&
            Height          =   285
            Index           =   0
            Left            =   1560
            TabIndex        =   6
            Text            =   "0"
            Top             =   240
            Width           =   375
         End
         Begin VB.ComboBox cboPort_ES 
            BackColor       =   &H00FFFFFF&
            Height          =   315
            Index           =   0
            Left            =   120
            TabIndex        =   5
            Text            =   "Ecriture Port A"
            Top             =   240
            Width           =   1455
         End
         Begin VB.Shape Shape1 
            BackColor       =   &H00004080&
            BackStyle       =   1  'Opaque
            Height          =   255
            Index           =   0
            Left            =   2040
            Shape           =   3  'Circle
            Top             =   240
            Width           =   255
         End
         Begin VB.Shape Shape1 
            BackColor       =   &H00004080&
            BackStyle       =   1  'Opaque
            Height          =   255
            Index           =   1
            Left            =   2400
            Shape           =   3  'Circle
            Top             =   240
            Width           =   255
         End
         Begin VB.Shape Shape1 
            BackColor       =   &H00004080&
            BackStyle       =   1  'Opaque
            Height          =   255
            Index           =   2
            Left            =   2760
            Shape           =   3  'Circle
            Top             =   240
            Width           =   255
         End
         Begin VB.Shape Shape1 
            BackColor       =   &H00004080&
            BackStyle       =   1  'Opaque
            Height          =   255
            Index           =   3
            Left            =   3120
            Shape           =   3  'Circle
            Top             =   240
            Width           =   255
         End
         Begin VB.Shape Shape1 
            BackColor       =   &H00004080&
            BackStyle       =   1  'Opaque
            Height          =   255
            Index           =   4
            Left            =   3480
            Shape           =   3  'Circle
            Top             =   240
            Width           =   255
         End
         Begin VB.Shape Shape1 
            BackColor       =   &H00004080&
            BackStyle       =   1  'Opaque
            Height          =   255
            Index           =   5
            Left            =   3840
            Shape           =   3  'Circle
            Top             =   240
            Width           =   255
         End
         Begin VB.Shape Shape1 
            BackColor       =   &H00004080&
            BackStyle       =   1  'Opaque
            Height          =   255
            Index           =   6
            Left            =   4200
            Shape           =   3  'Circle
            Top             =   240
            Width           =   255
         End
         Begin VB.Shape Shape1 
            BackColor       =   &H00004080&
            BackStyle       =   1  'Opaque
            Height          =   255
            Index           =   7
            Left            =   4560
            Shape           =   3  'Circle
            Top             =   240
            Width           =   255
         End
      End
      Begin VB.Frame fraPortC 
         Appearance      =   0  'Flat
         BackColor       =   &H00C0E0FF&
         Caption         =   "Port C"
         ForeColor       =   &H80000008&
         Height          =   615
         Left            =   120
         TabIndex        =   1
         Top             =   960
         Width           =   4935
         Begin VB.TextBox txtPort 
            Alignment       =   1  'Right Justify
            BackColor       =   &H00C0FFC0&
            Height          =   285
            Index           =   1
            Left            =   1560
            TabIndex        =   3
            Text            =   "0"
            Top             =   240
            Width           =   375
         End
         Begin VB.ComboBox cboPort_ES 
            Height          =   315
            Index           =   1
            Left            =   120
            TabIndex        =   2
            Text            =   "Lecture Port C"
            Top             =   240
            Width           =   1455
         End
         Begin VB.Shape Shape1 
            BackColor       =   &H00008000&
            BackStyle       =   1  'Opaque
            Height          =   255
            Index           =   8
            Left            =   2040
            Shape           =   3  'Circle
            Top             =   240
            Width           =   255
         End
         Begin VB.Shape Shape1 
            BackColor       =   &H00008000&
            BackStyle       =   1  'Opaque
            Height          =   255
            Index           =   9
            Left            =   2400
            Shape           =   3  'Circle
            Top             =   240
            Width           =   255
         End
         Begin VB.Shape Shape1 
            BackColor       =   &H00008000&
            BackStyle       =   1  'Opaque
            Height          =   255
            Index           =   10
            Left            =   2760
            Shape           =   3  'Circle
            Top             =   240
            Width           =   255
         End
         Begin VB.Shape Shape1 
            BackColor       =   &H00008000&
            BackStyle       =   1  'Opaque
            Height          =   255
            Index           =   11
            Left            =   3120
            Shape           =   3  'Circle
            Top             =   240
            Width           =   255
         End
         Begin VB.Shape Shape1 
            BackColor       =   &H00008000&
            BackStyle       =   1  'Opaque
            Height          =   255
            Index           =   12
            Left            =   3480
            Shape           =   3  'Circle
            Top             =   240
            Width           =   255
         End
         Begin VB.Shape Shape1 
            BackColor       =   &H00008000&
            BackStyle       =   1  'Opaque
            Height          =   255
            Index           =   13
            Left            =   3840
            Shape           =   3  'Circle
            Top             =   240
            Width           =   255
         End
         Begin VB.Shape Shape1 
            BackColor       =   &H00008000&
            BackStyle       =   1  'Opaque
            Height          =   255
            Index           =   14
            Left            =   4200
            Shape           =   3  'Circle
            Top             =   240
            Width           =   255
         End
         Begin VB.Shape Shape1 
            BackColor       =   &H00008000&
            BackStyle       =   1  'Opaque
            Height          =   255
            Index           =   15
            Left            =   4560
            Shape           =   3  'Circle
            Top             =   240
            Width           =   255
         End
      End
   End
   Begin Test_ES_Num_LabjackU12.AfficheurOctet AfficheurOctet1 
      Height          =   255
      Index           =   1
      Left            =   1200
      TabIndex        =   8
      Top             =   2640
      Width           =   2775
      _ExtentX        =   4895
      _ExtentY        =   450
   End
End
Attribute VB_Name = "ES_Num"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
' ToDo

Option Explicit

Dim i As Integer

Const nb_ports = 2 ' nb de ports

Dim m_port(nb_ports) As Byte ' 8 bits (contenu de chaque port)
Dim m_mode(2) As Boolean ' mode de chaque port (False=écriture ; True=Lecture)

Private Sub initialise_port(port As Byte)

End Sub



Public Property Let port(voie As Byte, ByVal val As Byte)
    m_port(voie) = val
    txtPort(voie).Text = m_port(voie)
    'PropertyChanged "Text"
End Property

Public Property Get porta() As Byte

    'porta = txtPortA.Text
End Property


'Private Sub cboPort_ES_Change(voie As Byte)

'If cboPort_ES(voie).Index = 0 Then
'    cboPort_ES(voie).Text = "Entrée"
'End If

'If cboPort_ES(voie).Index = 1 Then
'    cboPort_ES(voie).Text = "Sortie"
'End If

'initialise_port (voie)
'End Sub



Private Sub Timer1_Timer()
'If IsNumeric(txtPortA.Text) Then
'    If cboPortA_ES.ListIndex = 1 And CInt(txtPortA.Text) < 256 Then
'        '''DlPortWritePortUchar prta, CByte(Text1.Text)
'        affiche_led_rouge (CByte(txtPortA.Text))
'    Else
'        txtPortA.Text = "0"
'    End If
'Else
'    txtPortA.Text = "0"
'End If
'''If Porta_es.ListIndex = 0 Then
'''    Text1.Text = DlPortReadPortUchar(prta)
'''End If

'If cboPortC_ES.ListIndex = 1 And CInt(txtPortC.Text) < 256 Then
'''DlPortWritePortUchar prtc, CByte(Text2.Text)
'Else
'    txtPortC.Text = 0
'    Erreur ("Erreur")
'End If

'If cboPortC_ES.ListIndex = 0 Then
    '''Text2.Text = DlPortReadPortUchar(prtc)
'affiche_led_verte (CByte(txtPortC.Text))
'End If



End Sub
'Private Sub affiche_led_rouge(ByVal nombre)
'For i = 0 To 7
'    If nombre And 2 ^ i Then
'        Shape1(7 - i).BackColor = &HFF& ' rouge clair
'    Else
'        Shape1(7 - i).BackColor = &H4080& ' rouge foncé
'    End If
'Next i
'End Sub
'Private Sub affiche_led_verte(ByVal nombre)
'For i = 0 To 7
'    If nombre And 2 ^ i Then
'        Shape1(15 - i).BackColor = &HFF00& ' vert clair
'    Else
'        Shape1(15 - i).BackColor = &H8000&  'vert foncé
'    End If
'Next i
'End Sub


Private Sub UserControl_Initialize()
    '  Initialise la liste
    cboPort_ES(0).AddItem "Lecture Port A"
    cboPort_ES(0).AddItem "Ecriture Port A"
    cboPort_ES(0).ListIndex = 1
    cboPort_ES(0).AddItem "Lecture Port C"
    cboPort_ES(0).AddItem "Ecriture Port C"
    cboPort_ES(0).ListIndex = 0
        
'    initialise_ports
'    initialise_port (0)
'    initialise_port (1)
'    initialise_port_c
    
    Timer1.Interval = 10
    Timer1.Enabled = True

End Sub


Private Sub Erreur(msg As String)
    Debug.Print msg
End Sub

