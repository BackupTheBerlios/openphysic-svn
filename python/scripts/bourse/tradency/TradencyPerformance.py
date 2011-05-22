#!/usr/bin/env python3

#    TradencyPerformance analyzer
#
#       But : ce script permet d'analyser les performances de diverses stratégies utilisées
#       dans le système de trading automatique Tradency http://www.tradency.com/
#
#       Technique : exportez depuis l'interface de Tradency le fichier Excel contenant les performances
#       (en réalité ça n'est pas un fichier Excel mais c'est un fichier HTML qui contient un tableau)
#       copiez ce fichier sous le nom TradencyPerformance.html
#       lancez le script via $ python3 TradencyPerformance.py
#       modifiez-le afin qu'il vous convienne en ajoutant des critères complémentaires
#       aucune garantie n'est apportée quand à l'utilisation de ce script
#       c'est vous qui tradez et qui devez respecter un money management !
#       pensez à observer l'historique de trading d'une stratégie afin de vraiment vous assurer
#       qu'elle vous aurait convenu (en espérant qu'elle vous convienne par la suite)
#
#    Copyright (C) 2010  "Sébastien CELLES" <s.celles@gmail.com>
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

from TradencyPerformanceClass import *

datasource = open('TradencyPerformance.html')
#myparser = HTMLTableParser(datasource)
#myparser.parse()
myparser = TradencyPerformanceParser(datasource)
myparser.print_data()

header = myparser.get_header()
data = myparser.get_data()

#print(data)
#print(header)

# convert list of list to list of objects
dataObj = []
for row in data:
    myPerformance = TradencyPerformance(header, row)
    dataObj.append(myPerformance)

#print(row)

#['Stratégie', 'Symbole', 'T-Score', 'NumTrades', 'Max DD', 'Pips', 'Positions Max', '% gain', 'TAR', 'Profit', 'Facteur de Profit', 'Date', 'GMT (pips)', 'Temps de Trade Moyen', 'PMT (pips)', 'TPM (pips)', 'PMT (pips)']

criterium = 'T-Score' #'Temps de Trade Moyen' #'T-Score' #'Espérance'
descending = True
nw_data = sorted(dataObj, key=lambda dataObj: dataObj.__dict__[criterium], reverse=not descending)
i=1
for row in nw_data:
    if row.__dict__['TradeDepuis']>timedelta(30) and row.__dict__['NumTrades']>30 and row.__dict__['Facteur de Profit']>1 and row.__dict__['Facteur de Profit']<3.5 and row.__dict__['Espérance']>5:
    #if True:
        print("=== {4}: {0}\t\t{1}\t{2}={3} ===".format(row.__dict__['Stratégie'], row.__dict__['Symbole'], criterium, row.__dict__[criterium], i))
        #print(row)
        row.display()
        print('')
        i = i + 1

"""
Mes remarques

http://www.trader-forex.fr/forum/systemes-de-trading-auto/11080-fxcm-system-selector-fss-6.html

"""

