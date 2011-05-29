#!/usr/bin/env python3

#    Useful class
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

def inbound(bounds, vals):
    nb = [0 for i in range(0,len(bounds))]
    for i in range(0, len(bounds)-1):
        print("[{0};{1}]".format(bounds[i],bounds[i+1]))
    return nb

bounds = [1,2,3]
print(bounds)
vals = [1.4,1.5,2.1,2.3,2.5]
print(vals)
nb = inbound(bounds, vals)
print(nb)