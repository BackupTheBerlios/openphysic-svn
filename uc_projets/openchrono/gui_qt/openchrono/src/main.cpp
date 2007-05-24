// Application (QT / QTopia ...)
#include <QApplication>

// Test GUI
#include "dialogimpl.h"

// GUI
#include "mainwinimpl.h"
#include "aboutimpl.h"
#include "testwinimpl.h"

// 
#include "data.h"
//

int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
	
	//DialogImpl win;
	//AboutImpl win;
	MainWinImpl win;
	TestWinImpl wintest;
	
	Data myCurrentData;
	
	win.show(); 
	wintest.show();
	
	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}
