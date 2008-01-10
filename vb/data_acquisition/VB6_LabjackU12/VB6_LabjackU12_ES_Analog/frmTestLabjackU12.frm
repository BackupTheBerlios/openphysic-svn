VERSION 5.00
Begin VB.Form frmTestLabjackU12 
   Caption         =   "Form1"
   ClientHeight    =   4080
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7845
   LinkTopic       =   "Form1"
   ScaleHeight     =   4080
   ScaleWidth      =   7845
   StartUpPosition =   3  'Windows Default
   Begin TestLabjackU12.ES_Analog ES_Analog1 
      Height          =   2055
      Left            =   120
      TabIndex        =   1
      Top             =   240
      Width           =   6855
      _ExtentX        =   12091
      _ExtentY        =   3625
   End
   Begin VB.Timer Timer1 
      Interval        =   10
      Left            =   6840
      Top             =   1560
   End
   Begin VB.Label Label1 
      Caption         =   "Label1"
      Height          =   855
      Left            =   1320
      TabIndex        =   0
      Top             =   2760
      Width           =   1815
   End
End
Attribute VB_Name = "frmTestLabjackU12"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Form_Load()

    'ES_Analog1.sortie1 = 3
    ES_Analog1.Sortie(0) = 3
    'ES_Analog1.
End Sub

Private Sub Timer1_Timer()
    'Label1.Caption = ES_Analog1.entrée1
    'Label1.Caption = ES_Analog1.entrée(0)
    Label1.Caption = ES_Analog1.Nb_entrées_analogiques_max
End Sub
