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

    Data myCurrentData;

    //DialogImpl win;
    //AboutImpl win;
    MainWinImpl win;
    TestWinImpl wintest;
    //win.myCurrentData = myCurrentData;

    win.show();
    wintest.show();

    app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
    return app.exec();
}
