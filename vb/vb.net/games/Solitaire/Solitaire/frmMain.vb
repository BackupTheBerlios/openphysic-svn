Option Explicit On
Option Strict On

Public Class frmMain
    Const dimension As Integer = 7

    Dim aJeu(dimension - 1, dimension - 1) As Trou

    Const strTitre As String = "Solitaire"
    Dim nb_coups_joues As Integer ' nb de coups joues

    Enum Tablier
        Europeen
        Anglais
    End Enum

    Enum Situation
        Arret
        Enlevement
        Jeu
        FinJeu
    End Enum

    Enum Trou
        Impossible
        Vide
        Occupe
    End Enum

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
    End Sub

    Private Sub afficher()
        PictureBox1.Refresh()
    End Sub

    Private Sub initialiser_jeu()
        Dim i, j As Integer
        For i = 0 To dimension - 1
            For j = 0 To dimension - 1
                aJeu(i, j) = Trou.Occupe
            Next
        Next
    End Sub

    Private Sub afficher_tablier(ByVal g As Graphics)

    End Sub
End Class
