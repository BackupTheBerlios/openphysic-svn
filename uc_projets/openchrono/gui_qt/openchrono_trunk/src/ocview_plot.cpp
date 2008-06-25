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

#include "ocview_plot.h"

OCView_Plot::OCView_Plot(LogData * logdata)
{
  //setup_ui(this);
 
  m_logdata = logdata;

  connect( &timer, SIGNAL( timeout() ), this, SLOT( update() ) );

  //init(this);
}

OCView_Plot::~OCView_Plot()
{
  
}

void OCView_Plot::update(void)
{
  
}
