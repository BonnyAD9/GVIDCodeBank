#include "queue.h"

#include <stdlib.h>
#include <stdbool.h>

typedef struct _TNode _TNode;

struct _TNode
{
    _TNode* next;
    char item;
};

struct TQueue
{
    _TNode* take;
    _TNode* add;
};

void _queueDelete(TQueue* q);
bool _queuePop(TQueue* q, char* outItem);
bool _queuePush(TQueue* q, char item);

bool queueDelete(TQueue** q)
{
    if (!q || !*q)
    {
        return false;
    }

    _queueDelete(*q);

    return true;
}

void _queueDelete(TQueue* q)
{
    while (queuePop(q, NULL)) ;
    free(q);
}

bool queuePop(TQueue* q, char* outItem)
{
    if (!q)
    {
        return false;
    }

    char item;
    if (!outItem)
    {
        outItem = &item;
    }

    return _queuePop(q, outItem);
}

bool _queuePop(TQueue* q, char* outItem)
{
    if (!q->take)
    {
        return false;
    }

    _TNode* node = q->take;
    *outItem = node->item;

    q->take = node->next;
    if (!node->next)
    {
        q->add = NULL;
    }

    free(node);

    return true;
}

bool queuePush(TQueue* q, char item)
{
    if (!q)
    {
        return false;
    }

    return _queuePush(q, item);
}

bool _queuePush(TQueue* q, char item)
{
    _TNode* node = calloc(1, sizeof(_TNode));
    if (!node)
    {
        return false;
    }

    node->item = item;
    if (q->add)
    {
        q->add->next = node;
    }
    q->add = node;

    if (!q->take)
    {
        q->take = node;
    }

    return true;
}

TQueue* queueCreate()
{
    return calloc(1, sizeof(TQueue));
}
