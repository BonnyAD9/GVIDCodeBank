#ifndef SMALLESTSQUARES_H_INCLUDED
#define SMALLESTSQUARES_H_INCLUDED

#include <stdbool.h>

#include "Matrix.h"

typedef float (*TFunc)(float);

float ssSquareDistances(TMatrix* m, TFunc func);

bool ssConstant(TMatrix* values, float* a);

bool ssLinear(TMatrix* values, float* a, float* b);

#endif // SMALLESTSQUARES_H_INCLUDED
