' Afficheur 8 bits
' ================

' propri�t�s
'  Couleur : couleur de toutes les LED (allum�es)
'  N : nombre � afficher / nombre affich�

' Rem : se passer des groupes de contr�les
'  http://plasserre.developpez.com/v3-9.htm

Option Explicit On
Option Strict On

Public Class AfficheurOctet
    Const Nbits As Integer = 8

    Dim Leds(Nbits - 1) As Led.Led

    Dim m_N As Byte ' nb � afficher (sur 8 bits)
    Dim i As Integer
    ' couleur de toutes les leds (lorsqu'elles sont allum�es)
    Dim m_Couleur As Color = Color.FromArgb(0, 255, 0)

    Private Led2 As Led.Led

    Private Sub AfficheurOctet_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        FlowLayoutPanel1.FlowDirection = FlowDirection.RightToLeft

        For i = 0 To Nbits - 1
            Leds(i) = New Led.Led
            Me.FlowLayoutPanel1.Controls.Add(Leds(i))
        Next i
    End Sub


    Private Sub Eteindre_toutes()
        For Each ctl As Led.Led In FlowLayoutPanel1.Controls
            ctl.Eteindre()
        Next
        afficher()
    End Sub

    Private Sub Allumer_toutes()
        For Each ctl As Led.Led In FlowLayoutPanel1.Controls
            ctl.Allumer()
        Next
        afficher()
    End Sub

    Public Property N() As Byte
        Get
            N = m_N
        End Get
        Set(ByVal value As Byte)
            If m_N <> value Then
                m_N = value
                'PropertyChanged N
            End If
            afficher()
        End Set
    End Property

    Private Sub afficher()
        'Debug.Print "afficher"
        Dim N As Byte
        N = m_N ' copie afin de ne pas modifier la valeur de m_N
        Dim i As Integer = 0
        For Each ctl As Led.Led In FlowLayoutPanel1.Controls
            If N >= 2 ^ i Then ' bit � 1
                ctl.Allumer()
            Else ' bit � 0
                ctl.Eteindre()
            End If
            i = i + 1
        Next
    End Sub

    Public Property Couleur() As Color
        Get
            Couleur = m_Couleur
        End Get
        Set(ByVal value As Color)
            If value <> m_Couleur Then
                m_Couleur = value
                ' PropertyChanged

            End If
        End Set
    End Property

    ' Permet de savoir si un bit est activ� ou pas
    ' Cette propri�t� peut-�tre volontairement d�sactiv�e
    ' afin ne pas faciliter la vie aux �l�ves
    ' en mettant Private au lieu de Public
    'Public Property Bit(ByVal thisbit As Byte) As Boolean
    '    Get
    '        Bit = Led1(thisbit).Etat
    '    End Get
    '    Set(ByVal new_val As Boolean)
    '        If (Led1(thisbit).Etat = True And new_val = False) Then
    '            m_N = m_N - CByte(2 ^ thisbit)
    '        End If
    '        If (Led1(thisbit).Etat = False And new_val = True) Then
    '            m_N = m_N + CByte(2 ^ thisbit)
    '        End If
    ''PropertyChanged(Bit(thisbit))
    '        afficher()
    '    End Set
    'End Property
End Class