#include "SmallestSquares.h"

#include <stdbool.h>
#include <math.h>

#include "Matrix.h"
#include "GEM.h"

float _ssSquareDistances(TMatrix* m, TFunc func);
float _ssConstant(TMatrix* values);
bool _ssLinear(TMatrix* values, float* a, float* b);

float ssSquareDistances(TMatrix* m, TFunc func)
{
    if (!m)
    {
        return NAN;
    }

    return _ssSquareDistances(m, func);
}

float _ssSquareDistances(TMatrix* m, TFunc func)
{
    float sum = 0;
    for (int i = 0; i < m->sizeJ; i++)
    {
        float num = m->data[1][i] - func(m->data[0][i]);
        sum += num * num;
    }
    return sum;
}

bool ssConstant(TMatrix* values, float* a)
{
    if (!values || !a)
    {
        return false;
    }

    *a = _ssConstant(values);

    return true;
}

float _ssConstant(TMatrix* values)
{
    float sa = 0;
    for (int i = 0; i < values->sizeJ; i++)
    {
        sa += values->data[1][i];
    }

    return sa / values->sizeJ;
}

bool ssLinear(TMatrix* values, float* a, float* b)
{
    if (!values || (!a && !b))
    {
        return false;
    }

    float val;
    if (!a)
    {
        a = &val;
    }
    else if (!b)
    {
        b = &val;
    }

    return _ssLinear(values, a, b);
}

bool _ssLinear(TMatrix* values, float* a, float* b)
{
    TMatrix* m = matrixCreate(2, 3);
    if (!m)
    {
        return false;
    }

    float sa = 0, sb = 0, sc = 0, sd = 0;
    for (int i = 0; i < values->sizeJ; i++)
    {
        sa += values->data[0][i] * values->data[0][i];
        sb += values->data[0][i];
        sc += values->data[0][i] * values->data[1][i];
        sd += values->data[1][i];
    }

    m->data[0][0] = sa; m->data[0][1] = sb;            m->data[0][2] = sc;
    m->data[1][0] = sb; m->data[1][1] = values->sizeJ; m->data[1][2] = sd;

    if (gem(m) != ONE)
    {
        matrixDelete(&m);
        return false;
    }

    *a = m->data[0][2];
    *b = m->data[1][2];

    matrixDelete(&m);
    return true;
}
