#include "plot.h"

#include <qwt_legend.h>

Plot::Plot(QWidget *parent):
    QwtPlot(parent)
{
    setTitle("Slider and plot Demonstration");
    insertLegend(new QwtLegend(), QwtPlot::RightLegend);

    // Set axis titles
    setAxisTitle(xBottom, "t");
    setAxisTitle(yLeft, "y");
}
