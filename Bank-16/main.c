/*
 * Projekt: Bank-16
 * Autor:   Jakub Antonín Štigler
 * Datum:   3/19/2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "IterEqSolver.h"

int len;
float* coefitients;
float* derivationCoefs;

float function(float num);
float derivation(float num);
void clearIn();

int main()
{
    printf("=====<<HORNER>>=====\n");
    printf("Enter length of polynomial: ");
    int length;
    if (scanf(" %d", &length) != 1)
    {
        printf("failed to read number\n");
        return EXIT_FAILURE;
    }
    clearIn();
    if (length <= 0)
    {
        printf("invalid number\n");
        return EXIT_FAILURE;
    }
    float coefs[length];
    printf("Enter coeficients: ");
    for (int i = 0; i < length; i++)
    {
        if (scanf(" %f", &coefs[i]) != 1)
        {
            printf("failed to read coficients\n");
            return EXIT_FAILURE;
        }
    }
    clearIn();
    printf("Enter number to use in the polynomial: ");
    float num;
    if (scanf(" %f", &num) != 1)
    {
        printf("failed to read number\n");
        return EXIT_FAILURE;
    }
    clearIn();
    printf("result of evaluated polynimial: %f\n", iesHorner(coefs, length, num));

    printf("==<<HALFING INTERVAL>>==\n");
    coefitients = coefs;
    len = length;
    printf("Enter interval: ");
    float a, b;
    if (scanf(" %f %f", &a, &b) != 2)
    {
        printf("couldn't read interval\n");
        return EXIT_FAILURE;
    }
    clearIn();
    const float err = 0.01;
    num = iesHalfingInterval(function, err, a, b);
    if (isnan(num))
    {
        printf("invalid interval\n");
    }
    else
    {
        printf("solution: %f\n", num);
    }

    printf("===<<RGULA FALSI>>==\n");
    num = iesRegulaFalsi(function, err, a, b);
    if (isnan(num))
    {
        printf("invalid interval\n");
    }
    else
    {
        printf("solution: %f\n", num);
    }

    printf("=====<<NEWTON>>=====\n");
    printf("Enter derivation of the polynomial: ");
    float deriv[length - 1];
    for (int i = 0; i < length - 1; i++)
    {
        if (scanf(" %f", &deriv[i]) != 1)
        {
            printf("couldn't read derivation\n");
            return EXIT_FAILURE;
        }
    }
    clearIn();
    printf("Enter starting number: ");
    if (scanf(" %f", &a) != 1)
    {
        printf("couldn't read number\n");
        return EXIT_FAILURE;
    }
    clearIn();
    derivationCoefs = deriv;
    num = iesNewton(function, derivation, err, a);
    if (isnan(num))
    {
        printf("number didn't converge\n");
        return EXIT_SUCCESS;
    }
    printf("solution: %f\n", num);

    return EXIT_SUCCESS;
}

float function(float num)
{
    return iesHorner(coefitients, len, num);
}

float derivation(float num)
{
    return iesHorner(derivationCoefs, len - 1, num);
}

void clearIn()
{
    scanf("%*[^\n]");
    scanf("%*c");
}
