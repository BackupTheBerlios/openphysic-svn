#!/usr/bin/python
# -*- coding: utf8 -*-

import urllib 
from BeautifulSoup import BeautifulSoup

#f = urllib.urlopen("http://www.oanda.com/currency/real-time-rates") # online
f = open('oanda-real-time-rates.html') # offline

html = f.read()

soup = BeautifulSoup(html)

#print soup.prettify() # display all the web page

table = soup.find('table')

print(table.prettify())

dat = [ map(str, row.findAll("td")) for row in table.findAll("tr") ]

# ligne 0 header
# ligne 1 currency_first
# denière ligne currency_last
for row in dat[2:-1]:
    print(row)
