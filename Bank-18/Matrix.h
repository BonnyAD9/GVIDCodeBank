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

typedef enum
{
    MAJOR_DIAGONAL,
    MINOR_DIAGONAL,
    HORIZONTAL,
    VERTICAL,
} TAxis;

bool matrixIsSymetrycByAxis(TMatrix* m, TAxis axis);

TMatrix* matrixCreate(int sizeI, int sizeJ);

bool matrixRead(TMatrix* matrix, FILE* f);

bool matrixWrite(TMatrix* matrix, FILE* f);

bool matrixDelete(TMatrix** matrix);

#endif // MATRIX_H_INCLUDED
