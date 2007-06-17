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

#ifndef OCWINDOWS_H
#define OCWINDOWS_H
//
#include <QApplication>
//
//#include <QObject>

class OCWindows //: public QObject
  {
    //    Q_OBJECT

  public:
    OCWindows();
    virtual ~OCWindows();

    //QString ocname;

    //OCWindows * page_current;
    QWidget * page_current;

  protected:
    OCWindows * page_parent;
    OCWindows * page_brother_next;
    OCWindows * page_brother_previous;
    OCWindows * page_child_first;

/*
    virtual void navigate_on_ok(void);
    virtual void navigate_on_cancel(void);
    virtual void navigate_on_left(void);
    virtual void navigate_on_right(void);
*/
  };

#endif
