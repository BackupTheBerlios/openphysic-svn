' Afficheur 8 bits
' ================

' propri�t�s
'  Couleur : couleur de toutes les LED (allum�es)
'  N : nombre � afficher / nombre affich�

Option Explicit On
Option Strict On

Public Class AfficheurOctet
    Private Sub AfficheurOctet_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

    End Sub

    Const Nbits As Integer = 8
    Dim m_N As Byte ' nb � afficher (sur 8 bits)
    Dim i As Integer
    ' couleur de toutes les leds (lorsqu'elles sont allum�es)
    Dim m_Couleur As Color = Color.FromArgb(0, 255, 0)

    Private Sub Eteindre_toutes()
        For i = 0 To Nbits - 1
            Led1(i).�teindre()
        Next i
        afficher()
    End Sub

    Private Sub Allumer_toutes()
        For i = 0 To Nbits - 1
            Led1(i).allumer()
        Next i
        afficher()
    End Sub

    Public Property N() As Byte
        Get
            N = m_N
        End Get
        Set(ByVal value As Byte)
            If m_N <> value Then
                m_N = value
                'PropertyChanged ColorON
            End If
            afficher()
        End Set
    End Property

    Private Sub afficher()
        'Debug.Print "afficher"
        Dim N As Byte
        N = m_N ' copie afin de ne pas modifier la valeur de m_N
        For i = Nbits - 1 To 0 Step -1
            If N >= 2 ^ i Then ' bit � 1
                N = N - CByte(2 ^ i)
                Led1(i).Allumer()
            Else ' bit � 0
                Led1(i).Eteindre()
            End If
        Next i
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
    Public Property Bit(ByVal thisbit As Byte) As Boolean
        Get
            Bit = Led1(thisbit).Etat
        End Get
        Set(ByVal new_val As Boolean)
            If (Led1(thisbit).Etat = True And new_val = False) Then
                m_N = m_N - CByte(2 ^ thisbit)
            End If
            If (Led1(thisbit).Etat = False And new_val = True) Then
                m_N = m_N + CByte(2 ^ thisbit)
            End If
            'PropertyChanged(Bit(thisbit))
            afficher()
        End Set
    End Property
End Class