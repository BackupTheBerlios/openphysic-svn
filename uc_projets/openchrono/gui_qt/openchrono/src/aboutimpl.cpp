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

#include "aboutimpl.h"
//

/*
 *  Constructs a about box which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 */
AboutImpl::AboutImpl( QWidget * parent, Qt::WFlags f, Data * data ) : QWidget(parent, f)
{
    setupUi(this);
    m_Data = data;

    //textBrowser->setHtml("Hello");

    connect(quit, SIGNAL(clicked()), this, SLOT(goodBye()));
}

/*
 *  Destroys the object and frees any allocated resources
 */
AboutImpl::~AboutImpl()
{
    // no need to delete child widgets, Qt does it all for us
}


/*
 *  A simple slot... not very interesting.
 */
void AboutImpl::goodBye()
{
    close();
}
//


