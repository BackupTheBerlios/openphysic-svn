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
	
	connect(butStartStop, SIGNAL( clicked() ), this, SLOT( on_start_stop() ));
	connect(butClear, SIGNAL( clicked() ), this, SLOT( on_clear() ));
	//QObject::connect(butShow, SIGNAL(clicked()), this, SLOT(on_show()));
	
	QTimer * timer = new QTimer(this);
	connect( timer, SIGNAL(timeout()), this, SLOT(on_show()) );
	timer->start(25);
	
}
//

void DialogImpl::on_clear(void) 
{	
	if (!running) {
		gettimeofday(&tv1, NULL);
		//&tv2 = &tv1;
	}
}

void DialogImpl::on_start_stop(void) 
{
	running = !running;
	gettimeofday(&tv2, NULL);
}

void DialogImpl::on_show(void) 
{
	gettimeofday(&tv2, NULL);
	
	QString strMsg;
	QString strTime;
	
	
	if (running) {
		strMsg = QString("RUNNING");
	}
	else {
		strMsg = QString("NOT RUNNING");
	}
	lblMsg->setText(strMsg);
	
	
	//diff = (tv2.tv_sec-tv1.tv_sec) * 1000000L + (tv2.tv_usec-tv1.tv_usec); // en us
    
    strTime = QString("ToDo");
	//strTime = QString(sprintf(diff,"%L"));
	
	ptm = localtime (&tv2.tv_sec);
	//strftime (time_string, sizeof (time_string), "%Y-%m-%d %H:%M:%S", ptm);
	strftime (time_string, sizeof (time_string), "%M:%S", ptm);
	milliseconds = tv2.tv_usec / 1000;
	strTime.sprintf("%s.%03ld\n", time_string, milliseconds);	 
	lblTime->setText(strTime);

	
	//ToDo
}
