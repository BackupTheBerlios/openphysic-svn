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

#include "questionsimpl.h"
//

QuestionsImpl::QuestionsImpl( QWidget * parent, Qt::WFlags f, Data * data ) : QWidget(parent, f)
{
  setupUi(this);
  m_Data = data;
  
  setGeometry(750,320,320,240);
  
  QString str = QString("Choose an answer.");
  
  //setMessage(str);
}

/*
void MessageImpl::setTitle(QString str)
{
  lblTitle->setText(str);
  this->setWindowTitle(str);
}

void MessageImpl::setMessage(QString str)
{
  lblMessage->setText(str);
}
*/

//
