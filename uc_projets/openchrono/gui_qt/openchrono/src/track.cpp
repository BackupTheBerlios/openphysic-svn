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

#include "track.h"
//

Track::Track(  )
{
  setName("MyTrack");
  setLaps(5);
  setEtaps(2);
}

QString Track::name(void) const
  {
    return m_name;
  }

void Track::setName(const QString name)
{
  m_name = name;
}

int Track::laps(void) const
  {
    return m_laps_number;
  }

void Track::setLaps(const int laps)
{
  m_laps_number = laps;
}

int Track::etaps(void) const
  {
    return m_etaps_number;
  }

void Track::setEtaps(const int etaps)
{
  if (etaps >= 1)
    {
      m_etaps_number = etaps;
    }
  else
    {
      m_etaps_number = 1;
    }
}

QDomNode Track::to_node( QDomDocument &dom_doc )// , const Track &t )
{

  QDomElement dom_elt = dom_doc.createElement( "track" );

  QString strBuf;

  dom_elt.setAttribute( "etaps", strBuf.setNum( etaps() ) );
  dom_elt.setAttribute( "laps", strBuf.setNum( laps() ) );
  dom_elt.setAttribute( "name", name() );

  return dom_elt;


/*
  QDomDocument dom_elt;

  QDomElement name = dom_elt.createElement("name");
  //  QDomText _name = dom_elt.createTextNode( name() );
  //QDomElement etaps = dom_elt.createElement("etaps");
  //  QDomText _etaps = dom_elt.createTextNode( strBuf.setNum( etaps() ) );
  //QDomElement laps = dom_elt.createElement("laps");
  //  QDomText _laps = dom_elt.createTextNode( strBuf.setNum( laps() ) );

  track.appendChild(name);
    name.appendChild(_name);
  track.appendChild(laps);
    laps.appendChild(_laps);
  track.appendChild(etaps);
    etaps.appendChild(_etaps);

  return dom_elt;
*/



}



