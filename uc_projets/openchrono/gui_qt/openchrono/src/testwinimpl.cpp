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
#include <QTimer>

#include <iostream> //for test

#include "mainwinimpl.h"

TestWinImpl::TestWinImpl( QWidget * parent, Qt::WFlags f, Data * data ) : QDialog(parent, f)
{
  setupUi(this);
  m_data = data;
  //m_win = win;

  setGeometry(450,100,580,240);

  // connection bouton StartStop page de test
  connect(        StartStop	, SIGNAL( clicked() ),
                      m_data                , SLOT( start() )                       );

  // connect signals and slots
  //connect(slider, SIGNAL(valueChanged(int)),
  //         lcd, SLOT(display(int)));
  //QObject::connect(SliderRPM, SIGNAL(valueChanged(int)), progressBar, SLOT(setValue(int)));
  //QObject::connect(SliderRPM, SIGNAL(valueChanged(int)), lblRPM, SLOT(setNum(int)));

  connect(butTest, SIGNAL( clicked() ), this, SLOT( test() ) ); // test button

  // connect keyboard (on the test window to the app)
/*
  connect(butOk, SIGNAL( clicked() ), m_win, SLOT( on_ok() ) );
  connect(butCancel, SIGNAL( clicked() ), m_win, SLOT( on_cancel() ) );
  connect(butUp, SIGNAL( clicked() ), m_win, SLOT( on_up() ) );
  connect(butDown, SIGNAL( clicked() ), m_win, SLOT( on_down() ) );
  connect(butLeft, SIGNAL( clicked() ), m_win, SLOT( on_left() ) );
  connect(butRight, SIGNAL( clicked() ), m_win, SLOT( on_right() ) );
*/

  init(); // initial values of the test window

  // Timer to update data entered using the test window
  QTimer * timer = new QTimer(this);
  connect( timer, SIGNAL( timeout() ), this, SLOT( update() ) );
  timer->start(25);
}
//

TestWinImpl::~TestWinImpl()
{
}

void TestWinImpl::init(void)
{
  SliderRPM->setValue(2000);
  SliderTemp1->setValue(51);
  SliderTemp2->setValue(52);
}

void TestWinImpl::update(void)
{
  m_data->vehicule.engine.rpm.set(SliderRPM->value());
  m_data->vehicule.engine.temperature_1.set(SliderTemp1->value());
  m_data->vehicule.engine.temperature_2.set(SliderTemp2->value());
}

void TestWinImpl::test(void)
{
  std::cout << "Test Win" << std::endl;
  m_data->test();
  m_data->vehicule.engine.engine_state.show();
}



