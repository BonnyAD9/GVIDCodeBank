#include "BinaryTree.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct _btTNode
{
    int key;
    _btTNode* left;
    _btTNode* right;
};

#define Node _btTNode*

int _btMin(Node n);
int _btMax(Node n);
void _btPrint(BinaryTree bt, FILE* out, TPrintStrategy strategy);
Node _btCreateNode(int key, Node left, Node right);
long _btKeyPosition(Node n, int key);
void _btPrintSmaller(Node n, FILE* out, int key, TPrintStrategy strategy);
void _btPrintLarger(Node n, FILE* out, int key, TPrintStrategy strategy);
void _btDelete(BinaryTree bt);
bool _btDeleteKey(BinaryTree bt, int key);
int _btCount(Node n);
int _btDepth(Node n);
void _btPrintNode(Node node, FILE* out, TPrintStrategy strategy);
BinaryTree _btLocateNode(BinaryTree bt, int key);
bool _btAddKey(BinaryTree bt, int key);
bool _btAddNode(BinaryTree bt, Node node);
void _btDeleteNode(Node node, bool recursive);

int btMin(BinaryTree bt)
{
    if (!bt || !*bt)
    {
        return -1;
    }

    return _btMin(*bt);
}

int _btMin(Node n)
{
    return n->left ? _btMin(n->left) : n->key;
}

int btMax(BinaryTree bt)
{
    if (!bt || !*bt)
    {
        return -1;
    }

    return _btMax(*bt);
}

int _btMax(Node n)
{
    return n->right ? _btMax(n->right) : n->key;
}

bool btPrint(BinaryTree bt, FILE* out, TPrintStrategy strategy)
{
    if (!bt || !out)
    {
        return false;
    }

    _btPrint(bt, out, strategy);

    return true;
}

void _btPrint(BinaryTree bt, FILE* out, TPrintStrategy strategy)
{
    _btPrintNode(*bt, out, strategy);
    fprintf(out, "\n");
}

long btKeyPosition(BinaryTree bt, int key)
{
    if (!bt)
    {
        return -1;
    }

    return _btKeyPosition(*bt, key);
}

long _btKeyPosition(Node n, int key)
{
    if (!n)
    {
        return -1;
    }
    if (n->key == key)
    {
        return 0;
    }

    bool right = n->key < key;
    long pos = right ? _btKeyPosition(n->right, key) : _btKeyPosition(n->left, key);
    if (pos < 0)
    {
        return -1;
    }
    long count = (pos & btCountMask) >> btCountShift;
    long path = pos & ~btCountMask;

    count++;
    path = path << 1 | right;

    return count << btCountShift | path;
}

bool btPrintSmaller(BinaryTree bt, FILE* out, int key, TPrintStrategy strategy)
{
    if (!bt || !out)
    {
        return false;
    }

    _btPrintSmaller(*bt, out, key, strategy);
    fprintf(out, "\n");

    return true;
}

void _btPrintSmaller(Node n, FILE* out, int key, TPrintStrategy strategy)
{
    if (!n)
    {
        return;
    }

    if (n->key == key)
    {
        _btPrintNode(n->left, out, strategy);
        return;
    }

    if (n->key > key)
    {
        _btPrintSmaller(n->left, out, key, strategy);
        return;
    }

    switch (strategy)
    {
    case INORDER:
        _btPrintNode(n->left, out, strategy);
        fprintf(out, "%d ", n->key);
        _btPrintSmaller(n->right, out, key, strategy);
        return;
    case PREORDER:
        fprintf(out, "%d ", n->key);
        _btPrintNode(n->left, out, strategy);
        _btPrintSmaller(n->right, out, key, strategy);
        return;
    case POSTORDER:
        _btPrintNode(n->left, out, strategy);
        _btPrintSmaller(n->right, out, key, strategy);
        fprintf(out, "%d ", n->key);
        return;
    default:
        _btPrintSmaller(n->right, out, key, strategy);
        fprintf(out, "%d ", n->key);
        _btPrintNode(n->left, out, strategy);
        return;
    }
}

bool btPrintLarger(BinaryTree bt, FILE* out, int key, TPrintStrategy strategy)
{
    if (!bt || !out)
    {
        return false;
    }

    _btPrintLarger(*bt, out, key, strategy);
    fprintf(out, "\n");

    return true;
}

void _btPrintLarger(Node n, FILE* out, int key, TPrintStrategy strategy)
{
    if (!n)
    {
        return;
    }

    if (n->key == key)
    {
        _btPrintNode(n->right, out, strategy);
        return;
    }

    if (n->key < key)
    {
        _btPrintLarger(n->right, out, key, strategy);
        return;
    }

    switch (strategy)
    {
    case INORDER:
        _btPrintLarger(n->left, out, key, strategy);
        fprintf(out, "%d ", n->key);
        _btPrintNode(n->right, out, strategy);
        return;
    case PREORDER:
        fprintf(out, "%d ", n->key);
        _btPrintLarger(n->left, out, key, strategy);
        _btPrintNode(n->right, out, strategy);
        return;
    case POSTORDER:
        _btPrintLarger(n->left, out, key, strategy);
        _btPrintNode(n->right, out, strategy);
        fprintf(out, "%d ", n->key);
        return;
    default:
        _btPrintNode(n->right, out, strategy);
        fprintf(out, "%d ", n->key);
        _btPrintLarger(n->left, out, key, strategy);
        return;
    }
}

bool btAddKey(BinaryTree bt, int key)
{
    if (!bt)
    {
        return false;
    }

    return _btAddKey(bt, key);
}

Node _btCreateNode(int key, Node left, Node right)
{
    Node node = malloc(sizeof(Node));
    if (!node)
    {
        return NULL;
    }

    node->key = key;
    node->left = left;
    node->right = right;

    return node;
}

bool btDelete(BinaryTree* bt)
{
    if (!bt || !*bt)
    {
        return false;
    }

    _btDelete(*bt);
    *bt = NULL;

    return true;
}

void _btDelete(BinaryTree bt)
{
    if (*bt)
    {
        _btDeleteNode(*bt, true);
    }

    free(bt);
}

bool btDeleteKey(BinaryTree bt, int key)
{
    if (!bt)
    {
        return false;
    }

    return _btDeleteKey(bt, key);
}

bool _btDeleteKey(BinaryTree bt, int key)
{
    BinaryTree loc = _btLocateNode(bt, key);

    Node toRem = *loc;

    if (!toRem)
    {
        return false;
    }

    Node left = toRem->left;
    Node right = toRem->right;

    _btDeleteNode(toRem, false);

    *loc = left;
    if (!right)
    {
        return true;
    }

    _btAddNode(loc, right);

    return true;
}

int btCount(BinaryTree bt)
{
    if (!bt)
    {
        return -1;
    }

    return _btCount(*bt);
}

int _btCount(Node bt)
{
    return bt ? _btCount(bt->left) + _btCount(bt->right) + 1 : 0;
}

int btDepth(BinaryTree bt)
{
    if (!bt)
    {
        return -1;
    }

    return _btDepth(*bt);
}

int _btDepth(Node n)
{
    if (!n)
    {
        return 0;
    }

    int left = _btDepth(n->left);
    int right = _btDepth(n->right);

    return left > right ? left + 1 : right + 1;
}

BinaryTree btCreate()
{
    return calloc(1, sizeof(Node));
}

void _btPrintNode(Node node, FILE* out, TPrintStrategy strategy)
{
    if (!node)
    {
        return;
    }

    switch (strategy)
    {
    case INORDER:
        _btPrintNode(node->left, out, strategy);
        fprintf(out, "%d ", node->key);
        _btPrintNode(node->right, out, strategy);
        return;
    case PREORDER:
        fprintf(out, "%d ", node->key);
        _btPrintNode(node->left, out, strategy);
        _btPrintNode(node->right, out, strategy);
        return;
    case POSTORDER:
        _btPrintNode(node->left, out, strategy);
        _btPrintNode(node->right, out, strategy);
        fprintf(out, "%d ", node->key);
        return;
    default:
        _btPrintNode(node->right, out, strategy);
        fprintf(out, "%d ", node->key);
        _btPrintNode(node->left, out, strategy);
        return;
    }
}

bool _btAddKey(BinaryTree bt, int key)
{
    BinaryTree t = _btLocateNode(bt, key);
    if (*t)
    {
        return false;
    }

    *t = _btCreateNode(key, NULL, NULL);

    return *t;
}

bool _btAddNode(BinaryTree bt, Node node)
{
    BinaryTree t = _btLocateNode(bt, node->key);
    if (*t)
    {
        return false;
    }

    *t = node;

    return true;
}

BinaryTree _btLocateNode(BinaryTree bt, int key)
{
    Node n = *bt;
    if (!n || n->key == key)
    {
        return bt;
    }

    if (n->key > key)
    {
        return _btLocateNode(&n->left, key);
    }
    return _btLocateNode(&n->right, key);
}

void _btDeleteNode(Node node, bool recursive)
{
    if (!recursive)
    {
        free(node);
        return;
    }

    if (node->left)
    {
        _btDeleteNode(node->left, true);
    }
    if (node->right)
    {
        _btDeleteNode(node->right, true);
    }

    free(node);
}
