#include "Search.h"

int _searchSeq(float* arr, const int length, float value);
int _searchSeqWStop(float* arr, const int length);
int _searchSortSeq(float* arr, const int length, float value);
int _searchSortSeqWStop(float* arr, const int length);
int _searchSortBinary(float* arr, const int length, float value);

int searchSeq(float* arr, const int length, float value)
{
    if (!arr || length < 0)
    {
        return S_ERROR;
    }

    return _searchSeq(arr, length, value);
}

int _searchSeq(float* arr, const int length, float value)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }

    return S_NOT_PRESENT;
}

int searchSeqWStop(float* arr, const int length, float value)
{
    if (!arr || length < 0)
    {
        return S_ERROR;
    }

    arr[length] = value;
    return _searchSeqWStop(arr, length);
}

int _searchSeqWStop(float* arr, const int length)
{
    int i;
    for (i = 0; arr[i] != arr[length]; i++) ;
    return i == length ? S_NOT_PRESENT : i;
}

int searchSortSeq(float* arr, const int length, float value)
{
    if (!arr || length < 0)
    {
        return S_ERROR;
    }

    return _searchSortSeq(arr, length, value);
}

int _searchSortSeq(float* arr, const int length, float value)
{
    int i;
    for (i = 0; i < length && arr[i] < value; i++) ;
    return i < length && arr[i] == value ? i : S_NOT_PRESENT;
}

int searchSortSeqWStop(float* arr, const int length, float value)
{
    if (!arr || length < 0)
    {
        return S_ERROR;
    }

    arr[length] = value;
    return _searchSortSeqWStop(arr, length);
}

int _searchSortSeqWStop(float* arr, const int length)
{
    int i;
    for (i = 0; arr[i] < arr[length]; i++) ;
    return i == length ? S_NOT_PRESENT : i;
}

int searchSortBinary(float* arr, const int length, float value)
{
    if (!arr || length < 0)
    {
        return S_ERROR;
    }

    return _searchSortBinary(arr, length, value);
}

int _searchSortBinary(float* arr, const int length, float value)
{
    if (length == 1)
    {
        return arr[0] == value ? 0 : S_NOT_PRESENT;
    }
    else if (length <= 0)
    {
        return S_NOT_PRESENT;
    }

    int p = length / 2;
    if (arr[p] == value)
    {
        return p;
    }
    if (arr[p] < value)
    {
        int index = _searchSortBinary(&arr[p + 1], length - p - 1, value);
        return index < 0 ? index : index + p + 1;
    }
    return _searchSortBinary(arr, p, value);
}
