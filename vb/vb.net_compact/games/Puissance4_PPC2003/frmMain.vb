Option Explicit On

Public Class frmMain
    Const nb_lignes As Integer = 6
    Const nb_colonnes As Integer = 7

    Const rayon_jeton As Double = 0.4

    Dim aJeu(nb_colonnes - 1, nb_lignes - 1) As Integer ' matrice du jeu
    Dim aNbPions(nb_colonnes - 1) As Integer ' nb de pions dans une colonne donnée
    Dim nb_coups_joues As Integer ' nb de coups joues
    Const alignes As Integer = 4 ' nb de pions à aligner pour gagner

    Dim joueur As Integer
    ' joueur = 1 ou 2

    Dim etat_de_la_partie As Integer
    ' 0 en cours
    ' 1 partie gagnée par joueur 1
    ' 2 partie gagnée par joueur 2
    ' 3 partie nulle

    Dim g As Graphics

    Private Sub mnuApropos_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles mnuApropos.Click
        MsgBox("Puissance 4" & Chr(13) & "par S. CELLES")
    End Sub

    Private Sub mnuNouveau_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles mnuNouveau.Click
        initialiser_jeu()
        afficher_jeu()
    End Sub

    Private Sub PictureBox1_Paint(ByVal sender As Object, ByVal e As System.Windows.Forms.PaintEventArgs) Handles PictureBox1.Paint
        g = e.Graphics

        Dim i, j As Integer

        g.Clear(Color.White)

        afficher_grille(g)

        For j = 0 To nb_lignes - 1
            For i = 0 To nb_colonnes - 1
                afficher_jeton(g, i, j, aJeu(i, j))
            Next i
        Next j

    End Sub

    Private Sub afficher_jeton(ByRef g As Graphics, ByVal X As Integer, ByVal Y As Integer, ByVal joueur As Integer)
        If joueur = 1 Then
            afficher_disque(g, X, Y, Color.Red)
        ElseIf joueur = 2 Then
            afficher_disque(g, X, Y, Color.Yellow)
        Else
            ' la case est vide !
        End If
    End Sub


    Private Sub afficher_disque(ByRef g As Graphics, ByVal X As Integer, ByVal Y As Integer, ByVal couleur As Color)
        Dim x1, y1 As Double
        Dim w1, h1 As Double
        x1 = X - 0.5 : y1 = Y - 0.5 : jeu_vers_pic(x1, y1)
        w1 = rayon_jeton : h1 = rayon_jeton : jeu_vers_pic(w1, h1)

        Dim stylo As Pen
        stylo = New Pen(couleur)

        g.DrawEllipse(stylo, x1, y1, w1, h1)
    End Sub


    Private Sub PictureBox1_MouseUp(ByVal sender As Object, ByVal e As System.Windows.Forms.MouseEventArgs) Handles PictureBox1.MouseUp
        'MsgBox(String.Format("Debug: Button={0} Xpic={1} Ypic={2}", e.Button, e.X, e.Y)) ' coordonnée picturebox
        Dim X, Y As Double
        X = e.X : Y = e.Y : pic_vers_jeu(X, Y) ' changement de coordonnées PicureBox vers Jeu
        'MsgBox(String.Format("Debug: Button={0} Xjeu={1} Yjeu={2}", e.Button, X, Y)) ' coordonnée jeu (double)

        Dim Xentier, Yentier As Integer
        Xentier = Int(X)
        Yentier = Int(Y)
        'MsgBox(String.Format("Debug: Button={0} Xjeu={1} Yjeu={2}", e.Button, Int(X), Int(Y))) ' coordonnée jeu (integer)

        If e.Button = Windows.Forms.MouseButtons.Left And etat_de_la_partie = 0 Then
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

            If aNbPions(Xentier) < nb_lignes Then ' il reste de la place pour poser le pion
                aJeu(Xentier, aNbPions(Xentier) + 1) = joueur ' placement du pion
                aNbPions(Xentier) = aNbPions(Xentier) + 1 ' incrémentation du nb de pion sur la colonne
                nb_coups_joues = nb_coups_joues + 1 ' incrémentation du nb de coups joués
                tester_victoire(Xentier, aNbPions(Xentier))
                changer_joueur()
            Else ' la case n'est pas vide
                Beep()
            End If
        Else
        End If

        afficher_jeu()
        afficher_message()

    End Sub

    'Private Sub initialiser_affichage(ByRef g As Graphics)
    'End Sub

    Private Sub afficher_jeu()
        PictureBox1.Refresh()
    End Sub


    Private Sub afficher_message()
        If etat_de_la_partie = 0 Then ' partie en cours
            If joueur = 1 Then
                lblMessage.Text = "Joueur 1 (rouge) c'est à vous de jouer !" _
                    + vbCrLf + "Il reste " + CStr(nb_coups_restants()) + " coup(s)"
            Else
                lblMessage.Text = "Joueur 2 (jaune) c'est à vous de jouer !" _
                    + vbCrLf + "Il reste " + CStr(nb_coups_restants()) + " coup(s)"
            End If
        ElseIf etat_de_la_partie = 1 Then
            lblMessage.Text = "Le joueur 1 (rouge) a gagné !"
        ElseIf etat_de_la_partie = 2 Then
            lblMessage.Text = "Le joueur 2 (jaune) a gagné !"
        ElseIf etat_de_la_partie = 3 Then
            lblMessage.Text = "Match nul"
        End If
    End Sub

    Private Sub initialiser_jeu()
        Dim i, j As Integer

        ' Effacement de la matrice de jeu
        For j = 0 To nb_lignes - 1
            For i = 0 To nb_colonnes - 1
                aJeu(i, j) = 0
            Next i
        Next j

        ' Effacement de la liste de pions par colonnes
        For i = 0 To nb_colonnes - 1
            aNbPions(i) = 0
        Next i

        joueur = 1
        etat_de_la_partie = 0

        afficher_message()
    End Sub

    Private Sub changer_joueur()
        If joueur = 1 Then
            joueur = 2
        Else
            joueur = 1
        End If
    End Sub


    ' changement de coordonnées jeu->picturebox
    '       xjeu
    '       /\
    '   -------> xpic
    '  |    |
    ' /|    |
    ' \|----+
    'yjeu
    '  |
    ' \ /
    '  ypic
    ' mise à l'échelle + rotation 90°
    Private Sub jeu_vers_pic(ByRef x As Double, ByRef y As Double)
        Dim xtemp As Double = x
        Dim ytemp As Double = y
        x = PictureBox1.Width - (ytemp / nb_lignes) * PictureBox1.Width
        y = PictureBox1.Height - (xtemp / nb_colonnes) * PictureBox1.Height
    End Sub


    ' changement de coordonnées picturebox->jeu
    ' remise à l'échelle + rotation -90°
    Private Sub pic_vers_jeu(ByRef x As Double, ByRef y As Double)
        Dim xtemp As Double = x
        Dim ytemp As Double = y
        y = ((PictureBox1.Width - xtemp) / PictureBox1.Width) * nb_lignes
        x = ((PictureBox1.Height - ytemp) / PictureBox1.Height) * nb_colonnes
    End Sub

    Private Sub tester_changement_jeu_vers_pic(ByRef g As Graphics)
        'g.DrawLine(stylo, 0, 0, PictureBox1.Width, PictureBox1.Height) ' diagonale pour test

        Dim stylo As Pen ' = Pens.Black
        stylo = New Pen(Color.Black)

        ' changement de coordonnées jeu->picturebox
        Dim x1, y1, x2, y2 As Double
        x1 = 0 : y1 = 0 : jeu_vers_pic(x1, y1)
        x2 = nb_colonnes : y2 = nb_lignes : jeu_vers_pic(x2, y2)
        g.DrawLine(stylo, x1, y1, x2, y2)
        'g.DrawEllipse(stylo,
    End Sub

    Private Sub afficher_grille(ByRef g As Graphics)
        Dim i, j As Integer
        Dim x1, y1, x2, y2 As Double
        Dim stylo As Pen ' = Pens.Black
        stylo = New Pen(Color.Black)

        ' Tracé de la grille
        '  lignes horizontales (sur jeu)
        For i = 1 To nb_lignes - 1
            ' changement de coordonnées jeu->picturebox
            x1 = 0 : y1 = i : jeu_vers_pic(x1, y1)
            x2 = nb_colonnes : y2 = i : jeu_vers_pic(x2, y2)
            g.DrawLine(stylo, x1, y1, x2, y2) ' ligne horizontale (sur jeu)
        Next i

        '  lignes verticales (sur jeu)
        For j = 1 To nb_colonnes - 1
            ' changement de coordonnées jeu->picturebox
            x1 = j : y1 = 0 : jeu_vers_pic(x1, y1)
            x2 = j : y2 = nb_lignes : jeu_vers_pic(x2, y2)
            g.DrawLine(stylo, x1, y1, x2, y2) ' ligne verticale (sur jeu)
        Next j
    End Sub

    Private Function nb_coups_restants() As Integer
        nb_coups_restants = nb_lignes * nb_colonnes - nb_coups_joues
    End Function

    Private Sub frmMain_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles MyBase.Load
        initialiser_jeu()
        afficher_jeu()
    End Sub


    Private Sub tester_victoire(ByVal X As Integer, ByVal Y As Integer)
        etat_de_la_partie = 0

        ' on teste en se déplaçant vers la gauche et la droite pour compter les pions
        ' voisins du même joueur
        ' on procède de même vers le bas (mais pas vers le haut !)
        ' on compte aussi les voisins en diagonale

        Dim i, j As Integer
        Dim voisins As Integer

        ' comptage du nb de voisins vers le bas
        voisins = 0
        If aNbPions(X) >= alignes Then ' uniquement si la colonne comporte assez de pions
            For i = 1 To alignes - 1
                If aJeu(X, Y - i) = joueur Then
                    voisins = voisins + 1
                Else
                    ' ça n'est pas un pion du joueur en cours
                    Exit For
                End If
            Next i
        End If
        If voisins = alignes - 1 Then ' 4 alignés = 3 voisins
            etat_de_la_partie = joueur
        End If

        ' comptage du nb de voisins à gauche et à droite
        voisins = 0
        ' voisins de gauche
        For j = 1 To alignes - 1
            If X + j <= nb_colonnes Then
                If aJeu(X + j, Y) = joueur Then
                    voisins = voisins + 1
                Else
                    ' ça n'est pas un pion du joueur en cours
                    Exit For
                End If
            End If
        Next j

        ' voisins de droite
        For j = 1 To alignes - 1
            If X - j >= 1 Then
                If aJeu(X - j, Y) = joueur Then
                    voisins = voisins + 1
                Else
                    ' ça n'est pas un pion du joueur en cours
                    Exit For
                End If
            End If
        Next j
        ' test du nb de voisins
        If voisins = alignes - 1 Then ' 4 alignés = 3 voisins
            etat_de_la_partie = joueur
        End If


        ' comptage du nb de voisins en diagonale /
        voisins = 0
        ' voisins de haut-droite
        For j = 1 To alignes - 1
            If X + j <= nb_colonnes And Y + j <= nb_lignes Then
                If aJeu(X + j, Y + j) = joueur Then
                    voisins = voisins + 1
                Else
                    ' ça n'est pas un pion du joueur en cours
                    Exit For
                End If
            End If
        Next j
        ' voisins de bas-gauche
        For j = 1 To alignes - 1
            If X - j >= 1 And Y - j >= 1 Then
                If aJeu(X - j, Y - j) = joueur Then
                    voisins = voisins + 1
                Else
                    ' ça n'est pas un pion du joueur en cours
                    Exit For
                End If
            End If
        Next j
        ' test du nb de voisins
        If voisins = alignes - 1 Then ' 4 alignés = 3 voisins
            etat_de_la_partie = joueur
        End If

        ' comptage du nb de voisins en diagonale \
        voisins = 0
        ' voisins de haut-gauche
        For j = 1 To alignes - 1
            If X - j >= 1 And Y + j <= nb_lignes Then
                If aJeu(X - j, Y + j) = joueur Then
                    voisins = voisins + 1
                Else
                    ' ça n'est pas un pion du joueur en cours
                    Exit For
                End If
            End If
        Next j
        ' voisins de bas-droite
        For j = 1 To alignes - 1
            If X + j <= nb_colonnes And Y - j >= 1 Then
                If aJeu(X + j, Y - j) = joueur Then
                    voisins = voisins + 1
                Else
                    ' ça n'est pas un pion du joueur en cours
                    Exit For
                End If
            End If
        Next j
        ' test du nb de voisins
        If voisins = alignes - 1 Then ' 4 alignés = 3 voisins
            etat_de_la_partie = joueur
        End If
    End Sub

End Class
