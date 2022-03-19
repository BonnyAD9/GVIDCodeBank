/*
 * Projekt: Bank-15
 * Autor:   Jakub Antonín Štigler
 * Datum:   3/19/2022
 */

#include <stdio.h>
#include <stdlib.h>

#include "Matrix.h"
#include "IterEqSysSolver.h"

void clearIn();

int main()
{
    printf("======<<READ>>======\n");
    printf("Enter matrix size and than the matrix itself: ");
    TMatrix* m = matrixRead(stdin);
    clearIn();
    if (!m)
    {
        printf("failed to read matrix\n");
        return EXIT_FAILURE;
    }

    printf("==<<EQUATION SYSTEM>==\n");
    bool isES = iessIsEqSystem(m);
    if (isES)
    {
        printf("matrix is system of equations\n");
    }
    else
    {
        printf("matrix is not system of equations\n");
    }

    printf("==<<DIAGONALLY DOMINANT>>==\n");
    bool isDD = iessIsDiagonallyDominant(m);
    if (isES)
    {
        if (isDD)
        {
            printf("matrix is diagonally dominant\n");
        }
        else
        {
            printf("matrix is not diagonally dominant\n");
        }
    }

    printf("======<<GSIM>>======\n");
    if (isES && isDD)
    {
        float* res = iessGSIM(m, 0.01);
        if (!res)
        {
            printf("the equation system does not converge\n");
            return EXIT_SUCCESS;
        }
        for (int i = 0; i < m->sizeI; i++)
        {
            printf("x%d = %f\n", i, res[i]);
        }
    }

    return EXIT_SUCCESS;
}

void clearIn()
{
    scanf("%*[^\n]");
    scanf("ˇ*c");
}
