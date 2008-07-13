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

#include <QStyle>
#include <QPlastiqueStyle> // style
//#include <QWindowsXPStyle>

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

#include "qaccelerometer.h"
#include "qrpmmeter.h"
#include "ticker.h"

#include "engine_state.h"


#include <QLineEdit>
#include <QPainter>
//#include <QString>

int main(int argc, char ** argv)
{
  /* Application */
  QApplication app( argc, argv );

  /* Style */
  QApplication::setStyle(new QPlastiqueStyle);
  //QApplication::setStyle(new QWindowsStyle); 
  //QApplication::setStyle("QPushButton { color: white }");

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


  //QWidget win;
  //win.show();

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


  winMain.set_parent(&winMain); /* page par defaut */
  winEngine.is_brother_of(&winMain);
    //winEngineMenu1.is_first_child_of(&winEngine);
    //winEngineMenu2.is_brother_of(&winEngineMenu1);
    //winEngineMenu2.is_last_child();

  winAbout.is_brother_of(&winEngine);
  winAbout.is_last_child();


  //winPlot.activate();

  /* Fenêtre de test */
  //TestWinImpl winTest(0, 0, &myCurrentData, &logdata);
  TestWinImpl winTest(0, 0, &myCurrentData);
  winTest.show();


  winMain.activate();

  winMain.setFocus();

  //app.connect( &winTest, SIGNAL( accepted() ), &app, SLOT( quit() ) );
  app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );


  //QWidget accel;
  //QAccelerometer accel;
  //accel.show();

  //QRPMMeter rpm;
  //rpm.set(10000);
  //rpm.setMax(16000);
  //rpm.setMin(0);
  //rpm.show();

  //Ticker ticker("OpenChrono");
  //ticker.show();
  //QString str = "test";
  //str = QString("bla bla");
  //ticker.setText(str);

  //winTest.close();


  //QLineEdit txt;
  //txt.show();

  int exit;
  exit = app.exec();

  return exit;
}

