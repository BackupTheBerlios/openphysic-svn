VERSION 5.00
Begin VB.UserControl ctlPlot 
   BackColor       =   &H00FFC0C0&
   ClientHeight    =   2580
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   3945
   ScaleHeight     =   2580
   ScaleWidth      =   3945
   Begin VB.HScrollBar HScroll1 
      Height          =   255
      Left            =   240
      TabIndex        =   1
      Top             =   2040
      Width           =   1335
   End
   Begin VB.PictureBox Picture1 
      BackColor       =   &H00FFFFFF&
      Height          =   1695
      Left            =   0
      ScaleHeight     =   1635
      ScaleWidth      =   1995
      TabIndex        =   0
      Top             =   0
      Width           =   2055
   End
End
Attribute VB_Name = "ctlPlot"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Dim m_buffer As clsCircularBuffer

Dim m_window_capacity As Integer ' <= m_buffer.Capacity
Dim m_window_position As Integer ' 0 <= x <= m_buffer.Capacity-m_window_capacity

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


Private Sub UserControl_Initialize()
'Debug.Print "Initialize"

Set m_buffer = New clsCircularBuffer
m_buffer.Capacity = 10

m_window_capacity = 6
'm_window_position = 4 ' =window_capacity => affiche les derniers points
'm_window_position = 0 ' =0 => affiche les premiers points
m_window_position = 0

Picture1.ScaleMode = 0

'm_buffer.addItem (1)
'm_buffer.addItem (2)
'm_buffer.addItem (3)

'Picture1.ScaleMode = 0
'Picture1.ScaleWidth = m_buffer.Capacity
'Picture1.ScaleHeight = -5
'Picture1.ScaleTop = 10
'Picture1.ScaleLeft = 0

m_points_mode = Points_Mode.Dot

End Sub

Private Sub Picture1_Paint()
'Picture1.Line (0, Picture1.Height)-(Picture1.Width, 0)

'Debug.Print "Paint"



Dim xmin As Double
Dim xmax As Double
Dim ymin As Double
Dim ymax As Double

Dim margin_left As Double
Dim margin_right As Double
Dim margin_top As Double
Dim margin_bottom As Double

xmin = 0
xmax = m_window_capacity - 1 'm_buffer.Capacity - 1 'm_window_capacity 'm_buffer.Capacity
ymin = 0
ymax = 5

margin_left = (xmax - xmin) / 10
margin_right = margin_left
margin_top = (ymax - ymin) / 10
margin_bottom = margin_top

Picture1.ScaleWidth = (xmax - xmin) + margin_right + margin_left
Picture1.ScaleHeight = -(ymax - ymin + margin_top + margin_bottom)
Picture1.ScaleTop = 5 + margin_top
Picture1.ScaleLeft = xmin - margin_left

Picture1.DrawWidth = 1
Picture1.ForeColor = vbRed
'Picture1.Line (0, 0)-(xmax, ymax) 'diag pour tester

Picture1.ForeColor = vbBlack
Picture1.DrawWidth = 3
Picture1.Line (xmin, 0)-(xmax, 0) ' axe abs
Picture1.Line (0, ymin)-(0, ymax) ' axe ord

Dim i As Integer

' Lines
'Picture1.DrawWidth = 1
'Picture1.ForeColor = vbGreen
'For i = 1 To m_buffer.Used - 1
'    Picture1.Line (i - 1, m_buffer.FromFirst(i - 1))-(i, m_buffer.FromFirst(i))
'Next i

' Points (dot or circle)

'If m_points_mode = Points_Mode.Dot Then ' .
    Picture1.DrawWidth = 1
    Picture1.ForeColor = vbRed
    Picture1.FillStyle = 0
    Picture1.FillColor = vbRed
    
    Dim points_number As Integer
    If m_buffer.Used <= m_window_capacity Then
        points_number = m_buffer.Used
    Else
        points_number = m_window_capacity
    End If
    Dim real_window_position As Integer
    'If m_window_position >= m_buffer.Capacity - m_window_capacity Then
    '    real_window_position = 0
    'Else
        real_window_position = m_window_position
    'End If
    
    For i = 1 To points_number 'm_buffer.Used 'points_number ' m_buffer.Used
        Picture1.Circle (i - 1, m_buffer.FromFirst(i - 1 + real_window_position)), m_ray
    Next i

'ElseIf m_points_mode = Points_Mode.AddCross Then ' +
'    m_delta_x = Picture1.ScaleWidth / 50 ' 1#
'    m_delta_y = Abs(Picture1.ScaleHeight) / 50
'    Picture1.DrawWidth = 1
'    Picture1.ForeColor = vbRed
'    Picture1.FillStyle = 0
'    Picture1.FillColor = vbRed
'    For i = 1 To m_buffer.Used
'        Picture1.Line (i - 1 - m_delta_x, m_buffer.FromFirst(i - 1))-(i - 1 + m_delta_x, m_buffer.FromFirst(i - 1))
'        Picture1.Line (i - 1, m_buffer.FromFirst(i - 1) - m_delta_y)-(i - 1, m_buffer.FromFirst(i - 1) + m_delta_y)
'    Next i

'ElseIf m_points_mode = Points_Mode.TimesCross Then  ' x
'    m_delta_x = Picture1.ScaleWidth / 70
'    m_delta_y = Abs(Picture1.ScaleHeight) / 70
'    Picture1.DrawWidth = 1
'    Picture1.ForeColor = vbRed
'    Picture1.FillStyle = 0
'    Picture1.FillColor = vbRed
'    For i = 1 To m_buffer.Used
'        Picture1.Line (i - 1 - m_delta_x, m_buffer.FromFirst(i - 1) - m_delta_y)-(i - 1 + m_delta_x, m_buffer.FromFirst(i - 1) + m_delta_y)
'        Picture1.Line (i - 1 - m_delta_x, m_buffer.FromFirst(i - 1) + m_delta_y)-(i - 1 + m_delta_x, m_buffer.FromFirst(i - 1) - m_delta_y)
'    Next i

'End If



End Sub



Private Sub UserControl_Resize()
Picture1.Height = Height - HScroll1.Height
Picture1.Width = Width

HScroll1.Left = 0
HScroll1.Top = Height - HScroll1.Height
HScroll1.Width = Width
End Sub

'Public Sub Show()
'Picture1.Line (0, 0)-(Picture1.Width, Picture1.Height)

'Picture1.CurrentX = Picture1.Width / 2
'Picture1.CurrentY = Picture1.Height / 2
'Picture1.Print "hello"
'End Sub

Public Sub add(ByVal value As Double)
m_buffer.addItem (value)
'Debug.Print "add"

Picture1.Refresh
End Sub

Public Sub update_scoll_bar()
HScroll1.Min = 0
HScroll1.Max = m_buffer.Capacity - 1
'HScroll1.r = 0
End Sub

Private Sub HScroll1_Change()
Debug.Print "HScroll Change"
End Sub

Private Sub HScroll1_Scroll()
Debug.Print "HScroll Scroll"
End Sub
