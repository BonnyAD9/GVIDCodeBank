#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED

#define S_ERROR -2
#define S_NOT_PRESENT -1

int searchSeq(float* arr, const int length, float value);

int searchSeqWStop(float* arr, const int length, float value);

int searchSortSeq(float* arr, const int length, float value);

int searchSortSeqWStop(float* arr, const int length, float value);

int searchSortBinary(float* arr, const int length, float value);

#endif // SEARCH_H_INCLUDED
