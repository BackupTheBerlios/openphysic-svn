/*
OpenChrono
Copyright (C) 2007  Sebastien CELLES
 
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.
 
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
 
You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

// Test
//#include <iostream> // cout << "Test" << endl;
//using namespace std;

// Application (QT / QTopia ...)
#include <QApplication> // QT
//#include <qtopiaapplication> // QTopia

// Test GUI
#include "dialogimpl.h"

// GUI
#include "mainwinimpl.h"
#include "aboutimpl.h"
#include "testwinimpl.h"
//
#include "data.h"
//
#include "ocwindows.h" // ocview ocdocument

int main(int argc, char ** argv)
{
  QApplication app( argc, argv );

  Data myCurrentData;

  //myCurrentData.start();

  //OCWindows * win;
  OCWindows win;

  DialogImpl winDialog(0, 0, &myCurrentData);
  AboutImpl winAbout(0, 0, &myCurrentData);
  MainWinImpl winMain(0, 0, &myCurrentData);
  TestWinImpl winTest(0, 0, &myCurrentData, &winMain);


  // connection bouton StartStop page de test
  app.connect(        (&winTest)->StartStop	, SIGNAL( clicked() ),
                      &winMain                , SLOT( start() )                       );


  // Init pages relations
  //  -> parent init
  (&winMain)->page_parent = &winMain; // page time
  //  -> first child init
  (&winMain)->page_child_first = NULL; // ToDo
  //  -> next brother init
  (&winMain)->page_brother_next = NULL; // ToDo
  //  -> previous brother init
  (&winMain)->page_brother_previous = NULL; // ToDo


  //winAbout.show();
  //winDialog.show();


  (&win)->page_current = &winMain;
  //(&win)->page_current = &winAbout;
  //(&win)->page_current = &winDialog;

  //(&win)->page_current = &winMain;

  //winMain.show();
  //win->show();

  ((&win)->page_current)->show();


  // fenetre de test
  winTest.show();


  app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );

  return app.exec();
}
