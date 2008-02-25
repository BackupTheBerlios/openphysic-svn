#include "global.h"		// include our global settings

#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>

#include "uart.h"		// include uart function library
#include "rprintf.h"	// include printf function library
#include "a2d.h"		// include A/D converter function library
#include "timer.h"		// include timer function library (timing, PWM, etc)
#include "vt100.h"		// include VT100 terminal library

/*
Envoyer sur la liaison série des caractères
En réception on retrouve ces caractères
Remarque : pour les caractères ASCII codés sur 8 bits
il faut penser à modifier le terminal "Data bits=8"
 */

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

inline void echo(void) {
   while (1) {
		//rprintf("Running\r\n");

		c=-1;
		while(c==-1) {
			c=uartGetByte();
		}
		uartSendByte(c);
	}
}

inline void echoV2(void) {
   while (1) {
		char myReceivedByte;
		u08 res;
		res=FALSE;
		while(!res) {
 			res=uartReceiveByte( &myReceivedByte );
	 	}
 		uartSendByte(myReceivedByte);
 	}
}

/*
inline void echo_buff(void) {
   while (1) {
		uartFlushReceiveBuffer();
		cBuffer* buff;
		u08 res;
		res=TRUE;
		while(res) {
			buff=uartGetTxBuffer();
			res=uartReceiveBufferIsEmpty();
		}
		uartAddToTxBuffer(u08 data);
		uartSendTxBuffer();
	}
}
*/

int main(void)
{
	uart_init();

	echo();
	//echoV2();
	//echo_buff();

   return(0);
}











