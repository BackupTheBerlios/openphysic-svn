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

// Test
//#include <iostream> // cout << "Test" << endl;
//using namespace std;

// Application (QT / QTopia ...)
#include <QApplication> // QT
//#include <qtopiaapplication> // QTopia

// Test GUI
#include "dialogimpl.h"

// GUI
#include "mainwinimpl.h"
//#include "aboutimpl.h"
#include "testwinimpl.h"
//
#include "data.h"
//
#include "ocwindows.h"

int main(int argc, char ** argv)
{
    QApplication app( argc, argv );

    Data myCurrentData;
    myCurrentData.setRPM(2000.0);
    myCurrentData.setT1(50.0);
    myCurrentData.setT2(60.0);
    //myCurrentData.start();

    OCWindows * win;

    //DialogImpl winDialog(0, 0, &myCurrentData);
    //AboutImpl winAbout(0, 0, &myCurrentData);
    MainWinImpl winMain(0, 0, &myCurrentData);
    TestWinImpl winTest(0, 0, &myCurrentData);

    // connection testwin -> data
    //connect( &winTest, SIGNAL( SliderChanged() ), &winMain, SLOT( slotRPM() );
    /*
    app.connect(	(&winTest)->SliderRPM	, SIGNAL( valueChanged(int) ),
    				&myCurrentData			, SLOT( slotRPM_TestWin(int) )			);
    */


    // connection data -> mainwin
    //connect( &myCurrentData, SIGNAL( signalRPMChanged() ), &winMain, SLOT( slotRPM() );


    // connection directe testwin -> mainwin (test)
    app.connect(	(&winTest)->SliderRPM	, SIGNAL( valueChanged(int) ),
			(&winMain)->GraphicRPM	, SLOT( setValue(int) )			);   	
//			(&winMain)->GraphicRPM	, SLOT( slotRPM(int) )			);   	


    // Init pages relations
    //  -> parent init
    (&winMain)->page_parent = &winMain; // page time
    //  -> first child init
    (&winMain)->page_child_first = NULL; // ToDo
    //  -> next brother init
    (&winMain)->page_brother_next = NULL; // ToDo
    //  -> previous brother init
    (&winMain)->page_brother_previous = NULL; // ToDo

    
    //win = &winMain;

    //(&win)->page_current = &winMain;

    winMain.show();
    //win->show();


    winTest.show();
    //winAbout.show();


    /*
    myCurrentData.setRPM(2500.0);
    myCurrentData.setT1(51.0);
    myCurrentData.setT2(61.0);
    */

    app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );

    return app.exec();
}
