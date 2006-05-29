# Getting Started "More magic" section 
# Using new wx namespace and namespace qualification style 
import wx 
ID_ABOUT = 101 
ID_EXIT  = 110 
ID_OPEN  = 111 
 
class MainWindow(wx.Frame): 
    """ We simply derive a new class of Frame. """ 
    def __init__(self, parent, id, title): 
        wx.Frame.__init__(self, parent, wx.ID_ANY, title, size = (200, 100), style = wx.DEFAULT_FRAME_STYLE |wx.NO_FULL_REPAINT_ON_RESIZE) 
        self.control = wx.TextCtrl(self, 1, style=wx.TE_MULTILINE) 
        self.CreateStatusBar() # A statusbar in the bottom of the window 
        #Setting up the menu 
        filemenu=wx.Menu() 
        filemenu.Append(ID_OPEN, "&Open","Open a file") 
        filemenu.Append(ID_ABOUT, "&About","Information about this program") 
        filemenu.AppendSeparator() 
        filemenu.Append(ID_EXIT, "E&xit", "Terminate the program") 
        # Creating the menubar 
        menuBar=wx.MenuBar() 
        menuBar.Append(filemenu, "&File",) #Adding the filemenu to the MenuBar 
        self.SetMenuBar(menuBar) #Adding the MenuBar to the Frame content 
 
        wx.EVT_MENU(self, ID_OPEN, self.OnOpen)   #attach the menu-event ID_OPEN to method self.OnOpen 
        wx.EVT_MENU(self, ID_ABOUT, self.OnAbout) #attach the menu-event ID_ABOUT to method self.OnAbout 
        wx.EVT_MENU(self, ID_EXIT, self.OnExit)   #attach the menu-event ID_EXIT to method self.OnExit 
         
        self.Show(True) # Note the capital on 'True' 
 
    def OnAbout(self, e): 
        d=wx.MessageDialog(self, "A sample editor \n" "in wxPython", "About Sample Editor", wx.OK) 
                          #Create a message dialog box 
        d.ShowModal() # Shows it 
        d.Destroy() # finally destroy it when finished 
 
    def OnExit(self, e): 
        self.Close(True) #Close the frame, note capitalization of 'T' in 'True' 
 
    def OnOpen(self, e): 
        """ Open a file""" 
        import os                # might not be optimal spot, but pedagogically clear, move if implement 'Save' 
        self.dirname=os.getcwd() 
        dlg = wx.FileDialog(self, "Choose a file", self.dirname, "", "*.*", wx.OPEN) 
        if dlg.ShowModal() == wx.ID_OK: 
            self.filename=dlg.GetFilename() 
            self.dirname=dlg.GetDirectory() 
            f=open(os.path.join(self.dirname, self.filename), 'r') 
            self.control.SetValue(f.read()) 
            f.close() 
        dlg.Destroy() 
 
app = wx.PySimpleApp() 
frame = MainWindow(None, -1, "Sample editor") 
app.MainLoop()
