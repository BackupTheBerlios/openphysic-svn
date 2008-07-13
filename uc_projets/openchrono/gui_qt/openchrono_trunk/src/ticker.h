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

#ifndef TICKER_H
#define TICKER_H

/*
Scrolling message
Stock ticker
sample : QT4 et C++ ; p 173
*/

#include <QWidget>

class Ticker : public QWidget
  {
    Q_OBJECT
    //QPROPERTY(QString text READ text WRITE setText)


    public:
      Ticker(QWidget *parent = 0);

      void setText(const QString & newText);
      QString text() const { return myText; }
      QSize sizeHint() const;

    protected:
      void paintEvent(QPaintEvent * event);
      void timerEvent(QTimerEvent * event);
      void showEvent(QShowEvent * event);
      void hideEvent(QHideEvent * event);

    private:
      QString myText;
      int offset;
      int myTimerId;
  };

#endif
