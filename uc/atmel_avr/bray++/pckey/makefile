# AVRGCC Test by Bray++

include $(AVR)/include/make1

########### change this lines according to your project ##################

#put the name of the target mcu here (-2313, -8515, -8535, -mega103, -mega106)
        MCU     = -8515

#put the name of the target file here (without extension)
        TRG     = test

#put your C sourcefiles here
        SRC     = lcd.c pckb.c $(TRG).c

#put additional assembler source file here
        ASRC    =

#needed libraries and object files to link
        LIB     =

#needed includes to compile
        INC	=

#compiler flags
        CPFLAGS = -O2

#assembler flags
	ASFLAGS = -L

#linker flags
        LDFLAGS = -v -l$(TRG).lnk

########### you should not need to change the following line #############
include $(AVR)/include/make2

###### dependecies, add any dependencies you need here ###################
$(TRG).o : $(TRG).c lcd.h pckb.h
lcd.o : lcd.c lcd.h
pckb.o : pckb.c pckb.h
