#!/usr/bin/python
# -*- coding: utf-8 -*-

import re

htmlfilename = 'ZuluTrade-TradeHistory.html'
htmlfile = open(htmlfilename, 'rb')
data = htmlfile.read()
data = data.replace('<br/>','__br__')
data = data.replace('<br />','__br__')
data = data.replace('&lt;','<')
#data = re.sub('style="()"', '', data)

print(data)