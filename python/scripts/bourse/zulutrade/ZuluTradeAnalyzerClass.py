#!/usr/bin/env python
# -*- coding: utf8 -*-

#    ZuluTrade analyzer class
#
#       But : ce script permet d'analyser les performances de diverses stratégies utilisées
#       dans le système de trading automatique ZuluTrade http://www.zulutrade.com/
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


class ZuluTradeMyHistoryReader:
    def __init__(self, fh, types=[]):
    	pass
        #types = [str, str, float, int, float, float, int, float, float, float, float, self.strDate2date, float, self.strH2timedelta, float, float, float]
        #HTMLTableParser.__init__(self, fh, types)
        #self.feed(fh.read())


class Dict2Obj:
    def __init__(self, format, value):
        
        i = 0
        for key in format:
            self.__dict__[key] = value[i]
            i = i + 1
                
    def __repr__(self):
        return repr(self.__dict__)
        
    def display(self):
        for key in self.__dict__:
            print("\t{0} = {1}".format(key,self.__dict__[key]))


class ZuluTradeMyHistory(Dict2Obj):
    def __init__(self, format, value):
        Dict2Obj.__init__(self, format, value)

        # add specials indicators
        #self.__dict__['Durée Trade'] = self.__dict__['Fermer Heure'] - self.__dict__['Ouvrir Heure']

