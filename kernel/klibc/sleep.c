#include "sleep.h"

void sleep(volatile int count) {
    count *= 50000;
	while (count--);
}

