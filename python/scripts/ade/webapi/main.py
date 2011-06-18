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
import time

class ade_webapi():
    def __init__(self, url, login, password):
        self.url = url
        self.login = login
        self.password = password
        
        self.sessionId = None
        
        self.debug = True

    def xml_debug(self, xmlrep):
        if self.debug:
            print(xmlrep)
            time.sleep(2)

    def connect(self):
        f = urllib.urlopen(self.url + "function={0}&login={1}&password={2}".format('connect', self.login, self.password))
        xmlrep = f.read()
        self.xml_debug(xmlrep)
        
        dom = xml.dom.minidom.parseString(xmlrep)
        elt = dom.getElementsByTagName('session')[0]
        self.sessionId = elt.getAttribute('id')

    def disconnect(self):
        f = urllib.urlopen(self.url + "function={0}&sessionId={1}".format('disconnect', self.sessionId))
        xmlrep = f.read()
        self.xml_debug(xmlrep)
        
    def getProjectsById(self, id):
        f = urllib.urlopen(self.url + "function={0}&sessionId={1}&id={2}".format('getProjects', self.sessionId, id))
        xmlrep = f.read()
        self.xml_debug(xmlrep)

    def getProjects(self, detail):
        f = urllib.urlopen(self.url + "function={0}&sessionId={1}&detail={2}".format('getProjects', self.sessionId, detail))
        xmlrep = f.read()
        self.xml_debug(xmlrep)
        
    def setProject(self, projectId):
        f = urllib.urlopen(self.url + "function={0}&sessionId={1}&projectId={2}".format('setProject', self.sessionId, projectId))
        xmlrep = f.read()
        self.xml_debug(xmlrep)
            
    def getResources(self): # ToFix
        f = urllib.urlopen(self.url + "function={0}&sessionId={1}&tree=true&name=Amphi&category=classroom".format('getResources', self.sessionId))
        xmlrep = f.read()
        self.xml_debug(xmlrep)

    def getActivities(self):
        f = urllib.urlopen(self.url + "function={0}&sessionId={1}&tree=true".format('getActivities', self.sessionId))
        xmlrep = f.read()
        self.xml_debug(xmlrep)
        
    def getEvents(self):
        pass
        
    def getCosts(self):
        pass

    def getCaracteristics(self):
        pass
        
    def getDate(self, week, day, slot):
        pass

myade = ade_webapi('https://upplanning.appli.univ-poitiers.fr/ade/webapi?', 'login', 'password')
myade.connect()
myade.getProjects(4)
myade.setProject(11) # 2010-2011=>11 2011-2012=>1
#myade.getResources()
myade.getActivities()
myade.disconnect()
