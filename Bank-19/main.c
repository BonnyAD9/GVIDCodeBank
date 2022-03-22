/*
 * Projekt: Bank-19
 * Autor:   Jakub Antonín Štigler
 * Datum:   3/21/2022
 */

#include <stdio.h>
#include <stdlib.h>

#include "Sorts.h"

void printArr(float* arr, const int length);
void cpyArr(float* arr1, float* arr2, const int length);
void clearIn();

int main()
{
    printf("=====<<INSERT>>=====\n");
    printf("Enter length of array: ");
    int length;
    if (scanf(" %d", &length) != 1 || length <= 0)
    {
        printf("couldn't read length\n");
        return EXIT_FAILURE;
    }
    clearIn();
    float arr[length];
    printf("Enter the array: ");
    for (int i = 0; i < length; i++)
    {
        if (scanf(" %f", &arr[i]) != 1)
        {
            printf("couldn't read array\n");
            return EXIT_FAILURE;
        }
    }
    clearIn();
    float sor[length + 1];
    cpyArr(arr, sor, length);
    sortInsert(sor, length);
    printArr(sor, length);

    printf("===<<INSERT STOP>>==\n");
    cpyArr(arr, sor, length);
    sortInsertWStop(sor, length);
    printArr(sor, length);

    printf("=====<<SELECT>>=====\n");
    cpyArr(arr, sor, length);
    sortSelect(sor, length);
    printArr(sor, length);

    printf("=====<<BUBBLE>>=====\n");
    cpyArr(arr, sor, length);
    sortBubble(sor, length);
    printArr(sor, length);

    printf("======<<MERGE>>=====\n");
    cpyArr(arr, sor, length);
    sortMerge(sor, length);
    printArr(sor, length);

    return 0;
}

void printArr(float* arr, const int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

void cpyArr(float* arr1, float* arr2, const int length)
{
    for (int i = 0; i < length; i++)
    {
        arr2[i] = arr1[i];
    }
}

void clearIn()
{
    scanf("%*[^\n]");
    scanf("%*c");
}
