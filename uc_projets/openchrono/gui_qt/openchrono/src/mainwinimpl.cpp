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

#include "mainwinimpl.h"
//

#include <iostream>
#include <cmath>

#include "keyboard.h"

//
#include <QTimer>
//

MainWinImpl::MainWinImpl( QWidget * parent, Qt::WFlags f, Data * data ) : QWidget(parent, f)
{
  setupUi(this); //ui.setupUi(this);
  m_Data = data;

  setGeometry(50,50,320,240);

  //TestWin();

  //UpdateData();

  // update RPM
  GraphicRPM->setMaximum((int) m_Data->vehicule.engine.rpm.max());
  GraphicRPM->setMinimum((int) m_Data->vehicule.engine.rpm.min());

  //delete layout();
  //setLayout(vboxLayout);

  QTimer * timer = new QTimer(this);
  connect( timer, SIGNAL(timeout()), this, SLOT(UpdateData()) );
  timer->start(25);

}
//

void MainWinImpl::TestWin(void)
{
  lblMessage->setText("XXXXXXXXXXXXXXXXXX");

  GraphicRPM->setValue(16000);

  lblCurrLapTime->setText("XX:XX:XXX");
  lblBestLapTime->setText("XX:XX:XXX");
  lblLastLapTime->setText("XX:XX:XXX");

  lblLap->setText("XXX");
  lblEtap->setText("XX / XX");

  lblTemp1->setText("XXXXX");
  lblTemp2->setText("XXXXX");
}

void MainWinImpl::showRPM(void)
{
  double rpm = m_Data->vehicule.engine.rpm.value();  
  double rpmMax = m_Data->vehicule.engine.rpm.max();
  int value;

  if ( rpm <= rpmMax )
    {
      value = (int) (round(rpm/10)*10);
    }
  else
    {
      value = (int) rpmMax;
    }
  GraphicRPM->setValue(value);

  /* couleur */
  //QColormap ? QLineargradient ?
  //GraphicRPM->
  //QPalette palette;
  //QPalette::ColorRole colorrole = QPalette::Window;
  //QGradient gradient;
  //gradient.setColorAt(0, Qt::green);
  //gradient.setColorAt(.5, Qt::yellow);
  //gradient.setColorAt(1, Qt::red);
  //QColor color = Qt::red;
  //palette.setColor(QPalette::Window, color);
  //this->setPalette ( palette );

}

void MainWinImpl::showT1(void)
{
  lblTemp1->setText(m_Data->vehicule.engine.temperature_1.getStr());
}

void MainWinImpl::showT2(void)
{
  lblTemp2->setText(m_Data->vehicule.engine.temperature_2.getStr());
}

void MainWinImpl::showCurrentLapTime(void)
{
  lblCurrLapTime->setText(m_Data->chrono.getStrCurrentLapTime());
}

void MainWinImpl::showLastLapTime(void)
{
  lblLastLapTime->setText(m_Data->chrono.getStrLastLapTime());
}

void MainWinImpl::showBestLapTime(void)
{
  lblBestLapTime->setText(m_Data->chrono.getStrBestLapTime());
}

void MainWinImpl::showLap(void)
{
  QString strLap;
  if ( m_Data->track.laps() > 1 ) 
    {
      strLap.sprintf("%d / %d", m_Data->position.lap(), m_Data->track.laps());
    }
  else
  	{
  	  strLap.sprintf("%d", m_Data->position.lap());
  	}
  lblLap->setText(strLap);
}

void MainWinImpl::showEtap(void)
{
  QString strEtap;
  strEtap.sprintf("%d / %d",m_Data->position.etap(),m_Data->track.etaps());
  lblEtap->setText(strEtap);
}

void MainWinImpl::UpdateData(void)
{
  showRPM();
  showT1();
  showT2();
  showCurrentLapTime();
  showLastLapTime();
  showBestLapTime();
  showLap();
  showEtap();
}

void MainWinImpl::on_ok(void)
{
  std::cout << "ok" << std::endl;
}

void MainWinImpl::on_cancel(void)
{
  std::cout << "cancel" << std::endl;
}

void MainWinImpl::on_up(void)
{
  std::cout << "up" << std::endl;
}

void MainWinImpl::on_down(void)
{
  std::cout << "down" << std::endl;
}

void MainWinImpl::on_left(void)
{
  std::cout << "left" << std::endl;
}

void MainWinImpl::on_right(void)
{
  std::cout << "right" << std::endl;
}

void MainWinImpl::keyPressEvent(QKeyEvent *event)
{
  switch ( event->key() ) {
  case B_OK: // Ok
    on_ok();
    break;
  case B_CANCEL: // Cancel
    on_cancel();
    break;
  case B_UP:
    on_up();
    break;
  case B_DOWN:
    on_down();
    break;
  case B_LEFT:
    on_left();
    break;
  case B_RIGHT:
    on_right();
    break;
  default:
    break; // n'importe quelle autre touche
  }
}


