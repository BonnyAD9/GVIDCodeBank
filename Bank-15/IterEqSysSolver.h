#ifndef ITEREQSYSSOLVER_H_INCLUDED
#define ITEREQSYSSOLVER_H_INCLUDED

#include <stdbool.h>

#include "Matrix.h"

bool iessIsEqSystem(TMatrix* m);

bool iessIsDiagonallyDominant(TMatrix* m);

float* iessGSIM(TMatrix* m, const float err);

#endif // ITEREQSYSSOLVER_H_INCLUDED
