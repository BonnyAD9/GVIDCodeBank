#include "Matrix.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool _matrixIsSymetrycByAxis(TMatrix* m, TAxis axis);
TMatrix* _matrixCreate(int sizeI, int sizeJ);
bool _matrixRead(TMatrix* matrix, FILE* f);
void _matrixWrite(TMatrix* matrix, FILE* f);
void _matrixDelete(TMatrix* matrix);

bool matrixIsSymetrycByAxis(TMatrix* m, TAxis axis)
{
    if (!m || m->sizeI != m->sizeJ)
    {
        return false;
    }

    return _matrixIsSymetrycByAxis(m, axis);
}

bool _matrixIsSymetrycByAxis(TMatrix* m, TAxis axis)
{
    switch (axis)
    {
    case VERTICAL: // |
        for (int i = 0; i < m->sizeI; i++)
        {
            for (int j = 0; j < m->sizeJ / 2; j++)
            {
                if (m->data[i][j] != m->data[i][m->sizeJ - j - 1])
                {
                    return false;
                }
            }
        }
        return true;
    case HORIZONTAL: // -
        for (int i = 0; i < m->sizeI / 2; i++)
        {
            for (int j = 0; j < m->sizeJ; j++)
            {
                if (m->data[i][j] != m->data[m->sizeI - i - 1][j])
                {
                    return false;
                }
            }
        }
        return true;
    case MINOR_DIAGONAL: // /
        for (int i = 0; i < m->sizeI - 1; i++)
        {
            for (int j = 0; j < m->sizeJ - 1; j++)
            {
                if (m->data[i][j] != m->data[m->sizeI - j - 1][m->sizeJ - i - 1])
                {
                    return false;
                }
            }
        }
        return true;
    case MAJOR_DIAGONAL: // \o
        for (int i = 1; i < m->sizeI; i++)
        {
            for (int j = 1; j < m->sizeJ; j++)
            {
                if (m->data[i][j] != m->data[j][i])
                {
                    return false;
                }
            }
        }
        return true;
    }

    return false;
}

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

        for (int j = 0; j < i; i++)
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

bool matrixRead(TMatrix* m, FILE* f)
{
    if (!m || !f)
    {
        return false;
    }

    return _matrixRead(m, f);
}

bool _matrixRead(TMatrix* m, FILE* f)
{
    for (int i = 0; i < m->sizeI; i++)
    {
        for (int j = 0; j < m->sizeJ; j++)
        {
            if (fscanf(f, " %f", &m->data[i][j]) != 1)
            {
                return false;
            }
        }
    }

    return true;
}

bool matrixWrite(TMatrix* matrix, FILE* f)
{
    if (!matrix || !f)
    {
        return false;
    }

    _matrixWrite(matrix, f);

    return true;
}

void _matrixWrite(TMatrix* matrix, FILE* f)
{
    fprintf(f, "%d %d\n", matrix->sizeI, matrix->sizeJ);

    for (int i = 0; i < matrix->sizeI; i++)
    {
        for (int j = 0; j < matrix->sizeJ; j++)
        {
            fprintf(f, "%f ", matrix->data[i][j]);
        }
        fprintf(f, "\n");
    }
}

bool matrixDelete(TMatrix** matrix)
{
    if (!matrix || !*matrix)
    {
        return false;
    }

    _matrixDelete(*matrix);
    *matrix = NULL;

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
