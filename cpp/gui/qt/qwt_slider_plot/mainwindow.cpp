#include "mainwindow.h"
#include "slider.h"
#include "plot.h"

#include <math.h>

#include <qlayout.h>



MainWindow::MainWindow(QWidget *p): 
    QWidget(p)
{
QHBoxLayout *mainLayout = new QHBoxLayout();
Slider *slider = new Slider(p);
//QLabel *plot = new QLabel("Add a graph here");
Plot *plot = new Plot(p);

mainLayout->addWidget(slider);
mainLayout->addWidget(plot);

this->setLayout(mainLayout);


}


