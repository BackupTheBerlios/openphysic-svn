#! /usr/bin/env python
# -*- coding: Latin-1 -*-

def convMajMin(ch):
    "�change les majuscules et les minuscules dans la cha�ne ch"
    nouvC = ""                   # cha�ne � construire
    for car in ch:
        code = ord(car)
        if car >= "A" and car <= "Z":
            code = code + 32
        elif car >= "a" and car <= "z":
            code = code - 32
        nouvC = nouvC + chr(code)
    return nouvC

# Test :
if __name__ == '__main__':
    print convMajMin("Ferdinand-Charles de CAMARET")
