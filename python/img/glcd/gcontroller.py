#!/usr/bin/env/python
# -*- coding: utf8 -*-

class ColorEnum:
	MONOCHROME = 0	# Monochrome bitmap (1bpp)
	GRAY4BPP = 1	# 16 gray levels bitmap (4bpp)
	COLOR8BPP = 2	# 255 colors (8 bpp)
	COLOR12BPP = 3	# 4096 colors (12bpp)
	COLOR16BPP = 4	# 65535 colors (16bpp)

class Color:

	def __init__(self, color=ColorEnum.MONOCHROME):
		self.color = color
	
	def __str__(self):
		if self.color == ColorEnum.MONOCHROME:
			return "Monochrome bitmap (1bpp)"
		elif self.color == ColorEnum.GRAY4BPP:
			return "16 gray levels bitmap (4bpp)"
		elif self.color == ColorEnum.COLOR8BPP:
			return "255 colors (8 bpp)"
		elif self.color == ColorEnum.COLOR12BPP:
			return "4096 colors (12bpp)"
		elif self.color == ColorEnum.COLOR16BPP:
			return "65535 colors (16bpp)"
		else:
			return "Undefined color"
			

class PagingEnum:
	L2R = 0	# Table horizontal from left to right
	R2L = 1	# Table horizontal from right to left
	U2D = 2	# Table vertical downwards
	D2U = 3	# Table vertical upwards

class Paging:
	paging = PagingEnum.L2R

	def __init__(self, paging=PagingEnum.L2R):
		self.paging = paging
	
	def __str__(self):
		if self.paging == PagingEnum.L2R:
			return "Table horizontal from left to right"
		elif self.paging == PagingEnum.R2L:
			return "Table horizontal from right to left"
		elif self.paging == PagingEnum.U2D:
			return "Table vertical downwards"
		elif self.paging == PagingEnum.D2U:
			return "Table vertical upwards"
		else:
			return "Undefined paging"
			
			
class OriginEnum:
	TL = 0	# Origin at Top Left
	BL = 1	# Origin at Bottom Left

class Origin:
	origin = OriginEnum.TL

	def __init__(self, origin=OriginEnum.TL):
		self.origin = origin
	
	def __str__(self):
		if self.origin == OriginEnum.TL:
			return "Origin at Top Left"
		elif self.origin == OriginEnum.BL:
			return "Origin at Bottom Left"
		else:
			return "Undefined origin"


class MSB:
	is_first = True # MSB First
	
	def __init__(self, pos='FIRST'):
		if pos=='FIRST':
			self.is_first = True
		elif pos=='LAST':
			self.is_first = False
		else:
			raise Exception, "Unknow MSB position"

	def __str__(self):
		if self.is_first:
			return "Most Signifiant Bit First"
		else:
			return "Most Signifiant Bit Last"


class GController:
	name = "noname"
	
	size = (240, 128) # (w, h)
	color = Color(ColorEnum.MONOCHROME)
	paging = Paging(PagingEnum.L2R)
	origin = Origin(OriginEnum.TL)
	msb = MSB('FIRST') # Most Signifiant Bit first
	
	pixelsperbyte = 8 # 8 or 6

	#backcolor = 0
	#forecolor = 0

	def __init__(self, name="noname"):
		self.name = name
		
		print name
		
		if self.name == "T6963":
			"""
			240x128
			Monochrome bitmap (1bpp)
			Table horizontal from left to right
			Origin at Top Left
			MSB First
			"""
			self.size = (240, 128)
			self.color = Color(ColorEnum.MONOCHROME)
			self.paging = Paging(PagingEnum.L2R)
			self.origin = Origin(OriginEnum.TL)
			self.msb = MSB('FIRST')
			self.pixelsperbyte = 8
			
			
		elif self.name == "KS0108B":
			"""
			240x128
			Monochrome bitmap (1bpp)
			Table vertical downwards
			Origin at Top Left
			MSB Last
			"""
			self.size = (240, 128)
			self.color = Color(ColorEnum.MONOCHROME)
			self.paging = Paging(PagingEnum.U2D)
			self.origin = Origin(OriginEnum.TL)
			self.msb = MSB('LAST')
			self.pixelsperbyte = 8
			
		else:
			print "Unknow Graphic controller"

	def __str__(self):
		return self.name
			
	def display(self):
		print """Graphic Controller:
	Name: %(name)s
	Size: %(size)s
	Color: %(color)s
	Paging: %(paging)s
	Origin: %(origin)s
	MSB: %(msb)s
	Pixels per byte: %(pixelsperbyte)s
""" % {
	'name': self.name,
	'size': self.size,
	'color': self.color,
	'paging': self.paging,
	'origin': self.origin,
	'msb': self.msb,
	'pixelsperbyte': self.pixelsperbyte
	}

