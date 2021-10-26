#include "mem.h"

void *memcpy(void *dest, const void *src, unsigned long long nbytes) {
	unsigned char *q = (unsigned char *)dest;
	unsigned char *p = (unsigned char *)src;
	unsigned char *end = p + nbytes;

	while (p != end) {
		*q++ = *p++;
	}

	return dest;
}


int memcmp(const void *s1, const void *s2, unsigned long long n) {
	unsigned char *byte1 = (unsigned char *)s1;
	unsigned char *byte2 = (unsigned char *)s2;
	while ((*byte1 == *byte2) && (n > 0)) {
		++byte1;
		++byte2;
		--n;
	}

	if (n == 0) {
		return 0;
	}
	return *byte1 - *byte2;
}

void *memset(void *dest, unsigned char val, unsigned long long len) {
	unsigned char *temp = (unsigned char *)dest;
	for (; len != 0; len--)
		*temp++ = val;
	return dest;
}

