/*
 * Projekt: Banka-uloh-1
 * Autor:   Jakub Antonín Štigler
 * Datum:   1/29/2022
 */

#include <stdio.h>
#include <stdlib.h>

#include "Matrix.h"


//int main(int argc, char *argv[])  // pro parametry prikazoveho radku
int main(void)
{
    printf("=====<<BANK-1>>=====\n");
    char inPath[] = "matrix.txt";
    FILE* in = fopen(inPath, "r");
    FILE* out = stdout;

    printf("======<<READ>>======\n");
    TMatrix* mat = matRead(in, 1, 0);
    fclose(in);
    if (!mat)
    {
        matFree(&mat);
        printf("couldn't read from file '%s'\n", inPath);
        return EXIT_FAILURE;
    }

    printf("======<<WRITE>>=====\n");
    if (!matWrite(mat, out))
    {
        matFree(&mat);
        printf("couldn't write\n");
        return EXIT_FAILURE;
    }

    printf("===<<EVEN COUNT>>===\n");
    if (!matColumnEvenCount(mat))
    {
        matFree(&mat);
        printf("couldn't get count of even numbers in each column\n");
        return EXIT_FAILURE;
    }
    matWrite(mat, out);
    mat->sizeI--;

    printf("===<<BORDER SUM>>===\n");
    int bs;
    int cs;
    matBorderSum(mat,  &bs, &cs);
    printf("border: %d\n", bs);
    printf("center: %d\n", cs);

    printf("===<<QUARTER SUM>>==\n");
    int s;
    matQuarterSum(mat, 1, &s);
    printf("%2d ", s);
    matQuarterSum(mat, 2, &s);
    printf("%2d\n", s);
    matQuarterSum(mat, 3, &s);
    printf("%2d ", s);
    matQuarterSum(mat, 4, &s);
    printf("%2d\n", s);

    printf("=====<<SYMETRY>>====\n");
    int symetry = -1;
    matGetSymetry(mat, &symetry);
    switch (symetry)
    {
    case MAT_SYMETRY_NONE:
        printf("none\n");
        break;
    case MAT_SYMETRY_VERTICAL:
        printf("vertical\n");
        break;
    case MAT_SYMETRY_HORIZONTAL:
        printf("horizontal\n");
        break;
    case MAT_SYMETRY_BOTH:
        printf("vertical and horizontal");
        break;
    default:
        printf("an error ocured");
        matFree(&mat);
        return EXIT_FAILURE;
    }

    printf("====<<TRANSPOSE>>===\n");
    TMatrix* transposed = matTranspose(mat);
    if (!matWrite(transposed, out))
    {
        matFree(&mat);
        printf("failed to transpose matrix");
        return EXIT_FAILURE;
    }
    matFree(&transposed);

    printf("=====<<ROTATE>>=====\n");
    for (int i = 0; i < 4; i++)
    {
        TMatrix* rotated = matRotate(mat, i);
        printf("rotate %d:\n", i);
        if (!matWrite(rotated, out))
        {
            matFree(&mat);
            printf("failed to rotate matrix\n");
            return EXIT_FAILURE;
        }
        matFree(&rotated);
    }

    matFree(&mat);

    return EXIT_SUCCESS;
}
