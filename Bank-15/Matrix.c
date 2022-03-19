#include "Matrix.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

TMatrix* _matrixCreate(int sizeI, int sizeJ);
TMatrix* _matrixRead(FILE* in);
void _matrixWrite(TMatrix* matrix, FILE* out);
void _matrixDelete(TMatrix* matrix);

TMatrix* matrixCreate(int sizeI, int sizeJ)
{
    if (sizeI <= 0 || sizeJ <= 0)
    {
        return NULL;
    }

    return _matrixCreate(sizeI, sizeJ);
}

TMatrix* _matrixCreate(int sizeI, int sizeJ)
{
    TMatrix* m = malloc(sizeof(TMatrix));
    if (!m)
    {
        return NULL;
    }

    m->data = malloc(sizeI * sizeof(float*));
    if (!m->data)
    {
        free(m);
        return NULL;
    }

    for (int i = 0; i < sizeI; i++)
    {
        m->data[i] = calloc(sizeJ, sizeof(float));
        if (m->data[i])
        {
            continue;
        }

        for (int j = 0; j < i; j++)
        {
            free(m->data[j]);
        }
        free(m->data);
        free(m);
        return NULL;
    }

    m->sizeI = sizeI;
    m->sizeJ = sizeJ;

    return m;
}

TMatrix* matrixRead(FILE* in)
{
    if (!in)
    {
        return NULL;
    }

    return _matrixRead(in);
}

TMatrix* _matrixRead(FILE* in)
{
    int sizeI, sizeJ;
    if (fscanf(in, " %d %d", &sizeI, &sizeJ) != 2)
    {
        return NULL;
    }

    TMatrix* m = matrixCreate(sizeI, sizeJ);
    if (!m)
    {
        return NULL;
    }

    for (int i = 0; i < sizeI; i++)
    {
        for (int j = 0; j < sizeJ; j++)
        {
            if (fscanf(in, " %f", &m->data[i][j]) != 1)
            {
                _matrixDelete(m);
                return NULL;
            }
        }
    }

    return m;
}

bool matrixWrite(TMatrix* matrix, FILE* out)
{
    if (!matrix || !out)
    {
        return false;
    }

    _matrixWrite(matrix, out);

    return true;
}

void _matrixWrite(TMatrix* matrix, FILE* out)
{
    fprintf(out, "%d %d\n", matrix->sizeI, matrix->sizeJ);
    for (int i = 0; i < matrix->sizeI; i++)
    {
        for (int j = 0; j < matrix->sizeJ; j++)
        {
            fprintf(out, "%f ", matrix->data[i][j]);
        }
        fprintf(out, "\n");
    }
}

bool matrixDelete(TMatrix** matrix)
{
    if (!matrix || !*matrix)
    {
        return false;
    }

    _matrixDelete(*matrix);

    return true;
}

void _matrixDelete(TMatrix* matrix)
{
    for (int i = 0; i < matrix->sizeI; i++)
    {
        free(matrix->data[i]);
    }

    free(matrix->data);
    free(matrix);
}
