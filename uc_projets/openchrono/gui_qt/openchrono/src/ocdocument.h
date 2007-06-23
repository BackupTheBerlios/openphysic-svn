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

#ifndef OCDOCUMENT_H
#define OCDOCUMENT_H
//
#include <QApplication>

#include "ocview.h"
#include "data.h"

class OCDocument
  {
  public:
    OCDocument();
    virtual ~OCDocument();

    void set_parent(OCDocument * ocdoc);
    void set_brother_next(OCDocument * ocdoc);
    void set_brother_previous(OCDocument * ocdoc);
    void set_child_first(OCDocument * ocdoc);
    void set_no_child(void);

    virtual void KeyEvent(int keyname); //(QChar keyname);

    void activate(void);


    //Data * data; // static ?


  protected:
    void desactivate(void);

    OCDocument * page_parent;
    OCDocument * page_brother_next;
    OCDocument * page_brother_previous;
    OCDocument * page_child_first;

    void activate_parent(void);
    void activate_brother_next(void);
    void activate_brother_previous(void);
    void activate_child_first(void);

    OCView * view;

    void set_view(OCView * ocview);


  private:

  };

#endif
