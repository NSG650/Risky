#include "uart/uart.h"

int kmain(void) { 
	puts("Hello RISC-V World!\r\n");
	for(;;)
		;
	return 0;
}
