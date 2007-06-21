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

#ifndef OCDOCUMENT_MAINWIN_H
#define OCDOCUMENT_MAINWIN_H

#include "ocdocument.h"

#include "ocview_mainwin.h"

class OCDocument_MainWin : public OCDocument
  {
  public:
    OCDocument_MainWin() { set_view(new OCView_MainWin(this)); };
    virtual ~OCDocument_MainWin();

  private:

  };
#endif