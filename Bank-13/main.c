/*
 * Projekt: Bank-13
 * Autor:   Jakub Antonín Štigler
 * Datum:   2/15/2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getUserEmails(FILE* users, FILE* emails, FILE* out, char* user);

int main(int argc, char **argv)
{
    return 0;
}

int getUserEmails(FILE* users, FILE* emails, FILE* out, char* user)
{
    unsigned short userId;
    char str[21];

    do
    {
        if (fscanf(users, " %x %10s", &userId, str) != 2)
        {
            return -1;
        }
    }
    while (strcmp(str, user) != 0);

    unsigned short id;
    int count = 0;

    while (fscanf(emails, " %x %20s", &id, str) == 2)
    {
        if (id == userId)
        {
            count++;
            fprintf(out, "%s\n", str);
        }
    }

    return count << 16 | id;
}
