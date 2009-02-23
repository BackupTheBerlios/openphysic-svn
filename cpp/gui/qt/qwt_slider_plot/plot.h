//#include <qwidget.h>
#include <qwt_plot.h>

//#include <qlabel.h>
//#include <qwt_slider.h>

class Plot: public QwtPlot
{
    Q_OBJECT
public:
    Plot(QWidget *parent);

//private slots:
    //void setNum(double v);

//private:
//    QwtSlider *d_slider;
//    QLabel *d_label;
};
