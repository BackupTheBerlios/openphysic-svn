#ifndef MAINWINIMPL_H
#define MAINWINIMPL_H
//
#include "ui_mainwin.h"
//

class MainWinImpl : public QMainWindow, public Ui::MainWin
{
Q_OBJECT
public:
	MainWinImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:	
};
#endif
