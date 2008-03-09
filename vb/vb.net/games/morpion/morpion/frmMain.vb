Public Class frmMain
    Const dimension_default As Integer = 3
    Dim dimension As Integer

    'Dim aJeu(dimension_default, dimension_default) As Integer ' tableau décrivant les pions joués
    Dim aJeu(,) As Integer ' tableau décrivant les pions joués
    ' 0 pas de coup sur cette case
    ' 1 un pion du joueur 1
    ' 2 un pion du joueur 2

    Dim joueur As Integer
    ' joueur=1 ou 2

    Dim etat_de_la_partie As Integer
    ' 0 en cours
    ' 1 partie gagnée par joueur 1
    ' 2 partie gagnée par joueur 2
    ' 3 partie nulle

    Dim g As Graphics

    Private Sub frmMain_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Debug.Print("frmMain_Load")
        'g = picturebox1.

        txtDimension.Text = dimension_default.ToString

        lancer_partie()
    End Sub

    Private Sub cmdQuitter_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles cmdQuitter.Click
        End
    End Sub

    Private Sub PictureBox1_MouseUp(ByVal sender As Object, ByVal e As System.Windows.Forms.MouseEventArgs)
        Debug.Print("Bouton:{0} X:{1} Y:{2}", e.Button.ToString, e.X, e.Y)


    End Sub

    Private Sub PictureBox1_Paint(ByVal sender As Object, ByVal e As System.Windows.Forms.PaintEventArgs)
        Debug.Print("PictureBox1_Paint")
        'Dim g As Graphics = e.Graphics
        g = e.Graphics
        'Beep()
        initialiser_affichage(g)
        afficher_jeu(g)
        'g.DrawLine(Pens.Black, 0, 0, PictureBox1.Width, PictureBox1.Height)
        'g.DrawLine(Pens.Black, 0, 0, 300, 300)
    End Sub

    Private Sub txtDimension_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs)
        If IsNumeric(txtDimension.Text) Then
            dimension = CInt(txtDimension.Text)
        Else
            dimension = dimension_default
        End If

        ReDim aJeu(dimension - 1, dimension - 1)
        ' les dim inférieures du tableau ne peuvent être que 0 en VB.Net
        ' -> 0 To dimension - 1
        ' pas besoin de Redim Preserve car on relance le jeu
        ' quand on modifie la dimension
        lancer_partie()
        'initialiser_affichage()
        'afficher_jeu(g)
    End Sub

    Private Sub initialiser_affichage(ByRef g As Graphics)
        g.TranslateTransform(0, PictureBox1.Height)
        g.ScaleTransform(CSng(PictureBox1.Width) / CSng(300), -CSng(PictureBox1.Height) / CSng(300))
    End Sub


    Private Sub lancer_partie()
        Dim i, j As Integer

        ' initialiser le tableau de jeu
        ' c'est nécessaire en cas de redémarrage d'une partie
        For i = 0 To dimension - 1
            For j = 0 To dimension - 1
                aJeu(i, j) = 0
            Next j
        Next i

        joueur = 1
        etat_de_la_partie = 0

        afficher_message()
    End Sub

    Private Sub afficher_message()
        If etat_de_la_partie = 0 Then ' partie en cours
            If joueur = 1 Then
                lblMessage.Text = "Joueur 1 c'est à vous de jouer !" _
                    + vbCrLf + "Il reste " + CStr(nb_coups_restants()) + " coup(s)"
            Else
                lblMessage.Text = "Joueur 2 c'est à vous de jouer !" _
                    + vbCrLf + "Il reste " + CStr(nb_coups_restants()) + " coup(s)"
            End If
        Else
            joueur = 0
            If etat_de_la_partie = 1 Then
                lblMessage.Text = "Le joueur 1 a gagné !"
            ElseIf etat_de_la_partie = 2 Then
                lblMessage.Text = "Le joueur 2 a gagné !"
            ElseIf etat_de_la_partie = 3 Then
                lblMessage.Text = "Match nul"
            End If
        End If
    End Sub

    Private Sub afficher_jeu(ByRef g As Graphics)
        Dim i, j As Integer

        g.Clear(Color.White)

        afficher_grille(g)

        'afficher_croix 1, 1
        'afficher_cercle 1, 2

        ' afficher les pions
        For i = 0 To dimension - 1
            For j = 0 To dimension - 1
                If aJeu(i, j) = 1 Then
                    afficher_croix(g, i, j)
                End If
                If aJeu(i, j) = 2 Then
                    afficher_cercle(g, i, j)
                End If
            Next j
        Next i

        afficher_message()
    End Sub

    Private Sub afficher_grille(ByRef g As Graphics)
        Dim i, j As Integer

        ' lignes verticales
        For i = 1 To dimension - 1
            g.DrawLine(Pens.Black, i * 100, 0, i * 100, dimension * 100)
        Next i

        ' lignes horizontales
        For j = 1 To dimension - 1
            g.DrawLine(Pens.Black, 0, j * 100, dimension * 100, j * 100)
        Next j
    End Sub

    Private Sub afficher_croix(ByRef g As Graphics, ByVal i As Integer, ByVal j As Integer)
        'Picture1.Line (i - 1, j - 1)-(i, j)
        'Picture1.Line (i - 1, j)-(i, j - 1)
    End Sub

    Private Sub afficher_cercle(ByRef g As Graphics, ByVal i As Integer, ByVal j As Integer)
        'g.DrawEllipse(Pens.Black, i - 0.5, j - 0.5, 0.5, 0.5)
        'Picture1.Circle (i - 0.5, j - 0.5), 0.5, vbRed
    End Sub

    Private Sub changer_joueur()

    End Sub

    Private Function nb_coups_restants() As Integer
        Dim i, j As Integer

        'nb_coups_restants = 0
        For i = 0 To dimension - 1
            For j = 0 To dimension - 1
                If aJeu(i, j) = 0 Then
                    nb_coups_restants = nb_coups_restants + 1
                End If
            Next j
        Next i
    End Function

    Private Sub tester_victoire(ByVal X As Integer, ByVal Y As Integer)
        etat_de_la_partie = 0

        ' on teste la victoire en faisant le produit sur une ligne, une colonne
        ' ou sur les 2 deux diagonales
        ' ex joueur 1 dimension 3 : 1*1*1=1^3
        ' ex joueur 2 dimension 3 : 2*2*2=2^3
        ' joueur^dimension
        Dim i As Integer

        Dim res_V As Integer
        Dim res_H As Integer
        Dim res_D1 As Integer
        Dim res_D2 As Integer

        res_V = 1 ' verticale
        res_H = 1 ' horizontale
        res_D1 = 1 ' diagonale /
        res_D2 = 1 ' diagonale \

        ' calcul des produits sur
        ' lignes verticales et horizontales
        ' lignes diagonale D1 et D2
        For i = 0 To dimension - 1
            res_V = aJeu(i, Y) * res_V
            res_H = aJeu(X, i) * res_H
            res_D1 = aJeu(i, i) * res_D1
            res_D2 = aJeu(dimension + 1 - i, i) * res_D2
        Next i

        ' le joueur gagne s'il a fait une ligne verticale, une horizontale
        ' ou une (des deux) diagonale
        If res_V = joueur ^ dimension Or res_H = joueur ^ dimension _
            Or res_D1 = joueur ^ dimension Or res_D2 = joueur ^ dimension Then
            etat_de_la_partie = joueur
        End If

    End Sub


    Private Sub cmdRecommencer_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)
        lancer_partie()
        'afficher_jeu(g)
    End Sub

End Class
