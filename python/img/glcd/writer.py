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