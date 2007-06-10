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

#include "engine.h"
//

Engine::Engine(  )
{
    setName("Engine1");
    set_two_strokes();
}

QString Engine::name(void) const
{
    return m_name;
}

void Engine::setName(const QString name)
{
    m_name = name;
}

void Engine::set_two_strokes(void)
{
    m_mode = engine_two_strokes;
}

void Engine::set_four_stroke(void)
{
    m_mode = engine_four_strokes;
}

int Engine::strokes(void) const
{
    if ( m_mode == engine_two_strokes )
    {
      return 2;
    } 
    else if ( m_mode == engine_four_strokes )
    {
      return 4;
    }       
    else
    {
      return 0;
    }
}

int Engine::rpm_factor(void)
{
    if ( m_mode == engine_two_strokes )
    {
      return 2;
    } 
    else if ( m_mode == engine_four_strokes )
    {
      return 1;
    }       
    else
    {
      return 0;
    }
}

