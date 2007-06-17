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

#ifndef MAINWINIMPL_H
#define MAINWINIMPL_H
//
#include "ui_mainwin.h"
//

#include "data.h"
#include "ocwindows.h"

#include <QKeyEvent>

class MainWinImpl : public QWidget, public Ui::MainWin, public OCWindows
  {
    Q_OBJECT
  public:
    MainWinImpl( QWidget * parent = 0, Qt::WFlags f = 0, Data * myData = 0 );
    void TestWin(void);

  private slots:
    void UpdateData();

    void on_ok(void);
    void on_cancel(void);
    void on_up(void);
    void on_down(void);
    void on_left(void);
    void on_right(void);


  private:
    Data * m_Data;

    void showRPM(void);
    void showT1(void);
    void showT2(void);
    void showCurrentLapTime(void);
    void showLastLapTime(void);
    void showBestLapTime(void);
    void showLap(void);
    void showEtap(void);

    void keyPressEvent(QKeyEvent *event);

  };
#endif
