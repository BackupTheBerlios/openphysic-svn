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

#include <QString>

Track::Track(  )
{
  setName("MyTrack");
  setLaps(50);
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
  m_etaps_number = etaps;
}

