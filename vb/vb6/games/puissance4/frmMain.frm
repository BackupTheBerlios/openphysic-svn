VERSION 5.00
Begin VB.Form frmMain 
   Caption         =   "Puissance 4"
   ClientHeight    =   3960
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8235
   LinkTopic       =   "Form1"
   ScaleHeight     =   3960
   ScaleWidth      =   8235
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2 
      Caption         =   "&Quitter"
      Height          =   495
      Left            =   5640
      TabIndex        =   4
      Top             =   3240
      Width           =   1215
   End
   Begin VB.CommandButton cmdRecommencer 
      Caption         =   "&Recommencer"
      Height          =   495
      Left            =   5640
      TabIndex        =   3
      Top             =   1800
      Width           =   1215
   End
   Begin VB.CommandButton cmdTest 
      Caption         =   "&Tester"
      Height          =   495
      Left            =   5640
      TabIndex        =   1
      Top             =   2520
      Width           =   1215
   End
   Begin VB.PictureBox Picture1 
      BackColor       =   &H00FFFFFF&
      Height          =   3495
      Left            =   240
      ScaleHeight     =   3435
      ScaleWidth      =   4275
      TabIndex        =   0
      Top             =   240
      Width           =   4335
   End
   Begin VB.Label lblMessage 
      Alignment       =   2  'Center
      Height          =   1215
      Left            =   4920
      TabIndex        =   2
      Top             =   360
      Width           =   3135
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Const nb_lignes = 6
Const nb_colonnes = 7

Const rayon_jeton = 0.4

Dim aJeu(1 To nb_colonnes, 1 To nb_lignes) As Integer ' matrice du jeu
Dim aNbPions(1 To nb_colonnes) As Integer ' nb de pions dans une colonne donnée
Dim nb_coups_joues ' nb de coups joues
Const alignes = 4 ' nb de pions à aligner pour gagner

'Dim i, j, i2 As Integer

Dim joueur As Integer

Private Sub cmdRecommencer_Click()
initialiser_jeu
afficher_jeu
End Sub

Private Sub cmdTest_Click()
    Debug.Print "Debug"
    Debug.Print joueur, nb_coups_restants
End Sub

Private Sub Command2_Click()
End
End Sub

Private Sub Form_Load()
' initialisation afficheur (PictureBox)
With Picture1
    .ScaleMode = 0
    .ScaleHeight = -nb_lignes
    .ScaleWidth = nb_colonnes
    .ScaleTop = nb_lignes
    .ScaleLeft = 0
End With

initialiser_jeu
End Sub

Private Sub afficher_grille()
Dim i, j As Integer

' Tracé de la grille
Picture1.ForeColor = vbBlack ' couleur de tracé
'Picture1.FillColor = vbBlack ' couleur de remplissage
For i = 1 To nb_lignes - 1
    Picture1.Line (0, i)-(nb_colonnes, i) ' ligne horizontale
Next i

For j = 1 To nb_colonnes - 1
    Picture1.Line (j, 0)-(j, nb_lignes) ' ligne verticale
Next j
End Sub

Private Sub afficher_jeton(ByVal X As Integer, ByVal Y As Integer, ByVal joueur As Integer)
If joueur = 1 Then
    afficher_jeton1 X, Y
ElseIf joueur = 2 Then
    afficher_jeton2 X, Y
Else
    ' la case est vide !
End If
End Sub


Private Sub afficher_jeton1(ByVal X As Integer, ByVal Y As Integer)
Picture1.ForeColor = vbRed
Picture1.FillStyle = 0 ' mode de remplissage = plein
Picture1.FillColor = Picture1.ForeColor ' couleur de remplissage

Picture1.Circle (X - 0.5, Y - 0.5), rayon_jeton
End Sub

Private Sub afficher_jeton2(ByVal X As Integer, ByVal Y As Integer)
Picture1.ForeColor = vbYellow ' couleur de contour
Picture1.FillStyle = 0 ' mode de remplissage = plein
Picture1.FillColor = Picture1.ForeColor

Picture1.Circle (X - 0.5, Y - 0.5), rayon_jeton
End Sub

Private Sub Picture1_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
Dim Xentier, Yentier As Integer
Dim partie As Integer
partie = etat_partie

If Button = 1 And partie = 0 Then
    Xentier = Int(X) + 1
    Yentier = Int(Y) + 1
    
    ' En cas de clic sur la limite haute du PictureBox
    If Yentier >= nb_lignes + 1 Then
        Yentier = nb_lignes
    End If
    
    ' En cas de clic sur la limite droite du PictureBox
    If Xentier >= nb_colonnes + 1 Then
        Xentier = nb_colonnes
    End If
    
    Debug.Print "(X,Y)=(" + CStr(X) + ";" + CStr(Y) + ")"
    Debug.Print "(X,Y)=(" + CStr(Xentier) + ";" + CStr(Yentier) + ")"
    
    If aNbPions(Xentier) < nb_lignes Then ' il reste de la place pour poser le pion
        aJeu(Xentier, aNbPions(Xentier) + 1) = joueur ' placement du pion
        aNbPions(Xentier) = aNbPions(Xentier) + 1 ' incrémentation du nb de pion sur la colonne
        nb_coups_joues = nb_coups_joues + 1 ' incrémentation du nb de coups joués
        changer_joueur
    Else ' la case n'est pas vide
        Beep
        Debug.Print "La colonne est pleine"
    End If
Else
    Debug.Print "Fin de la partie"
End If

afficher_jeu
afficher_message

End Sub


Private Sub changer_joueur()
    If joueur = 1 Then
        joueur = 2
    Else
        joueur = 1
    End If
End Sub

Private Sub Picture1_Paint()
afficher_jeu
End Sub

Private Sub afficher_jeu()
Dim i, j As Integer

Picture1.Cls ' effacement

' test diagonale
'Picture1.Line (0, 0)-(nb_colonnes, nb_lignes) ' ligne verticale

afficher_grille

' Afficher les jetons
'afficher_jeton1 1, 1
'afficher_jeton2 2, 1
For j = 1 To nb_lignes
    For i = 1 To nb_colonnes
        afficher_jeton i, j, aJeu(i, j)
    Next i
Next j

End Sub

Private Sub initialiser_jeu()
Dim i, j As Integer

' Effacement de la matrice de jeu
For j = 1 To nb_lignes
    For i = 1 To nb_colonnes
        aJeu(i, j) = 0
    Next i
Next j

' Effacement de la liste de pions par colonnes
For i = 1 To nb_colonnes
    aNbPions(i) = 0
Next i

joueur = 1

afficher_message
End Sub

Private Function nb_coups_restants() As Integer
    nb_coups_restants = nb_lignes * nb_colonnes - nb_coups_joues
End Function

Private Function partie_est_gagne_par() As Integer
' 0 : personne
' 1 : joueur 1
' 2 : joueur 2
Dim k As Integer
Dim i, i2 As Integer
Dim j, j2 As Integer
Dim temp As Integer ' variable pour vérification du nombre de pions alignés
partie_est_gagne_par = 0

For k = 1 To 2 ' joueur
    ' ligne horizontale
    For j = 1 To nb_lignes
        temp = 0
        For i = 1 To nb_colonnes - alignes + 1
            temp = 0
            For i2 = i To i + alignes - 1
                If aJeu(i2, j) = k Then
                    temp = temp + 1
                End If
            Next i2
            If temp = alignes Then
                partie_est_gagne_par = k
            End If
        Next i
    Next j

    ' ligne verticale
    For i = 1 To nb_colonnes
        temp = 0
        For j = 1 To aNbPions(i) - alignes + 1
            'au lieu de nb_lignes - alignes + 1 (pas la peine de tester verticalement là
            'où il n'y a pas de pions)
            temp = 0
            For j2 = j To j + alignes - 1
                If aJeu(i, j2) = k Then
                    temp = temp + 1
                End If
            Next j2
            If temp = alignes Then
                partie_est_gagne_par = k
            End If
        Next j
    Next i
    
    ' / (6)
    'For i = 1 To nb_lignes ' Indice de la diagonale (ToFix)
    '    temp = 0
    '    For j = 1 To longueur_diag_BGHD(i) - alignes + 1
    '        temp = 0
    '        For j2 = j To j + alignes - 1
    '            If aJeu(i, j2) = k Then
    '                temp = temp + 1
    '            End If
    '        Next j2
    '        If temp = alignes Then
    '            partie_est_gagne_par = k
    '        End If
    '    Next j
    'Next i
    
    ' \
    
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
