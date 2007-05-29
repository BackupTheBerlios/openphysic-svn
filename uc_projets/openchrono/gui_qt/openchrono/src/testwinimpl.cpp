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

#include "testwinimpl.h"
//
TestWinImpl::TestWinImpl( QWidget * parent, Qt::WFlags f, Data * data ) : QDialog(parent, f)
{
    setupUi(this);
    m_Data = data;

    // connect signals and slots
    //connect(slider, SIGNAL(valueChanged(int)),
    //         lcd, SLOT(display(int)));
    //QObject::connect(SliderRPM, SIGNAL(valueChanged(int)), progressBar, SLOT(setValue(int)));
    //QObject::connect(SliderRPM, SIGNAL(valueChanged(int)), lblRPM, SLOT(setNum(int)));

    Update();
}
//

void TestWinImpl::Update(void) {
    SliderRPM->setValue(2000);
    SliderTemp1->setValue(50);
    SliderTemp2->setValue(50);
}

/*
Color RGB
Vert  :   0 255   0 
Jaune : 255 255   0
Rouge : 255   0   0
*/
