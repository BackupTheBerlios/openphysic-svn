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


    Public Sub New()

        ' Cet appel est requis par le Concepteur Windows Form.
        InitializeComponent()


    End Sub

    Private Sub GroupBox1_Enter(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles GroupBox0.Enter

    End Sub
End Class
