#ifndef GEM_H_INCLUDED
#define GEM_H_INCLUDED

#include "Matrix.h"

typedef enum
{
    ERROR = -1,
    ZERO = 0,
    ONE = 1,
    INFINIT = 2,
} TSolCount;

TSolCount gem(TMatrix* m);

#endif // GEM_H_INCLUDED
