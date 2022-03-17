#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int sizeI;
    int sizeJ;
    float** data;
} TMatrix;

TMatrix* matrixCreate(int sizeI, int sizeJ);

TMatrix* matrixRead(FILE* in);

bool matrixWrite(TMatrix* matrix, FILE* out);

bool matrixDelete(TMatrix** matrix);

#endif // MATRIX_H_INCLUDED
