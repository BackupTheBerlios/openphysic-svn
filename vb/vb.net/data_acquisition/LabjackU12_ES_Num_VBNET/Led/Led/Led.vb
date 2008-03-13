' Diode �lectroluminescente DEL
' =============================

' S�bastien CELLES
' IUT de Poitiers
' D�partement G�nie Thermique et Energie
' s.celles at gmail.com

' M�thodes publiques
'  allumer : allume la LED
'  �teindre : �teint la LED
'  inverser : inverse l'�tat de la LED

' Propri�t�s (en lecture/�criture)
'  ColorON : couleur lorsque la LED est allum�e
'  ColorOFF : couleur lorsque la LED est �teinte
'  Etat : �tat de la LED (�teinte ou allum�e)

' Ev�nements
'  Click : clic sur la LED
'  Change : changement d'�tat de la LED

' ToDo : Color = ColorON et calcul automatique de ColorOFF

Option Explicit On
Option Strict On

Imports System.Math ' pour Math.Sqrt

Public Class Led

    'Event Click()
    'Event Change()

    ' Couleur �teint/allum�
    'Dim m_ColorOFF As Color = Color.FromArgb(128, 64, 0) ' rouge fonc�
    'Dim m_ColorON As Color = Color.FromArgb(255, 0, 0) ' rouge vif
    Dim m_ColorOFF As Color = Color.FromArgb(0, 128, 0) ' vert fonc�
    Dim m_ColorON As Color = Color.FromArgb(0, 255, 0) ' vert vif

    ' Etat de la LED
    Public Enum LED As Integer
        Eteinte ' 0
        Allumee ' 1
    End Enum
    ' Etat de la LED (�teinte par d�faut)
    Dim m_Etat As LED = LED.Eteinte

    Dim g As Graphics

    Public Sub New()

        ' Cet appel est requis par le Concepteur Windows Form.
        InitializeComponent()

        ' Ajoutez une initialisation quelconque apr�s l'appel InitializeComponent().

    End Sub



    Private Sub PictureBox1_Paint(ByVal sender As Object, ByVal e As System.Windows.Forms.PaintEventArgs) Handles PictureBox1.Paint
        g = e.Graphics

        Dim couleur As Color

        If m_Etat = LED.Eteinte Then
            couleur = m_ColorOFF
        Else ' m_Etat = Etat.Allumee
            couleur = m_ColorON
        End If

        Dim brosse As SolidBrush = New SolidBrush(couleur)

        g.FillEllipse(brosse, 0, 0, PictureBox1.Width, PictureBox1.Height)
    End Sub

    Private Sub PictureBox1_MouseUp(ByVal sender As Object, ByVal e As System.Windows.Forms.MouseEventArgs) Handles PictureBox1.MouseUp
        'Debug.Print(String.Format("Button={0} X={1} Y={2}", e.Button, e.X, e.Y))
        Dim Xc, Yc As Double ' Centre
        Xc = CDbl(PictureBox1.Width) / 2.0
        Yc = CDbl(PictureBox1.Height) / 2.0
        Dim d As Double ' distance par rapport au centre
        d = Sqrt((e.X - Xc) ^ 2 + (e.Y - Yc) ^ 2)
        'Debug.Print(String.Format("Distance={0}", d))
        If d <= Min(Xc, Yc) Then
            Debug.Print("In")
            'RaiseEvent Click()
        Else
            Debug.Print("Out")
        End If
    End Sub


    Public Property Etat() As LED
        Get
            Return m_Etat
        End Get
        Set(ByVal new_etat As LED)
            m_Etat = new_etat
        End Set
    End Property

    Public Property ColorON() As Color
        Get
            Return m_ColorON
        End Get
        Set(ByVal value As Color)
            m_ColorON = value
        End Set
    End Property

    Public Property ColorOFF() As Color
        Get
            Return m_ColorOFF
        End Get
        Set(ByVal value As Color)
            m_ColorOFF = value
        End Set
    End Property

    Public Sub allumer()
        If m_Etat = LED.Eteinte Then ' LED �teinte
            'RaiseEvent Change()
        End If

        m_Etat = LED.Allumee

        afficher()
    End Sub

    Public Sub �teindre()
        If m_Etat = LED.Allumee Then ' LED Allum�e
            'RaiseEvent Change()
        End If

        m_Etat = LED.Eteinte

        afficher()
    End Sub

    Public Sub inverser()
        'RaiseEvent Change()

        If m_Etat = LED.Allumee Then
            m_Etat = LED.Eteinte
        Else
            m_Etat = LED.Allumee
        End If

        afficher()
    End Sub

    Public Sub afficher()
        PictureBox1.Refresh()
    End Sub
End Class
