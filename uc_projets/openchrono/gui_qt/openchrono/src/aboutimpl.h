#ifndef ABOUTIMPL_H
#define ABOUTIMPL_H
//
#include "ui_about.h"
//
class AboutImpl : public QWidget, public Ui::About
{
Q_OBJECT
public:
	AboutImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
    virtual ~AboutImpl();
private slots:
    void goodBye();
};
#endif
