#!/usr/bin/env/python
# -*- coding: utf8 -*-

from writer import Writer

class Writer_C(Writer):
	
	def header(self):
		self.fd.write("""/*********************************************************
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
 
#include <stdint.h>

#define N_%(data)s %(dsize)s
uint8_t %(data)s[N_%(data)s];

void init_%(data)s(void) {

""" % self.params)

	def append(self, d):
		if self.sp==1:
			self.fd.write("\t")
		
		self.fd.write("data[%i] = 0x%02X;" % (self.i, d))
		
		self.i = self.i + 1
		
		self.space_data("   ")

	def footer(self):
		self.fd.write("""
}

/*********************************************************/
""" % self.params)