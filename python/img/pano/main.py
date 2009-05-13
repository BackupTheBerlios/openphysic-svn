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

newW=W/2 # largeur image finale


def img(image, i, Nb):
	# i = 0..Nb-1
	box = (0, 0, newW, H)
	return im.crop(box)

	
Nb=20
for i in range(0, Nb):
	region=img(im,i,Nb)
	outfile_region="logo_%d.gif"%i
	region.save(outfile_region, "GIF")


#def roll(image, delta):
#    "Roll an image sideways"

#    xsize, ysize = image.size

#    delta = delta % xsize
#    if delta == 0: return image

#    part1 = image.crop((0, 0, delta, ysize))
#    part2 = image.crop((delta, 0, xsize, ysize))
#    image.paste(part2, (0, 0, xsize-delta, ysize))
#    image.paste(part1, (xsize-delta, 0, xsize, ysize))

#    return image

#region=roll(im,10)
#region.save(outfile, "GIF")