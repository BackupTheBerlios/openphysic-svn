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
/*
    setName("MyTrack");
    setLaps_number(50);
    setEtaps_number(1);
*/
}

QString Track::name(void)
{
    return m_name;
}

void Track::setName(QString name)
{
    m_name = name;
}

int Track::laps_number(void)
{
    return m_laps_number;
}

void Track::setLaps_number(int laps)
{
    m_laps_number = laps;
}

int Track::etaps_number(void)
{
    return m_etaps_number;
}

void Track::setEtaps_number(int etaps)
{
    m_etaps_number = etaps;
}

