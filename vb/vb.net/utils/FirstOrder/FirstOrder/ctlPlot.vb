Public Class ctlPlot
    Dim m_buffer As New clsCircularBuffer(Of Double)

    Enum Points_Mode
        None
        Dot
        AddCross
        TimesCross
    End Enum
    Dim m_points_mode As Points_Mode

    Const m_ray As Double = 0.4
    Dim m_delta_x As Double
    Dim m_delta_y As Double


    Private Sub ctlPlot_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        'm_buffer = New clsCircularBuffer(Of Double)
        m_buffer.Capacity = 64

        m_points_mode = Points_Mode.Dot
    End Sub

    Private Sub PictureBox1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox1.Click

    End Sub

    Private Sub PictureBox1_Paint(ByVal sender As Object, ByVal e As System.Windows.Forms.PaintEventArgs) Handles PictureBox1.Paint
        Dim p As New Pen(Color.Black)

        ' ToDo: mise à l'échelle du PictureBox (fonction de conversion)
        ' ou creation d'un PictureBox simulant les propriétés de VB6
        '  ScaleWidth ScaleLeft ScaleHeight ScaleTop

        ' points

        ' +

        ' x

        ' ligne

        ' Graphics Path

        e.Graphics.DrawLine(p, 0, 0, 100, 100)
    End Sub



    Public Sub add(ByVal value As Double)
        m_buffer.addItem(value)
        'Debug.Print "add"

        PictureBox1.Refresh()
    End Sub
End Class
