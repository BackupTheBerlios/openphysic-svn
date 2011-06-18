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
    def __init__(self, url, login, password):
        self.url = url
        self.login = login
        self.password = password
        
        self.sessionId = None

    def connect(self):
        #f = urllib.urlopen(self.url + "function=connect&login={0}&password={1}".format(self.login, self.password))
        #xmlrep = f.read()
        xmlrep = """<?xml version="1.0" encoding="UTF-8"?>
<session id="130a433bf04"/>"""
        #print(xmlrep)
        dom = xml.dom.minidom.parseString(xmlrep)
        elt = dom.getElementsByTagName('session')[0]
        self.sessionId = elt.getAttribute('id')

    def disconnect(self):
        #f = urllib.urlopen(self.url + "function=disconnect")
        #xmlrep = f.read()
        xmlrep = """<?xml version="1.0" encoding="UTF-8"?>
<disconnected sessionId=""/>"""

        print(xmlrep)

myade = ade_webapi('https://upplanning.appli.univ-poitiers.fr/ade/webapi?', 'login', 'password')
myade.connect()
myade.disconnect()