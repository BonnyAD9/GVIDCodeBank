#include "IterEqSysSolver.h"

#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#include "Matrix.h"

bool _iessIsEqSystem(TMatrix* m);
bool _iessIsDiagonallyDominant(TMatrix* m);
bool _iessGSIM(TMatrix* m, const float err, float* res, const int lim);
float _iessNewVal(TMatrix* m, float* res, int iPos);
void _iessPrepareGSIM(TMatrix* m);

bool iessIsEqSystem(TMatrix* m)
{
    return m && _iessIsEqSystem(m);
}

bool _iessIsEqSystem(TMatrix* m)
{
    return m->sizeI + 1 == m->sizeJ;
}

bool iessIsDiagonallyDominant(TMatrix* m)
{
    return iessIsEqSystem(m) && _iessIsDiagonallyDominant(m);
}

bool _iessIsDiagonallyDominant(TMatrix* m)
{
    for (int i = 0; i < m->sizeI; i++)
    {
        float sum = 0;
        for (int j = 0; j < m->sizeJ - 1; j++)
        {
            if (j != i)
            {
                sum += m->data[i][j];
            }
        }

        if (fabs(sum) >= fabs(m->data[i][i]))
        {
            return false;
        }
    }

    return true;
}

float* iessGSIM(TMatrix* m, const float err)
{
    if (!iessIsDiagonallyDominant(m))
    {
        return NULL;
    }

    float* res = calloc(m->sizeI, sizeof(float));
    if (!res)
    {
        return NULL;
    }

    _iessPrepareGSIM(m);

    if (!_iessGSIM(m, fabs(err), res, 1000))
    {
        free(res);
        return NULL;
    }

    return res;
}

bool _iessGSIM(TMatrix* m, const float err, float* res, const int lim)
{
    bool cont = true;
    int l;

    for (l = 0; cont && l < lim; l++)
    {
        cont = false;
        for (int i = 0; i < m->sizeI; i++)
        {
            float old = res[i];
            res[i] = _iessNewVal(m, res, i);
            cont |= fabs(res[i] - old) > err;
        }
    }

    return l != lim;
}

float _iessNewVal(TMatrix* m, float* res, int iPos)
{
    float sum = m->data[iPos][m->sizeJ - 1];

    for (int j = 0; j < m->sizeJ - 1; j++)
    {
        sum -= m->data[iPos][j] * res[j];
    }

    return sum;
}

void _iessPrepareGSIM(TMatrix* m)
{
    for (int i = 0; i < m->sizeI; i++)
    {
        float d = m->data[i][i];
        m->data[i][i] = 0;
        for (int j = 0; j < m->sizeJ; j++)
        {
            m->data[i][j] /= d;
        }
    }
}
