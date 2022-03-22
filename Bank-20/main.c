/*
 * Projekt: Bank-20
 * Autor:   Jakub Antonín Štigler
 * Datum:   3/22/2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FileSort.h"

int main(int argc, char** argv)
{
    if (argc != 5 && argc != 6)
    {
        printf("invlaid number of arguments\n");
        return EXIT_FAILURE;
    }

    FILE* f1 = NULL;
    FILE* f2 = NULL;
    FILE* f3 = NULL;

    if (strcmp(argv[1], "combine") == 0)
    {
        if (argc != 5)
        {
            printf("invalid number of arguments for combine\n");
        }
        f1 = fopen(argv[2], "r");
        f2 = fopen(argv[3], "r");
        f3 = fopen(argv[4], "w");
        if (!f1 || !f2 || !f3)
        {
            printf("couldn't open one of files\n");
            goto onFail;
        }
        fsCombine(f1, f2, f3);
    }
    else if (strcmp(argv[1], "tuple") == 0)
    {
        if (argc != 5)
        {
            printf("invalid number of arguments for tuple\n");
        }
        f1 = fopen(argv[2], "r");
        f2 = fopen(argv[3], "r");
        f3 = fopen(argv[4], "w");
        if (!f1 || !f2 || !f3)
        {
            printf("couldn't open one of files\n");
            goto onFail;
        }
        fsCombineTuples(f1, f2, f3);
    }
    else if (strcmp(argv[1], "split") == 0)
    {
        if (argc != 6)
        {
            printf("invalid number of arguments for split\n");
        }
        f1 = fopen(argv[2], "r");
        f2 = fopen(argv[3], "w");
        f3 = fopen(argv[4], "w");
        if (!f1 || !f2 || !f3)
        {
            printf("couldn't open one of files");
            goto onFail;
        }
        int tupC = atoi(argv[5]);
        if (!fsSplit(f1, f2, f3, tupC))
        {
            printf("invalid size of tuple\n");
            goto onFail;
        }
    }
    else
    {
        printf("invalid action\n");
        return EXIT_FAILURE;
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    printf("success\n");
    return EXIT_SUCCESS;

onFail:
    if (f1)
    {
        fclose(f1);
    }
    if (f2)
    {
        fclose(f2);
    }
    if (f3)
    {
        fclose(f3);
    }
    return EXIT_FAILURE;
}
