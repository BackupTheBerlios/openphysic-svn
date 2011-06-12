#!/usr/bin/env python
# -*- coding: utf8 -*-

"""
    ZuluTrade analyzer class

       But : ce script permet d'analyser les performances de diverses stratégies utilisées
       dans le système de trading automatique ZuluTrade http://www.zulutrade.com/

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

from BeautifulSoup import BeautifulSoup
import re
from datetime import datetime

class ZuluTradeMyHistoryParser():
    def __init__(self, datasource):
        html = datasource.read()
        soup = BeautifulSoup(html)
        table = soup.find('table')
        #print(table)
        self.lstData = []
        self.lstHead = []
        rows = table.findAll('tr')
        i = 0
        for tr in rows:
            lstRow = []
            if i==0:
                cols = tr.findAll('th')
                for td in cols:
                    val = td.findAll(text=True)    
                    lstRow.append(str(val[0]))
                self.lstHead = lstRow
            else:
                cols = tr.findAll('td')
                for td in cols:
                    val = td.findAll(text=True)
                    lstRow.append(val)
                self.lstData.append(lstRow)
            i = i + 1

        # 0..8
        # 9 # &lt;tr>&lt;td>Gross PnL:&lt;/td>&lt;td>-€12.49&lt;/td>&lt;/tr>&lt;tr>&lt;td>Interest:&lt;/td>&lt;td>€0.00&lt;/td>&lt;/tr>&lt;tr>&lt;td>Commision:&lt;/td>&lt;td>€0.00&lt;/td>&lt;/tr>&lt;tr>&lt;td>Net PnL:&lt;/td>&lt;td>-€12.49&lt;/td>&lt;/tr>&lt;/table>" style="background-color:#FFD2D2;">-15 pips
        # 10 # xxx pips / €xxx.yy
        
        datasource.close()

        for i in range(0, len(self.lstData)):
            for j in range(0, 10+1):
                val = self.lstData[i][j]
                if j==0 or j==1 or j==2:
                	val = str(val[0].strip())    
                elif j==3:
                    val = int(val[0])
                elif j==4 or j==5:
                    val = datetime.strptime(val[0].strip(), '%Y/%m/%d %H:%M:%S')
                elif j==6 or j==7:
                    val = float(val[0])
                elif j==8:
        	    	val = [int(val[0]), int(val[1])]
                elif j==9:
                    val[0] = val[0][val[0].find(';">')+3:len(val[0])] # nettoyer le code HTML
                    profitpips = float(val[0][0:val[0].find(" pips")]) # enlever _pips à la fin
                    val[1] = val[1].strip()
                    if val[1][0]=='-':
                        val[1] = val[1][1:len(val[1])]
                        profitcur = -float(val[1][1:(len(val[1]))]) # enlever le symb euro au début            
                    else:
                        profitcur = float(val[1][1:(len(val[1]))]) # enlever le symb euro au début
                    val = [profitpips, profitcur] # tofix
                elif j==10:
                    totalpips = float(val[0][0:val[0].find(" pips")]) # enlever _pips à la fin
                    val[1] = val[1].strip()
                    if val[1][0]=='-':
                        val[1] = val[1][1:len(val[1])]
                        totalcur = -float(val[1][1:(len(val[1]))]) # enlever le symb euro au début            
                    else:
                        totalcur = float(val[1][1:(len(val[1]))]) # enlever le symb euro au début
                    val = [totalpips, totalcur] # tofix
                else:
                	pass
                #print(val)
                self.lstData[i][j] = val
            #print(". "*10)

        #print("*"*10)

        #print(self.lstHead)
        # Rename head
        self.lstHead[0] = "Stratégie"
        self.lstHead[4] = "Ouvrir Heure"
        self.lstHead[5] = "Fermer Heure"
        self.lstHead[6] = "Ouvrir Prix"
        self.lstHead[7] = "Fermer Prix"
        self.lstHead[8] = "Haut/Bas"

    def get_header(self):
        return self.lstHead

    def get_data(self):
        return self.lstData
        
    def get(self, colname, index): #, lstindex = None):
        j =  self.lstHead.index(colname)
        return self.lstData[index][j]
        #if lstindex == None:
        #    return self.lstData[index][j]
        #else:
        #    return self.lstData[index][j][lstindex]

    def getAll(self, colname, lstindex = None):
        j =  self.lstHead.index(colname)
        lst = []
        for i in range(0, len(self.lstData)):
            if lstindex == None:
                lst.append(self.lstData[i][j])
            else:
                lst.append(self.lstData[i][j][lstindex])
        return lst

#  ###########################################

class Dict2Obj:
    def __init__(self, format, value):
        
        i = 0
        for key in format:
            self.__dict__[key] = value[i]
            i = i + 1
                
    def __repr__(self):
        return repr(self.__dict__)
        
    def display(self):
        for key in self.__dict__:
            print("\t{0} = {1}".format(key,self.__dict__[key]))

#  ###########################################

class ZuluTradeMyHistory(Dict2Obj):
    def __init__(self, format, value):
        Dict2Obj.__init__(self, format, value)
