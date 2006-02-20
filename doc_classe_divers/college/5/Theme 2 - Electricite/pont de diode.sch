*version 9.1 640040659
u 166
D? 9
R? 3
V? 3
@libraries
@analysis
@targets
@attributes
@translators
a 0 u 13 0 0 0 hln 100 PCBOARDS=PCB
a 0 u 13 0 0 0 hln 100 PSPICE=PSPICE
a 0 u 13 0 0 0 hln 100 XILINX=XILINX
@setup
unconnectedPins 0
connectViaLabel 0
connectViaLocalLabels 0
NoStim4ExtIFPortsWarnings 1
AutoGenStim4ExtIFPorts 1
@index
pageloc 1 0 2251 
@status
c 103:00:12:17:04:04;1042387444
*page 1 0 256 160 ma
@ports
@parts
part 5 D 300 200 v
a 0 sp 11 0 15 25 hln 100 PART=D
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=D4
a 0 ap 9 0 15 0 hln 100 REFDES=D4
part 2 D 300 130 v
a 0 sp 11 0 15 25 hln 100 PART=D
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=D1
a 0 ap 9 0 15 0 hln 100 REFDES=D1
part 3 D 420 130 v
a 0 sp 11 0 15 25 hln 100 PART=D
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=D2
a 0 ap 9 0 15 0 hln 100 REFDES=D2
part 4 D 420 200 v
a 0 sp 11 0 15 25 hln 100 PART=D
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=D3
a 0 ap 9 0 15 0 hln 100 REFDES=D3
part 120 D 360 150 d
a 0 x 0:13 0 0 0 hln 100 PKGREF=D5
a 0 xp 9 0 15 0 hln 100 REFDES=D5
a 0 sp 11 0 15 25 hln 100 PART=D
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=
part 119 R 360 150 v
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 15 25 hln 100 VALUE=
a 0 x 0 0 0 10 hlb 100 PART=
a 0 x 0:13 0 0 0 hln 100 PKGREF=
a 0 xp 9 0 15 0 hln 100 REFDES=
part 133 VDC 340 240 v
a 0 x 0:13 0 0 0 hln 100 PKGREF=
a 1 xp 9 0 24 7 hcn 100 REFDES=
a 0 s 0 0 22 37 hln 100 PART=VDC
a 1 u 13 0 -11 18 hcn 100 DC=
@conn
w 27
s 360 210 360 180 130
s 360 210 300 210 132
s 420 210 360 210 7
s 420 210 420 200 22
s 300 210 300 200 28
w 79
s 360 110 360 90 121
s 360 90 420 90 123
s 300 90 300 100 18
s 300 90 360 90 16
s 420 90 420 100 19
w 159
s 380 240 460 240 158
s 460 240 460 150 160
s 420 130 420 150 142
s 420 150 420 170 164
s 460 150 420 150 162
w 154
s 340 240 260 240 153
s 300 170 300 150 87
s 300 150 300 130 152
s 260 150 300 150 157
s 260 240 260 150 155
@junction
j 360 150
+ p 120 1
+ p 119 1
j 360 180
+ p 120 2
+ w 27
j 360 210
+ w 27
+ w 27
j 300 200
+ p 5 1
+ w 27
j 360 110
+ p 119 2
+ w 79
j 300 100
+ p 2 2
+ w 79
j 360 90
+ w 79
+ w 79
j 420 100
+ p 3 2
+ w 79
j 420 200
+ p 4 1
+ w 27
j 380 240
+ p 133 -
+ w 159
j 340 240
+ p 133 +
+ w 154
j 420 130
+ p 3 1
+ w 159
j 420 170
+ p 4 2
+ w 159
j 420 150
+ w 159
+ w 159
j 300 170
+ p 5 2
+ w 154
j 300 130
+ p 2 1
+ w 154
j 300 150
+ w 154
+ w 154
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A4
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
