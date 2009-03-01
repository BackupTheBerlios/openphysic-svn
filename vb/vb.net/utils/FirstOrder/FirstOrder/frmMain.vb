Option Explicit On
Option Strict On

Public Class frmMain
    Const delta_t As Integer = 100

    Const K As Double = 1
    Const tau As Double = 2 ' seconds

    Dim input As Double
    Dim output As Double
    Dim output_old As Double

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Timer1.Interval = delta_t
        'Timer1.Enabled = True

        init()
    End Sub

    Private Sub init()
        ' init input/output values
        output = 0
        output_old = 0
        input = 1

        ' refresh control
        txtInput.Text = CStr(input)
        lblOutput.Text = CStr(output)
    End Sub

    Private Sub cmdTest_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles cmdTest.Click
        Timer1.Enabled = Not Timer1.Enabled
    End Sub


    Dim dodt As Double
    Dim dodt_old As Double

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        'Beep()

        ' get input
        input = CDbl(Me.txtInput.Text)

        ' calculate output
        output_old = output
        '
        ' O(p) / I(p) = K / (1 + tau p)

        ' Method 1
        ' O(p) * (1 + tau p) = K I(p)
        ' o(t) + tau * do/dt = K i(t)
        ' with do/dt = ( o(t) - o(t-delta_t) ) / delta_t
        ' we get o(t)=f(K,tau,i,o(t-delta_t))
        output = (K * input + 1000 * tau / CDbl(delta_t) * output_old) / (1 + 1000 * tau / CDbl(delta_t))

        ' Method 2
        ' do/dt = K/tau i(t) - o(t)
        '
        ' -i-->*K/tau---->+ --|intgrate|---- o
        '                 -              |
        '                 ^--o-----------
        ' integrate do/dt to get o(t) (using trapezium rule)
        ' ToFix
        'dodt = input * K / tau - output
        'output = CDbl(delta_t) / (2.0 * 1000.0) * (dodt + dodt_old)
        'dodt_old = dodt

        ' show ouput
        lblOutput.Text = CStr(output)

    End Sub

    Private Function derive(ByRef outp As Double) As Double

    End Function

    Private Function integrate(ByRef outp As Double) As Double

    End Function


    Private Sub cmdInit_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles cmdInit.Click
        init()
    End Sub

 
End Class
