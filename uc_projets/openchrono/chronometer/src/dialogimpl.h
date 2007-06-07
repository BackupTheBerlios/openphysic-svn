#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include "ui_dialog.h"
//
#include <sys/time.h>
#include <unistd.h>

class DialogImpl : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	
	struct timeval tv1,tv2;
  	struct timezone tz;
  	long long diff;
  	bool running;
	
private slots:
	void on_clear(void);
	void on_start_stop(void);
	void on_show(void);

};
#endif



