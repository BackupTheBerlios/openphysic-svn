#!/usr/bin/env python3

#    FOREX class test
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


from ForexClass import *

myCurs = Currencies()

print(myCurs.USD)
#myCurs.USD.display()

#myPair = Pair(myCurs.EUR, myCurs.USD)
#myPair = Pair(myCurs, 'EURUSD')

#print(myPair)

myPairs = Pairs(myCurs)
print(myPairs.EURUSD)