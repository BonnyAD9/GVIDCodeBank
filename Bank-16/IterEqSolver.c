#include "IterEqSolver.h"

#include <stdbool.h>
#include <math.h>

float _iesHorner(float* coef, const int length, float num);
float _iesHalfingInterval(TFunc fun, float err, float a, float b);
float _iesRegulaFalsi(TFunc fuc, float err, float a, float b);
float _iesNewton(TFunc fun, TFunc deriv, float err, float a, const int lim);

float iesHorner(float* coef, const int length, float num)
{
    if (!coef || length <= 0)
    {
        return NAN;
    }

    return _iesHorner(coef, length, num);
}

float _iesHorner(float* coef, const int length, float num)
{
    float res = coef[0];
    for (int i = 1; i < length; i++)
    {
        res = res * num + coef[i];
    }
    return res;
}

float iesHalfingInterval(TFunc fun, float err, float a, float b)
{
    return _iesHalfingInterval(fun, fabs(err), a, b);
}

float _iesHalfingInterval(TFunc fun, float err, float a, float b)
{
    float p[] = { a, b };
    float v[] = { fun(a), fun(b) };

    if (v[0] * v[1] > 0)
        return NAN;

    while (fabs(v[0]) > err && fabs(v[1]) > err)
    {
        float np = (p[0] + p[1]) / 2;
        float nv = fun(np);

        bool rb = v[1] * nv > 0;

        p[rb] = np;
        v[rb] = nv;
    }

    return fabs(v[0]) < fabs(v[1]) ? p[0] : p[1];
}

float iesRegulaFalsi(TFunc fun, float err, float a, float b)
{
    return _iesRegulaFalsi(fun, fabs(err), a, b);
}

float _iesRegulaFalsi(TFunc fun, float err, float a, float b)
{
    float p[] = { a, b };
    float v[] = { fun(a), fun(b) };

    if (v[0] * v[1] > 0)
        return NAN;

    while (fabs(v[0]) > err && fabs(v[1]) > err)
    {
        float np = (p[0] * v[1] - p[1] * v[0]) / (v[1] - v[0]);
        float nv = fun(np);

        bool rb = v[1] * nv > 0;

        p[rb] = np;
        v[rb] = nv;
    }

    return fabs(v[0]) < fabs(v[1]) ? p[0] : p[1];
}

float iesNewton(TFunc fun, TFunc deriv, float err, float a)
{
    return _iesNewton(fun, deriv, fabs(err), a, 100);
}

float _iesNewton(TFunc fun, TFunc deriv, float err, float a, const int lim)
{
    int i = 0;
    for (float v = fun(a); i < lim && fabs(v) > err; v = fun(a), i++)
    {
        float d = deriv(a);
        a -= v / d;
    }
    return i == lim ? NAN : a;
}
