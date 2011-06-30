#!/usr/bin/env python
# -*- coding: utf8 -*-

"""
    Currensee Analyzer for History of a trader

       But : ce script permet d'analyser les trades effectués
       dans le système de trading http://www.currensee.com/

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

from CurrenseeAnalyzerClass import *

#  ###########################################
#  # Open XLS file
#  ###########################################
import xlrd
book = xlrd.open_workbook("Closed+Trades.xls")
sh = book.sheet_by_index(0)

for r in range(sh.nrows): #[0:3]
    print sh.row(r)[:7]

