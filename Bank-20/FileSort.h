#ifndef FILESORT_H_INCLUDED
#define FILESORT_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>

bool fsCombine(FILE* in1, FILE* in2, FILE* out);

bool fsCombineTuples(FILE* in1, FILE* in2, FILE* out);

bool fsSplit(FILE* in, FILE* out1, FILE* out2, int tupC);

#endif // FILESORT_H_INCLUDED
