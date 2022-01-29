#include "Matrix.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int (*FIndex)(int size, int same, int opposite);

int _forward(int size, int same, int opposite);
int _oppo(int size, int same, int opposite);
int _neg(int size, int same, int opposite);
int _oppoNeg(int size, int same, int opposite);
TMatrix* _matRotate(TMatrix* matrix, int deg);
TMatrix* _matTranspose(TMatrix* matrix);
bool _matGetSymetry(TMatrix* matrix, bool vert);
int _matQuarterSum(TMatrix* matrix, int quarter);
void _matBorderSum(TMatrix* matrix, int* borderSum, int* centerSum);
bool _matResize(TMatrix* matrix, int newI, int newJ);
void _matWrite(TMatrix* matrix, FILE* out);
TMatrix* _matRead(FILE* in, int extraI, int extraJ);
TMatrix* _matCreate(int sizeI, int sizeJ);

TMatrix* matRotate(TMatrix* matrix, int deg)
{
    if (!matrix || deg < 0 || deg > 3)
    {
        return NULL;
    }

    return _matRotate(matrix, deg);
}

int _forward(int size, int same, int opposite) { return same; }
int _oppo(int size, int same, int opposite) { return opposite; }
int _neg(int size, int same, int opposite) { return size - same - 1; }
int _oppoNeg(int size, int same, int opposite) { return size - opposite - 1; }

TMatrix* _matRotate(TMatrix* matrix, int deg)
{
    TMatrix* mat = deg & 1 ? _matCreate(matrix->sizeJ, matrix->sizeI) : _matCreate(matrix->sizeI, matrix->sizeJ);
    if (!mat)
    {
        return NULL;
    }
    FIndex fir = _forward;
    FIndex sec = _forward;

    switch (deg)
    {
    case 1:
        fir = _oppo;
        sec = _oppoNeg;
        break;
    case 2:
        fir = _neg;
        sec = _neg;
        break;
    case 3:
        fir = _oppoNeg;
        sec = _oppo;
        break;
    }

    for (int i = 0; i < matrix->sizeI; i++)
    {
        for (int j = 0; j < matrix->sizeJ; j++)
        {
            mat->data[fir(mat->sizeI, i, j)][sec(mat->sizeJ, j, i)] = matrix->data[i][j];
        }
    }

    return mat;
}

TMatrix* matTranspose(TMatrix* matrix)
{
    if (!matrix)
    {
        return NULL;
    }

    return _matTranspose(matrix);
}

TMatrix* _matTranspose(TMatrix* matrix)
{
    TMatrix* mat = _matCreate(matrix->sizeJ, matrix->sizeI);
    if (!mat)
    {
        return NULL;
    }

    for (int i = 0; i < matrix->sizeI; i++)
    {
        for (int j = 0; j < matrix->sizeJ; j++)
        {
            mat->data[j][i] = matrix->data[i][j];
        }
    }

    return mat;
}

bool matGetSymetry(TMatrix* matrix, int* symetry)
{
    if (!matrix || !symetry)
    {
        return false;
    }

    *symetry = _matGetSymetry(matrix, true);
    *symetry <<= 1;
    *symetry |= _matGetSymetry(matrix, false);

    return true;
}

bool _matGetSymetry(TMatrix* matrix, bool vert)
{
    int size[] = { matrix->sizeI, matrix->sizeJ };
    int pos[2];

    for (pos[0] = 0; pos[0] < size[vert] / 2; pos[0]++)
    {
        for (pos[1] = 0; pos[1] < size[!vert]; pos[1]++)
        {
            int sec = vert ? matrix->data[pos[1]][size[vert] - pos[0] - 1] : matrix->data[size[vert] - pos[0] - 1][pos[1]];
            if (matrix->data[pos[vert]][pos[!vert]] != sec)
            {
                return false;
            }
        }
    }

    return true;
}

bool matQuarterSum(TMatrix* matrix, int quarter, int* sum)
{
    if (!matrix || !sum || quarter < 1 || quarter > 4)
    {
        return false;
    }

    *sum = _matQuarterSum(matrix, quarter);
    return true;
}

int _matQuarterSum(TMatrix* matrix, int quarter)
{
    bool bot = quarter > 2;
    bool left = quarter & 1;
    int startI = bot ? matrix->sizeI / 2 : 0;
    int endI = bot ? matrix->sizeI : matrix->sizeI / 2;
    int startJ = left ? 0 : matrix->sizeJ / 2;
    int endJ = left ? matrix->sizeJ / 2 : matrix->sizeJ;

    int sum = 0;
    for (int i = startI; i < endI; i++)
    {
        for (int j = startJ; j < endJ; j++)
        {
            sum += matrix->data[i][j];
        }
    }

    return sum;
}

bool matBorderSum(TMatrix* matrix, int* borderSum, int* centerSum)
{
    if (!matrix || (!borderSum && !centerSum))
        return false;

    int bs;
    int cs;

    if (!borderSum)
    {
        borderSum = &bs;
    }
    if (!centerSum)
    {
        centerSum = &cs;
    }

    *borderSum = 0;
    *centerSum = 0;

    _matBorderSum(matrix, borderSum, centerSum);
    return true;
}

void _matBorderSum(TMatrix* matrix, int* borderSum, int* centerSum)
{
    for (int i = 0; i < matrix->sizeI; i++)
    {
        for (int j = 0; j < matrix->sizeJ; j++)
        {
            if (i == 0 || i == matrix->sizeI - 1 || j == 0 || j == matrix->sizeJ - 1)
            {
                *borderSum += matrix->data[i][j];
                continue;
            }
            *centerSum += matrix->data[i][j];
        }
    }
}

bool matColumnEvenCount(TMatrix* matrix)
{
    if (!_matResize(matrix, matrix->sizeI + 1, matrix->sizeJ))
    {
        return false;
    }

    for (int j = 0; j < matrix->sizeJ; j++)
    {
        matrix->data[matrix->sizeI - 1][j] = 0.0f;

        for (int i = 0; i < matrix->sizeI - 1; i++)
        {
            if ((matrix->data[i][j] & 1) == 0)
            {
                matrix->data[matrix->sizeI - 1][j]++;
            }
        }
    }

    return true;
}

bool _matResize(TMatrix* matrix, int newI, int newJ)
{
    int newSizeI = newI + matrix->sizeI / 2;
    int newSizeJ = matrix->_allocatedJ >= newJ ? matrix->_allocatedJ : newJ + matrix->sizeJ / 2;
    int prevAI = matrix->_allocatedI;
    if (matrix->_allocatedI >= newI)
    {
        matrix->sizeI = newI;
    }
    else
    {
        int** newDat = realloc(matrix->data, newSizeI * sizeof(int*));
        if (!newDat)
        {
            return false;
        }
        matrix->data = newDat;
        matrix->_allocatedI = newSizeI;
        bool ok = true;
        for (int i = prevAI; i < newSizeI; i++)
        {
            matrix->data[i] = calloc(newSizeJ, sizeof(int));
            ok = matrix->data[i] && ok;
        }
        if (!ok)
        {
            return false;
        }
        matrix->sizeI = newI;
    }
    if (matrix->_allocatedJ >= newJ)
    {
        matrix->sizeJ = newJ;
        return true;
    }
    for (int i = 0; i < prevAI; i++)
    {
        int* newData = realloc(matrix->data[i], newSizeJ * sizeof(int));
        if (!newData)
        {
            return false;
        }
        matrix->data[i] = newData;
        for (int j = 0; j < newSizeJ; j++)
        {
            matrix->data[i][j] = 0;
        }
    }
    matrix->_allocatedJ = newSizeJ;
    matrix->sizeJ = newJ;
    return true;
}

bool matWrite(TMatrix* matrix, FILE* out)
{
    if (!matrix || !out)
    {
        return false;
    }

    _matWrite(matrix, out);
    return true;
}

void _matWrite(TMatrix* matrix, FILE* out)
{
    fprintf(out, "%d %d\n", matrix->sizeI, matrix->sizeJ);

    for (int i = 0; i < matrix->sizeI; i++)
    {
        for (int j = 0; j < matrix->sizeJ; j++)
        {
            fprintf(out, "%2d ", matrix->data[i][j]);
        }
        fprintf(out, "\n");
    }
}

TMatrix* matRead(FILE* in, int extraI, int extraJ)
{
    if (!in || extraI < 0 || extraJ < 0)
    {
        return NULL;
    }

    return _matRead(in, extraI, extraJ);
}

TMatrix* _matRead(FILE* in, int extraI, int extraJ)
{
    int sizeI;
    int sizeJ;
    fscanf(in, "%d", &sizeI);
    fscanf(in, "%d", &sizeJ);
    sizeI += extraI;
    sizeJ += extraJ;

    TMatrix* mat = _matCreate(sizeI, sizeJ);
    mat->sizeI -= extraI;
    mat->sizeJ -= extraJ;

    if (!mat)
    {
        return NULL;
    }

    for (int i = 0; i < mat->sizeI; i++)
    {
        for (int j = 0; j < mat->sizeJ; j++)
        {
            if (fscanf(in, "%d", &mat->data[i][j]) != 1)
            {
                return mat;
            }
        }
    }

    return mat;
}

TMatrix* _matCreate(int sizeI, int sizeJ)
{
    TMatrix* mat = malloc(sizeof(TMatrix));
    if (!mat)
    {
        return NULL;
    }

    mat->data = malloc(sizeof(int*) * sizeI);
    if (!mat->data)
    {
        free(mat);
        return NULL;
    }

    for (int i = 0; i < sizeI; i++)
    {
        mat->data[i] = calloc(sizeJ, sizeof(int));
        if (!mat->data[i])
        {
            for (int j = 0; j < i; j++)
            {
                free(mat->data[j]);
            }
            free(mat->data);
            free(mat);
            return NULL;
        }
    }

    mat->sizeI = sizeI;
    mat->sizeJ = sizeJ;
    mat->_allocatedI = sizeI;
    mat->_allocatedJ = sizeJ;

    return mat;
}

void matFree(TMatrix** matrix)
{
    if (!matrix || !*matrix)
    {
        return;
    }

    TMatrix* mat = *matrix;

    if (mat->data)
    {
        for (int i = 0; i < mat->_allocatedI; i++)
        {
            free(mat->data[i]);
            mat->data[i] = NULL;
        }

        free(mat->data);
    }

    free(mat);

    *matrix = NULL;
}

