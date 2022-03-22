/*
 * Projekt: Bank-24
 * Autor:   Jakub Antonín Štigler
 * Datum:   3/22/2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void leaveBinary(char* str);
int intLim(char* str);
bool isHex(char c);
void clearIn();

int main(void)
{
    printf("=====<<BINARY>>=====\n");
    char str[1024];
    printf("Enter string: ");
    if (scanf("%1023[^\n]", str) != 1)
    {
        printf("couldn't read string\n");
        return EXIT_FAILURE;
    }
    clearIn();
    leaveBinary(str);
    printf("%s\n", str);

    printf("=====<<ADRESS>>=====\n");
    printf("Enter hexadecimal number: ");
    if (scanf("%1023[^\n]", str) != 1)
    {
        printf("couldn't read string\n");
        return EXIT_FAILURE;
    }
    clearIn();
    int lim = intLim(str);
    if (lim == 0)
    {
        printf("number cannot be adress in x64 system\n");
        return EXIT_SUCCESS;
    }
    printf("smallest system: %d\n", lim);

    printf("======<<OTHER>>=====\n");
    printf("...\n");

    return EXIT_SUCCESS;
}

void leaveBinary(char* str)
{
    int w = 0;
    for (int r = 0; str[r]; r++)
    {
        if (str[r] == '1' || str[r] == '0')
        {
            str[w] = str[r];
            w++;
        }
    }
    str[w] = 0;
}

int intLim(char* str)
{
    for (; *str && *str == '0'; str++) ;
    int i;
    for (i = 0; *str && i <= 16; str++, i++)
    {
        if (!isHex(*str))
        {
            return 0;
        }
    }

    if (i <= 2)
    {
        return 8;
    }
    if (i <= 4)
    {
        return 16;
    }
    if (i <= 8)
    {
        return 32;
    }
    if (i <= 16)
    {
        return 64;
    }
    return 0;
}

bool isHex(char c)
{
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

void clearIn()
{
    scanf("%*[^\n]");
    scanf("%*c");
}
