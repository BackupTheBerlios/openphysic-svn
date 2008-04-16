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

    Dim lay As TableLayoutPanel
    Dim layPort(nb_ports - 1) As TableLayoutPanel
    Dim gbPort(nb_ports - 1) As GroupBox
    Dim cboPort(nb_ports - 1) As ComboBox
    Dim txtPort(nb_ports - 1) As TextBox
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

        Dim i As Integer
        lay = New TableLayoutPanel
        lay.BackColor = Color.Red
        lay.SuspendLayout()

        lay.Dock = DockStyle.Fill
        lay.ColumnCount = 1
        lay.RowCount = 2

        lay.Dock = DockStyle.Fill

        lay.RowStyles.Add(New RowStyle(SizeType.Percent, 100.0!))
        lay.RowStyles.Add(New RowStyle(SizeType.Percent, 100.0!))
        'lay.RowStyles.Add(New RowStyle(SizeType.Absolute, 200.0!))

        For i = 0 To nb_ports - 1
            gbPort(i) = New GroupBox
            gbPort(i).BackColor = Color.Gray
            gbPort(i).Dock = DockStyle.Fill
            gbPort(i).Text = "Port " & CStr(i)

            layPort(i) = New TableLayoutPanel
            layPort(i).SuspendLayout()
            layPort(i).BackColor = Color.Yellow
            layPort(i).ColumnCount = 3
            layPort(i).RowCount = 1

            'cboPort(i) = New ComboBox
            'gbPort(i).Controls.Add(cboPort(i))

            'txtPort(i) = New TextBox
            'gbPort(i).Controls.Add(txtPort(i))

            AfficheurOctets(i) = New AfficheurOctet.AfficheurOctet
            gbPort(i).Controls.Add(AfficheurOctets(i))

            'lay.ColumnStyles.Add(New ColumnStyle(SizeType.Percent, 12.5!))
            'Leds(i) = New Led.Led
            'Leds(i).Anchor = AnchorStyles.Right And AnchorStyles.Left
            'Leds(i).Anchor = AnchorStyles.Top And AnchorStyles.Bottom And AnchorStyles.Right And AnchorStyles.Left
            'Leds(i).Dock = DockStyle.Fill    'DockStyle.Fill

            'gbPort(i).Controls.Add(layPort(i))
            layPort(i).ResumeLayout()
            lay.Controls.Add(gbPort(i), i, 0)
        Next i

        Me.gbEntréesSortiesNumériques.Controls.Add(Me.lay)
        lay.ResumeLayout()

        'AfficheurOctets(1).Couleur = Color.Red ' null ?

    End Sub
End Class
