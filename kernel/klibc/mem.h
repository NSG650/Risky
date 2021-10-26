#ifndef MEM_H
#define MEM_H

void *memcpy(void *dest, const void *src, unsigned long long nbytes);
int memcmp(const void *s1, const void *s2, unsigned long long n);
void *memset(void *dest, unsigned char val, unsigned long long len);

#endif