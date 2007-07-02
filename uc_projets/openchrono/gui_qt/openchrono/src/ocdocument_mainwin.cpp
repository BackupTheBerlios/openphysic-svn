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

#include "ocdocument_mainwin.h"

#include "ocview_mainwin.h"
#include "data.h"

/*
OCDocument_MainWin::OCDocument_MainWin()
{
  std::cout << "OCDocument_MainWin contructor" << std::endl;
  set_view(new OCView_MainWin(this));
  m_data = NULL;
}
*/

OCDocument_MainWin::OCDocument_MainWin(Data * data)
{
  std::cout << "OCDocument_MainWin contructor with data" << std::endl;
  set_view(new OCView_MainWin(this, data));
  //m_data = data;
}

/*
OCDocument_MainWin::OCDocument_MainWin(int x)
{
  set_view(new OCView_MainWin(this));
  m_data = NULL;
}
*/

OCDocument_MainWin::~OCDocument_MainWin()
{}

