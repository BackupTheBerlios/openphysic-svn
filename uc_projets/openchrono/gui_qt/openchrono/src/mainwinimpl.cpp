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
MainWinImpl::MainWinImpl( QWidget * parent, Qt::WFlags f, Data * data ) : QMainWindow(parent, f)
{	
	setupUi(this); //ui.setupUi(this);
	m_Data = data;
	
	setGeometry(100,100,320,240);

	//setLayout(verticalLayout);
	
	//TestWin();
	
	//UpdateAll();
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

void MainWinImpl::slotRPM(void) {
	GraphicRPM->setValue((int) m_Data->getRPM());
}

void MainWinImpl::slotT1(void) {
	// ToDo
}

void MainWinImpl::slotT2(void) {
	// ToDo
}

void MainWinImpl::slotCurrentTime(void) {
	// ToDo
}

void MainWinImpl::slotLastTime(void) {
	// ToDo
}

void MainWinImpl::slotBestTime(void) {
	// ToDo
}

void MainWinImpl::slotLap(void) {
	// ToDo
}

void MainWinImpl::slotEtap(void) {
	// ToDo
}

void MainWinImpl::UpdateAll(void) {
	slotRPM();
	slotT1();
	slotT2();
	slotCurrentTime();
	slotLastTime();
	slotBestTime();
	slotLap();
	slotEtap();
}