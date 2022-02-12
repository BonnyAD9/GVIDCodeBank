#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdbool.h>

typedef struct TStack TStack;

TStack* stackCreate();

bool stackPush(TStack* s, char item);

bool stackPop(TStack* s, char* outItem);

bool stackDelete(TStack** s, int* outCount);

#endif // STACK_H_INCLUDED
