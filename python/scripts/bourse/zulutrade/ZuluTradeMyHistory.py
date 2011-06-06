#!/usr/bin/env python
# -*- coding: utf8 -*-
  
#    ZuluTrade Analyzer for My History
#
#       But : ce script permet d'analyser les trades effectués
#       dans le système de trading automatique ZuluTrade http://www.zulutrade.com/
#       selon les signaux envoyés par divers providers
#
#    Copyright (C) 2011  "Sébastien CELLES" <s.celles@gmail.com>
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>

from ZuluTradeAnalyzerClass import *

#  ###########################################
#  # read XLS file        
#  ###########################################

datasource = open('ZuluTrade-TradeHistory.xls')
#print(datasource)
myreader = HTMLTableWithHeadParser(datasource)
#myreader = ZuluTradeMyHistoryReader(datasource)

myreader.print_data()

#header = myreader.get_header()
#data = myreader.get_data()
