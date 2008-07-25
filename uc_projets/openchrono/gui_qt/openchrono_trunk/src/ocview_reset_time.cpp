/*
OpenChrono
Copyright (C) 2008  Sebastien CELLES
 
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

#include "ocview_reset_time.h"

OCView_Reset_Time::OCView_Reset_Time(Data * data)
{
  setupUi(this);
  setupOCView(this);

  m_data=data;

  std::cout << "init view reset time" << std::endl;

  setWindowTitle(QApplication::translate("frmResetTime", "Reset time", 0, QApplication::UnicodeUTF8));
  lblTitle->setText(QApplication::translate("frmResetTime", "Reset time", 0, QApplication::UnicodeUTF8));
  lblQuestion->setText(QApplication::translate("frmResetTime", "Do you really want to reset time ?", 0, QApplication::UnicodeUTF8));
}


