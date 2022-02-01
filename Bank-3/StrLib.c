#include "StrLib.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void _strReverse2(char* str, int length);
void _strReverse(char* str, const int length);
void _swap(char* c1, char* c2);
void _strToUpper(char* str);
void _strToLower(char* str);
int _strWordCount(char* str);
void _strReplace(char* str, FPredicate predicate, char newChar);
int _strCount(char* str, FPredicate predicate, int* first, int* last);
char* _strRead(FILE* in, int length);

bool strReverse2(char* str, int length)
{
    if (!str || length <= 0)
    {
        return false;
    }

    _strReverse2(str, length);
    return true;
}

void _strReverse2(char* str, int length)
{
    _swap(str, &str[length - 1]);
    if (length <= 2)
    {
        return;
    }

    _strReverse(str + 1, length - 2);
}

bool strReverse(char* str, const int length)
{
    if (!str)
    {
        return false;
    }

    _strReverse(str, length);
    return true;
}

void _strReverse(char* str, const int length)
{
    const int lim = length >> 1;
    for (int i = 0; i < lim; i++)
    {
        _swap(&str[i], &str[length - i - 1]);
    }
}

void _swap(char* c1, char* c2)
{
    char h = *c1;
    *c1 = *c2;
    *c2 = h;
}

bool strToUpper(char* str)
{
    if (!str)
    {
        return false;
    }

    _strToUpper(str);
    return true;
}

void _strToUpper(char* str)
{
    for (; *str; str++)
    {
        if (*str >= 'a' && *str <= 'z')
        {
            *str += 'A' - 'a';
        }
    }
}

bool strToLower(char* str)
{
    if (!str)
    {
        return false;
    }

    _strToLower(str);
    return true;
}

void _strToLower(char* str)
{
    for (; *str; str++)
    {
        if (*str >= 'A' && *str <= 'Z')
        {
            *str += 'a' - 'A';
        }
    }
}

int strWordCount(char* str)
{
    if (!str)
    {
        return -1;
    }

    return _strWordCount(str);
}

int _strWordCount(char* str)
{
    int count = 0;
    for (int pos = 0, step; str[pos]; pos += step)
    {
        count += sscanf(&str[pos], " %*s%n", &step) >= 0;
    }
    return count;
}

bool strReplace(char* str, FPredicate predicate, char newChar)
{
    if (!str)
    {
        return false;
    }

    _strReplace(str, predicate, newChar);
    return true;
}

void _strReplace(char* str, FPredicate predicate, char newChar)
{
    for (; *str; str++)
    {
        if (predicate(*str))
        {
            *str = newChar;
        }
    }
}

int strCount(char* str, FPredicate predicate, int* first, int* last)
{
    if (!str)
    {
        return -1;
    }

    int i = 0;
    if (!first)
    {
        first = &i;
    }
    if (!last)
    {
        last = &i;
    }

    return _strCount(str, predicate, first, last);
}

int _strCount(char* str, FPredicate predicate, int* first, int* last)
{
    *first = -1;
    *last = -1;

    int count = 0;
    for (int i = 0; str[i]; i++)
    {
        if (predicate(str[i]))
        {
            count++;
            *last = i;
            if (*first < 0)
            {
                *first = i;
            }
        }
    }

    return count;
}

char* strRead(FILE* in, int length)
{
    if (!in || length <= 0)
    {
        return NULL;
    }

    return _strRead(in, length);
}

char* _strRead(FILE* in, int length)
{
    char* str = malloc((length + 1) * sizeof(char));
    if (!str)
    {
        return NULL;
    }

    if (!fgets(str, length + 1, in))
    {
        free(str);
        return NULL;
    }

    return str;
}
