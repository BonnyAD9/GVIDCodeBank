#include "GEM.h"

#include <stdbool.h>

bool _gemCheckMatrix(TMatrix* m);
void _gemForward(TMatrix* m);
TSolCount _gemBackward(TMatrix* m);

TSolCount gem(TMatrix* m)
{
    if (!m || !_gemCheckMatrix(m))
    {
        return ERROR;
    }

    _gemForward(m);
    return _gemBackward(m);
}

bool _gemCheckMatrix(TMatrix* m)
{
    return m->sizeI + 1 == m->sizeJ;
}

void _gemForward(TMatrix* m)
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

TSolCount _gemBackward(TMatrix* m)
{
    for (int i = m->sizeI - 1; i >= 0; i--)
    {
        if (m->data[i][i] == 0)
        {
            return m->data[i][m->sizeJ - 1] == 0 ? INFINIT : ZERO;
        }

        for (int j = i + 1; j < m->sizeJ - 1; j++)
        {
            m->data[i][m->sizeJ - 1] -= m->data[i][j] * m->data[j][m->sizeJ - 1];
            m->data[i][j] = 0;
        }

        m->data[i][m->sizeJ - 1] /= m->data[i][i];
        m->data[i][i] = 1;
    }

    return ONE;
}
