#!/usr/bin/env python
# -*- coding: utf8 -*-

"""
    Tri des comptes PAMM Alpari

       But : ce script permet de trier
       les comptes PAMM Alpari

    Copyright (C) 2011  "Sébastien CELLES" <sebastien.celles@univ-poitiers.fr>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>
"""

import csv

# Lecture des entêtes de colonnes
fileHead = open('head.txt', 'r')
strHead = fileHead.read()
fileHead.close()
lstHead = strHead.split("\n")

print(lstHead)

