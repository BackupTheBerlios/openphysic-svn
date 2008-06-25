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

#include "qaccelerometer.h"

#include <QtGui>

#include <iostream>

QAccelerometer::QAccelerometer(QWidget *parent = 0)
{
  setGeometry(QRect(0,0,100,100));
  //setSize(100,100);

  /* Tests */
  setGX(0.5);
  setGY(1.5);
}


void QAccelerometer::paintEvent(QPaintEvent * event)
{
  std::cout << "paint accelero" << std::endl;

  QPainter painter(this);

  QPen penCercle;
  penCercle.setWidth(3);
  penCercle.setColor(Qt::black);
  painter.setPen(penCercle);

  //painter.drawLine(0,0,30,30);
  //painter.drawEllipse(QRect(0,0,100,100));
painter.drawEllipse(QRect(0,0,100,100));
}

