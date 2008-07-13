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

#include "ticker.h"

#include <QtGui>


Ticker::Ticker(QWidget *parent) : QWidget(parent)
{
  offset = 0;
  myTimerId = 0;
}

void Ticker::setText(const QString & newText)
{
  myText = newText;
  update();
  updateGeometry();
}

QSize Ticker::sizeHint() const
{
  return fontMetrics().size(0, text());
}

void Ticker::paintEvent(QPaintEvent * event)
{
  QPainter painter(this);

  int textWidth = fontMetrics().width(text());
  if (textWidth <1)
    return;
  int x=-offset;
  while (x < width()) {
    painter.drawText(x, 0, textWidth, height(),
      Qt::AlignLeft | Qt::AlignVCenter, text());
  }
}

void Ticker::timerEvent(QTimerEvent * event)
{
  if (event->timerId() == myTimerId) {
    ++offset;
    if (offset >= fontMetrics().width(text()))
      offset=0;
    scroll(-1,0);
  } else {
    QWidget::timerEvent(event);
  }
}

void Ticker::showEvent(QShowEvent * event)
{
  myTimerId = startTimer(30);
}

void Ticker::hideEvent(QHideEvent * event)
{
  killTimer(myTimerId);
}

