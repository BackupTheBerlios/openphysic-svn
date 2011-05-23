#!/usr/bin/env python3

#    FOREX class
#
#       But : ce script permet d'analyser les performances de diverses stratégies utilisées
#       dans le système de trading automatique Tradency http://www.tradency.com/
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
        if dir == 'Buy':
            self.__buy__ = True
        elif dir == 'Sell':
            self.__buy__ = False
        else:
            #self.__buy__ = None
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

#class Pair

#class Lot
# Micro
# Mini
# Std