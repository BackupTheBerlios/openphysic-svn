// -*- compile-command: "g++ wxhello.cpp `wx-config --libs` `wx-config --cxxflags` -o wxhello" -*-

// wxhello.cpp
// Version using dynamic event routing
// Robert Roebling, Martin Bernreuther

#include <wx/wx.h>


class MyApp : public wxApp
{
  virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)


class MyFrame : public wxFrame
{
public:
  MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
  void OnQuit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);
};

enum
{
  ID_Quit=1,
  ID_About
};


bool MyApp::OnInit()
{
  MyFrame *frame = new MyFrame("Hello World", wxPoint(50,50),
			       wxSize(450,350));

  frame->Connect( ID_Quit, wxEVT_COMMAND_MENU_SELECTED,
		  (wxObjectEventFunction) &MyFrame::OnQuit );
  frame->Connect( ID_About, wxEVT_COMMAND_MENU_SELECTED,
		  (wxObjectEventFunction) &MyFrame::OnAbout );

  frame->Show(TRUE);
  SetTopWindow(frame);
  return TRUE;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
  : wxFrame((wxFrame*)NULL,-1,title,pos,size)
{
  // create menubar
  wxMenuBar *menuBar = new wxMenuBar;
  // create menu
  wxMenu *menuFile = new wxMenu;
  // append menu entries
  menuFile->Append(ID_About,"&About...");
  menuFile->AppendSeparator();
  menuFile->Append(ID_Quit,"E&xit");
  // append menu to menubar
  menuBar->Append(menuFile,"&File");
  // set frame menubar
  SetMenuBar(menuBar);
  
  // create frame statusbar
  CreateStatusBar();
  // set statusbar text
  SetStatusText("Welcome to wxWindows!");
}

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
  Close(TRUE);
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
  wxMessageBox("wxWindows Hello Word example.","About Hello World",
	       wxOK|wxICON_INFORMATION, this);
}
