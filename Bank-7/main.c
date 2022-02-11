/*
 * Projekt: Bank-7
 * Autor:   Jakub Antonín Štigler
 * Datum:   2/11/2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

bool checkMultipleBraces(char* str, char* left, char* right);
bool checkBraces(char* str, char left, char right);
int until(char* str, char* set);
bool contains(char* str, char c);
int indexOf(char* str, char c);
void clearIn();

int main()
{
    printf("====<<CHAR SET>>====\n");
    printf("Enter a char set: ");
    char charSet[256];
    scanf("%255[^\n]", charSet);
    clearIn();
    printf("Enter a string: ");
    char str[1024];
    scanf("%1023[^\n]", str);
    clearIn();
    int index = until(str, charSet);
    if (index == 0)
    {
        printf("all characters in the string are from the set\n");
    }
    else
    {
        printf("index of first character not in the set: %d\n", index);
    }

    printf("=====<<BRACES>>=====\n");
    printf("Enter string to match square braces: ");
    scanf("%1023[^\n]", str);
    clearIn();
    printf(checkBraces(str, '[', ']') ? "braces match\n" : "braces don't match\n");

    printf("==<<MULTI BRACES>>==\n");
    printf("Enter string to match braces: ");
    scanf("%1023[^\n]", str);
    clearIn();
    printf(checkMultipleBraces(str, "([{<", ")]}>") ? "successful match\n" : "failed to match braces\n");

    return EXIT_SUCCESS;
}

bool checkMultipleBraces(char* str, char* left, char* right)
{
    TStack* s = stackCreate();
    if (!s)
    {
        return false;
    }

    for (; *str; str++)
    {
        int index;
        if (contains(left, *str))
        {
            if (!stackAdd(s, *str))
            {
                stackDelete(&s, NULL);
                return false;
            }
        }
        else if ((index = indexOf(right, *str)) != -1)
        {
            char p;
            if (!tryStackPop(s, &p) || index != indexOf(left, p))
            {
                stackDelete(&s, NULL);
                return false;
            }
        }
    }

    int c = 1;
    stackDelete(&s, &c);
    return c == 0;
}

bool checkBraces(char* str, char left, char right)
{
    int bc = 0;
    for (; *str && bc >= 0; str++)
    {
        bc += *str == left;
        bc -= *str == right;
    }
    return bc == 0;
}

int until(char* str, char* set)
{
    for (int i = 1; *str; i++, str++)
    {
        if (!contains(set, *str))
        {
            return i;
        }
    }
    return 0;
}

bool contains(char* str, char c)
{
    return indexOf(str, c) != -1;
}

int indexOf(char* str, char c)
{
    for (int i = 0; *str; str++, i++)
    {
        if (*str == c)
        {
            return i;
        }
    }
    return -1;
}

void clearIn()
{
    scanf("%*[^\n]");
    scanf("%*c");
}
