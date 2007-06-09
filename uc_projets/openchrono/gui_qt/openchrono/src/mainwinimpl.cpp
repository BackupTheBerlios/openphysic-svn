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

    lblCurrTime->setText("XX:XX:XXX");
    lblBestTime->setText("XX:XX:XXX");
    lblLastTime->setText("XX:XX:XXX");

    lblLap->setText("XXX");
    lblEtap->setText("XX / XX");

    lblTemp1->setText("XXXXX");
    lblTemp2->setText("XXXXX");
}

void MainWinImpl::showRPM(void) {
    //GraphicRPM->setValue((int) m_Data->getRPM()); // ToFiX
}

void MainWinImpl::showT1(void) {
    // ToDo
}

void MainWinImpl::showT2(void) {
    // ToDo
}

void MainWinImpl::showCurrentTime(void) {
    // ToDo
    lblCurrTime->setText("XY:XY:XYZ");
}

void MainWinImpl::showLastTime(void) {
    // ToDo
}

void MainWinImpl::showBestTime(void) {
    // ToDo
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
    showCurrentTime();
    showLastTime();
    showBestTime();
    showLap();
    showEtap();
}
