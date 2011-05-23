#!/usr/bin/env python3

#    Tradency Analyzer for History
#
#       But : ce script permet d'analyser les trades d'une stratégie utilisée
#       dans le système de trading automatique Tradency http://www.tradency.com/
#       utilisé par différents brokers sous le nom FXCM Forex System Selector, Alpari NZ Systematic ...
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

from TradencyAnalyzerClass import *

#  ###########################################
#  # parse HTML file        
#  ###########################################

datasource = open('History.html')
#myparser = HTMLTableParser(datasource)
#myparser.parse()
myparser = TradencyHistoryParser(datasource)
#myparser.print_data()

header = myparser.get_header()
data = myparser.get_data()

#print(data)
for row in data:
	print(row)
print(header)