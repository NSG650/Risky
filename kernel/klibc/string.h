#ifndef STRING_H
#define STRING_H

char *strcpy(char *restrict d, const char *restrict s);
char *strncpy(char *restrict d, const char *restrict s, unsigned long long n);
int strcmp(const char *l, const char *r);
int strncmp(const char *_l, const char *_r, unsigned long long n);
unsigned long long strlen(const char *s);
char *strchr(const char *s, int c);
char *strchrnul(const char *s, int c);

#endif