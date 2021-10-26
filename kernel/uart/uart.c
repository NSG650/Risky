#include "uart.h"

int uart_putc(char ch) {
	while((*UART_LSR & UART_LSR_EMPTY_MASK) == 0);
	return *UART_THR = ch;
}

void uart_puts(char *s) {
	while(*s) uart_putc(*s++);
}
