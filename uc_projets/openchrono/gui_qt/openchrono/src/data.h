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

class Data //: public QObject
{
//Q_OBJECT

public:
    Data();
    //virtual ~Data(){  };


    // RPM rpm;
    double getRPM(void);
    void setRPM(double const RPM);
    double getRPMmax(void);
    void setRPMmax(double const RPM);
    double getRPMmin(void);
    void setRPMmin(double const RPM);


    // Temperature temperature;
    // °C ou F ou ...
    double getTemp1(void);
    void setTemp1(double const T1);

    double getTemp2(void);
    void setTemp2(double const T2);

    // Track
    //  name
    //  nb etap
    //  nb of lap (could be set to undef = -1)

    // Position
    //  etap (/nb etap)
    //  lap

    // Engine

    void start(void);

    Chrono chrono;

    void Test(void);

private:
    double m_RPM;
    double m_RPMmax;
    double m_RPMmin;

    double m_T1;
    double m_T2;

};
#endif
