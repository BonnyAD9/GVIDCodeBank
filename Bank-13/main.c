/*
 * Projekt: Bank-13
 * Autor:   Jakub Antonín Štigler
 * Datum:   2/15/2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum
{
    NONE      = 0x0,
    ABOVE_AVG = 0x1,
    BELOW_AVG = 0x2,
    ACTIVE    = 0x4,
    INACTIVE  = 0x8,
} TFilter;

int getVulcanos(FILE* in, FILE* out, TFilter flags);
float getVulcanosAverage(FILE* in);
bool readVulcano(FILE* in, char* name, float* height, bool* active);
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
    else if (strcmp(argv[1], "vulcanos") == 0)
    {
        FILE* in = fopen(argv[2], "r");
        if (!in)
        {
            printf("couldn't open file '%s'\n", argv[2]);
            return EXIT_FAILURE;
        }

        TFilter flags = NONE;

        argv += 2;
        while (*++argv)
        {
            if (strcmp(*argv, "active") == 0)
            {
                flags |= ACTIVE;
            }
            else if (strcmp(*argv, "inactive") == 0)
            {
                flags |= INACTIVE;
            }
            else if (strcmp(*argv, "above-avg") == 0)
            {
                flags |= ABOVE_AVG;
            }
            else if (strcmp(*argv, "below-avg") == 0)
            {
                flags |= BELOW_AVG;
            }
            else
            {
                printf("invalid arguemnt '%s'\n", *argv);
                fclose(in);
                return EXIT_FAILURE;
            }
        }

        getVulcanos(in, stdout, flags);

        fclose(in);
    }
    else
    {
        printf("invalid argument '%s'\n", argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int getVulcanos(FILE* in, FILE* out, TFilter flags)
{
    long pos = ftell(in);

    float avg = getVulcanosAverage(in);

    fseek(in, pos, SEEK_SET);

    bool aAvg  = flags & ABOVE_AVG;
    bool bAvg  = flags & BELOW_AVG;
    bool isAvg = aAvg || bAvg;
    bool yAct  = flags & ACTIVE;
    bool nAct  = flags & INACTIVE;
    bool act   = yAct || nAct;

    char name[21];
    float height;
    bool active;

    int count = 0;

    while (readVulcano(in, name, &height, &active))
    {
        if ((!isAvg || (aAvg && height > avg) || (bAvg && height < avg)) && (!act || (yAct && active) || (nAct && !active)))
        {
            fprintf(out, "%s %f %s\n", name, height, active ? "yes" : "no");
            count++;
        }
    }

    return count;
}

float getVulcanosAverage(FILE* in)
{
    char name[21];
    float height;
    bool active;

    float sum = 0.0f;
    int count;

    for (count = 0; readVulcano(in, name, &height, &active); count++)
    {
        sum += height;
    }

    return sum / count;
}

bool readVulcano(FILE* in, char* name, float* height, bool* active)
{
    char c;
    if (fscanf(in, " %20s %f %c %*[^\n]", name, height, &c) < 3)
        return false;
    *active = c == 'y' || c == 'a' || c == 'Y' || c == 'A';
    return true;
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
