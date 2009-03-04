VERSION 5.00
Begin VB.UserControl ctlPlot 
   ClientHeight    =   2580
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   3945
   ScaleHeight     =   2580
   ScaleWidth      =   3945
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





Private Sub Picture1_Paint()
'Picture1.Line (0, Picture1.Height)-(Picture1.Width, 0)
Picture1.Line (0, 0)-(m_buffer.Capacity, 5)

Dim i As Integer



End Sub

Private Sub UserControl_Initialize()
Debug.Print "Initialize"

Set m_buffer = New clsCircularBuffer
m_buffer.Capacity = 128

'm_buffer.addItem (1)
'm_buffer.addItem (2)
'm_buffer.addItem (3)

Picture1.ScaleMode = 0
Picture1.ScaleWidth = m_buffer.Capacity
Picture1.ScaleHeight = -5
Picture1.ScaleTop = 10
Picture1.ScaleLeft = 0

End Sub

Private Sub UserControl_Resize()
Picture1.Height = Height
Picture1.Width = Width
End Sub

Public Sub Show()
Picture1.Line (0, 0)-(Picture1.Width, Picture1.Height)

Picture1.CurrentX = Picture1.Width / 2
Picture1.CurrentY = Picture1.Height / 2
Picture1.Print "hello"
End Sub

Public Sub add(ByVal value As Double)

End Sub
