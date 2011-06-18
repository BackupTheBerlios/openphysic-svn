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

url = 'https://upplanning.appli.univ-poitiers.fr/ade/webapi?'
login = 'login'
password = 'password'

f = urllib.urlopen(url + "function=connect&login={0}&password={1}".format(login, password))
xml = f.read()

print(xml)

f = urllib.urlopen(url + "function=disconnect")
xml = f.read()

print(xml)
