#ifndef EQSYSSOLVER_H_INCLUDED
#define EQSYSSOLVER_H_INCLUDED

#include <stdbool.h>

#include "Matrix.h"

typedef enum
{
    ERROR = -1,
    ZERO = 0,
    ONE = 1,
    INFINITY = 2,
} TSolCount;

bool essGEMForward(TMatrix* m);

TSolCount essGEMSolCount(TMatrix* m);

bool essGEMAfterForward(TMatrix* m);

TSolCount essGEMBackRow(TMatrix* m, int iRow);

bool essGJAfterForward(TMatrix* m);

TSolCount essGJBack(TMatrix* m);

#endif // EQSYSSOLVER_H_INCLUDED
