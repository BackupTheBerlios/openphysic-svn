#!/usr/bin/env python
# -*- coding: utf8 -*-

"""
    ZuluTrade Analyzer for History of a signal provider (strategy)

       But : ce script permet d'analyser les trades effectués
       dans le système de trading automatique ZuluTrade http://www.zulutrade.com/
       pou 1 provider donné

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
#import xlrd
from openpyxl.reader.excel import load_workbook

#  ###########################################
#  # Parse HTML file        
#  ###########################################

from BeautifulSoup import BeautifulSoup

filename = 'Zulutrade_zulumaster1_Performance_2011-06-12.xls'
datasource = open(filename)
xml = datasource.read()
soup = BeautifulSoup(xml)
#print(soup.prettify())
table = soup.find('table')
#print(table)
rows = table.findAll('row')
print(rows)
for row in rows:
    print(row)
    print("-"*10)
       
#  0 : Provider Ticket
#  1 : Type
#  2 : Lots
#  3 : Currency
#  4 : Date Closed
#  5 : Price Opened
#  6 : Price Closed
#  7 : Highest Profit
#  8 : Worst Drawdown
#  9 : Roll
# 10 : Pips
# 11 : Net Profit &amp; Loss
# 12 : Live Trade?
# 13 : Accumulated Pips
# 14 : Accumulated Profit

#wb = load_workbook(filename)
#myparser = ZuluTradeHistoryParser(datasource)

#header = myparser.get_header()
#data = myparser.get_data()

#print(datasource)
#print wb.get_sheet_names()

datasource.close()
