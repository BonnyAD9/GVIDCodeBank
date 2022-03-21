/*
 * Projekt: Bank-18
 * Autor:   Jakub Antonín Štigler
 * Datum:   3/21/2022
 */

#include <stdio.h>
#include <stdlib.h>

#include "Matrix.h"
#include "SmallestSquares.h"

int ga;
int gb;

float function(float num);
void clearIn();

int main()
{
    printf("====<<CONSTANT>>====\n");
    printf("Enter number of entries: ");
    int size;
    if (scanf(" %d", &size) != 1)
    {
        printf("failed to read number of entries");
        return EXIT_FAILURE;
    }
    clearIn();
    TMatrix* m = matrixCreate(2, size);
    printf("Enter values of x and than values of y: ");
    if (!matrixRead(m, stdin))
    {
        printf("failed to read into matrix\n");
        return EXIT_FAILURE;
    }
    clearIn();
    float a;
    ssConstant(m, &a);
    printf("f(x)=%f\n", a);

    printf("=====<<LINEAR>>=====\n");
    float b;
    if (!ssLinear(m, &a, &b))
    {
        printf("failed to calculate nearest linear equation\n");
    }
    else
    {
        printf("f(x)=%fx+%f\n", a, b);
    }

    printf("===<<SYMETRICITY>>==\n");
    printf("Enter square matrix size: ");
    if (scanf(" %d", &size) != 1)
    {
        printf("couldn't read size\n");
        return EXIT_FAILURE;
    }
    clearIn();
    TMatrix* mat = matrixCreate(size, size);
    if (!mat)
    {
        printf("failed to create matrix\n");
        return EXIT_FAILURE;
    }
    printf("Enter the matrix data: ");
    if (!matrixRead(mat, stdin))
    {
        printf("failed to read matrix data\n");
        return EXIT_FAILURE;
    }
    printf("\\: %s\n", matrixIsSymetrycByAxis(mat, MAJOR_DIAGONAL) ? "yes" : "no");
    printf("/: %s\n", matrixIsSymetrycByAxis(mat, MINOR_DIAGONAL) ? "yes" : "no");
    printf("-: %s\n", matrixIsSymetrycByAxis(mat, HORIZONTAL) ? "yes" : "no");
    printf("|: %s\n", matrixIsSymetrycByAxis(mat, VERTICAL) ? "yes" : "no");
    matrixDelete(&mat);

    printf("==<<SQUARE DISTANCE SUM>>==\n");
    ga = a;
    gb = b;
    printf("sum: %f\n", ssSquareDistances(m, function));
    matrixDelete(&m);

    return EXIT_SUCCESS;
}

float function(float num)
{
    return ga * num + gb;
}

void clearIn()
{
    scanf("%*[^\n]");
    scanf("%*c");
}
