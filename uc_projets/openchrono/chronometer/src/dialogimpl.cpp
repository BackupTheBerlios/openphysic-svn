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
    gettimeofday(&tv2, NULL); // ToFiX tv2 should be a copy of tv1
    //&tv2 = &tv1;
    //timeval_subtract (&tvdiff, &tv2, &tv1);
  }
}

void DialogImpl::on_start_stop(void) 
{
  if (running) {
    gettimeofday(&tv2, NULL);
  } else {
    gettimeofday(&tv1, NULL);
    timeval_subtract (&tv1, &tv1, &tvdiff);
  }

  running = !running;
}

int DialogImpl::timeval_subtract (struct timeval *result, struct timeval *x, struct timeval *y)
{
  // see http://www.gnu.org/software/libc/manual/html_node/Elapsed-Time.html	
	
  /* Perform the carry for the later subtraction by updating y. */
  if (x->tv_usec < y->tv_usec) {
    int nsec = (y->tv_usec - x->tv_usec) / 1000000 + 1;
    y->tv_usec -= 1000000 * nsec;
    y->tv_sec += nsec;
  }
  if (x->tv_usec - y->tv_usec > 1000000) {
    int nsec = (x->tv_usec - y->tv_usec) / 1000000;
    y->tv_usec += 1000000 * nsec;
    y->tv_sec -= nsec;
  }
     
  /* Compute the time remaining to wait.
     tv_usec is certainly positive. */
  result->tv_sec = x->tv_sec - y->tv_sec;
  result->tv_usec = x->tv_usec - y->tv_usec;
     
  /* Return 1 if result is negative. */
  return x->tv_sec < y->tv_sec;
}

void DialogImpl::on_show(void) 
{	
  QString strMsg;
  QString strTime;
  
  
  if (running) {
    strMsg = QString("RUNNING");
    gettimeofday(&tv2, NULL);
  }
  else {
    strMsg = QString("NOT RUNNING");
  }
  
  lblMsg->setText(strMsg);
  
  
  timeval_subtract (&tvdiff, &tv2, &tv1);
  
  
  // see http://www.quepublishing.com/articles/article.asp?p=23618&seqNum=8&rl=1
  ptm = localtime (&tvdiff.tv_sec);
  strftime (time_string, sizeof (time_string), "%M:%S", ptm); //"%Y-%m-%d %H:%M:%S"
  milliseconds = tvdiff.tv_usec / 1000;
  strTime.sprintf("%s.%03ld\n", time_string, milliseconds);
  lblTime->setText(strTime);
	
}
