/*
 * Projekt: Bank-21
 * Autor:   Jakub Antonín Štigler
 * Datum:   3/22/2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Search.h"

bool isSorted(float* arr, const int length);
void clearIn();

int main()
{
    printf("=======<<SEQ>>======\n");
    printf("Enter length of array: ");
    int length;
    if (scanf(" %d", &length) != 1)
    {
        printf("failed to read length of array\n");
        return EXIT_FAILURE;
    }
    clearIn();
    printf("Enter the array: ");
    float arr[length + 1];
    for (int i = 0; i < length; i++)
    {
        if (scanf(" %f", &arr[i]) != 1)
        {
            printf("failed to read the array\n");
            return EXIT_FAILURE;
        }
    }
    clearIn();
    printf("Enter value to search for: ");
    float value;
    if (scanf(" %f", &value) != 1)
    {
        printf("failed to read value to search for\n");
        return EXIT_FAILURE;
    }
    clearIn();
    int index = searchSeq(arr, length, value);
    switch (index)
    {
    case S_ERROR:
        printf("invalid length\n");
        return EXIT_FAILURE;
    case S_NOT_PRESENT:
        printf("value is not present in the array\n");
        break;
    default:
        printf("index: %d\n", index);
        break;
    }

    printf("====<<SEQ STOP>>====\n");
    if ((index = searchSeqWStop(arr, length, value)) < 0)
    {
        printf("value is not present in the array\n");
    }
    else
    {
        printf("index: %d\n", index);
    }

    printf("===<<SEQ SORTED>>===\n");
    if (!isSorted(arr, length))
    {
        printf("array is not sorted\n");
        return EXIT_SUCCESS;
    }
    if ((index = searchSortSeq(arr, length, value)) < 0)
    {
        printf("value is not present in the array\n");
    }
    else
    {
        printf("index: %d\n", index);
    }

    printf("==<<SEQ STOP SORTED>>==\n");
    if ((index = searchSortSeqWStop(arr, length, value)) < 0)
    {
        printf("value is not present in the array\n");
    }
    else
    {
        printf("index: %d\n", index);
    }

    printf("=====<<BINARY>>=====\n");
    if ((index = searchSortBinary(arr, length, value)) < 0)
    {
        printf("value is not present in the array\n");
    }
    else
    {
        printf("index: %d\n", index);
    }

    return EXIT_SUCCESS;
}

bool isSorted(float* arr, const int length)
{
    for (int i = 1; i < length; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            return false;
        }
    }
    return true;
}

void clearIn()
{
    scanf("%*[^\n]");
    scanf("%*c");
}
