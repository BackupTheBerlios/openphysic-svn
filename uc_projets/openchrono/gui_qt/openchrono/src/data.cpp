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

#include <iostream> // ForTest std::cout << "Test" << std::endl;

Data::Data(  )
{
    setRPM(0.0);
    setRPMmax(16000.0);
    setRPMmin(0.0);

    setTemp1(0.0);
    setTemp2(0.0);
}


double Data::getRPM(void)
{
    return m_RPM;
}

void Data::setRPM(double const RPM)
{
    m_RPM=RPM;
}


double Data::getRPMmax(void)
{
    return m_RPMmax;
}

void Data::setRPMmax(double const RPM)
{
    m_RPMmax=RPM;
}


double Data::getRPMmin(void)
{
    return m_RPMmin;
}

void Data::setRPMmin(double const RPM)
{
    m_RPMmin=RPM;
}


double Data::getTemp1(void)
{
    return m_T1;
}

void Data::setTemp1(double const T1)
{
    m_T1=T1;
}


double Data::getTemp2(void)
{
    return m_T2;
}

void Data::setTemp2(double const T2)
{
    m_T2=T2;
}


void Data::start(void)
{
  std::cout << "Start or stop or etap" << std::endl;
    // on a line (start stop or etap)

  chrono.start();
  chrono.clear();



}


void Data::Test(void)
{
  std::cout << "Test data" << std::endl;
}

//


// slots fot TestWin
/*
void slotRPM_TestWin(int RPM) {
	setRPM( (double) RPM );
}
*/


// slots for captors
