#!/usr/bin/env/python
# -*- coding: utf8 -*-

class Writer:
	bytesperline = 4

	i = 0
	sp = 1
	
	def __init__(self, fd, params):
		self.fd = fd
		self.params = params


	
	def header(self):
		self.fd.write("""# HEADER of %(output)s #
""" % self.params)

	def append(self, d):
		self.fd.write("0x%02X" % d)

		self.space_data()

	def footer(self):
		self.fd.write("""# FOOTER of %(output)s #
""" % self.params)



	def __del__(self):
		self.fd.close()



	def space_data(self, space="\t"):
		if self.sp == self.bytesperline:
			self.fd.write("\n")
			self.sp = 0
		else:
			self.fd.write(space)
		self.sp = self.sp + 1
		
		
#"\tretlw\t0x%02X\n" % byte # ASM TAB MICROCHIP PIC
#"	DA	0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00" # ASM DATA MICROCHIP PIC
#"	.db	0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00" # ASM DATA ATMEL
#"fcb$00 , $00 , $00 , $00 , $00 , $00 , $00 , $00" # ASM DATA ATMEL
#Pix(0,0) = &H2A& : Pix(0,1) = &H20& : Pix(0,2) = &H00& : Pix(0,3) = &H00& # VB
