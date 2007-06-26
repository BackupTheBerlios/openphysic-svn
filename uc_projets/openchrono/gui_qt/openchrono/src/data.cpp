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
#include <QDomDocument>


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
  std::cout << " ToDo" << std::endl;
}

void Data::save(void)
{
  std::cout << "Saving data" << std::endl;

  QFile file( OC_CFG_FILE );
  QDir::setCurrent( OC_CFG_DIR );
  
  if( !file.open( QIODevice::WriteOnly ) ) {
    std::cerr << " Error : Can't save !" << std::endl;
  }

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

    QString strBuf;

    QDomElement track = doc.createElement("track");
/*
      QDomElement name = doc.createElement("name");
        QDomText _name = doc.createTextNode(this->track.name());
      QDomElement etaps = doc.createElement("etaps");
        QDomText _etaps = doc.createTextNode( strBuf.setNum(this->track.etaps()) );
      QDomElement laps = doc.createElement("laps");
        QDomText _laps = doc.createTextNode( strBuf.setNum(this->track.laps()) );
*/

    QDomElement position = doc.createElement("position");
    QDomElement vehicule = doc.createElement("vehicule");
    QDomElement chrono = doc.createElement("chrono");


  doc.appendChild(root);
    root.appendChild(track);
/*
      track.appendChild(name);
        name.appendChild(_name);
      track.appendChild(laps);
        laps.appendChild(_laps);
      track.appendChild(etaps);
        etaps.appendChild(_etaps);
*/

    root.appendChild(position);
    root.appendChild(vehicule);
    root.appendChild(chrono);


  QTextStream ts( &file );
  ts << doc.toString();
  //std::cout << doc.toString();

  file.close();

  std::cout << " Data saved" << std::endl;
}

//

