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

QAccelerometer::QAccelerometer(QWidget *parent = 0) : QWidget(parent)
{
  setGeometry(QRect(0,0,100,100));
  //setSize(100,100);

  setGmax(2);

  /* Tests */
  /*
  setGX(0.5);
  setGY(1.5);
  */
  setGX(0.);
  setGY(-1.5);

}


double QAccelerometer::gx_to_x(double g)
{
  int w = this->geometry().width()-1;
  return w/(2.0*Gmax())*(g-Gmax())+w;
}

double QAccelerometer::gy_to_y(double g)
{
  int h = this->geometry().height()-1;
  return -h/(2.0*Gmax())*(g-Gmax());
}

/*
double QAccelerometer::x_to_gx(double x)
{
  return 0.0;
}
*/

/*
double QAccelerometer::y_to_gy(double y)
{
  return 0.0;
}
*/

void QAccelerometer::drawCercle(QPainter & painter, double g)
{
  int x1, y1, x2, y2;
  x1 = (int) gx_to_x(-g);
  y1 = (int) gy_to_y(g);
  x2 = (int) gx_to_x(g);
  y2 = (int) gy_to_y(-g);
  painter.drawEllipse(x1,y1,x2-x1,y2-y1);    
}

void QAccelerometer::paintEvent(QPaintEvent * event)
{
  std::cout << "paint accelero" << std::endl;

  QPainter painter(this);

  QPen pen;
  pen.setWidth(1);


  int x1, y1, x2, y2;
  double g;
  painter.setBrush(Qt::NoBrush);

  pen.setColor(Qt::black);
  painter.setPen(pen);
  for (g=1 ; g<=Gmax() ; g+=1) {
    drawCercle(painter,g); 
  }

  pen.setColor(Qt::gray);
  painter.setPen(pen);
  for (g=0.5 ; g<=Gmax() ; g+=1) {
    drawCercle(painter,g); 
  }

  painter.setBrush(Qt::red);
  painter.setPen(Qt::red);
  x1 = (int) gx_to_x(GX())-2;
  y1 = (int) gy_to_y(GY())-2;
  x2 = (int) gx_to_x(GX())+2;
  y2 = (int) gy_to_y(GY())+2;
  painter.drawEllipse(x1,y1,x2-x1,y2-y1);
}

