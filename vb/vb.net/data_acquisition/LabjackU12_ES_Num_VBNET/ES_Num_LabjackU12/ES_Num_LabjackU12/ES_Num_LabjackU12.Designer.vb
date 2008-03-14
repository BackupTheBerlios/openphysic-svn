<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class ES_Num_LabjackU12
    Inherits System.Windows.Forms.UserControl

    'UserControl1 remplace la méthode Dispose pour nettoyer la liste des composants.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        If disposing AndAlso components IsNot Nothing Then
            components.Dispose()
        End If
        MyBase.Dispose(disposing)
    End Sub

    'Requise par le Concepteur Windows Form
    Private components As System.ComponentModel.IContainer

    'REMARQUE : la procédure suivante est requise par le Concepteur Windows Form
    'Elle peut être modifiée à l'aide du Concepteur Windows Form.  
    'Ne la modifiez pas à l'aide de l'éditeur de code.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.gbEntréesSortiesNumériques = New System.Windows.Forms.GroupBox
        Me.SuspendLayout()
        '
        'gbEntréesSortiesNumériques
        '
        Me.gbEntréesSortiesNumériques.Dock = System.Windows.Forms.DockStyle.Fill
        Me.gbEntréesSortiesNumériques.Location = New System.Drawing.Point(0, 0)
        Me.gbEntréesSortiesNumériques.Name = "gbEntréesSortiesNumériques"
        Me.gbEntréesSortiesNumériques.Size = New System.Drawing.Size(421, 150)
        Me.gbEntréesSortiesNumériques.TabIndex = 0
        Me.gbEntréesSortiesNumériques.TabStop = False
        Me.gbEntréesSortiesNumériques.Text = "Entrées/Sorties numériques"
        '
        'ES_Num_LabjackU12
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.Controls.Add(Me.gbEntréesSortiesNumériques)
        Me.Name = "ES_Num_LabjackU12"
        Me.Size = New System.Drawing.Size(421, 150)
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents gbEntréesSortiesNumériques As System.Windows.Forms.GroupBox

End Class
