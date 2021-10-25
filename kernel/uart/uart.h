#ifndef UART_H
#define UART_H

#define UART 0x10000000 /* UART base address */ 
#define UART_THR (unsigned char*)(UART+0x00) /* Transmitter Holding Register */
#define UART_LSR (unsigned char*)(UART+0x05) /* Line Status Register */
#define UART_LSR_EMPTY_MASK 0x40

int putc(char ch);
void puts(char *s);

#endif
