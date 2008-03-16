Option Explicit On
'Option Strict On

Imports System.Math

Public Class frmMain
    'Dim dimension As Integer
    Dim nb_colonnes As Integer = 7
    Dim nb_lignes As Integer = 7

    Dim aJeu(,) As Trou

    Const strTitre As String = "Solitaire"
    Dim nb_coups_joues As Integer ' nb de coups joues

    Enum Tablier
        Europeen
        Anglais
    End Enum
    Dim tab As Tablier

    Enum Situation
        Arret
        Enlevement
        Jeu
        FinJeu
    End Enum
    Dim mode As Situation

    Enum Trou
        Impossible
        Vide
        Occupe
        PretADeplacer
    End Enum

    Const rayon_jeton As Double = 0.4


    Private Sub frmMain_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        initialiser_jeu()
    End Sub

    Private Sub mnuNouveau_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles mnuNouveau.Click
        initialiser_jeu()
        afficher()
    End Sub

    Private Sub mnuAideApropos_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles mnuAideApropos.Click
        MsgBox(strTitre & Chr(13) & "par S. CELLES")
    End Sub


    Private Sub PictureBox1_Paint(ByVal sender As Object, ByVal e As System.Windows.Forms.PaintEventArgs) Handles PictureBox1.Paint
        Dim g As Graphics
        g = e.Graphics
        g.Clear(Color.White)
        Dim stylo As Pen
        stylo = Pens.Black
        'g.DrawLine(stylo, 0, 0, PictureBox1.Width, PictureBox1.Height)
        afficher_tablier(g)
        'afficher_pions(g)
        'afficher_tablier_console()
    End Sub

    Private Sub afficher()
        PictureBox1.Refresh()
    End Sub

    Private Sub initialiser_jeu()
        nb_coups_joues = 0
        tab = Tablier.Europeen
        mode = Situation.Arret

        'nb_colonnes = 8
        'nb_lignes = 7
        ReDim aJeu(nb_lignes - 1, nb_colonnes - 1)

        Dim i, j As Integer
        For i = 0 To nb_lignes - 1
            For j = 0 To nb_colonnes - 1
                aJeu(i, j) = Trou.Occupe
            Next
        Next

        If tab = Tablier.Europeen Then
            For i = 0 To 1
                For j = 0 To 1
                    aJeu(i, j) = Trou.Impossible
                    aJeu(nb_lignes - 1 - i, nb_colonnes - 1 - j) = Trou.Impossible
                    aJeu(i, nb_colonnes - 1 - j) = Trou.Impossible
                    aJeu(nb_colonnes - 1 - i, j) = Trou.Impossible
                Next
            Next

        ElseIf tab = Tablier.Anglais Then
            For i = 0 To 1
                For j = 0 To 1
                    If i = 1 And j = 1 Then
                    Else
                        aJeu(i, j) = Trou.Impossible
                        aJeu(nb_lignes - 1 - i, nb_colonnes - 1 - j) = Trou.Impossible
                        aJeu(i, nb_colonnes - 1 - j) = Trou.Impossible
                        aJeu(nb_lignes - 1 - i, j) = Trou.Impossible
                    End If
                Next
            Next
        End If

        ' Enlever un pion
        ' Enlever le pion central
        aJeu(CInt((nb_lignes - 1) / 2), CInt((nb_colonnes - 1) / 2)) = Trou.Vide


    End Sub

    Private Sub afficher_tablier(ByVal g As Graphics)
        'Debug.Print("Graphics")
        Dim i, j As Integer
        Dim x1, y1, x2, y2, xc, yc As Double
        Dim j1, i1, j2, i2 As Integer
        Dim stylo As Pen ' = Pens.Black
        stylo = New Pen(Color.Black)
        stylo.Width = 1

        Dim brosse As SolidBrush
        brosse = New SolidBrush(Color.Yellow)

        ' Tracé de la grille
        '  lignes horizontales (sur jeu)
        'For i = 1 To nb_lignes - 1
        '' changement de coordonnées jeu->picturebox
        'x1 = 0 : y1 = i : jeu_vers_pic(x1, y1)
        'x2 = nb_colonnes : y2 = i : jeu_vers_pic(x2, y2)
        'g.DrawLine(stylo, CInt(x1), CInt(y1), CInt(x2), CInt(y2)) ' ligne horizontale (sur jeu)
        'Next i

        '  lignes verticales (sur jeu)
        'For j = 1 To nb_colonnes - 1
        '' changement de coordonnées jeu->picturebox
        'x1 = j : y1 = 0 : jeu_vers_pic(x1, y1)
        'x2 = j : y2 = nb_lignes : jeu_vers_pic(x2, y2)
        'g.DrawLine(stylo, CInt(x1), CInt(y1), CInt(x2), CInt(y2)) ' ligne verticale (sur jeu)
        'Next j

        Dim pion As Trou

        For i = 0 To nb_lignes - 1
            For j = 0 To nb_colonnes - 1
                pion = aJeu(i, j)
                If pion <> Trou.Impossible Then
                    j1 = j : i1 = i : jeu_vers_pic(j1, i1)
                    j2 = j + 1 : i2 = i + 1 : jeu_vers_pic(j2, i2)
                    g.DrawRectangle(stylo, j1, i1, j2 - j1, i2 - i1) ' dessine juste la case !

                    If pion = Trou.Occupe Or aJeu(i, j) = Trou.PretADeplacer Then
                        'x1 = j : y1 = i : jeu_vers_pic(x1, y1)
                        'x2 = j + 1 : y2 = i + 1 : jeu_vers_pic(x2, y2)

                        'Dim x1, y1 As Double
                        'Dim x2, y2 As Double
                        xc = j + 0.5 ' abscisse centre
                        yc = i + 0.5 ' ordonnée centre
                        x1 = xc - rayon_jeton : y1 = yc + rayon_jeton : jeu_vers_pic(x1, y1)
                        x2 = xc + rayon_jeton : y2 = yc - rayon_jeton : jeu_vers_pic(x2, y2)

                        If pion = Trou.Occupe Then
                            brosse.Color = Color.Orange
                        Else ' pion = Trou.PretADeplacer
                            brosse.Color = Color.Red
                        End If
                        g.FillEllipse(brosse, CInt(x1), CInt(y1), CInt(x2 - x1), CInt(y2 - y1))
                    Else 'If aJeu(i, j) = Trou.Vide Then

                    End If
                End If
            Next
        Next
    End Sub


    ' Mise à l'échelle seule (pas de rotation)
    ' ----------------------------------------
    'Private Sub jeu_vers_pic(ByRef x As Double, ByRef y As Double)
    '    x = (x / nb_colonnes) * PictureBox1.Width
    '    y = (y / nb_lignes) * PictureBox1.Height
    'End Sub
    Private Sub jeu_vers_pic(ByRef x As Double, ByRef y As Double)
        x = (x * PictureBox1.Width) / nb_colonnes
        y = (y * PictureBox1.Height / nb_lignes)
    End Sub


    ' changement de coordonnées picturebox->jeu
    ' remise à l'échelle sans rotation
    Private Sub pic_vers_jeu(ByRef x As Double, ByRef y As Double)
        x = (x * nb_colonnes) / PictureBox1.Width
        y = (y * nb_lignes) / PictureBox1.Height
    End Sub


    Private Sub afficher_tablier_console()
        'Console.WriteLine("Console")
        Dim i, j As Integer
        Dim pion As Trou
        For i = 0 To nb_lignes - 1
            Console.Write(" ")
            For j = 0 To nb_colonnes - 1
                pion = aJeu(i, j)
                If pion = Trou.Impossible Then
                    Console.Write("#")
                ElseIf pion = Trou.Vide Then
                    Console.Write(" ")
                ElseIf pion = Trou.Occupe Then
                    Console.Write("*")
                Else
                    Console.Write("?")
                End If
            Next
            Console.WriteLine("")
        Next
        Console.WriteLine("---------")
        Console.WriteLine("Nb=" & nb_coups_joues)
        Console.WriteLine("---------")
    End Sub

    Private Function distance(ByVal i1 As Integer, ByVal j1 As Integer, ByVal i2 As Integer, ByVal j2 As Integer) As Integer
        If i1 = i2 Or j1 = j2 Then ' horizontale ou verticale 
            If i1 = i2 Then
                distance = Abs(j2 - j1)
            ElseIf j1 = j2 Then
                distance = Abs(i2 - i1)
            End If
        Else
            distance = 0
            Err.Raise(5, , "Diagonale interdite")
        End If
    End Function

    Private Sub deplacer(ByVal i1 As Integer, ByVal j1 As Integer, ByVal i2 As Integer, ByVal j2 As Integer)
        Dim iM, jM As Integer
        If aJeu(i1, j1) = Trou.Occupe Then
            If aJeu(i2, j2) = Trou.Vide Then
                If distance(i1, j1, i2, j2) = 2 Then
                    iM = CInt((i1 + i2) / 2) : jM = CInt((j1 + j2) / 2)
                    If aJeu(iM, jM) = Trou.Occupe Then
                        aJeu(i1, j1) = Trou.Vide
                        aJeu(i2, j2) = Trou.Occupe
                        aJeu(iM, jM) = Trou.Vide
                        nb_coups_joues = nb_coups_joues + 1
                    Else
                        Err.Raise(4, , "Pas de pion à sauter")
                    End If
                Else
                    Err.Raise(3, , "Distance différente de 2")
                End If
            Else
                Err.Raise(2, , "Pas de place pour poser le pion")
            End If
        Else
            Err.Raise(1, , "Pas de pion à déplacer")
        End If
    End Sub

    Private Sub mnuTest_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles mnuTest.Click
        Try
            deplacer(1, 3, 3, 3)
        Catch exc As Exception
            'Debug.Print(exc.ToString)
            'Debug.Print(exc.Message)
            MsgBox(exc.Message)
        End Try
        afficher()
    End Sub


    Private Sub PictureBox1_Resize(ByVal sender As Object, ByVal e As System.EventArgs) Handles PictureBox1.Resize
        Me.afficher()
    End Sub
End Class
