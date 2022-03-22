#ifndef VALIDATOR_H_INCLUDED
#define VALIDATOR_H_INCLUDED

#include <stdbool.h>

bool validMAC(char* str);

bool validIPv4(char* str);

bool validIPv6(char* str);

bool validEmail(char* str);

#endif // VALIDATOR_H_INCLUDED
