/*
Browser
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


// Application (QT / QTopia ...)
#include <Qt>
#include <QApplication> // QT

#include <QStyle>
#include <QPlastiqueStyle> // style
//#include <QWindowsXPStyle>

//#include <QTranslator> // i18n

//#include <qtopiaapplication> // QTopia

#include "browser.h"


int main(int argc, char ** argv)
{
  /* Application */
  QApplication app( argc, argv );

  /* Style */
  QApplication::setStyle(new QPlastiqueStyle);
  //QApplication::setStyle(new QWindowsStyle); 
  //QApplication::setStyle("QPushButton { color: white }");

  /* Traduction openchrono.qrc translations/openchrono_fr_FR.qm */
  /*
  QTranslator appTranslator;
  QString strTrans = QLatin1String("openchrono_")+QLocale::system().name();
  std::cout << ("Translation : ") << qPrintable(strTrans) << std::endl;
  //appTranslator.load(strTrans, qApp->applicationDirPath()+QLatin1String("/translations")); // sans ressource
  appTranslator.load(QLatin1String(":translations/")+strTrans); // avec ressource openchrono.qrc
  app.installTranslator(&appTranslator);
  */

  std::cout << "Browser" << std::endl;

  app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );

  int exit;
  exit = app.exec();

  return exit;
}

