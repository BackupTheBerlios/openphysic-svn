#!/usr/bin/python

import urllib 
from BeautifulSoup import BeautifulSoup

f = urllib.urlopen("http://www.oanda.com/currency/real-time-rates")
html = f.read()

soup = BeautifulSoup(html)

#print soup.prettify() # display all the web page

table = soup.find('table')

print(table.prettify())