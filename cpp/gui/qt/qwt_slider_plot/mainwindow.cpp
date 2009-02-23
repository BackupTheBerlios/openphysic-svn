#include "mainwindow.h"
#include "slider.h"

#include <math.h>

#include <qlayout.h>



MainWindow::MainWindow(QWidget *p): 
    QWidget(p)
{
QHBoxLayout *mainLayout = new QHBoxLayout();
Slider *slider = new Slider(p);
QLabel *pix = new QLabel("Add a graph here");

mainLayout->addWidget(slider);
mainLayout->addWidget(pix);

this->setLayout(mainLayout);


}


