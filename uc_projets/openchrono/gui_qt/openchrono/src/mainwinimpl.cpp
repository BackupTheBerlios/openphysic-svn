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

#include <QTimer>

MainWinImpl::MainWinImpl( QWidget * parent, Qt::WFlags f, Data * data ) : QWidget(parent, f)
{
    setupUi(this); //ui.setupUi(this);
    m_Data = data;

    setGeometry(100,100,320,240);

    //TestWin();

    //UpdateData();

    // update RPM
    GraphicRPM->setMaximum((int) m_Data->getRPMmax());
    GraphicRPM->setMinimum((int) m_Data->getRPMmin());
    
    //delete layout();
    //setLayout(vboxLayout);

    QTimer * timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(UpdateData()) );
    timer->start(25);

}
//

void MainWinImpl::TestWin(void) {
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

void MainWinImpl::showRPM(void) {
    GraphicRPM->setValue((int) m_Data->getRPM()); // ToFiX
}

void MainWinImpl::showT1(void) {
    // ToDo
    lblTemp1->setText("62 C");
}

void MainWinImpl::showT2(void) {
    // ToDo
    lblTemp2->setText("65 C");
}

void MainWinImpl::showCurrentLapTime(void) {
  lblCurrLapTime->setText(m_Data->chrono.getStrCurrentLapTime());
}

void MainWinImpl::showLastLapTime(void) {
  lblLastLapTime->setText(m_Data->chrono.getStrLastLapTime());
}

void MainWinImpl::showBestLapTime(void) {
  lblBestLapTime->setText(m_Data->chrono.getStrBestLapTime());
}

void MainWinImpl::showLap(void) {
    // ToDo
}

void MainWinImpl::showEtap(void) {
    // ToDo
}

void MainWinImpl::start(void) {
    m_Data->start();
}

void MainWinImpl::UpdateData(void) {
    showRPM();
    showT1();
    showT2();
    showCurrentLapTime();
    showLastLapTime();
    showBestLapTime();
    showLap();
    showEtap();
}
