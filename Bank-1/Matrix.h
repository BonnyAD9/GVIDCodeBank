#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int sizeI;
    int sizeJ;
    int _allocatedI;
    int _allocatedJ;
    int** data;
} TMatrix;

enum
{
    MAT_SYMETRY_NONE = 0,
    MAT_SYMETRY_HORIZONTAL = 1,
    MAT_SYMETRY_VERTICAL = 2,
    MAT_SYMETRY_BOTH = 3,
};

TMatrix* matRead(FILE* in, int extraI, int extraJ);

bool matWrite(TMatrix* matrix, FILE* out);

bool matColumnEvenCount(TMatrix* matrix);

bool matBorderSum(TMatrix* matrix, int* borderSum, int* centerSum);

bool matQuarterSum(TMatrix* matrix, int quarter, int* sum);

bool matGetSymetry(TMatrix* matrix, int* symetry);

TMatrix* matTranspose(TMatrix* matrix);

TMatrix* matRotate(TMatrix* matrix, int deg);

void matFree(TMatrix** matrix);

#endif // MATRIX_H_INCLUDED
