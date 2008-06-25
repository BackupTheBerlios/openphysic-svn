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
#include <Qt>
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
#include "logdata.h"
#include "logtime.h"
//
//#include "ocdocument.h" // ocview ocdocument (ex ocwindows)
//#include "ocview.h"

#include "ocview_mainwin.h"
#include "ocview_engine.h"
#include "ocview_about.h"
#include "ocview_plot.h"

#include "testwinimpl.h"


#include "engine_state.h"

int main(int argc, char ** argv)
{
  /* Application */
  QApplication app( argc, argv );

  /* Style */
  QApplication::setStyle(new QPlastiqueStyle);

  /* Traduction openchrono.qrc translations/openchrono_fr_FR.qm */
  QTranslator appTranslator;
  QString strTrans = QLatin1String("openchrono_")+QLocale::system().name();
  std::cout << ("Translation : ") << qPrintable(strTrans) << std::endl;
  //appTranslator.load(strTrans, qApp->applicationDirPath()+QLatin1String("/translations")); // sans ressource
  appTranslator.load(QLatin1String(":translations/")+strTrans); // avec ressource openchrono.qrc
  app.installTranslator(&appTranslator);

  std::cout << "OpenChrono1" << std::endl;

  Engine_State es;
  es.show();

  std::cout << "OpenChrono2" << std::endl;


  /* Données */
  Data myCurrentData;
  //myCurrentData = new Data();

  /* Log Data */
  LogData logdata(&myCurrentData);

  /* Log Time */
  LogTime logtime(&myCurrentData);

  std::cout << "OpenChrono3" << std::endl;

  /* Fenêtres de l'application */
  OCView_MainWin winMain(&myCurrentData);
  OCView_Engine winEngine; //(&myCurrentData);
  OCView_About winAbout;
  //OCView_Plot winPlot(&LogData);


  winMain.set_parent(&winMain);
  winMain.set_brother_next(&winEngine);
  winMain.set_brother_previous(&winAbout);
  winMain.set_no_child(); // set_child_first(&winMain);

  winEngine.set_parent(&winMain);
  winEngine.set_brother_next(&winAbout);
  winEngine.set_brother_previous(&winMain);
  winEngine.set_no_child();

  winAbout.set_parent(&winMain);
  winAbout.set_brother_next(&winMain);
  winAbout.set_brother_previous(&winEngine);
  winAbout.set_no_child();


  //winPlot.activate();

  /* Fenêtre de test */
  //TestWinImpl winTest(0, 0, &myCurrentData, &logdata);
  TestWinImpl winTest(0, 0, &myCurrentData);
  winTest.show();


  winMain.activate();

  app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );


  int exit;
  exit = app.exec();

  return exit;
}

