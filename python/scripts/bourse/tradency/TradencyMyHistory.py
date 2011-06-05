#!/usr/bin/env python3

#    Tradency Analyzer for MyHistory
#
#       But : ce script permet d'analyser les trades effectués sur le compte
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

datasource = open('MyHistory.html')
myparser = TradencyMyHistoryParser(datasource)

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
    myHistory = TradencyHistory(header, row)
    dataObj.append(myHistory)


#  ###########################################
#  # filter by date
#  ###########################################


#  ###########################################
#  # display data (selected and sorted)
#  ###########################################

i = 1
pips = 0
profit = 0
bilanStrateg = dict()

for row in dataObj:
    print("=== Trade {0}/{1} : {2} ({3})===".format(i, len(dataObj), row.__dict__['Stratégie'], row.__dict__['Symbole']))
    row.display()
    i = i + 1
    pips = pips + row.__dict__['Pips']
    profit = profit + row.__dict__['Profit']

    key = row.__dict__['Stratégie']+' ('+row.__dict__['Symbole']+')' # cumul par stratégie(symbole)
    try:
        #bilanStrateg[key] = bilanStrateg[key] + row.__dict__['Pips']
        bilanStrateg[key]['Pips total'] = bilanStrateg[key]['Pips total'] + row.__dict__['Pips']
        bilanStrateg[key]['Profit total'] = bilanStrateg[key]['Profit total'] + row.__dict__['Profit']
        bilanStrateg[key]['Nb Trades'] = bilanStrateg[key]['Nb Trades'] + 1
        bilanStrateg[key]['Montant (k) total'] = bilanStrateg[key]['Montant (k) total'] + row.__dict__['Montant (k)']
        bilanStrateg[key]['Durée Trade total'] = bilanStrateg[key]['Durée Trade total'] + row.__dict__['Durée Trade']

        bilanStrateg[key]['Pips moyen / trade'] = bilanStrateg[key]['Pips total']/bilanStrateg[key]['Nb Trades']
        bilanStrateg[key]['Profit moyen / trade'] = bilanStrateg[key]['Profit total']/bilanStrateg[key]['Nb Trades']
        bilanStrateg[key]['Durée moyen / trade'] = bilanStrateg[key]['Durée Trade total']//bilanStrateg[key]['Nb Trades'] # // is not a bug... deltatime/integer
        bilanStrateg[key]['Montant (k) moyen'] = bilanStrateg[key]['Montant (k) total']/bilanStrateg[key]['Nb Trades']

        #bilanStrateg[key]['Date/Heure Dernier Trade'] = row.__dict__['Fermer Heure']
		
    except:
        #bilanStrateg[key] = row.__dict__['Pips']
        bilanStrateg[key] = dict()
        bilanStrateg[key]['Stratégie'] = row.__dict__['Stratégie']
        bilanStrateg[key]['Symbole'] = row.__dict__['Symbole']
        bilanStrateg[key]['Nb Trades'] = 1
        bilanStrateg[key]['Pips total'] = row.__dict__['Pips']
        bilanStrateg[key]['Profit total'] = row.__dict__['Profit']
        bilanStrateg[key]['Montant (k) total'] = row.__dict__['Montant (k)']
        bilanStrateg[key]['Durée Trade total'] = row.__dict__['Durée Trade']
        bilanStrateg[key]['Date/Heure Premier Trade'] = row.__dict__['Ouvrir Heure']

print("="*20)

#print(bilanStrateg)

#lstBilanStrateg = [] # to sort bilan
#for key in bilanStrateg:
#    print("Bilan {0} \t\t Pips total = {1}".format(key, bilanStrateg[key]['Pips total']))
#    for key2 in bilanStrateg[key]:
#        print("\t{0} = {1}".format(key2, bilanStrateg[key][key2]))
#	#lstBilanStrateg.append([key, bilanStrateg[key]])
##	lstBilanStrateg.append({'Stratégie (Symbole)'=key, 'Pips total'=bilanStrateg[key]})


print("="*20)

print("Pips total = {0}".format(pips))
print("Profit total = {0}".format(profit))

print("="*20)


#v=bilanStrateg.items()
#lstBilanStrateg = sorted(bilanStrateg.items())
lstBilanStrateg = sorted(bilanStrateg.items(), key=lambda lstBilanStrateg: lstBilanStrateg[1]['Pips total'])
#dataObjSorted = sorted(dataObjSelected, key=lambda dataObjSelected: dataObjSelected.__dict__[criterion], reverse=not descending)

for key in lstBilanStrateg:
    print("Bilan {0} \t\t Pips total = {1}".format(key[1]['Stratégie']+' ('+key[1]['Symbole']+')', key[1]['Pips total']))
    #for key2 in key[1]:
    #    print("\t{0} = {1}".format(key2, key[1][key2]))

#print(lstBilanStrateg)
#print(items[1])