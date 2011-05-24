#!/usr/bin/env python3

#    FOREX class
#
#       But : ces classes définissent divers objets utilisés dans le FOREX
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

#class Currency
# cf ISO_4217 http://en.wikipedia.org/wiki/ISO_4217
# Symbol
# Name
# Num
# Digits (ex USD 1.23 => 2 digits)

#class Pair
# Symbol
# Bid
# Ask

#class Lot
# Micro 1000
# Mini 10000
# Std 100000

# Compte en EUR
#Parité 	Montant investit en devise 	Montant investi en Euros 	Position du pip 	Valeur du pip en devise cotée à l'incertain 	Valeur du pip en Euros
#GBP/USD 	10000 GBP 	10000*(GBP/EUR) 	0.0001 	10000*0.0001=1 USD 	1 / (EUR/USD)