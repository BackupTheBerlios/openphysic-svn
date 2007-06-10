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

#ifndef DATA_H
#define DATA_H
//
//#include <Qt> // ToFix
//
#include "chrono.h"
#include "rpm.h"
#include "temperature.h"
#include "track.h"
#include "position.h"
#include "engine.h"

class Data //: public QObject
{
//Q_OBJECT

public:
    Data();
    //virtual ~Data(){  };

    Rpm rpm;

    Temperature temperature_1;
    Temperature temperature_2;

    Track track;

    Position position;

    Engine engine;

    void start(void);
    Chrono chrono;

    void test(void);

private:

};
#endif
