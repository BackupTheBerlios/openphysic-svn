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

#include "ocview_engine.h"

OCView_Engine::OCView_Engine()
{
  setupUi(this);

  std::cout << "init view engine" << std::endl;

  setWindowTitle(QApplication::translate("frmMessage", "Engine", 0, QApplication::UnicodeUTF8));
  lblTitle->setText(QApplication::translate("frmMessage", "Engine", 0, QApplication::UnicodeUTF8));
  lblMessage->setText(QApplication::translate("frmMessage", "Click <strong>OK</strong> to enter in this menu.", 0, QApplication::UnicodeUTF8));

  init_view(this);
}

OCView_Engine::~OCView_Engine()
{}

