/*
 * Projekt: Bank-10
 * Autor:   Jakub Antonín Štigler
 * Datum:   2/12/2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void sum(char* a, char* b, char* result, int length);
void rotate(char* a, int amount, char* result, int length);
void shift(char* a, int amount, char* result, int length);
void xor(char* a, char* b, char* result);
void or(char* a, char* b, char* result);
void and(char* a, char* b, char* result);
bool isBinary(char* num, int digits);
void clearIn();

int main(void)
{
    const int len = 16;

    printf("======<<BITS>>======\n");
    printf("(16 character mark     :)      v\n");
    printf("Enter number a: ");
    char a[len + 1];
    scanf("%16s", a); // 16 coresponds to len
    clearIn();
    if (!isBinary(a, len))
    {
        printf("invalid number '%s'\n", a);
        return EXIT_FAILURE;
    }
    printf("Enter number b: ");
    char b[len + 1];
    scanf("%16s", b); // 16 coresponds to len
    clearIn();
    if (!isBinary(b, len))
    {
        printf("invalid number b '%s'\n", b);
        return EXIT_FAILURE;
    }
    char r[len + 1];
    r[len] = 0;
    printf("Enter amount to shift and rotate: ");
    int amount = 0;
    if (scanf("%d", &amount) != 1)
    {
        printf("invalid input\n");
        return EXIT_FAILURE;
    }
    clearIn();

    printf("=======<<AND>>======\n");
    and(a, b, r);
    printf("%s\n", r);

    printf("=======<<OR>>=======\n");
    or(a, b, r);
    printf("%s\n", r);

    printf("=======<<XOR>>======\n");
    xor(a, b, r);
    printf("%s\n", r);

    printf("======<<SHIFT>>=====\n");
    shift(a, amount, r, len);
    printf("a >> %d = %s\n", amount, r);
    shift(b, amount, r, len);
    printf("b >> %d = %s\n", amount, r);

    printf("=====<<ROTATE>>=====\n");
    rotate(a, amount, r, len);
    printf("a |> %d = %s\n", amount, r);
    rotate(b, amount, r, len);
    printf("b |> %d = %s\n", amount, r);

    printf("=======<<SUM>>======\n");
    sum(a, b, r, len);
    printf("%s\n", r);

    return EXIT_SUCCESS;
}

void sum(char* a, char* b, char* result, int length)
{
    char carry = '0';
    for (int i = length - 1; i >= 0; i--)
    {
        result[i] = (a[i] != b[i]) ^ (carry == '1') ? '1' : '0';
        carry = (a[i] == '1' && b[i] == '1') || (carry == '1' && (a[i] != b[i])) ? '1' : '0';
    }
}

void rotate(char* a, int amount, char* result, int length)
{
    amount %= length;
    if (amount == 0)
    {
        return;
    }

    for (int i = 0; i < length; i++)
    {
        result[(i + length + amount) % length] = a[i];
    }
}

void shift(char* a, int amount, char* result, int length)
{
    int step = amount < 0 ? -1 : 1;
    for (int i = amount < 0 ? length - 1 : 0; i < length && i >= 0; i += step)
    {
        int takeIndex = i - amount;
        result[i] = takeIndex < length && takeIndex >= 0 ? a[takeIndex] : '0';
    }
}

void xor(char* a, char* b, char* result)
{
    for (; *a && *b; a++, b++, result++)
    {
        *result = *a != *b ? '1' : '0';
    }
}

void or(char* a, char* b, char* result)
{
    for (; *a && *b; a++, b++, result++)
    {
        *result = *a == '1' || *b == '1' ? '1' : '0';
    }
}

void and(char* a, char* b, char* result)
{
    for (; *a && *b; a++, b++, result++)
    {
        *result = *a == '1' && *b == '1' ? '1' : '0';
    }
}

bool isBinary(char* num, int digits)
{
    int d;
    for (d = 0; *num; num++, d++)
    {
        if (*num != '0' && *num != '1')
        {
            return false;
        }
    }

    return d == digits;
}

void clearIn()
{
    scanf("%*[^\n]");
    scanf("%*c");
}
