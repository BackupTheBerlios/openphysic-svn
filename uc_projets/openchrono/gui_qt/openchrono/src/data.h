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

#ifndef DATA_H
#define DATA_H
//
//#include <qt>
//
class Data //: public QObject
{
//Q_OBJECT

public:
	Data();

	double getRPM(void);
	void setRPM(double const RPM);

	double getT1(void);
	void setT1(double const T1);

	double getT2(void);
	void setT2(double const T2);
	
	void start(void);

private:	
	double m_RPM;
	
	double m_T1;
	double m_T2;

/*
public slots:
	void slotRPM_TestWin(int);
*/

/*
	void slotT1(int);
	void slotT2(int);
*/
/*
	void slotCurrentTime(void);
	void slotLastTime(void);
	void slotBestTime(void);
	void slotLap(void);
	void slotEtap(void);
*/

/*
public signals:
	void RPMChanged(void);
	void T1Changed(void);
	void T2Changed(void);
	void CurrentTimeChanged(void);
	void LastTimeChanged(void);
	void BestTimeChanged(void);
	void LapChanged(void);
	void EtapChanged(void);
*/

};
#endif
