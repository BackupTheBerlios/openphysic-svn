#!/usr/bin/python
# -*- coding: utf8 -*-

"""
    Rates from Yahoo Finance
    	YQL Yahoo! Query Language
    	Open Data Tables http://www.datatables.org/

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

# http://query.yahooapis.com/v1/public/yql?q=select%20*%20from%20yahoo.finance.quotes%20where%20symbol%20in%20%28%22YHOO%22,%22AAPL%22,%22GOOG%22,%22MSFT%22%29&env=http://datatables.org/alltables.env

import yql

y = yql.Public()
query = 'select * from yahoo.finance.quotes where symbol="EURUSD=X" limit 1';
result = y.execute(query, env='http://datatables.org/alltables.env')
# ToFix : No definition found for Table yahoo.finance.quotes => env

#print(result)
#for row in result.rows:
#    print repr(row)

row = result.rows[0]
print(row['Bid'])