#ifndef TESTWINIMPL_H
#define TESTWINIMPL_H
//
#include "ui_testwin.h"
//
class TestWinImpl : public QDialog, public Ui::TestWin
{
Q_OBJECT
public:
	TestWinImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:	
};
#endif
