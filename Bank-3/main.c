/*
 * Projekt: Bank-3;
 * Autor:   Jakub Antonín Štigler
 * Datum:   2/1/2022
 */

#include <stdio.h>
#include <stdlib.h>

#include "StrLib.h"

char findChar = 'x';

void clearIn();
bool isDigit(char c) { return c >= '0' && c <= '9'; }
bool isX(char c) { return c == findChar; }

//int main(int argc, char *argv[])  // pro parametry prikazoveho radku
int main(void)
{
    printf("======<<READ>>======\n");
    printf("Enter string length: ");
    int length = -1;
    scanf("%d", &length);
    clearIn();
    printf("Enter string: ");
    char* str = strRead(stdin, length);
    clearIn();
    if (!str)
    {
        printf("Couldn't read the string\n");
        return EXIT_FAILURE;
    }
    printf("%s\n", str);

    printf("===<<DIGIT COUNT>>==\n");
    int first, last;
    int digitCount = strCount(str, isDigit, &first, &last);
    switch (digitCount)
    {
    case -1:
        printf("couldn't get digit count\n");
        break;
    case 0:
        printf("no digits\n");
        break;
    default:
        printf("digit count: %d\n", digitCount);
        printf("first digit index: %d\n", first);
        printf("last digit index: %d\n", last);
        break;
    }

    printf("=====<<REPLACE>>====\n");
    printf("Enter old and new character: ");
    char newChar = 'y';
    scanf(" %c%c", &findChar, &newChar);
    clearIn();
    strReplace(str, isX, newChar);
    printf("%s\n", str);

    printf("==<<HIDE NUMBERS>>==\n");
    strReplace(str, isDigit, '#');
    printf("%s\n", str);

    printf("===<<WORD COUNT>>===\n");
    int wc = strWordCount(str);
    printf("word count: %d\n", wc);

    printf("===<<LOWER UPPER>>==\n");
    strToLower(str);
    printf("lower: %s\n", str);
    strToUpper(str);
    printf("upper: %s\n", str);

    printf("=====<<REVERSE>>====\n");
    strReverse(str, length);
    printf("loop: %s\n", str);
    strReverse2(str, length);
    printf("recursion: %s\n", str);

    return 0;
}

void clearIn()
{
    scanf("%*[^\n]");
    scanf("%*c");
}
