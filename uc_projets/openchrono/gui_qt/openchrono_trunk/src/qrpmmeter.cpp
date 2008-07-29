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
  return (geometry().height()*3.0/4.0*value)/maximum()+this->geometry().height()*1.0/4.0;
  //return this->geometry().height();
}

void QRPMMeter::paintEvent(QPaintEvent * event)
{
  //std::cout << "paint RPMmeter" << std::endl;
  //std::cout << "value=" << this->value() << std::endl;

  QPainter painter(this);

  /* Rendering quality
    see file:///usr/share/qt4/doc/html/qpainter.html#RenderHint-enum
    Antialiasing should be set to 'false' to debug drawing error
 */
  painter.setRenderHint(QPainter::Antialiasing, true);
  //painter.setRenderHint(QPainter::TextAntialiasing, true);
  //painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
  //painter.setRenderHint(QPainter::HighQualityAntialiasing, true);

  QLinearGradient gradientON(0, 0, geometry().width(), 0);
  gradientON.setColorAt(0.0, Qt::green);
  gradientON.setColorAt(0.8, Qt::yellow);
  gradientON.setColorAt(1.0, Qt::red);
  painter.setBrush(gradientON);
  //painter.drawRect(0,0,this->geometry().width(),this->geometry().height());
  //QRectF rect(0,0,((this->geometry().width()-1)*this->value())/(this->maximum()),this->geometry().height()-1);

  // nothing // with contour
  //painter.setPen(QPen(gradient, 0)); // no contour

  // rectangle with gradient
  //painter.drawRect(rect);
  //painter.drawRoundedRect(rect,10.0,10.0);
  //painter.drawRoundedRect(rectangle, 20.0, 20.0);

  /* parallelogramme */

  // path (triangle, polygon) with gradient
/*
  QPainterPath path;
  path.moveTo(0.0, 0.0);
  path.lineTo((this->geometry().width()-1)*this->value()/(this->maximum()), 0.0);
  path.lineTo((this->geometry().width()-1)*this->value()/(this->maximum()), bottom(this->value()));
  path.lineTo(0, this->geometry().height()*1.0/4.0);
  path.closeSubpath();
  painter.drawPath(path);
*/


  /* barres */
  QLinearGradient gradientOFF(0, 0, geometry().width(), 0);
  QColor green = Qt::green;
  QColor yellow = Qt::yellow;
  QColor red = Qt::red;
  const int dark=250;
  gradientOFF.setColorAt(0.0, green.darker(dark));
  gradientOFF.setColorAt(0.8, yellow.darker(dark));
  gradientOFF.setColorAt(1.0, red.darker(dark));
  //gradientOFF=gradient.darker(150);


  const int N_Bar=80; // nombre de barres du RPMmetre
  const int Bar_Width=2; // largeur de la barre
  const double Bar_Height_Max=geometry().height()-1; // hauteur maxi de la barre
  const double Bar_Height_Min=Bar_Height_Max*0.25; // hauteur mini de la barre
  const double Bar_Height_Mid=Bar_Height_Max*0.4; // hauteur de la barre du milieu
  const double Bar_X_Space=2.0; // ecartement horizontal entre les barres


  QPen penOFF(gradientOFF, 0);
  QPen penON(gradientON, 0);

  for ( int i=0 ; i < N_Bar ; i++ ) {
    if (i<(((double) N_Bar)*(value()-minimum()))/(maximum()-minimum())) {
      painter.setPen(penON);
      painter.setBrush(gradientON);
    } else {
      painter.setPen(penOFF);
      painter.setBrush(gradientOFF);
    }
    QRectF rect(
      i * (Bar_Width + Bar_X_Space),
      0,
      Bar_Width,
      (((Bar_Height_Max-Bar_Height_Min)*(N_Bar/2.0-1)-(Bar_Height_Mid-Bar_Height_Min)*(N_Bar-1))
	   /(pow((N_Bar-1),2)*(N_Bar/2.0-1)-(pow(N_Bar/2.0-1,2)*(N_Bar-1))))*pow(i,2)
	  + (((Bar_Height_Max-Bar_Height_Min)*pow(N_Bar/2.0-1,2)-(Bar_Height_Mid-Bar_Height_Min)*pow(N_Bar-1,2))
           /((N_Bar-1)*pow(N_Bar/2.0-1,2)-(N_Bar/2.0-1)*pow(N_Bar-1,2)))*i
	  + Bar_Height_Min
    );
    //painter.drawRect(rect);
    painter.drawRoundedRect(rect,3,3);
/*
    QPainterPath path;
    path.moveTo(Bar_X_Space + i * (Bar_Width + Bar_X_Space), 0.0);
    path.lineTo((this->geometry().width()-1)*this->value()/(this->maximum()), 0.0);
    path.lineTo((this->geometry().width()-1)*this->value()/(this->maximum()), bottom(this->value()));
    path.lineTo(0, this->geometry().height()*1.0/4.0);
    path.closeSubpath();
    painter.drawPath(path);
*/

  // Value of RPM
  // format = "%v RPM"
  //painter.setRenderHint(QPainter::Antialiasing, false);
  QString strRPM;
  strRPM.sprintf("%d RPM", this->value());
  QPen penTxt(Qt::black);
  //penTxt.setWidth(0);
  if (value()>=maximum())
    penTxt.setColor(Qt::red);
  painter.setPen(penTxt);
  //painter.drawText(rect, Qt::AlignCenter, tr("16000 RPM"));
  QRectF rectTxt(0,0,this->geometry().width()*0.62,this->geometry().height());
  painter.drawText(rectTxt, Qt::AlignRight, strRPM);

  }
}


/*
Usefull links
http://doc.trolltech.com/4.4/painting-basicdrawing.html
http://doc.trolltech.com/4.4/painting-painterpaths.html
http://www.unixgarden.com/index.php/programmation/qt-4-%E2%80%93-3-dessins-et-graphismes
file:///usr/share/qt4/doc/html/qcolor.html
*/

