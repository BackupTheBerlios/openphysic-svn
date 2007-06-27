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

#include "data.h"
//
#include <QFile>
#include <QDir>
#include <QTextStream>
//#include <QDomDocument>
#include <QtXml>
#include <QMessageBox>

Data::Data(  )
{

  connect(this, SIGNAL( starting_first_lap() ),
          this, SLOT( on_starting_first_lap() ) );

  connect(this, SIGNAL( is_new_etap() ),
          this, SLOT( on_new_etap() ) );

  connect(this, SIGNAL( is_new_lap() ),
          this, SLOT( on_new_lap() ) );

  connect(this, SIGNAL( is_last_lap() ),
          this, SLOT( on_last_lap() ) );

  connect(this, SIGNAL( race_is_over() ),
          this, SLOT( on_race_over() ) );

  load();
}

/*
Data::~Data(  )
{
  save();
}
*/

void Data::start(void)
{
  if ( position.etap() == track.etaps() ) // passage ligne depart/arrivee
    {
      position.clearEtap();

      if ( position.lap() == 0 )
        {
          emit starting_first_lap();
        }

      if ( position.lap() == track.laps()-1 ) // debut du dernier tour de course
        {
          emit is_last_lap();
        }

      if ( position.lap() == track.laps() ) // fin du dernier tour de course
        {
          position.clearLap();
          if ( track.laps() > 1 )
            {
              emit race_is_over();
            }
        }

      position.newLap();
      emit is_new_lap();


    } else // passage ligne temps intermediaire
    {
      position.newEtap();
      emit is_new_etap();
    }

}


void Data::test(void)
{
  std::cout << "Test Data" << std::endl;
}

void Data::on_starting_first_lap(void)
{
  std::cout << "Starting first lap" << std::endl;
}

void Data::on_new_etap(void)
{
  std::cout << " New etap" << std::endl;
}

void Data::on_new_lap(void)
{
  std::cout << "New lap" << std::endl;

  chrono.update_last_and_best_lap_time();

  chrono.start();
  chrono.clear();
}

void Data::on_last_lap(void)
{
  std::cout << "Last lap" << std::endl;
}

void Data::on_race_over(void)
{
  std::cout << "Race over" << std::endl;
}

void Data::load(void)
{
  std::cout << "Loading data" << std::endl;

  QFile file( OC_CFG_FILE );
  QDir::setCurrent( OC_CFG_DIR );

  if( !file.open( QIODevice::ReadOnly ) )
    {
      std::cerr << " Error : Can't open !" << std::endl;
      file.close();
      return;
    }

  std::cout << " Loading..." << std::endl;
  //std::cout << " ToDo" << std::endl;

  /* validating document using dtd : not possible easily using Qt4 */

  /* En test */
  QDomDocument doc;
  QString errorStr;
  int errorLine;
  int errorColumn;

  /* looking for malformed xml file */
  if( !doc.setContent( &file, true, &errorStr, &errorLine, &errorColumn ) )
    {
      QMessageBox::warning(0,
                           QObject::tr("DOM Parser"),
                           QObject::tr("Parse error at line %1, "
                                       "column %2:\n%3")
                           .arg(errorLine)
                           .arg(errorColumn)
                           .arg(errorStr)
                          );
      file.close();
      return;
    }

  QDomElement root = doc.documentElement();

  /* looking for the root name 'ocdata' */
  //std::cout << "root = " << qPrintable(root.tagName()) << std::endl;
  if (root.tagName() != "ocdata")
    {
      QMessageBox::warning(0,
                           QObject::tr("DOM Parser"),
                           QObject::tr("Document should begin with <ocdata> and stop with </ocdata>")
                          );

      file.close();
      return;
    }

  /* parsing file */
  /*
    QDomNode node = root.firstChild();
    while ( !node.isNull() ) {
      if (node.toElement().tagname() = "entry") {
        parseEntry(node.toElement(), 0);
      }
      node = node.nextSibling(); 
    }
  */

  file.close();

  std::cout << " Data loaded" << std::endl;
}

void Data::save(void)
{
  std::cout << "Saving data" << std::endl;

  QFile file( OC_CFG_FILE );
  QDir::setCurrent( OC_CFG_DIR );

  if( !file.open( QIODevice::WriteOnly ) )
    {
      std::cerr << " Error : Can't save !" << std::endl;
      file.close();
      return;
    }

  std::cout << " Saving..." << std::endl;

  QDomImplementation impl = QDomDocument().implementation();

  QString name_ml = "OpenChronoML";
  QString publicId = "-//CELLES//DTD OpenChrono 0.1 //EN";
  QString systemId = "http://www.celles.net/dtd/openchrono.dtd";
  QDomDocument doc(impl.createDocumentType(name_ml,publicId,systemId));
  // add some XML comment at the beginning
  doc.appendChild(doc.createComment("This file describe data for OpenChrono a chronometer for mechanical sports"));
  doc.appendChild(doc.createTextNode("\n")); // for nicer output
  doc.appendChild(doc.createComment("http://www.celles.net/wikini/wakka.php?wiki=OpenChrono"));
  doc.appendChild(doc.createTextNode("\n")); // for nicer output

  QDomElement root = doc.createElement("ocdata"); // racine

  doc.appendChild(root);
  root.appendChild( track.to_node(doc) );
  root.appendChild( position.to_node(doc) );
  root.appendChild( vehicule.to_node(doc) );
  root.appendChild( chrono.to_node(doc) );

  QTextStream ts( &file );
  ts << doc.toString();
  //std::cout << doc.toString();

  file.close();

  std::cout << " Data saved" << std::endl;
}

//

