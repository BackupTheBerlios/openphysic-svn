<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmMain
    Inherits System.Windows.Forms.Form

    'Form remplace la méthode Dispose pour nettoyer la liste des composants.
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
        Me.lblMot = New System.Windows.Forms.Label
        Me.lblMessage = New System.Windows.Forms.Label
        Me.cmdJouer = New System.Windows.Forms.Button
        Me.cmdQuitter = New System.Windows.Forms.Button
        Me.SuspendLayout()
        '
        'lblMot
        '
        Me.lblMot.AutoSize = True
        Me.lblMot.Location = New System.Drawing.Point(131, 30)
        Me.lblMot.Name = "lblMot"
        Me.lblMot.Size = New System.Drawing.Size(35, 13)
        Me.lblMot.TabIndex = 0
        Me.lblMot.Text = "lblMot"
        Me.lblMot.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'lblMessage
        '
        Me.lblMessage.AutoSize = True
        Me.lblMessage.Location = New System.Drawing.Point(118, 86)
        Me.lblMessage.Name = "lblMessage"
        Me.lblMessage.Size = New System.Drawing.Size(60, 13)
        Me.lblMessage.TabIndex = 1
        Me.lblMessage.Text = "lblMessage"
        Me.lblMessage.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'cmdJouer
        '
        Me.cmdJouer.Location = New System.Drawing.Point(111, 120)
        Me.cmdJouer.Name = "cmdJouer"
        Me.cmdJouer.Size = New System.Drawing.Size(75, 23)
        Me.cmdJouer.TabIndex = 2
        Me.cmdJouer.Text = "&Jouer"
        Me.cmdJouer.UseVisualStyleBackColor = True
        '
        'cmdQuitter
        '
        Me.cmdQuitter.Location = New System.Drawing.Point(111, 168)
        Me.cmdQuitter.Name = "cmdQuitter"
        Me.cmdQuitter.Size = New System.Drawing.Size(75, 23)
        Me.cmdQuitter.TabIndex = 3
        Me.cmdQuitter.Text = "&Quitter"
        Me.cmdQuitter.UseVisualStyleBackColor = True
        '
        'frmMain
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(307, 234)
        Me.Controls.Add(Me.lblMot)
        Me.Controls.Add(Me.lblMessage)
        Me.Controls.Add(Me.cmdJouer)
        Me.Controls.Add(Me.cmdQuitter)
        Me.Name = "frmMain"
        Me.Text = "Pendu"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents lblMot As System.Windows.Forms.Label
    Friend WithEvents lblMessage As System.Windows.Forms.Label
    Friend WithEvents cmdJouer As System.Windows.Forms.Button
    Friend WithEvents cmdQuitter As System.Windows.Forms.Button

End Class
