#!/usr/bin/python
# -*- coding: utf8 -*-

from BeautifulSoup import BeautifulSoup
import urllib # urlopen
import sys # stdout

#f = urllib.urlopen("http://www.oanda.com/currency/real-time-rates") # online (test on 2011/06/06)
f = open('oanda-real-time-rates.html', 'r') # offline


#g = open('oanda-rates.csv', 'w')
g = sys.stdout

html = f.read()

soup = BeautifulSoup(html)

#print soup.prettify() # display all the web page

t = soup.findAll('table')


lstTables = []
for table in t:
    lstData = []
    rows = table.findAll('tr')
    for tr in rows:
        lstRow = []
        cols = tr.findAll('td')
        for td in cols:
            val = str(td.find(text=True))
            lstRow.append(val)
            g.write(val)
            g.write(";")
        g.write("\n")
        lstData.append(lstRow)
    lstTables.append(lstData)

nbcols = len(lstTables[0][:][0])
nblignes = len(lstTables[0][0][:])

f.close()
g.close()

#print(lstTables) # ValueError: I/O operation on closed file