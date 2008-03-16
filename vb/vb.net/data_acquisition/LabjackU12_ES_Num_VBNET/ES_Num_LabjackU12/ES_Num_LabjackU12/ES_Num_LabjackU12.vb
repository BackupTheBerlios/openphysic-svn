' LabjackU12
' E/S numérique

' Sébastien CELLES
' IUT de Poitiers
' Génie Thermique et Energie

' Propriétés
'  Mode(i) : Ecriture (0) ou Lecture (1)
'  Port(i) : valeur présente sur le port (en décimal)

Option Explicit On
Option Strict On

Public Class ES_Num_LabjackU12

    Const nb_ports As Byte = 2 ' nb de ports (de 0 à nb_ports-1)

    Dim m_port(nb_ports - 1) As Byte ' 8 bits (contenu de chaque port)

    Enum EMode
        Lecture
        Ecriture
    End Enum
    Dim m_mode(nb_ports - 1) As EMode ' mode de chaque port (False=écriture ; True=Lecture)

    Dim gbPort(nb_ports - 1) As GroupBox
    Dim cboPort(nb_ports - 1) As ComboBox
    Dim txtPort(nb_ports - 1) As ComboBox
    Dim AfficheurOctets(nb_ports - 1) As AfficheurOctet.AfficheurOctet

    Public Sub New()

        ' Cet appel est requis par le Concepteur Windows Form.
        InitializeComponent()

        ' Ajoutez une initialisation quelconque après l'appel InitializeComponent().
        'Me.gbEntréesSortiesNumériques = New System.Windows.Forms.GroupBox
        'Me.TableLayoutPanel1 = New System.Windows.Forms.TableLayoutPanel
        'Me.gbPortA = New System.Windows.Forms.GroupBox
        'Me.gbPortC = New System.Windows.Forms.GroupBox
        'Me.FlowLayoutPortA = New System.Windows.Forms.FlowLayoutPanel
        'Me.FlowLayoutPortB = New System.Windows.Forms.FlowLayoutPanel
        'Me.gbEntréesSortiesNumériques.SuspendLayout()
        'Me.TableLayoutPanel1.SuspendLayout()
        'Me.gbPortA.SuspendLayout()
        'Me.gbPortC.SuspendLayout()
        'Me.SuspendLayout()
    End Sub
End Class
