#!/usr/bin/env python
import os, sys
import Image

im = Image.open("logo.gif")
#outfile="logo2.gif"

W, H = im.size
#W=im.size[0] # width
#H=im.size[1] # height

print im.format, W, H, im.mode
#im.show()

	
Nb=10 # nb total de tranches
Nbsize=2 # nb de tranches dans une image
for i in range(0, Nb):
	outfile_region="temp_%.4d.gif" % i
	if i<=Nb-Nbsize:
		print "%d-%d" % (i, i+Nbsize-1)
		box = (i*W/Nb, 0, (i+Nbsize-1)*W/Nb, H)
		region=im.crop(box)
		region.save(outfile_region, "GIF")
	else:
		print "%d-%d ; %d-%d" % (i, Nb-1, 0, i-Nb+Nbsize-1)