#!/usr/bin/env python
# -*- coding: utf8 -*-

# =====================================================================
# = convert a picture to data for T6963 or KS0108B graphic controller =
# =====================================================================
# = Sebastien Celles                                                  =
# = 2010/04/16                                                        =
# =====================================================================
# = using Python Imaging Library (PIL)                                =
# =  http://www.pythonware.com/products/pil/                          =
# =  http://www.pythonware.com/library/pil/handbook/index.htm         =
# =====================================================================

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

import Image
import sys
from datetime import datetime

from gcontroller import GController

from writer import Writer
from writer_c import Writer_C
from writer_asm import Writer_ASM

def usage():
	print("""Usage: python glcd.py""")

def main():
	#input = 'glcd.bmp'
	input = 'samples/glcd_bw_240_128_hz2_8bits.bmp' # T6963   test case (1 to 8 pixels hz   ON - 0x01 0x03 0x07 0x0F 0x1F 0x3F 0x7F 0xFF)
	#input = 'samples/glcd_bw_240_128_vt_8bits.bmp' # KS0108B test case (1 to 8 pixels vert ON - 0x01 0x03 0x07 0x0F 0x1F 0x3F 0x7F 0xFF)
	output = 'glcd.c'
	#language = 'C_AVR' # language C_AVR C_PIC...
	pixelsperbyte = 8 # 8 or 6
	gcontroller = "T6963" # graphic controller T6963, KS0108B
	#gcontroller = "KS0108B" # graphic controller T6963, KS0108B
	
	gc = GController("T6963")
	gc.display()

	bytesperline = 4 # nb of bytes per lines of code
	var = "data" # variable's name of data

	im = Image.open(input)

	#im.show()
	data = list(im.getdata())
	#print data
	#print im.getpixel((239,127)) 

	w = im.size[0] # get image width
	h = im.size[1] # get image height
	px_nb = w * h # len(data)

	print """Input:
	Filename: %s
	Format: %s
	Size: %s
	Mode: %s
Output:
	Filename: %s""" %  (input, im.format, im.size, im.mode, output)
	
	#i=0
	#for d in data:
	#  i=i+1
	  #mean = (d[0]+d[1]+d[2])/3.0 # si RGB
	#  mean = d # 
	#  print "%i : %s : %i" % (i, d, mean)
  
	  #if mean == 0:
	  #	pass
	    #print "%i : %s : false" % (i, d)
	  #else:
	  #  print "%i : %s : true" % (i, d)

	#f = sys.stdout
	f = open(output, 'w')
	
	writer_params = {
		'output': output,
		'input': input,
		'format': im.format,
		'size': im.size,
		'mode': im.mode,
		'now': datetime.now(),
		'gcontroller': gcontroller,
		'data': "data",
		'bytespersline': 4,
		'dsize': px_nb/pixelsperbyte, 
	}

	#my_writer = Writer(f, writer_params)
	my_writer = Writer_C(f, writer_params)
	#my_writer = Writer_ASM(f, writer_params)


	my_writer.header()

	if gcontroller == "T6963":
		msb_first = True
		for i in range(0, px_nb/pixelsperbyte):
			byte = 0
			for bit in range(0, pixelsperbyte):
				offset = i*pixelsperbyte
				if msb_first:
					px = offset + pixelsperbyte - 1 - bit
				else:
					px = offset + bit
				byte = byte + data[px]*2**bit #T6963
			my_writer.append(byte)

	elif gcontroller == "KS0108B":
		msb_first = False
		for i in range(0, h/pixelsperbyte):
			for j in range(0, w):
				pixel = (j, i*pixelsperbyte) # x, y
				byte = 0
				for bit in range(0, pixelsperbyte):
					if msb_first:
						byte = byte + im.getpixel((pixel[0], pixel[1]+pixelsperbyte - 1 - bit))*2**bit
					else:
						byte = byte + im.getpixel((pixel[0], pixel[1]+bit))*2**bit
				my_writer.append(byte)

	else:
		msg = 'Unsupported graphic controller'
		print msg
		usage()
		exit
		#raise Exception, msg
		

	# End Of File
	
	my_writer.footer()
	
	my_writer.__del__()


if __name__ == "__main__":
    main()
