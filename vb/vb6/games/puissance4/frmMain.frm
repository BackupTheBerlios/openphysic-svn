VERSION 5.00
Begin VB.Form frmMain 
   Caption         =   "Puissance 4"
   ClientHeight    =   5160
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8235
   LinkTopic       =   "Form1"
   ScaleHeight     =   5160
   ScaleWidth      =   8235
   StartUpPosition =   3  'Windows Default
   Begin VB.PictureBox Picture1 
      BackColor       =   &H00FFFFFF&
      Height          =   3495
      Left            =   360
      ScaleHeight     =   3435
      ScaleWidth      =   4275
      TabIndex        =   0
      Top             =   480
      Width           =   4335
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

Dim aJeu(nb_colonnes, nb_lignes) As Integer
Dim aNbPions(nb_colonnes) As Integer

Dim i, j As Integer


Private Sub Form_Load()
With Picture1
    .ScaleMode = 0
    .ScaleHeight = -nb_lignes
    .ScaleWidth = nb_colonnes
    .ScaleTop = nb_lignes
    .ScaleLeft = 0
End With


End Sub

Private Sub afficher_grille()
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
partie = 0 'etat_partie

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
    
    'If aJeu(Xentier, Yentier) = 0 Then ' la case est bien vide
    '    aJeu(Xentier, Yentier) = joueur
    '    changer_joueur
    'Else ' la case n'est pas vide
    '    Beep
    'End If
End If

afficher_jeu

End Sub

Private Sub Picture1_Paint()
afficher_jeu
End Sub

Private Sub afficher_jeu()
Picture1.Cls ' effacement

' test diagonale
'Picture1.Line (0, 0)-(nb_colonnes, nb_lignes) ' ligne verticale

afficher_grille

'afficher_jeton1 1, 1
'afficher_jeton2 2, 1
End Sub
