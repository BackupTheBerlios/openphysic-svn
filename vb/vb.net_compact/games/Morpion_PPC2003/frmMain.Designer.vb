<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Public Class frmMain
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
    Private mainMenu1 As System.Windows.Forms.MainMenu

    'REMARQUE : la procédure suivante est requise par le Concepteur Windows Form
    'Elle peut être modifiée à l'aide du Concepteur Windows Form.  
    'Ne la modifiez pas à l'aide de l'éditeur de code.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.mainMenu1 = New System.Windows.Forms.MainMenu
        Me.PictureBox1 = New System.Windows.Forms.PictureBox
        Me.lblMessage = New System.Windows.Forms.Label
        Me.txtDimension = New System.Windows.Forms.TextBox
        Me.SuspendLayout()
        '
        'PictureBox1
        '
        Me.PictureBox1.Location = New System.Drawing.Point(17, 3)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(200, 200)
        '
        'lblMessage
        '
        Me.lblMessage.Anchor = CType((System.Windows.Forms.AnchorStyles.Left Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.lblMessage.Location = New System.Drawing.Point(17, 216)
        Me.lblMessage.Name = "lblMessage"
        Me.lblMessage.Size = New System.Drawing.Size(200, 52)
        Me.lblMessage.Text = "lblMessage"
        '
        'txtDimension
        '
        Me.txtDimension.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
                    Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.txtDimension.Location = New System.Drawing.Point(3, 216)
        Me.txtDimension.Name = "txtDimension"
        Me.txtDimension.Size = New System.Drawing.Size(0, 21)
        Me.txtDimension.TabIndex = 6
        Me.txtDimension.Text = "txtDimension"
        '
        'frmMain
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(96.0!, 96.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Dpi
        Me.AutoScroll = True
        Me.ClientSize = New System.Drawing.Size(240, 268)
        Me.Controls.Add(Me.lblMessage)
        Me.Controls.Add(Me.txtDimension)
        Me.Controls.Add(Me.PictureBox1)
        Me.Menu = Me.mainMenu1
        Me.Name = "frmMain"
        Me.Text = "Morpion"
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents PictureBox1 As System.Windows.Forms.PictureBox
    Friend WithEvents lblMessage As System.Windows.Forms.Label
    Friend WithEvents txtDimension As System.Windows.Forms.TextBox
End Class
