#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>

char *
mystrcpy(char *dest, const char *src);

char *
mystrcat(char *s1, const char *s2);

char *
mystrstr(const char *s1, const char *s2);

char *
mystrchr(const char *s1, const int c);

int
mystrcmp(const char *s1, const char *s2);

void *
mymemcpy(void *dest, const void *src, int n);

void *
mymemmove(void *dest, const void *src, int len);