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

  setGmax(2);

  /* Tests */
  setGX(0.5);
  setGY(1.5);
}


double QAccelerometer::gx_to_x(double g)
{
  return this->geometry().width()/(2.0*Gmax())*(g-Gmax())+this->geometry().width();
}

double QAccelerometer::gy_to_y(double g)
{
  return -this->geometry().height()/(2.0*Gmax())*(g-Gmax());
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

void QAccelerometer::paintEvent(QPaintEvent * event)
{
  std::cout << "paint accelero" << std::endl;

  QPainter painter(this);

  QPen penCercle;
  penCercle.setWidth(1);
  penCercle.setColor(Qt::black);
  painter.setPen(penCercle);

  QBrush brush;

  //painter.drawLine(0,0,30,30);
  //painter.drawEllipse(QRect(0,0,100,100));
  //painter.drawEllipse(QRect(0,0,100,100));

  int h,w,xc,yc;
  //w = this->geometry().width()-1;
  //h = this->geometry().height()-1;

//std::cout << h << ";" << w << std::endl;

  int x1, y1, x2, y2;
  /*
  x1 = (int) gx_to_x(-2.0);
  y1 = (int) gy_to_y(2.0);
  x2 = (int) gx_to_x(2.0);
  y2 = (int) gy_to_y(-2.0);
  //painter.drawLine(0,0,100,100);
  std::cout << "x1=" << x1 << ";" << "y1=" << y1 << std::endl;
  std::cout << "x2=" << x2 << ";" << "y2=" << y2 << std::endl;
  painter.drawLine(x1,y1,x2,y2);
  */

  //x1 = (int) gx_to_x(1);
  //y1 = (int) gy_to_y(0);
  //std::cout << "x1=" << x1 << ";" << "y1=" << y1 << std::endl;

  double g;
  painter.setBrush(Qt::NoBrush);
  for (g=0.5 ; g<=2 ; g+=0.5) {
    std::cout << g << std::endl;
    /*
    w = (this->geometry().width()-1)*(g/2.0);
    h = (this->geometry().height()-1)*(g/2.0);

    painter.drawEllipse(
      (this->geometry().width()-1)/2.0-w/2.0,
      (this->geometry().height()-1)/2.0-h/2.0,
      w,
      h
    );
    */

    /*
    x1 = (int) gx_to_x(-g);
    y1 = (int) gy_to_y(g);
    x2 = (int) gx_to_x(g);
    y2 = (int) gy_to_y(-g);
    */
  }

  g=1.5;
  x1 = (int) gx_to_x(-g);
  y1 = (int) gy_to_y(g);
  x2 = (int) gx_to_x(g);
  y2 = (int) gy_to_y(-g);
  painter.drawEllipse(x1,y1,x2,y2);    
  std::cout << "x1=" << x1 << ";" << "y1=" << y1 << std::endl;
  std::cout << "x2=" << x2 << ";" << "y2=" << y2 << std::endl;

/*
  painter.setBrush(Qt::black);
  g = 0.1;
  w = (this->geometry().width()-1)*(g/2.0);
  h = (this->geometry().height()-1)*(g/2.0);
  painter.drawEllipse(
    (this->geometry().width()-1)/2.0-w/2.0,
    (this->geometry().height()-1)/2.0-h/2.0,
    w,
    h
  );
*/

}

