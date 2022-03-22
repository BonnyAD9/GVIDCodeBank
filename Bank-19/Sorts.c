#include "Sorts.h"

#include <stdbool.h>
#include <stdlib.h>

void _sortInsert(float* arr, const int length);
void _sortInsertWStop(float* arr, const int length);
void _sortSelect(float* arr, const int length);
void _sortBubble(float* arr, const int length);
void _sortMerge(float* arr, float* buf, const int length, bool toSame);
void _sortSwap(float* a, float* b);

bool sortInsert(float* arr, const int length)
{
    if (!arr || length <= 0)
    {
        return false;
    }

    _sortInsert(arr, length);

    return true;
}

void _sortInsert(float* arr, const int length)
{
    for (int i = 1; i < length; i++)
    {
        float save = arr[i];
        int j;
        for (j = i; j > 0 && arr[j - 1] > save; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = save;
    }
}

bool sortInsertWStop(float* arr, const int length)
{
    if (!arr || length <= 0)
    {
        return false;
    }

    _sortInsertWStop(arr, length);

    return true;
}

void _sortInsertWStop(float* arr, const int length)
{
    for (int i = length - 2; i >= 0; i--)
    {
        arr[length] = arr[i];
        int j;
        for (j = i; arr[j + 1] < arr[length]; j++)
        {
            arr[j] = arr[j + 1];
        }
        arr[j] = arr[length];
    }
}

bool sortSelect(float* arr, const int length)
{
    if (!arr || length <= 0)
    {
        return false;
    }

    _sortSelect(arr, length);

    return true;
}

void _sortSelect(float* arr, const int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int mi = i;
        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[mi])
            {
                mi = j;
            }
        }

        _sortSwap(&arr[mi], &arr[i]);
    }
}

bool sortBubble(float* arr, const int length)
{
    if (!arr || length <= 0)
    {
        return false;
    }

    _sortBubble(arr, length);

    return true;
}

void _sortBubble(float* arr, const int length)
{
    int l = length - 1;
    for (int i = 0; i < length; i++)
    {
        int nl = l;
        for (int j = 0; j < l; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                _sortSwap(&arr[j], &arr[j + 1]);
                nl = j;
            }
        }
        l = nl;
    }
}

bool sortMerge(float* arr, const int length)
{
    if (!arr || length <= 0)
    {
        return false;
    }

    float buf[length];

    _sortMerge(arr, buf, length, true);

    return true;
}

void _sortMerge(float* arr, float* buf, const int length, bool toSame)
{
    if (length == 1)
    {
        if (toSame)
        {
            return;
        }
        buf[0] = arr[0];
        return;
    }

    int ll = length / 2;
    int rl = length - ll;

    _sortMerge(arr, buf, ll, !toSame);
    _sortMerge(&arr[ll], &buf[ll], rl, !toSame);

    float* la;
    float* ra;
    float* write;

    if (toSame)
    {
        la = buf;
        ra = &buf[ll];
        write = arr;
    }
    else
    {
        la = arr;
        ra = &arr[ll];
        write = buf;
    }

    for (int li = 0, ri = 0; li + ri < length;)
    {
        if (ri >= rl || (li < ll && la[li] < ra[ri]))
        {
            write[li + ri] = la[li];
            li++;
            continue;
        }
        write[li + ri] = ra[ri];
        ri++;
    }
}

void _sortSwap(float* a, float* b)
{
    float h = *a;
    *a = *b;
    *b = h;
}
