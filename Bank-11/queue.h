#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdbool.h>

typedef struct TQueue TQueue;

TQueue* queueCreate();

bool queuePush(TQueue* q, char item);

bool queuePop(TQueue* q, char* outItem);

bool queueDelete(TQueue** q);

#endif // QUEUE_H_INCLUDED
