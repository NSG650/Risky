#include "uart/uart.h"
#include "scheduler/process.h"

unsigned char a_stack[1024];

void b(void) {
	uart_puts("b: b\r\n");
	for(;;)
		;
}

void a(void) {
	uart_puts("a: a\r\n");
	process_switch(1);
}

int kmain(void) {
	uart_puts("Hello World!\r\n");
	process_create("a", (reg_t)a);
	process_create("b", (reg_t)b);
	process_dump_ptable();
	process_switch(0);
	return 0;
}