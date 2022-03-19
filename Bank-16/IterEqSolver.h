#ifndef ITEREQSOLVER_H_INCLUDED
#define ITEREQSOLVER_H_INCLUDED

#include <stdbool.h>

typedef float (*TFunc)(float num);

float iesHorner(float* coef, const int length, float num);

float iesHalfingInterval(TFunc fun, float err, float a, float b);

float iesRegulaFalsi(TFunc fuc, float err, float a, float b);

float iesNewton(TFunc fun, TFunc deriv, float err, float a);

#endif // ITEREQSOLVER_H_INCLUDED
