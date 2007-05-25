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
Data::Data(  ) 
{
	set_RPM(5000.0);
	set_T1(50.0);
	set_T2(60.0);
}

void Data::set_RPM(double const RPM)
{
	m_RPM=RPM;
}

double Data::get_T1(void)
{
	return m_T1;
}

void Data::set_T1(double const T1)
{
	m_T1=T1;
}

double Data::get_T2(void)
{
	return m_T2;
}

void Data::set_T2(double const T2)
{
	m_T2=T2;
}

//
