#!/usr/bin/env python
# -*- coding: utf8 -*-

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
from UsefulClass import *
from numpy import * # variance

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
#for row in data:
#	print(row)
#print(header)

#  ###########################################
#  # convert list of list to list of objects
#  ###########################################

dataObj = []
for row in data:
    dataObj.append(TradencyHistory(header, row))


#  ###########################################
#  # display data (selected and sorted)
#  ###########################################

i = 1
NbTrades = len(dataObj)
for row in dataObj:
    print("=== {0}/{1} : {2}\t\t{3}\t{4}\t{5} ===".format(i, NbTrades, row.__dict__['Stratégie'], row.__dict__['A/V'], row.__dict__['Montant (k)'], row.__dict__['Symbole']))
    #print(row)
    row.display()
    print('')
    i = i + 1

#  ###########################################
#  # Calculate stats
#  ###########################################
DureeTotaleTrades = timedelta()
winTrades = 0
lostTrades = 0
winPips = 0
lostPips = 0
totalPips = 0
pipsMin = 0
IpipsMin = -1
pipsMax = 0
IpipsMax = -1
i = 0
lstPips = []
lstPipsWin = []
lstPipsLost = []

for row in dataObj:
    DureeTotaleTrades = DureeTotaleTrades + row.__dict__['Durée Trade']
    Pips = row.__dict__['Pips']
    lstPips.append(Pips)
    totalPips = totalPips + Pips
    if Pips >= 0:
        winTrades = winTrades + 1
        winPips = winPips + row.__dict__['Pips']
        lstPipsWin.append(row.__dict__['Pips'])
    else:
        lostTrades = lostTrades + 1
        lostPips = lostPips + row.__dict__['Pips']
        print(lostPips)
        lstPipsLost.append(row.__dict__['Pips'])
    if Pips > pipsMax:
        pipsMax = Pips
        IpipsMax = i
    if Pips < pipsMin:
        pipsMin = Pips
        IpipsMin = i
    i = i + 1
    	

totalPips = sum(lstPips) # cumul des pips
winTrades = len(lstPipsWin) # nb de trades gagnants
lostTrades = len(lstPipsLost) # nb de trades perdants
winPips = sum(lstPipsWin) # cumul pips gagnants
lostPips = sum(lstPipsLost) # cumul pips perdants

print("Nb total de trades = {0}".format(NbTrades))
print("Total pips = {0}".format(totalPips))
print("Pips moyen par trade = {0}".format(totalPips/NbTrades))
print("Trades gagnants\tNb = {0}/{1} ({2}%) ; Pips gagnés moy = {3}".format(winTrades, NbTrades, winTrades/NbTrades*100, winPips/winTrades))
print("Trades perdants\tNb = {0}/{1} ({2}%) ; Pips perdus moy = {3}".format(lostTrades, NbTrades, lostTrades/NbTrades*100, lostPips/lostTrades))
#print("Espérance (Pips) = {0}".format(winTrades/NbTrades * (winPips/winTrades) + lostTrades/NbTrades * (lostPips/lostTrades)))
#print("Durée totale des trades = {0}".format(DureeTotaleTrades))
print("Durée moyenne des trades = {0}".format(DureeTotaleTrades//NbTrades)) # tmdelta//n uniquement si n entier
print("Meilleur trade = {0} pips".format(pipsMax))
dataObj[IpipsMax].display()
print("Pire trade = {0} pips".format(pipsMin))
dataObj[IpipsMin].display()

print(lstPips)
print(lstPipsWin)

# indice de proximité de valeur en pips
#  0: trades avec des valeurs très différentes
#  1: trades avec des valeurs très proches (de la moy)
a = array(lstPipsWin)
print("Proximité de la moy des pips gagnants [0(loin) - 1(proche)] = {0}".format(1-2*a.std()/(a.max()))) # std=écart-type (standard deviation)

print(lstPipsLost)
a = array(lstPipsLost)
print("Proximité de la moy des pips perdants [0(loin) - 1(proche)] = {0}".format(1+2*a.std()/(a.min()))) # std=écart-type (standard deviation)

#bounds = [x for x in range(-100,101,10)]
#nb = inbound(bounds, lstPips, True, True)
#print(bounds)
#print(nb)
#for i in range(0,len(bounds)-1):
#    print("[{0};{1}[".format(bounds[i], bounds[i+1]))
