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

for table in t:
    rows = table.findAll('tr')
    for tr in rows:
        cols = tr.findAll('td')
        for td in cols:
            g.write(str(td.find(text=True)))
            g.write(";")
        g.write("\n")

f.close()
g.close()  