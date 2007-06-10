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

#ifndef TRACK_H
#define TRACK_H

#include <QString>

class Track
{
public:
    Track( );

    QString name(void);
    void setName(QString name);

    int laps_number(void);
    void setLaps_number(int laps);

    int etaps_number(void);
    void setEtaps_number(int etaps);

private:
    QString m_name;
    int m_laps_number;	
    int m_etaps_number;

};

#endif

