' LabjackU12
' E/S num�rique

' S�bastien CELLES
' IUT de Poitiers
' G�nie Thermique et Energie

' Propri�t�s
'  Mode(i) : Ecriture (0) ou Lecture (1)
'  Port(i) : valeur pr�sente sur le port (en d�cimal)

Option Explicit On
Option Strict On

Public Class ES_Num_LabjackU12

    Const nb_ports As Byte = 2 ' nb de ports (de 0 � nb_ports-1)

    Dim m_port(nb_ports - 1) As Byte ' 8 bits (contenu de chaque port)

    Enum EMode
        Lecture
        Ecriture
    End Enum
    Dim m_mode(nb_ports - 1) As EMode ' mode de chaque port (False=�criture ; True=Lecture)

    Dim gbPort(nb_ports - 1) As GroupBox
    Dim cboPort(nb_ports - 1) As ComboBox
    Dim txtPort(nb_ports - 1) As ComboBox
    Dim AfficheurOctets(nb_ports - 1) As AfficheurOctet.AfficheurOctet

    Public Sub New()

        ' Cet appel est requis par le Concepteur Windows Form.
        InitializeComponent()

        ' Ajoutez une initialisation quelconque apr�s l'appel InitializeComponent().
        'Me.gbEntr�esSortiesNum�riques = New System.Windows.Forms.GroupBox
        'Me.TableLayoutPanel1 = New System.Windows.Forms.TableLayoutPanel
        'Me.gbPortA = New System.Windows.Forms.GroupBox
        'Me.gbPortC = New System.Windows.Forms.GroupBox
        'Me.FlowLayoutPortA = New System.Windows.Forms.FlowLayoutPanel
        'Me.FlowLayoutPortB = New System.Windows.Forms.FlowLayoutPanel
        'Me.gbEntr�esSortiesNum�riques.SuspendLayout()
        'Me.TableLayoutPanel1.SuspendLayout()
        'Me.gbPortA.SuspendLayout()
        'Me.gbPortC.SuspendLayout()
        'Me.SuspendLayout()
    End Sub
End Class
