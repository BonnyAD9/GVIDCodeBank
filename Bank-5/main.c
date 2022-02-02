/*
 * Projekt: Bank-5
 * Autor:   Jakub Antonín Štigler
 * Datum:   2/2/2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool readHexValues();
bool printInBase(int num, int base);
char getNumChar(int num);
double aEb(int num, int exponent);
void clearIn();

//int main(int argc, char *argv[])  // pro parametry prikazoveho radku
int main(void)
{
    printf("===<<HEX VALUES>>===\n");
    printf("Enter hex numbers to evaluate: ");
    if (!readHexValues())
    {
        printf("you entered invalid value!\n");
        clearIn();
    }

    printf("====<<NUM BASE>>====\n");
    printf("Enter number: ");
    int num;
    if (scanf(" %d", &num) < 0)
    {
        printf("invalid number\n");
        return EXIT_FAILURE;
    }
    int base;
    printf("Enter base: ");
    if (scanf(" %d", &base) < 0)
    {
        printf("invalid base\n");
        return EXIT_FAILURE;
    }
    clearIn();
    if (!printInBase(num, base))
    {
        printf("cannot get this number in that base\n");
    }
    else
    {
        printf("\n");
    }

    printf("===<<SCIENTIFIC>>===\n");
    printf("Enter number in scientific notation: ");
    int exponent;
    if (scanf("%dE%d", &num, &exponent) < 2)
    {
        printf("you entered invalid number");
    }
    else
    {
        printf("%.3E", aEb(num, exponent));
    }

    return 0;
}

double aEb(int num, int exponent)
{
    return (double)num * pow(10, exponent);
}

bool printInBase(int num, int base)
{
    if (num < 0 || base < 2 || base > 36)
    {
        return false;
    }

    int logN = (int)(log((double)num) / log((double)base)) + 1;
    double baseF = (double)base;
    double numF = (double)num / pow(baseF, (double)logN);

    for (int i = 0; i < logN; i++)
    {
        numF = numF * baseF + 1e-15; // adding the small number just to account for double imprecision
        int pNum = (int)numF;
        numF -= (double)pNum;
        printf("%c", getNumChar(pNum));
    }

    return true;
}

char getNumChar(int num)
{
    return num < 10 ? num + '0' : num + 'a' - 10;
}

bool readHexValues()
{
    unsigned int num = 0;
    char c;
    do
    {
        if (scanf("%x%c", &num, &c) <= 0)
        {
            return false;
        }
        printf("%u\n", num);
    } while (c != '\n');

    return true;
}

void clearIn()
{
    scanf("%*[^\n]");
    scanf("%*c");
}
