#!/usr/bin/env python

print "Dec \t Hex \t Bin"
for i in range(0, 2**8):
  iDec = "%03i" % i
  iHex = "0x%X" % i
  iBin = "0000 0000" 
  print "%s \t %s \t %s" % (iDec, iHex, iBin)
