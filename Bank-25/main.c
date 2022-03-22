/*
 * Projekt: Bank-25
 * Autor:   Jakub Antonín Štigler
 * Datum:   3/22/2022
 */

#include <stdio.h>
#include <stdlib.h>

#include "Validator.h"

void clearIn();

int main()
{
    printf("=======<<MAC>>======\n");
    printf("Enter adress: ");
    char str[1024];
    if (scanf("%[^\n]", str) != 1)
    {
        printf("failed to read string\n");
        return EXIT_FAILURE;
    }
    printf(validMAC(str) ? "valid\n" : "invalid\n");

    printf("======<<IPv4>>======\n");
    printf(validIPv4(str) ? "valid\n" : "invalid\n");

    printf("======<<IPv6>>======\n");
    printf(validIPv6(str) ? "valid\n" : "invalid\n");

    printf("======<<EMAIL>>=====\n");
    printf(validEmail(str) ? "valid\n" : "invalid\n");

    return EXIT_SUCCESS;
}

void clearIn()
{
    scanf("%*[^\n]");
    scanf("%*c");
}
