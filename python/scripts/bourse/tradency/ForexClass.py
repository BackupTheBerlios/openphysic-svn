#!/usr/bin/env python3

#    FOREX class
#
#       But : ces classes définissent divers objets utilisés dans le marché des devises (FOREX=FOReign EXchange)
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

import csv

class Direction:
    def __init__(self, dir = 'Buy'):
        self.__buy__ = None
        if dir == 'Buy':
            self.__buy__ = True
        elif dir == 'Sell':
            self.__buy__ = False
        else:
            raise Exception("'Buy' or 'Sell'")

    def __repr__(self):
    	if self.__buy__ == True:
    	    return 'Buy'
    	elif self.__buy__ == False:
    	    return 'Sell'
    	#else:
    	#    return 'Undef'

    def __eq__(self, other):
        return self.__buy__ == other.__buy__

    def __ne__(self, other):
        return self.__buy__ != other.__buy__

class Currency:
# cf ISO_4217 http://en.wikipedia.org/wiki/ISO_4217
    def __init_(self):
	    self.Code = '' # Symbol
	    self.Name = ''
	    self.Num = 0
	    self.Digits = 0 # ex USD 1.23 => 2 digits

class Currencies:
    def __init__(self):
        #pass
        reader = csv.reader(open("currencies.csv"), delimiter='\t')
        writer = csv.reader(open("currencies_nw.csv", 'wb'), delimiter='\t')
        data2 = []
        for row in reader:
            row2 = []
            for col in row:
                col = col.strip()
                row2.append(col)
            data2 = row2.append(row2)
            writer.writerow(row2)
            


class Pair:
    def __init_(self):
    	# ex EURUSD 1.5767/1.5769 bid/ask sell/buy
        self.Symbol = ''
        self.Bid = 0
        self.Ask = 0
        self.fromC = None # ex EUR
        self.toC = None # ex USD
        
    def spread(self):
    	return self.Ask - self.Bid

class Pairs:
    def __init__(self):
	    pass

#class Lot
# Micro 1000
# Mini 10000
# Std 100000

# Compte en EUR
#Parité 	Montant investit en devise 	Montant investi en Euros 	Position du pip 	Valeur du pip en devise cotée à l'incertain 	Valeur du pip en Euros
#GBP/USD 	10000 GBP 	10000*(GBP/EUR) 	0.0001 	10000*0.0001=1 USD 	1 / (EUR/USD)