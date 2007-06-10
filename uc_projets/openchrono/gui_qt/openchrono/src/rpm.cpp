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

#include "rpm.h"
//

Rpm::Rpm(  )
{
  set(0.0);
  setMax(16000.0);
  setMin(0.0);
}

double Rpm::value(void) const
  {
    return m_RPM;
  }

void Rpm::set(double const RPM)
  {
    m_RPM=RPM;
  }


double Rpm::max(void) const
  {
    return m_RPMmax;
  }

void Rpm::setMax(double const RPM)
{
  m_RPMmax=RPM;
}


double Rpm::min(void) const
  {
    return m_RPMmin;
  }

void Rpm::setMin(double const RPM)
{
  m_RPMmin=RPM;
}


