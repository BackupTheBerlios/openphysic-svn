#include "dialogimpl.h"
//
#include <sys/time.h>
#include <unistd.h>

#include <QTimer>

DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) : QDialog(parent, f)
{
	setupUi(this);
	
	running = false;
	on_clear();
	//on_show();
	
	QObject::connect(butStartStop, SIGNAL(clicked()), this, SLOT(on_start_stop()));
	QObject::connect(butClear, SIGNAL(clicked()), this, SLOT(on_clear()));
	//QObject::connect(butShow, SIGNAL(clicked()), this, SLOT(on_show()));
	
	QTimer * timer = new QTimer(this);
	connect( timer, SIGNAL(timeout()), this, SLOT(on_show()) );
	timer->start(25);
}
//

void DialogImpl::on_clear(void) 
{	
	if (!running) {
		gettimeofday(&tv1, &tz);
		//&tv2 = &tv1;
	}
}

void DialogImpl::on_start_stop(void) 
{
	running = !running;
	gettimeofday(&tv2, &tz);
}

void DialogImpl::on_show(void) 
{
	gettimeofday(&tv2, &tz);
	
	QString strMsg;
	QString strTime;
	
	
	if (running) {
		strMsg = QString("RUNNING");
	}
	else {
		strMsg = QString("NOT RUNNING");
	}
	
	
	diff = (tv2.tv_sec-tv1.tv_sec) * 1000000L + \
    	(tv2.tv_usec-tv1.tv_usec); // en us
    	
	//msg = QString(sprintf(diff,"%L"));

	//msg = QString("Test");
	
	strTime = QString("ToDo");
	
	lblTime->setText(strTime);
	
	lblMsg->setText(strMsg);
	
	//ToDo
}
