#!/usr/bin/env python

# =====================================================================
# = convert a picture to data for T6963 or KS0108B graphic controller =
# =====================================================================
# = Sebastien Celles                                                  =
# = 2010/04/16                                                        =
# =====================================================================
# = using Python Imaging Library Handbook                             =
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
from datetime import datetime

input = 'glcd.bmp'
output = 'glcd.c'

im = Image.open(input)
print "Input:", input, im.format, im.size, im.mode
print "Output:", output

#im.show()

data = list(im.getdata())
print data

i=0
for d in data:
  i=i+1
  #mean = (d[0]+d[1]+d[2])/3.0 # si RGB
  mean = d # 
  print "%i : %s : %i" % (i, d, mean)
  
  #if mean == 0:
  #	pass
    #print "%i : %s : false" % (i, d)
  #else:
  #  print "%i : %s : true" % (i, d)

f = open(output, 'w')
head = """/*********************************************************
 *  Filename: %(output)s
 *  Generated by Python script glcd.py
 *   using Python Imaging Library (PIL)
 *   %(now)s
 *  Input picture: %(input)s
 *  Image Format: %(format)s
 *  Image Size: %(size)s
 *  Image Mode: %(mode)s
 *********************************************************/
""" % {'output': output,
	'input': input,
	'format': im.format,
	'size': im.size,
	'mode': im.mode,
	'now': datetime.now()
	}

datastring = "data = \"\";"

# ToDo !!!!

eof = "/*********************************************************/"+"\n"

f.write(head)
f.write("\n")
f.write(datastring+"\n")
f.write("\n")
f.write(eof)

f.close()
