Option Explicit On
Option Strict On

Public Class frmMain
    Dim Buffer As clsCircularBuffer

    Private Sub cmdAdd_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles cmdAdd.Click

    End Sub

    Private Sub frmMain_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        'Set Buffer = New clsCircularBuffer
    End Sub

    Private Sub cmdAdd_Click()
        Buffer.addItem(CDbl(txtValue.Text))
        lblBufferUsed.Text = CStr(Buffer.Used)

        Show_first()
        'Show_last

        Show_full_buffer()

    End Sub

    Private Sub Show_first()
        ' Ordre chronologique
        Dim i As Integer
        'ListBox1.clear() ' tofix
        For i = 1 To Buffer.Used
            'ListBox1.addItem(Buffer.FromFirst(i - 1)) ' tofix
        Next i

    End Sub

    Private Sub Show_last()
        ' Ordre chronologique inversé
        Dim i As Integer
        'ListBox1.clear() ' tofix
        For i = 1 To Buffer.Used
            'List1.addItem(Buffer.FromLast(i - 1)) ' tofix
        Next i

    End Sub


    Private Sub Show_full_buffer()
        Dim i As Integer

        ' Contenu du buffer (pour debug)
        'ListBox2.clear() 'tofix
        For i = 1 To Buffer.Capacity
            'Dim buf
            'Set buf = Buffer.Buffer
            'ListBox2.addItem(Buffer.value(i - 1)) ' tofix
        Next i
    End Sub

End Class
