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

	
Nb=20 # nb total de tranches
Nbsize=4 # nb de tranches dans une image
for i in range(0, Nb-Nbsize):
	print i,i+Nbsize
	box = (i*W/Nb, 0, (i+Nbsize)*W/Nb, H)
	#box = (i*W/Nb*Nbsize, 0, (i+1)*W/Nb*Nbsize, H)
	region=im.crop(box)
	outfile_region="logo_%.4d.gif"%i
	region.save(outfile_region, "GIF")