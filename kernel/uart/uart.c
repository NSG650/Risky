#include "uart.h"

int putc(char ch) {
	while((*UART_LSR & UART_LSR_EMPTY_MASK) == 0);
	return *UART_THR = ch;
}

void puts(char *s) {
	while(*s) putc(*s++);
}
