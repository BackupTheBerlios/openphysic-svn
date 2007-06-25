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

#include "ocview.h"
#include "ocdocument.h"

#include "keyboard.h"


OCView::OCView(void)
{
  // contruct
  document = NULL;
}

OCView::OCView(OCDocument * ocdoc)
{
  // contruct
  document = ocdoc;
}

OCView::~OCView(void)
{
  // destruct
}


void OCView::keyPressEvent(QKeyEvent * event)
{
  switch ( event->key() )
    {
    case B_OK: // Ok
      std::cout << "OK" << std::endl;
      document->activate_child_first();
      break;
    case B_CANCEL: // Cancel
      std::cout << "CANCEL" << std::endl;
      document->activate_parent();
      break;
    case B_UP:
      std::cout << "UP" << std::endl;
      //
      break;
    case B_DOWN:
      std::cout << "DOWN" << std::endl;
      //
      break;
    case B_LEFT:
      std::cout << "LEFT" << std::endl;
      document->activate_brother_previous();
      break;
    case B_RIGHT:
      std::cout << "RIGHT" << std::endl;
      document->activate_brother_next();
      break;
    default:
      //
      break; // n'importe quelle autre touche
    }
}


