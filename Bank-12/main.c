/*
 * Projekt: Bank-12
 * Autor:   Jakub Antonín Štigler
 * Datum:   2/12/2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum
{
    NONE = 0,
    REPLACE = 1,
    COMBINE = 2,
    COUNT = 3,
    FIND = 4,
};

void find(FILE* in, FILE* out, int value);
void countWords(FILE* in, FILE* out);
void combine(FILE* in, FILE* in2, FILE* out);
void replace(FILE* in, FILE* out, char find, char* replace);

int main(int argc, char** argv)
{
    FILE* out = stdout;
    FILE* in = NULL;
    FILE* in2 = NULL;
    bool closeOut = false;
    char r = '#';
    char* rBy;
    int action = NONE;
    int toFind = -1;
    if (argc < 2)
    {
        printf("invalid number of arguments\n");
        return EXIT_FAILURE;
    }
    while (*++argv)
    {
        if (strcmp(*argv, "in") == 0)
        {
            if (!argv++)
            {
                printf("missing argument after 'in'\n");
                goto onFail;
            }
            FILE* f = fopen(*argv, "r");
            if (!f)
            {
                printf("couldn't open file '%s'\n", *argv);
                goto onFail;
            }
            if (in)
            {
                fclose(in);
            }
            in = f;
        }
        else if (strcmp(*argv, "replace") == 0)
        {
            action = REPLACE;
            if (!argv++)
            {
                printf("missing argument after 'replace'\n");
                goto onFail;
            }
            r = (*argv)[0];
        }
        else if (strcmp(*argv, "by") == 0)
        {
            if (!argv++)
            {
                printf("missing argument after 'by'\n");
                goto onFail;
            }
            rBy = *argv;
        }
        else if (strcmp(*argv, "into") == 0)
        {
            if (!argv++)
            {
                printf("missing argument after 'into'\n");
                goto onFail;
            }
            FILE* f = fopen(*argv, "w");
            if (!f)
            {
                printf("couldn't open file '%s'\n", *argv);
                goto onFail;
            }
            if (closeOut)
            {
                fclose(out);
            }
            closeOut = true;
            out = f;
        }
        else if (strcmp(*argv, "combine") == 0)
        {
            action = COMBINE;
            if (!argv++)
            {
                printf("missing argument after 'combine'\n");
                goto onFail;
            }
            FILE* f = fopen(*argv, "r");
            if (!f)
            {
                printf("couldn't open file '%s'\n", *argv);
                goto onFail;
            }
            if (in)
            {
                fclose(in);
            }
            in = f;
        }
        else if (strcmp(*argv, "and") == 0)
        {
            if (!argv++)
            {
                printf("missing argument after 'and'\n");
                goto onFail;
            }
            FILE* f = fopen(*argv, "r");
            if (!f)
            {
                printf("couldn't open file '%s'\n", *argv);
                goto onFail;
            }
            if (in2)
            {
                fclose(in);
            }
            in2 = f;
        }
        else if (strcmp("count-words", *argv) == 0)
        {
            action = COUNT;
        }
        else if (strcmp("find", *argv) == 0)
        {
            action = FIND;
            if (!argv++)
            {
                printf("missing argument after 'find'\n");
                goto onFail;
            }
            toFind = atoi(*argv);
            if (toFind <= 0)
            {
                printf("invalid value to find '%s'", *argv);
                goto onFail;
            }
        }
        else
        {
            printf("invalid argument '%s'\n", *argv);
            goto onFail;
        }
    }

    switch (action)
    {
    case REPLACE:
        if (!in)
        {
            printf("no input file specified\n");
            goto onFail;
        }
        if (!rBy)
        {
            printf("no string to replace with specified\n");
            goto onFail;
        }
        replace(in, out, r, rBy);
        break;
    case COMBINE:
        if (!in)
        {
            printf("first input file not specified\n");
            goto onFail;
        }
        if (!in2)
        {
            printf("second input file not specified\n");
            goto onFail;
        }
        combine(in, in2, out);
        break;
    case COUNT:
        if (!in)
        {
            printf("input file not specified\n");
            goto onFail;
        }
        countWords(in, out);
        break;
    case FIND:
        if (!in)
        {
            printf("input file not specified\n");
            goto onFail;
        }
        if (toFind == 0)
        {
            printf("no value to fnd specified\n");
            goto onFail;
        }
        find(in, out, toFind);
        break;
    default:
        printf("no action specified\n");
        goto onFail;
    }

    if (in)
    {
        fclose(in);
    }
    if (in2)
    {
        fclose(in2);
    }
    if (closeOut)
    {
        fclose(out);
    }
    return EXIT_SUCCESS;

onFail:
    if (in)
    {
        fclose(in);
    }
    if (in2)
    {
        fclose(in2);
    }
    if (closeOut)
    {
        fclose(out);
    }
    return EXIT_FAILURE;
}

void find(FILE* in, FILE* out, int value)
{
    int pos = 0;
    do
    {
        int num;
        if (fscanf(in, "%d", &num) == 1)
        {
            pos++;
            if (num == value)
            {
                fprintf(out, "value '%d' is on the position %d\n", value, pos);
                return;
            }
        }
    } while (fscanf(in, "%*c") == 0);
    fprintf(out, "value '%d' is not present\n", value);
}

void countWords(FILE* in, FILE* out)
{
    int wordCount = 0;
    char c = 'k';
    do
    {
        if (c == '\n')
        {
            fprintf(out, "%d\n", wordCount);
            wordCount = 0;
        }
        if (fscanf(in, "%*[^\n \t]") == 0)
        {
            wordCount++;
        }
    } while (fscanf(in, "%c", &c) == 1);
    if (wordCount != 0)
    {
        fprintf(out, "%d", wordCount);
    }
}

void combine(FILE* in, FILE* in2, FILE* out)
{
    FILE* read = in;
    bool isIn = true;
    char c;
    while (fscanf(read, "%c", &c) == 1)
    {
        fprintf(out, "%c", c);
        if (c == '\n')
        {
            read = isIn ? in2 : in;
            isIn = !isIn;
        }
    }

    if (c != '\n')
    {
        fprintf(out, "\n");
    }

    read = isIn ? in2 : in;
    while (fscanf(read, "%c", &c) == 1)
    {
        fprintf(out, "%c", c);
    }
}

void replace(FILE* in, FILE* out, char find, char* replace)
{
    char c;
    while (fscanf(in, "%c", &c) == 1)
    {
        if (c == find)
        {
            fprintf(out, "%s", replace);
            continue;
        }
        fprintf(out, "%c", c);
    }
}
