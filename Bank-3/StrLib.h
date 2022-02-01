#ifndef STRLIB_H_INCLUDED
#define STRLIB_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>

typedef bool (*FPredicate)(char c);

char* strRead(FILE* in, int length);

int strCount(char* str, FPredicate predicate, int* first, int* last);

bool strReplace(char* str, FPredicate predicate, char newChar);

int strWordCount(char* str);

bool strToLower(char* str);

bool strToUpper(char* str);

bool strReverse(char* str, const int length);

bool strReverse2(char* str, int length);

#endif // STRLIB_H_INCLUDED
