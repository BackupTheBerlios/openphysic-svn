#!/usr/bin/env python3

#    Useful class test
#
#       But : ce fichier définit diverses fonctions pratiques
#
#    Copyright (C) 2011  "Sébastien CELLES" <s.celles@gmail.com>
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>

from UsefulClass import *

bounds = [1, 2, 3, 4]
vals = [0.5, 1.4, 1.5, 2.1, 2.3, 2.5, 3.1, 3.1, 4.1]
nb = inbound(bounds, vals, True, True)
print(vals)
print(bounds)
print(nb)