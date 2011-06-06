#!/usr/bin/python

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

i = 0
for row in dat:
    if i>=2:
      print(row)
    i = i + 1