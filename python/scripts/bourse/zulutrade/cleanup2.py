#!/usr/bin/python
 
from BeautifulSoup import BeautifulSoup

datasource = open('ZuluTrade-TradeHistory.html')

html = datasource.read()

soup = BeautifulSoup(''.join(html))
 
print soup.prettify()