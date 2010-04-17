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

from writer import Writer

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

	bytesperline = 4 # nb of bytes per lines of code
	var = "data" # variable's name of data

	im = Image.open(input)
	print("Input:", input, im.format, im.size, im.mode)
	print("Output:", output)

	#im.show()
	data = list(im.getdata())
	#print data
	#print im.getpixel((239,127)) 

	w = im.size[0] # get image width
	h = im.size[1] # get image height
	px_nb = w * h # len(data)
	
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

	f = open(output, 'w')

	#my_writer = Writer(output)
	my_writer = Writer(sys.stdout)
	
	wdata = []

	# Header

	head_params = {
		'output': output,
		'input': input,
		'format': im.format,
		'size': im.size,
		'mode': im.mode,
		'now': datetime.now(),
		'gcontroller': gcontroller,
	}
	
	head_c = """/*********************************************************
 * Graphic controller: %(gcontroller)s
 * Filename: %(output)s
 * Generated by Python script glcd.py
 *  using Python Imaging Library (PIL)
 *   http://www.pythonware.com/products/pil/
 *  %(now)s
 * Input picture: %(input)s
 * Image Format: %(format)s
 * Image Size: %(size)s
 * Image Mode: %(mode)s
 *********************************************************/
""" % head_params

	head_asm = """\t; \t\tGraphic controller: %(gcontroller)s
\t; \t\tFilename: %(output)s
\t; \t\tGenerated by Python script glcd.py
\t; \t\t using Python Imaging Library (PIL)
\t; \t\t  http://www.pythonware.com/products/pil/
\t; \t\t %(now)s
\t; \t\tInput picture: %(input)s
\t; \t\tImage Format: %(format)s
\t; \t\tImage Size: %(size)s
\t; \t\tImage Mode: %(mode)s
""" % head_params

	my_writer.header()

	# Datastring

	datastring = """#include <stdint.h>

#define N_%(data)s %(size)s
uint8_t %(data)s[N_%(data)s];

void init_%(data)s(void){
""" % {'data': var, 'size': px_nb/pixelsperbyte}

	#datastring = datastring + "int %s[4000];" % var + "\n\n"

	#datastring = datastring + "void init_%s(void){" % var + "\n"

	sp = 1
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
			wdata.append(byte)
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
				wdata.append(byte)
				my_writer.append(byte)

	else:
		msg = 'Unsupported graphic controller'
		print(msg)
		usage()
		exit
		#raise Exception, msg
		
	for byte in range(0, len(wdata)):
		datastring = datastring + "\t%s[%i] = 0x%02X;" % (var, byte, wdata[byte]) # C
		if sp == bytesperline:
			datastring = datastring + "\n"
			sp = 0
		else:
			datastring = datastring + " "
		sp = sp + 1		
			#datastring = datastring + "\tretlw\t0x%02X\n" % byte # ASM TAB MICROCHIP PIC
			#"	DA	0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00" # ASM DATA MICROCHIP PIC
			#"	.db	0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00" # ASM DATA ATMEL
			#"fcb$00 , $00 , $00 , $00 , $00 , $00 , $00 , $00" # ASM DATA ATMEL
			#Pix(0,0) = &H2A& : Pix(0,1) = &H20& : Pix(0,2) = &H00& : Pix(0,3) = &H00& # VB

	datastring = datastring + "}\n"

	# End Of File
	
	my_writer.footer()

	eof_c = "/*********************************************************/"+"\n"
	eof_asm = "\t; \t\tEOF"

	# Write ASM
	#f.write(head_asm)
	#f.write("\n")
	#f.write(datastring)
	#f.write("\n")
	#f.write(eof_asm)

	# Write C
	f.write(head_c)
	f.write("\n")
	f.write(datastring)
	f.write("\n")
	f.write(eof_c)

	f.close()
	
	my_writer.__del__()


if __name__ == "__main__":
    main()
