#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdbool.h>

typedef struct _TStack TStack;

TStack* stackCreate();

bool stackAdd(TStack* s, char item);

bool tryStackPop(TStack* s, char* value);

bool stackDelete(TStack** s, int* len);

#endif // STACK_H_INCLUDED
