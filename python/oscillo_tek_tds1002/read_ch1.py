#!/usr/bin/env python

import numpy
import pylab
from visa import *
hw = instrument("COM1")

# Clear status
hw.write("*CLS")

# Identification
hw.write("*IDN?") # no \n
print hw.read()

# Short ident
#hw.write("ID?")
#print hw.read()

# Acquire Mode
hw.write("ACQuire:MODe AVErage")
#print hw.read()

#hw.write("ACQuire:MODe?")         
#print hw.read()

#
#hw.write("ACQuire:STATE STOP")

#hw.write("ACQuire:STATE RUN")
#hw.write("AUTOSet EXECute")

#hw.write("acquire:stopafter sequence")
#hw.write("acquire:state on")
#hw.write("*opc?")

hw.write("CH1:SCA?")
scale[1] = hw.read()
print scale[1]

#hw.write("data:encdg ascii")
#hw.write("curve?")

#raw_data = ''

#tmp_data = hw.read()
#raw_data = raw_data + tmp_data

# Close hardware
#hw.close()
