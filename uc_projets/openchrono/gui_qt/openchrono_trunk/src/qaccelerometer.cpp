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

QAccelerometer::QAccelerometer(QWidget *parent) : QWidget(parent)
{
  setGeometry(QRect(0,0,100,100));
  //setSize(100,100);

  setGmax(2);

  /* Tests */
  /*
  setGX(0.5);
  setGY(1.5);
  */
/*
  setGX(0.5);
  setGY(-1.5);
*/
  setG(0.0, 0.0);

  m_editable = false;
}

void QAccelerometer::setGX(const double g)
{
  m_GX = g;
  this->update();
}

void QAccelerometer::setGY(const double g)
{
  m_GY = g;
  this->update();
}

void QAccelerometer::setG(const double gx, const double gy)
{
  m_GX = gx;
  m_GY = gy;
  this->update();
}

double QAccelerometer::gx_to_x(double g)
{
  double w = (double) (this->geometry().width()-1);
  return w/(2.0*Gmax())*(g-Gmax())+w;
}

double QAccelerometer::gy_to_y(double g)
{
  double h = (double) (this->geometry().height()-1);
  return -h/(2.0*Gmax())*(g-Gmax());
}

double QAccelerometer::x_to_gx(double x)
{
/*
x = w/(2.0*Gmax)*(g-Gmax)+w
(x-w)*(2.0*Gmax)/w+Gmax
*/
  double w = (double) (this->geometry().width()-1);
  return (x-w)*(2.0*Gmax())/w+Gmax();
}

double QAccelerometer::y_to_gy(double y)
{
  double h = (double) (this->geometry().height()-1);
/* 
y = -h/(2.0*Gmax)*(g-Gmax)
y * 2.0*Gmax/h + Gmax
*/
  return Gmax() - ((double) y) * 2.0*Gmax()/((double) h);
}

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
  //std::cout << "paint accelero" << std::endl;

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

void QAccelerometer::setEditable() {
  m_editable = true;
}

void QAccelerometer::unsetEditable() {
  m_editable = false;
}

void QAccelerometer::mousePressEvent (QMouseEvent * event)
{
  if (m_editable) {
/*
    std::cout << "mousePressEvent on QAccelerometer "
      << "X=" << event->x() << " ; " << "Y=" << event->y()
      << " - "
      << "Gx=" << x_to_gx(event->x()) << " ; " << "Gy=" << y_to_gy(event->y()) << std::endl;
*/

    setGX(x_to_gx(event->x()));
    setGY(y_to_gy(event->y()));

    emit clicked();

    this->update();
  }
}

