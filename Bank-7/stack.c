#include "stack.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct _tNode _TNode;

struct _tNode
{
    _TNode* next;
    char value;
};

struct _TStack
{
    _TNode* node;
};

void _stackDelete(TStack* s, int *len);
bool _tryStackPop(TStack* s, char* value);
bool _stackAdd(TStack* s, char item);

bool stackDelete(TStack** s, int* len)
{
    if (!s || !*s)
    {
        return false;
    }

    int l;
    if (!len)
    {
        len = &l;
    }

    _stackDelete(*s, len);
    return true;
}

void _stackDelete(TStack* s, int* len)
{
    for (*len = 0; _tryStackPop(s, NULL); (*len)++) ;
    free(s);
}

bool tryStackPop(TStack* s, char* value)
{
    if (!s)
    {
        return false;
    }

    return _tryStackPop(s, value);
}

bool _tryStackPop(TStack* s, char* value)
{
    if (!s->node)
    {
        return false;
    }

    _TNode* node = s->node;
    s->node = node->next;

    if (value)
    {
        *value = node->value;
    }

    free(node);

    return true;
}

bool stackAdd(TStack* s, char item)
{
    if (!s)
    {
        return false;
    }

    return _stackAdd(s, item);
}

bool _stackAdd(TStack* s, char item)
{
    _TNode* node = malloc(sizeof(_TNode));
    if (!node)
    {
        return false;
    }

    node->next = s->node;
    node->value = item;
    s->node = node;

    return true;
}

TStack* stackCreate()
{
    return calloc(1, sizeof(TStack));
}

