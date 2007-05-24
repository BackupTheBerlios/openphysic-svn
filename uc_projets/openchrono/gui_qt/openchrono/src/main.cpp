#include <QApplication>
//
#include "dialogimpl.h"
//
#include "mainwinimpl.h"
#include "aboutimpl.h"
//
int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
	
	//DialogImpl win;
	//MainWinImpl win;
	AboutImpl win;
	
	win.show(); 
	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}
