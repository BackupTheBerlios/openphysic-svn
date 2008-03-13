<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class AfficheurOctet
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
        Me.Button1 = New System.Windows.Forms.Button
        Me.Led1 = New Led.Led
        Me.SuspendLayout()
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(0, 0)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(75, 23)
        Me.Button1.TabIndex = 0
        Me.Button1.Text = "Button1"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'Led1
        '
        Me.Led1.Couleur = System.Drawing.Color.Red
        Me.Led1.Etat = Led.Led.LED.Eteinte
        Me.Led1.Location = New System.Drawing.Point(59, 70)
        Me.Led1.Name = "Led1"
        Me.Led1.Size = New System.Drawing.Size(15, 15)
        Me.Led1.TabIndex = 1
        '
        'AfficheurOctet
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.Controls.Add(Me.Led1)
        Me.Controls.Add(Me.Button1)
        Me.Name = "AfficheurOctet"
        Me.Size = New System.Drawing.Size(370, 150)
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents Led1 As Led.Led

End Class
