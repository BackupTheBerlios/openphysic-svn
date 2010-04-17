#!/usr/bin/env/python
# -*- coding: utf8 -*-

class Writer:
	#wdata = []
	
	def __init__(self, fd):
		self.fd = fd
	
	def header(self):
		print >>self.fd, "# HEADER #"

	def append(self, d):
		#self.wdata.append(d)
		print >>self.fd, "0x%02X" % d

	def footer(self):
		print >>self.fd, "# FOOTER #"

	def __del__(self):
		self.fd.close()