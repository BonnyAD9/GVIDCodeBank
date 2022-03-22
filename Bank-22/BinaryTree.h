#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>

typedef struct _btTNode _btTNode;

#define BinaryTree _btTNode**
#define btCountMask 0xFC000000
#define btCountShift 26

typedef enum
{
    INORDER,
    PREORDER,
    POSTORDER,
    INREVERSE,
} TPrintStrategy;

int btMin(BinaryTree bt);

int btMax(BinaryTree bt);

bool btPrint(BinaryTree bt, FILE* out, TPrintStrategy strategy);

long btKeyPosition(BinaryTree bt, int key);

bool btPrintSmaller(BinaryTree bt, FILE* out, int key, TPrintStrategy strategy);

bool btPrintLarger(BinaryTree bt, FILE* out, int key, TPrintStrategy strategy);

bool btAddKey(BinaryTree bt, int key);

bool btDelete(BinaryTree* bt);

bool btDeleteKey(BinaryTree bt, int key);

int btCount(BinaryTree bt);

int btDepth(BinaryTree bt);

BinaryTree btCreate();

#endif // BINARYTREE_H_INCLUDED
