#!/usr/bin/python
# -*- coding: utf8 -*-

"""
    ADE API Test

    Copyright (C) 2011 "Sébastien Celles" <s.celles@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>
"""

import urllib
import xml.dom.minidom

class ade_webapi():
    def __init__(self):
        self.url = 'https://upplanning.appli.univ-poitiers.fr/ade/webapi?'
        self.login = 'login'
        self.password = 'pswd'

        #f = urllib.urlopen(self.url + "function=connect&login={0}&password={1}".format(self.login, self.password))
        #xmlrep = f.read()
        xmlrep = """<?xml version="1.0" encoding="UTF-8"?>
<session id="130a433bf04"/>"""
        #dom = dom.minidom.parseString(xmlrep)

        print(xmlrep)

        #f = urllib.urlopen(self.url + "function=disconnect")
        #xmlrep = f.read()
        xmlrep = """<?xml version="1.0" encoding="UTF-8"?>
<disconnected sessionId=""/>"""

        print(xmlrep)

myade = ade_webapi()
