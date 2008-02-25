#include "global.h"		// include our global settings

#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>

#include "uart.h"		// include uart function library
#include "rprintf.h"	// include printf function library
#include "a2d.h"		// include A/D converter function library
#include "timer.h"		// include timer function library (timing, PWM, etc)
#include "vt100.h"		// include VT100 terminal library

int uart_init(void)
{
	// initialize our libraries
	// initialize the UART (serial port)
	uartInit();
	// set the baud rate of the UART for our debug/reporting output
	uartSetBaudRate(9600);
	// set uartSendByte as the output for all rprintf statements
	rprintfInit(uartSendByte);
	// initialize the timer system
	timerInit();
	// initialize vt100 library
	vt100Init();
	vt100ClearScreen();
	// print a little intro message so we know things are working
	//rprintf("AVR - UART echo\r\n");
}

volatile int c;

inline void echo7(void) {
	// caractères sur 7 bits uniquement !
	c=-1;
	while(c==-1) {
		c=uartGetByte();
	}
	uartSendByte(c);
}

//inline void echo8(void) {

//}

int main(void)
{
	uart_init();

   while (1) {
	   //rprintf("Running\r\n");
	
      echo7();
   }
   return(0);
}








