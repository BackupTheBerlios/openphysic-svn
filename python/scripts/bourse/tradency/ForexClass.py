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
from datetime import datetime

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
    def __init__(self, code = '', name = '', num = 0, digits = 0, locations = []):
        if len(code)!=3:
            raise(Exception('Currency code must be 3 letters long. ex: EUR'))    	

        self.Code = code # Symbol
        self.Name = name
        self.Num = num
        self.Digits = digits # ex USD 1.23 => 2 digits
        self.Locations = locations

    def __repr__(self):
    	return self.Code
    
    def display(self):
    	print(self.__dict__)
        #print(repr(self.__dict__))
        

class Currencies(dict):
    def __init__(self):
        #pass
        reader = csv.reader(open("currencies.csv"), delimiter='\t')
        i = 0
        for row in reader:
            if i!=0:
                self.__dict__[row[0]] = Currency(row[0], row[3], row[1], row[2])
            i = i + 1
        
    def __repr__(self):
        return repr(self.__dict__)


class Pair:
    #def __init__(self, fromC = None, toC = None):
    	# ex EURUSD 1.5767/1.5769 bid/ask sell/buy
        #self.fromC = fromC # ex EUR
        #self.toC = toC # ex USD
        #self.Symbol = ''
        #self.Bid = 0
        #self.Ask = 0
        #self.update()

    def __init__(self, currencies = None, symbol = ''):
    	# ex EURUSD 1.5767/1.5769 bid/ask sell/buy 1EUR=1.58$
        if len(symbol)!=6:
            raise(Exception('Pair symbol must be 6 letters long. ex: EURUSD'))    	
        #self.fromC = Currency(symbol[:3]) # ex EUR
        #self.toC = Currency(symbol[3:]) # ex USD
        try:
            self.fromC = currencies.__dict__[symbol[:3]] # ex EUR
        except:
            raise(Exception("The xxx currency in xxx/yyy pair doesn't exist"))
        try:
            self.toC = currencies.__dict__[symbol[3:]] # ex USD        
        except:
            raise(Exception("The yyy currency in xxx/yyy pair doesn't exist"))
        self.Bid = 0
        self.Ask = 0
        self.PipPosition = 4 # 0.0001 (so 4 because 10^(-4)) for most pairs but for xxxJPY PipPosition=2
        self.date = datetime.now()
        self.update()
        
    def update(self):
    	self.Symbol = self.fromC.Code + self.toC.Code
    	self.spread = self.Ask - self.Bid

    def __repr__(self):
    	self.update()
    	return self.Symbol


class Pairs:
    def __init__(self, currencies = None):
    	pass
        #reader = csv.reader(open("pairs.csv"), delimiter='\t')
        #i = 0
        #for row in reader:
        #    if i!=0:
        #        pair = Pair(currencies, row[0])
        #        self.__dict__[row[0]] = pair
        #    i = i + 1
        
    def __repr__(self):
        return repr(self.__dict__)


#class Lot
# Micro 1000
# Mini 10000
# Std 100000

# Pip calculator
# Compte en EUR
#Parité 	Montant investit en devise 	Montant investi en Euros 	Position du pip 	Valeur du pip en devise cotée à l'incertain 	Valeur du pip en Euros
#GBP/USD 	10000 GBP 	10000*(GBP/EUR) 	0.0001 	10000*0.0001=1 USD 	1 / (EUR/USD)

# Candelstick
# OHLC = Open High Low Close