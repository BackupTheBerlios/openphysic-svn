#!/usr/bin/env python3

from html.parser import HTMLParser
from datetime import date, datetime, timedelta
#import csv

class TradencyPerformance:
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

class TradencyPerformanceParser(HTMLParser):
    def __init__(self, fh):
        """
        {fh} must be an input stream returned by open() or urllib2.urlopen()
        """
        HTMLParser.__init__(self)
        self.header = []
        self.data = []
        self.state = 0 # 0:init 1:table 2:end of table
        self.rows = 0
        self.cels = 0
        self.cols = 0
        self.feed(fh.read())

    def handle_starttag(self, tag, attrs):
        if tag == 'table':
            self.state = 1

        if self.state == 1:
            if tag == 'tr':
                self.rows = self.rows + 1
                self.cols = 0
                self.row = []
                #self.row = ()
        	
            if tag == 'td':
                self.cels = self.cels + 1
                self.cols = self.cols + 1

    def handle_endtag(self, tag):
    	#if tag == 'table':
    	#	self.state = 2

        if tag == 'tr':
            #print(self.row)

            if self.rows == 1:
            	self.header.append(self.row) # list
                #self.header.append(tuple(self.row)) # tuple
            else:
                self.data.append(self.row) # list
                #myPerformance = TradencyPerformance(self.header, self.row)
                #self.data.append(myPerformance) # list
                #self.data.append(tuple(self.row)) # tuple

    	#if tag == 'td':
    	#	print("yo")

    def handle_data(self, data):
        if self.rows == 1: # head
            self.row.append(data)
        else: # head
            if self.cols in {3,5,6,8,9,10,11,13,15,16,17}: # real
                self.row.append(float(data))
            elif self.cols in {4,7}: # integer
                self.row.append(int(data))
            elif self.cols in {12}: # date
                #self.row.append(data)
                self.row.append(datetime.strptime(data, '%m/%d/%Y').date())
                #self.row.append(date.today())
            elif self.cols in {14}: # heure
                #self.row.append(timedelta(hours=130, minutes=6, seconds=43.371))
                data = data.split(':')
                data = timedelta(hours=int(data[0]), minutes=int(data[1]), seconds=float(data[2]))
                self.row.append(data)

            else:
                self.row.append(data) # string

    def get_data(self):
        return self.data

    def get_header(self):
        return self.header[0]

    def print_data(self):
        print("rows = ", self.rows)
        print("cols = ", self.cols)
        print("cels = ", self.cels)
        print("state = ", self.state)
        print("row = ", self.row)
        print("data = ", self.data)

datasource = open('TradencyPerformance.html')
myparser = TradencyPerformanceParser(datasource)

#myparser.print_data()
header = myparser.get_header()
data = myparser.get_data()


#print(header)

# convert list of list to list of objects
# and add specials indicators
dataO = []
t = date.today()
for row in data:
    myPerformance = TradencyPerformance(header, row)
	
    myPerformance.__dict__['Espérance'] = (myPerformance.__dict__['% gain']/100)*myPerformance.__dict__['GMT (pips)'] + (1-myPerformance.__dict__['% gain']/100)*myPerformance.__dict__['PMT (pips)']
    TradeDepuis = t - myPerformance.__dict__['Date']
    myPerformance.__dict__['TradeDepuis'] = t - myPerformance.__dict__['Date'] 
    myPerformance.__dict__['NbTradesParJour'] = float(myPerformance.__dict__['NumTrades'])/(TradeDepuis.days)
	
    dataO.append(myPerformance)


#['Stratégie', 'Symbole', 'T-Score', 'NumTrades', 'Max DD', 'Pips', 'Positions Max', '% gain', 'TAR', 'Profit', 'Facteur de Profit', 'Date', 'GMT (pips)', 'Temps de Trade Moyen', 'PMT (pips)', 'TPM (pips)', 'PMT (pips)']

criterium = 'Espérance' #'T-Score'
descending = True
nw_data=sorted(dataO, key=lambda dataO: dataO.__dict__[criterium], reverse=not descending)
#nw_data=sorted(dataO, key=lambda dataO: dataO.__dict__['Espérance'], reverse=False)
#nw_data=sorted(dataO, key=lambda dataO: dataO.__dict__['Pips'], reverse=False)
for row in nw_data:
    if row.__dict__['TradeDepuis']>timedelta(30) and row.__dict__['NumTrades']>30:
        print("=== {0}\t\t{1}\t{2}={3} ===".format(row.__dict__['Stratégie'], row.__dict__['Symbole'], criterium, row.__dict__[criterium]))
        #print(row)
        row.display()
        print('')

