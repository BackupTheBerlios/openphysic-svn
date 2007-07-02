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
#include <QPlastiqueStyle> // style
#include <QTranslator> // i18n
//#include <qtopiaapplication> // QTopia

// Test GUI
//#include "dialogimpl.h"

// GUI
//#include "mainwinimpl.h"
//#include "aboutimpl.h"
//#include "testwinimpl.h"
//#include "messageimpl.h"
//#include "questionsimpl.h"
//
#include "data.h"
//
//#include "ocdocument.h" // ocview ocdocument (ex ocwindows)
//#include "ocview.h"

#include "ocdocument_mainwin.h"
#include "ocdocument_engine.h"

#include "testwinimpl.h"


int main(int argc, char ** argv)
{
  QApplication app( argc, argv );

  QApplication::setStyle(new QPlastiqueStyle);

  /* voir openchrono.qrc translations/openchrono_fr.qm */
  //QTranslator appTranslator;
/*
  appTranslator.load(QLatin1String("openchrono_")+QLocale::system().name(),
                     qApp->applicationDirPath());
  app.installTranslator(&appTranslator);
  */

  Data myCurrentData;
  //myCurrentData.load();


  OCDocument_MainWin winMain(&myCurrentData);
  OCDocument_Engine winEngine; //(&myCurrentData);


  //TestWinImpl winTest(0, 0, &myCurrentData, &winMain);


  // connection bouton StartStop page de test
  //app.connect(        (&winTest)->StartStop	, SIGNAL( clicked() ),
  //                    &myCurrentData                , SLOT( start() )                       );


  winMain.set_parent(&winMain);
  winMain.set_brother_next(&winEngine);
  winMain.set_brother_previous(&winEngine);
  winMain.set_no_child(); // set_child_first(&winMain);

  winEngine.set_parent(&winMain);
  winEngine.set_brother_next(&winMain);
  winEngine.set_brother_previous(&winMain);
  winEngine.set_no_child();


  winMain.activate();


  // fenetre de test
  //winTest.show();


  app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );

  int exit;
  exit = app.exec();

  //myCurrentData.save(); // save data

  return exit;
}

