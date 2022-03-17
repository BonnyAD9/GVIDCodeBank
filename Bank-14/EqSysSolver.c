#include "EqSysSolver.h"

#include <stdbool.h>

#include "Matrix.h"

bool _essIsValid(TMatrix* m);
void _essGEMForward(TMatrix* m);
TSolCount _essGEMSolCount(TMatrix* m);
bool _essGEMAfterForward(TMatrix* m);
TSolCount _essGEMBackRow(TMatrix* m, int iRow);
bool _essGJAfterForward(TMatrix* m);
TSolCount _essGJBack(TMatrix* m);

bool _essIsValid(TMatrix* m)
{
    return m && m->sizeI + 1 == m->sizeJ;
}

bool essGEMForward(TMatrix* m)
{
    if (!_essIsValid(m))
    {
        return false;
    }

    _essGEMForward(m);

    return true;
}

void _essGEMForward(TMatrix* m)
{
    for (int i = 1; i < m->sizeI; i++)
    {
        for (int ii = i; ii < m->sizeI; ii++)
        {
            for (int j = i; j < m->sizeJ; j++)
            {
                m->data[ii][j] = m->data[ii][j] * m->data[i - 1][i - 1] - m->data[i - 1][j] * m->data[ii][i - 1];
            }

            m->data[ii][i - 1] = 0;
        }
    }
}

TSolCount essGEMSolCount(TMatrix* m)
{
    if (!_essIsValid(m))
    {
        return ERROR;
    }

    return _essGEMSolCount(m);
}

TSolCount _essGEMSolCount(TMatrix* m)
{
    TSolCount sc;
    for (int i = m->sizeI - 1; i >= 0; i--)
    {
        sc = _essGEMBackRow(m, i);
        if (sc != ONE)
        {
            return sc;
        }
    }

    return ONE;
}

bool essGEMAfterForward(TMatrix* m)
{
    if (!_essIsValid(m))
    {
        return false;
    }

    return _essGEMAfterForward(m);
}

bool _essGEMAfterForward(TMatrix* m)
{
    for (int i = 1; i < m->sizeI; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (m->data[i][j] != 0)
            {
                return false;
            }
        }
    }

    return true;
}

TSolCount essGEMBackRow(TMatrix* m, int iRow)
{
    if (!_essIsValid(m) || iRow < 0 || iRow >= m->sizeI)
    {
        return ERROR;
    }

    return _essGEMBackRow(m, iRow);
}

TSolCount _essGEMBackRow(TMatrix* m, int iRow)
{
    for (int j = iRow + 1; j < m->sizeJ - 1; j++)
    {
        m->data[iRow][m->sizeJ - 1] -= m->data[iRow][j] * m->data[j][m->sizeJ - 1];
        m->data[iRow][j] = 0;
    }

    if (m->data[iRow][iRow] == 0)
    {
        return m->data[iRow][m->sizeJ - 1] == 0 ? INFINITY : ZERO;
    }

    m->data[iRow][m->sizeJ - 1] /= m->data[iRow][iRow];
    m->data[iRow][iRow] = 1;

    return ONE;
}

bool essGJAfterForward(TMatrix* m)
{
    if (!_essIsValid(m))
    {
        return false;
    }

    return _essGJAfterForward(m);
}

bool _essGJAfterForward(TMatrix* m)
{
    for (int i = 0; i < m->sizeI; i++)
    {
        for (int j = 0; j < m->sizeJ - 1; j++)
        {
            if (m->data[i][j] != 0 && i != j)
                return false;
        }
    }
    return true;
}

TSolCount essGJBack(TMatrix* m)
{
    if (!_essIsValid(m))
    {
        return ERROR;
    }

    return _essGJBack(m);
}

TSolCount _essGJBack(TMatrix* m)
{
    for (int i = 0; i < m->sizeI; i++)
    {
        if (m->data[i][i] == 0)
        {
            return m->data[i][m->sizeJ - 1] == 0 ? INFINITY : ZERO;
        }

        m->data[i][m->sizeJ - 1] /= m->data[i][i];
        m->data[i][i] = 1;
    }

    return ONE;
}
