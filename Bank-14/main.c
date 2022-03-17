/*
 * Projekt: Bank-14
 * Autor:   Jakub Antonín Štigler
 * Datum:   3/17/2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Matrix.h"
#include "EqSysSolver.h"

void clearIn();

int main(void)
{
    printf("===<<GEM FORWARD>>==\n");
    printf("Enter file with matrix: ");
    char path[257];
    if (scanf("%256s", path) != 1)
    {
        printf("failed to read path\n");
        return EXIT_FAILURE;
    }
    clearIn();
    FILE* f = fopen(path, "r");
    if (!f)
    {
        printf("couldn't open file '%s'\n", path);
        return EXIT_FAILURE;
    }
    TMatrix* m = matrixRead(f);
    fclose(f);
    if (!m)
    {
        printf("couldn't read matrix\n");
        return EXIT_FAILURE;
    }
    printf("the matrix:\n");
    matrixWrite(m, stdout);
    if (!essGEMForward(m))
    {
        printf("the matrix has invalid dimensions\n");
        return EXIT_FAILURE;
    }
    printf("after forward:\n");
    matrixWrite(m, stdout);

    printf("==<<GEM SOLUTIONS>>==\n");
    TSolCount sc = essGEMSolCount(m);
    switch (sc)
    {
    case ZERO:
        printf("system of equations has no solutions\n");
        break;
    case ONE:
        printf("system of equations has single solution\n");
        break;
    case INFINITY:
        printf("system has infinitely many solutions\n");
        break;
    default:
        printf("an error occured\n");
        return EXIT_FAILURE;
    }

    printf("==<<GEM AFTER FORWARD>>==\n");
    printf("Enter file with matrix: ");
    if (scanf("%256s", path) != 1)
    {
        printf("failed to read path\n");
        return EXIT_FAILURE;
    }
    clearIn();
    f = fopen(path, "r");
    if (!f)
    {
        printf("couldn't read from file '%s'", path);
        return EXIT_FAILURE;
    }
    TMatrix* m0 = matrixRead(f);
    fclose(f);
    if (!m0)
    {
        printf("couldn't read matrix\n");
        return EXIT_FAILURE;
    }
    printf("the matrix:\n");
    matrixWrite(m0, stdout);
    if (essGEMAfterForward(m0))
    {
        printf("matrix is after forward GEM\n");
    }
    else
    {
        printf("matrix isn't after forward GEM\n");
    }
    matrixDelete(&m0);

    printf("==<<GEM BACKWARD>>==\n");
    if (sc == ONE)
    {
        printf("solution to the first system of equations:\n");
        for (int i = 0; i < m->sizeI; i++)
        {
            printf("x%d = %f\n", i, m->data[i][m->sizeJ - 1]);
        }
    }
    matrixDelete(&m);

    printf("==<<GJ AFTER FORWARD>>==\n");
    printf("Enter file with matrix: ");
    if (scanf("%256s", path) != 1)
    {
        printf("couldn't read path\n");
        return EXIT_FAILURE;
    }
    f = fopen(path, "r");
    if (!f)
    {
        printf("couldn't read from file '%s'\n", path);
        return EXIT_FAILURE;
    }
    m = matrixRead(f);
    if (!m)
    {
        printf("couldn't read matrix\n");
        return EXIT_FAILURE;
    }
    printf("the matrix:\n");
    matrixWrite(m, stdout);
    bool af = essGJAfterForward(m);
    if (af)
    {
        printf("matrix is after forward GJEM\n");
    }
    else
    {
        printf("matrix isn't after forward GJEM\n");
    }

    printf("==<<GJEM BACKWARD>>==\n");
    if (af)
    {
        switch (essGJBack(m))
        {
        case ZERO:
            printf("the system of equations has no solution\n");
            break;
        case ONE:
            for (int i = 0; i < m->sizeI; i++)
            {
                printf("x%d = %f\n", i, m->data[i][m->sizeJ - 1]);
            }
            break;
        case INFINITY:
            printf("the system of equations has infinitely many solutions\n");
            break;
        default:
            printf("the matrix has invalid dimensions\n");
            return EXIT_FAILURE;
        }
    }

    printf("======<<ATD.>>======\n");

    return EXIT_SUCCESS;
}

void clearIn()
{
    scanf("%*[^\n]");
    scanf("%*c");
}
