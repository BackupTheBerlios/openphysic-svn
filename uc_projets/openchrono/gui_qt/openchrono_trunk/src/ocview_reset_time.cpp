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

OCView_Reset_Time::OCView_Reset_Time()
{
  setupUi(this);

  std::cout << "init view reset time" << std::endl;

/*
  setWindowTitle(QApplication::translate("frmMessage", "Engine", 0, QApplication::UnicodeUTF8));
  lblTitle->setText(QApplication::translate("frmMessage", "<h1>Engine</h1>", 0, QApplication::UnicodeUTF8));
  lblMessage->setText(QApplication::translate("frmMessage", "<h2>Click <u><i>OK</i></u> to enter in this menu.</h2>", 0, QApplication::UnicodeUTF8));
*/

/*
QString str = tr("Press <b>Ok</b> to <i>enter</i> here.");
  str += ( QLatin1String("<br/>") + tr("Press <b>Cancel</b> to <i>quit</i>.") );
  str += ( QLatin1String("<br/>") + tr("Press <b>Right</b> to go to <i>next page</i>.") );
  str += ( QLatin1String("<br/>") + tr("Press <b>Left</b> to go to <i>previous page</i>.") );
*/

  init(this);
}


