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

#include "qrpmmeter.h"

#include <QtGui>

#include <iostream>

QRPMMeter::QRPMMeter(QWidget *parent) : QProgressBar(parent)
{
  std::cout << "RPMmeter" << std::endl;
}

double QRPMMeter::bottom(int value)
{
  //return 0.0;
  //return (this->geometry().height()*value)/this->maximum()+this->geometry().height()*1.0/4.0;
  return (this->geometry().height()*3.0/4.0*value)/this->maximum()+this->geometry().height()*1.0/4.0;
  //return this->geometry().height();
}

void QRPMMeter::paintEvent(QPaintEvent * event)
{
  //std::cout << "paint RPMmeter" << std::endl;
  //std::cout << "value=" << this->value() << std::endl;

  QString strRPM;
  strRPM.sprintf("%d RPM", this->value());

  //str = " RPM";

  QPainter painter(this);

  QLinearGradient gradient(0, 0, this->geometry().width(), 0);
  gradient.setColorAt(0.0, Qt::green);
  gradient.setColorAt(0.7, Qt::yellow);
  gradient.setColorAt(1.0, Qt::red);
  painter.setBrush(gradient);
  //painter.drawRect(0,0,this->geometry().width(),this->geometry().height());
  QRectF rect(0,0,((this->geometry().width()-1)*this->value())/(this->maximum()),this->geometry().height()-1);

  // rectangle with gradient
  painter.setPen(QPen(gradient, 0)); // no contour
  //painter.drawRect(rect);
  //painter.drawRoundedRect(rect,10.0,10.0);
  //painter.drawRoundedRect(rectangle, 20.0, 20.0);

  // path (triangle, polygon) with gradient
  QPainterPath path;
  path.moveTo(0.0, 0.0);
  path.lineTo(this->geometry().width()*this->value()/(this->maximum()),0.0);
  path.lineTo(this->geometry().width()*this->value()/(this->maximum()),bottom(this->value()));
  path.lineTo(0,this->geometry().height()*1.0/4.0);
  path.closeSubpath();
  painter.drawPath(path);

  // Value of RPM
  // format = "%v RPM"
  painter.setPen(Qt::black);
  //painter.drawText(rect, Qt::AlignCenter, tr("16000 RPM"));
  painter.drawText(QRectF(0,0,this->geometry().width()*0.62,this->geometry().height()), Qt::AlignRight, strRPM);
  //painter.drawText(50, 50, "hello");
}


/*
Usefull links
http://doc.trolltech.com/4.4/painting-basicdrawing.html
http://doc.trolltech.com/4.4/painting-painterpaths.html
http://www.unixgarden.com/index.php/programmation/qt-4-%E2%80%93-3-dessins-et-graphismes
*/

