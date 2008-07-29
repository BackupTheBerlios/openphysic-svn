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

#include "ocview_recall_laptime.h"

OCView_Recall_Laptime::OCView_Recall_Laptime()
{
  setupUi(this);
  setupOCView(this);

  std::cout << "init recall laptime" << std::endl;

  setWindowTitle(QApplication::translate("frmMessage", "Recall laptime", 0, QApplication::UnicodeUTF8));
  lblTitle->setText(QApplication::translate("frmMessage", "<img src=\":/icons/openchrono.png\" width=\"32\" height=\"32\"/> Laptime <img src=\":/icons/clock.svg\" width=\"32\" height=\"32\"/>", 0, QApplication::UnicodeUTF8));
}
