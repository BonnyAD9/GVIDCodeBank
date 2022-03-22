/*
 * Projekt: Bank-22
 * Autor:   Jakub Antonín Štigler
 * Datum:   3/22/2022
 */

#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"

void clearIn();

int main()
{
    printf("=======<<MIN>>======\n");
    printf("Enter values of the tree: ");
    BinaryTree bt = btCreate();
    if (!bt)
    {
        printf("failed to create binary tree\n");
        return EXIT_FAILURE;
    }
    char c;
    int key;
    while (scanf("%d%c", &key, &c) == 2)
    {
        if (!btAddKey(bt, key))
        {
            printf("duplicate: %d\n", key);
        }
        if (c == '\n')
        {
            break;
        }
    }
    printf("min: %d\n", btMin(bt));

    printf("=======<<MAX>>======\n");
    printf("max: %d\n", btMax(bt));

    printf("=====<<INORDER>>====\n");
    btPrint(bt, stdout, INORDER);

    printf("====<<INREVERSE>>===\n");
    btPrint(bt, stdout, INREVERSE);

    printf("=======<<ADD>>======\n");
    printf("Enter key to add: ");
    if (scanf(" %d", &key) != 1)
    {
        printf("failed to read new key\n");
        return EXIT_FAILURE;
    }
    clearIn();
    if (!btAddKey(bt, key))
    {
        printf("that key already exists\n");
    }
    btPrint(bt, stdout, INORDER);

    printf("======<<FIND>>======\n");
    printf("Enter key to find: ");
    if (scanf(" %d", &key) != 1)
    {
        printf("failed to read key\n");
        return EXIT_FAILURE;
    }
    clearIn();
    long path = btKeyPosition(bt, key);
    if (path < 0)
    {
        printf("this key is not in the tree\n");
    }
    else
    {
        long count = path >> btCountShift;
        printf("position fo the key in the tree: ");
        for (int i = 0; i < count; i++)
        {
            printf(path & 1 ? "R" : "L");
            path >>= 1;
        }
        printf("\n");
    }

    printf("=====<<SMALLER>>====\n");
    btPrintSmaller(bt, stdout, key, INORDER);

    printf("=====<<LARGER>>=====\n");
    btPrintLarger(bt, stdout, key, INORDER);

    printf("=====<<REMOVE>>=====\n");
    printf("Enter key to remove: ");
    if (scanf(" %d", &key) != 1)
    {
        printf("couldn't read key\n");
    }
    clearIn();
    if (!btDeleteKey(bt, key))
    {
        printf("couldn't delete that key\n");
    }
    else
    {
        btPrint(bt, stdout, INORDER);
    }

    printf("=====<<WEIGHT>>=====\n");
    printf("count: %d\n", btCount(bt));

    printf("=====<<HEIGHT>>=====\n");
    printf("depth: %d\n", btDepth(bt));

    printf("=====<<DELETE>>=====\n");
    btDelete(&bt);

    return EXIT_SUCCESS;
}

void clearIn()
{
    scanf("%*[^\n]");
    scanf("%*c");
}
