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
Nbsize=2 # nb de tranches dans une image
for i in range(0, Nb):
	outfile_region="temp_%.4d.gif" % i
	if i<=Nb-Nbsize:
		i1=i
		i2=i+Nbsize-1
		print "%s : %d-%d" % (outfile_region, i1, i2)
		box = (i1*W/Nb, 0, (i2+1)*W/Nb, H)
		region=im.crop(box)
		region.save(outfile_region, "GIF")
	else:
		i1=i
		i2=Nb-1
		i3=0
		i4=i-Nb+Nbsize-1
		print "%s : %d-%d ; %d-%d" % (outfile_region, i1, i2, i3, i4)
		box = (0, 0, W, H)
		part1 = im.crop((i1*W/Nb, 0, W, H))
		part2 = im.crop((0, 0, (i4+1)*W/Nb, H))
		#region=im.crop((0,0,W/Nb*Nbsize,H))
		#region.paste(part1, (0, 0, W/100, H))
    	#region.paste(part2, (xsize-delta, 0, xsize, ysize))
		#region.save(outfile_region, "GIF")
