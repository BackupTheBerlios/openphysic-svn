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

#include "ocview_mainwin.h"
#include "ocdocument.h"

#include <iostream>
#include <cmath>

#include "keyboard.h"

//
#include <QTimer>

OCView_MainWin::OCView_MainWin(OCDocument * ocdoc, Data * data) : OCView(ocdoc)
{
  m_data = data;

  setupUi(this);

  setWindowTitle(QLatin1String("MainWin"));

  //test();

  //UpdateData();

  // update RPM
  //std::cout << qPrintable(tr("RPMmin:")) <<  m_data->vehicule.engine.rpm.max() << std::endl;
  //std::cout << qPrintable(tr("RPMmax:")) <<  m_data->vehicule.engine.rpm.min() << std::endl;

  GraphicRPM->setMaximum((int) m_data->vehicule.engine.rpm.max());
  GraphicRPM->setMinimum((int) m_data->vehicule.engine.rpm.min());

  //delete layout();
  //setLayout(vboxLayout);

  QTimer * timer = new QTimer(this);
  connect( timer, SIGNAL(timeout()), this, SLOT(UpdateData()) );
  timer->start(25); //
}

OCView_MainWin::~OCView_MainWin()
{}


void OCView_MainWin::test(void)
{
  lblMessage->setText(QLatin1String("XXXXXXXXXXXXXXXXXX"));

  GraphicRPM->setValue(16000);

  lblCurrLapTime->setText(QLatin1String("XX:XX:XXX"));
  lblBestLapTime->setText(QLatin1String("XX:XX:XXX"));
  lblLastLapTime->setText(QLatin1String("XX:XX:XXX"));

  lblLap->setText(QLatin1String("XXX"));
  lblEtap->setText(QLatin1String("XX / XX"));

  lblTemp1->setText(QLatin1String("XXXXX"));
  lblTemp2->setText(QLatin1String("XXXXX"));
}


void OCView_MainWin::showRPM(void)
{
  double rpm = m_data->vehicule.engine.rpm.value();
  double rpmMax = m_data->vehicule.engine.rpm.max();
  int value;

  if ( rpm <= rpmMax )
    {
      value = (int) (round(rpm/10)*10);
    }
  else
    {
      value = (int) rpmMax;
    }

  //std::cout << "value:" << value << std::endl;

  GraphicRPM->setValue(value);

  // couleur
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

void OCView_MainWin::showT1(void)
{
  lblTemp1->setText(m_data->vehicule.engine.temperature_1.getStr());
}

void OCView_MainWin::showT2(void)
{
  lblTemp2->setText(m_data->vehicule.engine.temperature_2.getStr());
}

void OCView_MainWin::showCurrentLapTime(void)
{
  lblCurrLapTime->setText(m_data->chrono.getStrCurrentLapTime());
}

void OCView_MainWin::showLastLapTime(void)
{
  lblLastLapTime->setText(m_data->chrono.getStrLastLapTime());
}

void OCView_MainWin::showBestLapTime(void)
{
  lblBestLapTime->setText(m_data->chrono.getStrBestLapTime());
}

void OCView_MainWin::showLap(void)
{
  QString strLap;
  if ( m_data->track.laps() > 1 )
    {
      strLap.sprintf("%d / %d", m_data->position.lap(), m_data->track.laps());
    }
  else
    {
      strLap.sprintf("%d", m_data->position.lap());
    }
  lblLap->setText(strLap);
}

void OCView_MainWin::showEtap(void)
{
  QString strEtap;
  strEtap.sprintf("%d / %d", m_data->position.etap(), m_data->track.etaps());
  lblEtap->setText(strEtap);
}

void OCView_MainWin::UpdateData(void)
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


