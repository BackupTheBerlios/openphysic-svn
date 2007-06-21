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

#include "ocdocument.h"

#include "keyboard.h"

OCDocument::OCDocument(void)
{
  page_parent = NULL;
  page_brother_next = NULL;
  page_brother_previous = NULL;
  page_child_first = NULL;
}

OCDocument::~OCDocument(void)
{
  // destruct
}

void OCDocument::set_view(OCView * ocview)
{
  view = ocview;
}


void OCDocument::set_parent(OCDocument * ocdoc)
{
  page_parent = ocdoc;
}

void OCDocument::set_brother_next(OCDocument * ocdoc)
{
  page_brother_next = ocdoc;

}

void OCDocument::set_brother_previous(OCDocument * ocdoc)
{
  page_brother_previous = ocdoc;

}

void OCDocument::set_child_first(OCDocument * ocdoc)
{
  page_child_first = ocdoc;
}




void OCDocument::activate_parent(void)
{
  page_parent->activate();
}

void OCDocument::activate_brother_next(void)
{
  page_brother_next->activate();
}

void OCDocument::activate_brother_previous(void)
{
  page_brother_previous->activate();
}

void OCDocument::activate_child_first(void)
{
  page_child_first->activate();
}

void OCDocument::activate(void)
{
  view->show();
}



void OCDocument::KeyEvent(int keyname) //(QChar keyname)
{
  switch ( keyname ) {
  case B_OK: // Ok
    activate_child_first();
    break;
  case B_CANCEL: // Cancel
    activate_parent();
    break;
  case B_UP:
    //
    break;
  case B_DOWN:
    //
    break;
  case B_LEFT:
    activate_brother_previous();
    break;
  case B_RIGHT:
    activate_brother_next();
    break;
  default:
    //
    break; // n'importe quelle autre touche
  }
}


/*
void OCDocument::navigate_on_ok(void)
{
  //ptr_current_page = &page_engine_menu;
  //ptr_page_goto = ptr_current_page->page_child_first;
}

void OCDocument::navigate_on_cancel(void)
{
  //ptr_page_goto = ptr_current_page->page_parent;
}

void OCDocument::navigate_on_left(void)
{
  //ptr_page_goto = ptr_current_page->page_brother_previous;
}

void OCDocument::navigate_on_right(void)
{
  //ptr_page_goto = ptr_current_page->page_brother_next;
}
*/



