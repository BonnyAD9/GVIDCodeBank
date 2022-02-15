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
    if (argc < 3)
    {
        printf("invalid number of arguments\n");
        return EXIT_FAILURE;
    }
    if (strcmp(argv[1], "user") == 0)
    {
        if (argc != 5)
        {
            printf("invalid number of arguments\n");
            return EXIT_FAILURE;
        }

        FILE* users = fopen(argv[3], "r");
        if (!users)
        {
            printf("couldn't open file '%s'\n", argv[3]);
            return EXIT_FAILURE;
        }

        FILE* emails = fopen(argv[4], "r");
        if (!emails)
        {
            fclose(users);
            printf("couldn't open file '%s'\n", argv[4]);
            return EXIT_FAILURE;
        }

        int res = getUserEmails(users, emails, stdout, argv[2]);
        fclose(users);
        fclose(emails);

        if (res < 0)
        {
            printf("failed to load emails from user '%s'\n", argv[2]);
            return EXIT_FAILURE;
        }

        int id = res & 0x0000ffff;
        int mailCount = res >> 16;
        switch (mailCount)
        {
        case 0:
            printf("user %s with id %4x has no email adress\n", argv[2], id);
            break;
        case 1:
            printf("user %s with id %4x has 1 email adress\n", argv[2], id);
            break;
        default:
            printf("user %s with id %4x has %d email adresses\n", argv[2], id, mailCount);
            break;
        }
    }

    return EXIT_SUCCESS;
}

int getUserEmails(FILE* users, FILE* emails, FILE* out, char* user)
{
    unsigned int userId;
    char str[21];

    do
    {
        if (fscanf(users, " %4x %10s", &userId, str) != 2)
        {
            return -1;
        }
    }
    while (strcmp(str, user) != 0);

    unsigned int id;
    int count = 0;

    while (fscanf(emails, " %4x %20s", &id, str) == 2)
    {
        if (id == userId)
        {
            count++;
            fprintf(out, "%s\n", str);
        }
    }

    return count << 16 | id;
}
