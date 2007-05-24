/****************************************************************************
**
** Copyright (C) 2007 Sebastien CELLES. All rights reserved.
**
** This software is licensed under the terms of the GNU General Public
** License (GPL) version 2 and above.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#include "aboutimpl.h"
//

/* 
 *  Constructs a about box which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 */
AboutImpl::AboutImpl( QWidget * parent, Qt::WFlags f) : QWidget(parent, f)
{
	setupUi(this);
	connect(quit, SIGNAL(clicked()), this, SLOT(goodBye()));
}

/*  
 *  Destroys the object and frees any allocated resources
 */
 /*
AboutImpl::~AboutImpl()
{
	// no need to delete child widgets, Qt does it all for us
}
*/


/*
 *  A simple slot... not very interesting.
 */
 /*
void AboutImpl::goodBye()
{
    close();
}
*/
//


