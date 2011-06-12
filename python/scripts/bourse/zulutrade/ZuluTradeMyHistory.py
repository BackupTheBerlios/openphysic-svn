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

from ZuluTradeAnalyzerClass import *

#  ###########################################
#  # Parse HTML file        
#  ###########################################

datasource = open('ZuluTrade-TradeHistory.html')
myparser = ZuluTradeMyHistoryParser(datasource)

header = myparser.get_header()
data = myparser.get_data()

#print(myparser.MoveFirst)
#print(myparser.MoveNext)
#print(myparser.EOF)
#print(myparser.get('Profit', 2)) #
#print(myparser.getAll('Fournisseur'))
#print(myparser.getAll('Profit', 0)) # liste des profits en pips

#  ###########################################
#  # convert list of list to list of objects
#  ###########################################

dataObj = []
for row in data:
    myHistory = ZuluTradeMyHistory(header, row)
    dataObj.append(myHistory)

for row in dataObj:
    #print("Fournisseur {0}".format(row['Stratégie']))
    row.display()
    print("-"*10)