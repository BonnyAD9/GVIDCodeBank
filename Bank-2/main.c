/*
 * Projekt: Bank-2
 * Autor:   Jakub Antonín Štigler
 * Datum:   1/29/2022
 */

#include <stdio.h>
#include <stdlib.h>

char interface(char** choices, int length);
void histogram();
int* getHistogram();
void lastN();
void polynomial();
float horner(float* poly, int length, float number);

//int main(int argc, char *argv[])
int main(void)
{
    const int length = 3;
    char* choices[] = {
        "PPolynomial",
        "NLast N",
        "HHistogram",
    };

    char c = '\0';
    while (c != 'K')
    {
        c = interface(choices, length);
        switch (c)
        {
        case 'P':
            polynomial();
            break;
        case 'N':
            lastN();
            break;
        case 'H':
            histogram();
            break;
        case 'X':
            printf("Invalid choice\n");
            break;
        case 'K':
            printf("Quitting\n");
            break;
        case '\0':
            break;
        default:
            printf("Error\n");
            break;
        }
    }
    return 0;
}

char interface(char** choices, int length)
{
    printf("======<<MENU>>======\n");
    printf("0. Exit\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d. %s\n", i + 1, &choices[i][1]);
    }
    printf("Enter your choice: ");
    int c = -1;
    scanf("%d", &c);
    scanf("%*[^\n]");
    scanf("%*c");
    if (c < 0 || c > length)
    {
        return 'X';
    }
    if (c == 0)
    {
        return 'K';
    }
    return choices[c - 1][0];
}

void histogram()
{
    printf("====<<HISTOGRAM>>===\n");
    printf("Enter charaters: ");
    int* his = getHistogram();

    printf("Small english letters counts:\n");
    for (char i = 'a'; i <= 'z'; i++)
    {
        printf("%c: %d\n", i, his[(int)i]);
    }

    free(his);
}

int* getHistogram()
{
    int* counts = calloc(256, sizeof(int));
    char c = '5';
    for (int i = 0; c != '\n' ; i++)
    {
        scanf("%c", &c);
        counts[(int)c]++;
    }
    return counts;
}

void lastN()
{
    printf("=====<<LAST N>>=====\n");
    printf("Enter N: ");
    int n;
    scanf("%d", &n);

    printf("Enter numbers: ");
    float arr[n];
    int i;
    char c = 'k';
    for (i = 0; c != '\n'; i++)
    {
        scanf("%f%c", &arr[i % n], &c);
    }

    float sum = 0;
    printf("Last %d numbers: ", n);
    for (int j = i; j < i + n; j++)
    {
        sum += arr[j % n];
        printf("%f ", arr[j % n]);
    }

    printf("\nSum of last %d numbers: %f\n", n, sum);

    printf("Last %d numbers reversed: ", n);
    for (int j = i - 1; j >= 0 && j >= i - n; j--)
    {
        printf("%f ", arr[j % n]);
    }
    printf("\n");
}

void polynomial()
{
    printf("===<<POLYNOMIAL>>===\n");
    printf("Enter degree of polynomial: ");
    int deg;
    scanf("%d", &deg);
    deg++;

    printf("Enter coefficients: ");
    float poly[deg];
    for (int i = 0; i < deg; i++)
    {
        scanf("%f", &poly[i]);
        //printf("%f", &poly[i]);
    }

    printf("Enter number: ");
    float num;
    scanf("%f", &num);

    printf("result: %f\n", horner(poly, deg, num));
}

float horner(float* poly, int length, float number)
{
    if (length == 0)
    {
        return 0;
    }

    int res = poly[0];
    for (int i = 1; i < length; i++)
    {
        res = res * number + poly[i];
    }

    return res;
}
