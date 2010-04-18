#!/usr/bin/env/python
# -*- coding: utf8 -*-

class ColorEnum:
	MONOCHROME = 0	#Monochrome bitmap (1bpp)
	GRAY4BPP = 1	#16 gray levels bitmap (4bpp)
	COLOR8BPP = 2	#255 colors (8 bpp)
	COLOR12BPP = 3	#4096 colors (12bpp)
	COLOR16BPP = 4	#65535 colors (16bpp)

class PagingEnum:
	L2R = 0	#Table horizontal from left to right
	R2L = 1	#Table horizontal from right to left
	U2D = 2	#Table vertical downwards
	D2U = 3	#Table vertical upwards

class OriginEnum:
	TL = 0	#Origin at Top Left
	BL = 1	#Origin at Bottom Left

class GController:
	#name = ""
	
	size = (240, 128) # (w, h)

	color = ColorEnum.MONOCHROME
	
	paging = PagingEnum.L2R
	
	origin = OriginEnum.TL
		
	msb_first = True # Most Signifiant Bit first

	#backcolor = 0
	#forecolor = 0

	def __init__(self, name="noname"):
		self.name = name
		
		if self.name == "T6963":
			"""
			240x128
			Monochrome bitmap (1bpp)
			Table horizontal from left to right
			Origin at Top Left
			MSB First
			"""
			size = (240, 128)
			color = ColorEnum.MONOCHROME
			paging = PagingEnum.L2R
			origin = OriginEnum.TL
			msb_first = True
			
			
		elif self.name == "KS0108B":
			"""
			240x128
			Monochrome bitmap (1bpp)
			Table vertical downwards
			Origin at Top Left
			MSB Last
			"""
			size = (240, 128)
			color = ColorEnum.MONOCHROME
			paging = PagingEnum.U2D
			origin = OriginEnum.TL
			msb_first = False
			
		else:
			print "Unknow Graphic controller"
			
	def display(self):
		print """Graphic Controller:
	Name: %(name)s
	Size: %(size)s
	Color: %(color)s
	Paging: %(paging)s
	Origin: %(origin)s
	MSB First: %(msb)s
""" % {
	'name': self.name,
	'size': self.size,
	'color': self.color,
	'paging': self.paging,
	'origin': self.origin,
	'msb': self.msb_first,
	}

