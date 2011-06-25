#!/usr/bin/env python
# -*- coding: utf8 -*-

#    Sharpe ratio & Sortino ratio
#
#       But : ce fichier teste les fonctions ratio de Sharpe et ratio de Sortino
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

from sharpe import *

val = [1, 2, 3, -1, -2]

print(val)

sh_r = sharpe_ratio()

so_r = sortino_ratio()
