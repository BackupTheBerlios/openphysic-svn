#include "testpattern.h"
#include "ui_testpattern.h"
#include "qpainter.h"

Testpattern::Testpattern(QWidget *parent)
    : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

    this->setWindowState(Qt::WindowFullScreen);

    QPalette palette;
    palette.setColor(QPalette::Window, Qt::white); // QColor(0,255,0,255)
    this->setPalette(palette);


}

void Testpattern::paintEvent(QPaintEvent * event)
{
    //int w = 640;
    //int h = 480;

    testpattern1();

}

void Testpattern::testpattern1(void)
{
    QPainter painter(this);
    QRect dim = painter.window();
    painter.setPen(QPen(Qt::black, 1));
    //painter.drawLine(dim.topLeft(), dim.bottomRight()); // diag

    int x,y,w,h;
    dim.getRect(&x,&y,&w,&h);
    //w = 640;
    //h = 480;

    int i, j=0;
    for (i=0 ; i<h ; i++) {
        for (j=0 ; j<w ; j++) {
            if (i%2==1 && j%2==1) {
                painter.drawPoint(j,i);
            }
        }
    }
}

Testpattern::~Testpattern()
{
    delete ui;
}
