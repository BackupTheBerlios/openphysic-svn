#!/usr/bin/python
# -*- coding: utf8 -*-

"""
    Bitcoin rates from Mt Gox API

    Copyright (C) 2011 "NoOne" <noone@nowhere.com>
    You can donate @ 1MDzyfk4s2KzY1N5VybfDNRDQucrBZoMA5

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
import json
import datetime
import time

def update():
    #f = urllib.urlopen("http://mtgox.com/code/data/ticker.php")
    #json_data = f.read()

    # Value for test 2011/06/18 @ 09:45
    d = {'ticker': {'high': 17.2, 'low':13, 'vol':83990, 'buy':15.2303, 'sell':15.4499, 'last':15.2303}}
    json_data = json.dumps(d)

    #print(json_data)

    data=json.loads(json_data)
    #print(data['ticker']['sell'])
    print("""Bitcoin rates from Mt Gox API @ {0}
Buy : {1}
Sell : {2}
High : {3}
Low : {4}
Last : {5}
Vol : {6}""".format(
    datetime.datetime.now(), #.strftime('%Y/%m/%d %H:%M:%s'),
    data['ticker']['buy'],
    data['ticker']['sell'],
    data['ticker']['high'],
    data['ticker']['low'],
    data['ticker']['last'],
    data['ticker']['vol']
))
    print("="*10)
    #f.close()

while(True):
    update()
    time.sleep(6)
