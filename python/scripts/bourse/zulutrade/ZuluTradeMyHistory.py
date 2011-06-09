#!/usr/bin/env python
# -*- coding: utf8 -*-

"""
    ZuluTrade Analyzer for My History

       But : ce script permet d'analyser les trades effectués
       dans le système de trading automatique ZuluTrade http://www.zulutrade.com/
       selon les signaux envoyés par divers providers

    Copyright (C) 2011  "Sébastien CELLES" <s.celles@gmail.com>

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

#from ZuluTradeAnalyzerClass import *

#  ###########################################
#  # read HTML file        
#  ###########################################

from BeautifulSoup import BeautifulSoup

datasource = open('ZuluTrade-TradeHistory.html')
html = datasource.read()
soup = BeautifulSoup(html)
table = soup.find('table')
#print(table)
lstData = []
rows = table.findAll('tr')
i = 0
for tr in rows:
    lstRow = []
    cols = tr.findAll('td')
    j = 0
    for td in cols:
        #val = str(td.find(text=True))
        val = td.findAll(text=True)
        #val = td.text
        #val = val.strip()
        lstRow.append(val)
        j = j + 1
    lstData.append(lstRow)
    i = i + 1
# 0..8
# 9 # &lt;tr>&lt;td>Gross PnL:&lt;/td>&lt;td>-€12.49&lt;/td>&lt;/tr>&lt;tr>&lt;td>Interest:&lt;/td>&lt;td>€0.00&lt;/td>&lt;/tr>&lt;tr>&lt;td>Commision:&lt;/td>&lt;td>€0.00&lt;/td>&lt;/tr>&lt;tr>&lt;td>Net PnL:&lt;/td>&lt;td>-€12.49&lt;/td>&lt;/tr>&lt;/table>" style="background-color:#FFD2D2;">-15 pips
print(lstData[2][7])
print(lstData[2][8])

datasource.close()


#print(datasource)
#myreader = HTMLTableWithHeadParser(datasource)
#myreader = ZuluTradeMyHistoryReader(datasource)

#myreader.print_data()

#header = myreader.get_header()
#data = myreader.get_data()
