#ifndef MAINWINIMPL_H
#define MAINWINIMPL_H
//
#include "ui_mainwin.h"
//

#include "data.h"

class MainWinImpl : public QMainWindow, public Ui::MainWin
{
Q_OBJECT
public:
	MainWinImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	
private slots:	

private:
	//Data & myCurrentData;
};
#endif
