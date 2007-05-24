/*
OpenChrono
Copyright (C) 2007  Sebastien CELLES

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

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
