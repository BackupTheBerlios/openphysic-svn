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

#include "engine_state.h"
//

Engine_State::Engine_State(  )
{
  switch_off();
  set_idle();
}

void switch_on(void)
{
  m_on = true;
}

void switch_off(void)
{
  set_idle();
  m_on = false;
}

void set_idle(void)
{
  m_idle = true;
}

void unset_idle(void)
{
  m_idle = false;  
}

