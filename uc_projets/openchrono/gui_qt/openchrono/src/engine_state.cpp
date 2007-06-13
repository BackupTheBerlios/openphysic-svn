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
  m_on = false; // motor is off
  m_idle = true; // motor is idle
}

void Engine_State::switch_on(void)
{
  if (m_on == false) {
    m_on = true;
    emit switched_on();
  }
}

void Engine_State::switch_off(void)
{
  if ( m_on == true ) {
    set_to_idle();
    m_on = false;
    emit switched_off();
  }
}

void Engine_State::set_to_idle(void)
{
  if ( m_idle == false ) {
    m_idle = true;
    emit was_set_to_idle();
  }
}

void Engine_State::unset_idle(void)
{
  if ( m_idle == true ) {
    m_idle = false;
    emit was_unset_to_idle();
  }
}


void Engine_State::show(void)
{
  std::cout << "ON " << m_on << " ; " << "IDLE " << m_idle << std::endl;
}


