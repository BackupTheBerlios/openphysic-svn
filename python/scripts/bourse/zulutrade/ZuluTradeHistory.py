#!/usr/bin/env python
# -*- coding: utf8 -*-

"""
    ZuluTrade Analyzer for History of a signal provider (strategy)

       But : ce script permet d'analyser les trades effectués
       dans le système de trading automatique ZuluTrade http://www.zulutrade.com/
       pour 1 signal provider donné

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

from ZuluTradeAnalyzerClass import *

#  ###########################################
#  # Parse XLS (XML) file        
#  ###########################################

from BeautifulSoup import BeautifulSoup

filename = 'Zulutrade_zulumaster1_Performance_2011-06-12.xls'
myparser = ZuluTradeHistoryParser(filename)

header = myparser.get_header()
data = myparser.get_data()
#print(header)
#print(data)
#print(header)

#  ###########################################
#  # convert list of list to list of objects
#  ###########################################

dataObj = []
for row in data:
    myHistory = ZuluTradeMyHistory(header, row)
    dataObj.append(myHistory)

i = 1
for row in dataObj:
    #print("Fournisseur {0}".format(row['Stratégie']))
    row.display()
    print("-"*10)
    i = i + 1
    
Pips = myparser.getAll('Pips')
PipsMin = min(Pips)
PipsMax = max(Pips)
print("Pips Min = {0}".format(PipsMin))
print("Pips Max = {0}".format(PipsMax))