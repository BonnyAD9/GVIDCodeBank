#include "stack.h"

#include <stdlib.h>
#include <stdbool.h>

typedef struct _TNode _TNode;

struct _TNode
{
    _TNode* next;
    char item;
};

struct TStack
{
    _TNode* root;
};

int _stackDelete(TStack* s);
bool _stackPop(TStack* s, char* outItem);
bool _stackPush(TStack* s, char item);

bool stackDelete(TStack** s, int* outCount)
{
    if (!s || !*s)
    {
        return false;
    }

    if (outCount)
    {
        *outCount = _stackDelete(*s);
    }
    else
    {
        _stackDelete(*s);
    }

    return true;
}

int _stackDelete(TStack* s)
{
    int count;
    for (count = 0; stackPop(s, NULL); count++) ;

    free(s);

    return count;
}

bool stackPop(TStack* s, char* outItem)
{
    if (!s)
    {
        return false;
    }

    char item;
    if (!outItem)
    {
        outItem = &item;
    }

    return _stackPop(s, outItem);
}

bool _stackPop(TStack* s, char* outItem)
{
    _TNode* node = s->root;
    if (!node)
    {
        return false;
    }

    s->root = node->next;
    *outItem = node->item;
    free(node);

    return true;
}

bool stackPush(TStack* s, char item)
{
    if (!s)
    {
        return false;
    }

    return _stackPush(s, item);
}

bool _stackPush(TStack* s, char item)
{
    _TNode* node = malloc(sizeof(_TNode));
    if (!node)
    {
        return false;
    }

    node->item = item;
    node->next = s->root;
    s->root = node;

    return true;
}

TStack* stackCreate()
{
    return calloc(1, sizeof(TStack));
}
