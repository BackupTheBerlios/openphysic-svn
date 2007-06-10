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

}

void Data::start(void)
{
  std::cout << "Start or stop or etap" << std::endl;
    // on a line (start stop or etap)

  chrono.start();
  chrono.clear();
}


void Data::test(void)
{
  std::cout << "Test Data" << std::endl;
}

//

