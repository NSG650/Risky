#include "string.h"

static char *stpcpy(char *restrict d, const char *restrict s) {
	for (; (*d = *s); s++, d++)
		;

	return d;
}


char *strcpy(char *restrict dest, const char *restrict src) {
	stpcpy(dest, src);
	return dest;
}

char *strncpy(char *dest, const char *src, unsigned long long n) {
	char *ptr = dest;

	while (*src != '\0' && n--) {
		*ptr++ = *src++;
	}

	*ptr = '\0';
	return dest;
}

int strcmp(const char s1[], const char s2[]) {
	int i;

	for (i = 0; s1[i] == s2[i]; i++) {
		if (s1[i] == '\0')
			return 0;
	}

	return s1[i] - s2[i];
}

int strncmp(const char *s1, const char *s2, unsigned long long n) {
	unsigned long long count = 0;
	while (count < n) {
		if (s1[count] == s2[count]) {
			if (s1[count] == '\0') {
				// Found null termination
				return 0;
			} else {
				count++;
			}
		} else
			return s1[count] - s2[count];
	}

	return 0;
}

unsigned long long strlen(const char *s) {
	unsigned long long i = 0;

	while (s[i] != '\0') {
		++i;
	}

	return i;
}
char *strchr(const char *s, int c) {
	char *r = strchrnul(s, c);
	return *(unsigned char *)r == (unsigned char)c ? r : 0;
}

char *strchrnul(const char *s, int c) {
	c = (unsigned char)c;
	if (!c) {
		return (char *)s + strlen(s);
	}

	for (; *s && *(unsigned char *)s != c; s++)
		;
	return (char *)s;
}