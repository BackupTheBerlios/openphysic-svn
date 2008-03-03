VERSION 5.00
Begin VB.Form frmMain 
   Caption         =   "Morpion"
   ClientHeight    =   3495
   ClientLeft      =   120
   ClientTop       =   420
   ClientWidth     =   5880
   LinkTopic       =   "Form1"
   ScaleHeight     =   3495
   ScaleWidth      =   5880
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox txtDimension 
      Height          =   495
      Left            =   3840
      TabIndex        =   4
      Top             =   360
      Width           =   1215
   End
   Begin VB.CommandButton cmdQuitter 
      Caption         =   "&Quitter"
      Height          =   495
      Left            =   3840
      TabIndex        =   3
      Top             =   2640
      Width           =   1215
   End
   Begin VB.CommandButton cmdRecommencer 
      Caption         =   "&Recommencer"
      Height          =   495
      Left            =   3840
      TabIndex        =   2
      Top             =   1920
      Width           =   1215
   End
   Begin VB.PictureBox Picture1 
      BackColor       =   &H00FFFFFF&
      Height          =   2775
      Left            =   360
      ScaleHeight     =   2715
      ScaleWidth      =   2715
      TabIndex        =   0
      Top             =   360
      Width           =   2775
   End
   Begin VB.Label lblMessage 
      Height          =   735
      Left            =   3840
      TabIndex        =   1
      Top             =   960
      Width           =   1335
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim i, j As Integer

Const dimension_default = 3
Dim dimension As Integer

'Dim aJeu(dimension_default, dimension_default) As Integer ' tableau décrivant les pions joués
Dim aJeu() As Integer ' tableau décrivant les pions joués
' 0 pas de coup sur cette case
' 1 un pion du joueur 1
' 2 un pion du joueur 2

Dim joueur As Integer

Private Sub afficher_grille()
For i = 1 To dimension - 1
    Picture1.Line (i, 0)-(i, dimension)
Next i

For j = 1 To dimension - 1
    Picture1.Line (0, j)-(dimension, j)
Next j
End Sub

Private Sub afficher_croix(ByVal i As Integer, ByVal j As Integer)
    Picture1.Line (i - 1, j - 1)-(i, j)
    Picture1.Line (i - 1, j)-(i, j - 1)
End Sub

Private Sub afficher_cercle(ByVal i As Integer, ByVal j As Integer)
    Picture1.Circle (i - 0.5, j - 0.5), 0.5, vbRed
End Sub



Private Sub lancer_partie()
' initialiser le tableau de jeu
' c'est nécessaire en cas de redémarrage d'une partie
For i = 1 To dimension
    For j = 1 To dimension
        aJeu(i, j) = 0
    Next j
Next i

joueur = 1

afficher_message
End Sub

Private Sub cmdQuitter_Click()
End
End Sub

Private Sub cmdRecommencer_Click()
lancer_partie
afficher_jeu
End Sub

Private Sub Form_Load()
txtDimension.Text = dimension_default

lancer_partie

End Sub

Private Sub initialiser_affichage()
Picture1.ScaleMode = 0
Picture1.ScaleWidth = dimension
Picture1.ScaleHeight = -dimension
Picture1.ScaleTop = dimension
End Sub

Private Sub changer_joueur()
    If joueur = 1 Then
        joueur = 2
    Else
        joueur = 1
    End If
End Sub

Private Sub Picture1_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
Dim Xentier, Yentier As Integer
Dim partie As Integer
partie = etat_partie

If Button = 1 And partie = 0 Then
    Xentier = Int(X) + 1
    Yentier = Int(Y) + 1
    
    ' En cas de clic sur la limite haute du PictureBox
    If Yentier = dimension + 4 Then
        Yentier = dimension
    End If
    
    ' En cas de clic sur la limite droite du PictureBox
    If Xentier = dimension + 1 Then
        Xentier = dimension
    End If
    
    'Debug.Print "(X,Y)=(" + CStr(X) + ";" + CStr(Y) + ")"
    'Debug.Print "(X,Y)=(" + CStr(Xentier) + ";" + CStr(Yentier) + ")"
    
    If aJeu(Xentier, Yentier) = 0 Then ' la case est bien vide
        aJeu(Xentier, Yentier) = joueur
        changer_joueur
    Else ' la case n'est pas vide
        Beep
    End If
End If

afficher_jeu
    
End Sub

Private Sub Picture1_Paint()
afficher_jeu
End Sub

Private Sub afficher_message()
Dim gagnant As Integer
gagnant = etat_partie
If gagnant = 0 Then ' partie en cours
    If joueur = 1 Then
        lblMessage.Caption = "Joueur 1 c'est à vous de jouer !" _
            + vbCrLf + "Il reste " + CStr(nb_coups_restants) + " coup(s)"
    Else
        lblMessage.Caption = "Joueur 2 c'est à vous de jouer !" _
            + vbCrLf + "Il reste " + CStr(nb_coups_restants) + " coup(s)"
    End If
ElseIf gagnant = 1 Then
    lblMessage.Caption = "Le joueur 1 a gagné !"
ElseIf gagnant = 2 Then
    lblMessage.Caption = "Le joueur 2 a gagné !"
ElseIf gagnant = 3 Then
    lblMessage.Caption = "Match nul"
End If
End Sub

Private Sub afficher_jeu()
    Picture1.Cls

    afficher_grille

    'afficher_croix 1, 1
    'afficher_cercle 1, 2
    
    ' afficher les pions
    For i = 1 To dimension
        For j = 1 To dimension
            If aJeu(i, j) = 1 Then
                afficher_croix i, j
            End If
            If aJeu(i, j) = 2 Then
                afficher_cercle i, j
            End If
        Next j
    Next i
    
    afficher_message
End Sub

Private Function nb_coups_restants() As Integer
For i = 1 To dimension
    For j = 1 To dimension
        If aJeu(i, j) = 0 Then
            nb_coups_restants = nb_coups_restants + 1
        End If
    Next j
Next i
End Function

Private Function partie_est_gagne_par() As Integer
' 0 : personne
' 1 : joueur 1
' 2 : joueur 2
Dim k As Integer
Dim temp As Integer ' variable pour vérification du nombre de pions aligné
partie_est_gagne_par = 0
For k = 1 To 2 ' joueur

    For j = 1 To dimension
        temp = 0
        For i = 1 To dimension
            ' ligne horizontale
            If aJeu(i, j) = k Then
                temp = temp + 1
            End If
        Next i
        If temp = dimension Then
            partie_est_gagne_par = k
        End If
    Next j

    For j = 1 To dimension
        temp = 0
        For i = 1 To dimension
            'ligne verticale
            If aJeu(j, i) = k Then
                temp = temp + 1
            End If
        Next i
        If temp = dimension Then
            partie_est_gagne_par = k
        End If
    Next j
    
    ' diag /
    temp = 0
    For i = 1 To dimension
        If aJeu(i, i) = k Then
            temp = temp + 1
        End If
    Next i
    If temp = dimension Then
        partie_est_gagne_par = k
    End If
    
    ' diag \
    temp = 0
    For i = 1 To dimension
        If aJeu(dimension - i + 1, i) = k Then
            temp = temp + 1
        End If
    Next i
    If temp = dimension Then
        partie_est_gagne_par = k
    End If

Next k

End Function

Private Function etat_partie() As Integer
' 0 : partie en cours (il reste des coups à faire)
' 1 : partie gagnée par le joueur 1
' 2 : partie gagnée par le joueur 2
' 3 : partie nulle (plus de coup à jouer)

Dim gagnant As Integer
gagnant = partie_est_gagne_par

If gagnant = 1 Then
    etat_partie = 1
ElseIf gagnant = 2 Then
    etat_partie = 2
ElseIf nb_coups_restants = 0 And gagnant = 0 Then
    etat_partie = 3
Else
    etat_partie = 0
End If

End Function

Private Sub txtDimension_Change()
If IsNumeric(txtDimension.Text) Then
    dimension = CInt(txtDimension.Text)
Else
    dimension = dimension_default
End If
    
ReDim aJeu(1 To dimension, 1 To dimension) ' Preserve
lancer_partie
initialiser_affichage
afficher_jeu

End Sub
