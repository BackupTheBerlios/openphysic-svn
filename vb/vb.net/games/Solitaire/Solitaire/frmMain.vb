Option Explicit On
Option Strict On

Public Class frmMain

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

    Const dimension As Integer = 7

    Dim aJeu(dimension - 1, dimension - 1) As Trou

    Private Sub frmMain_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

    End Sub
End Class
