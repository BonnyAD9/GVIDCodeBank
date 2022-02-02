/*
 * Projekt: Bank-3
 * Autor:   Jakub Antonín Štigler
 * Datum:   2/2/2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef bool (*FFilter)(bool b);

bool readData(FILE* in, char* name, const int nameSize, float* height, bool* active);
void heightAverage(FILE* in, FFilter filter);
void higherThan(FILE* in, FFilter filter, float lim);
void list(FILE* in, FFilter filter, FILE* inAll, FILE* inY, FILE* inN);
bool all(bool b) { return true; }
bool activeOnly(bool b) { return b; }
bool inactiveOnly(bool b) { return !b; }

//int main(void)
int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("invalid number of arguments\n");
        return EXIT_FAILURE;
    }

    FILE* f = fopen(argv[1], "r");
    if (!f)
    {
        printf("couldn't open file '%s'\n", argv[1]);
        return EXIT_FAILURE;
    }

    int index = 3;

    FFilter filter = all;
    if (strcmp(argv[2], "-y") == 0)
    {
        filter = activeOnly;
    }
    else if (strcmp(argv[2], "-n") == 0)
    {
        filter = inactiveOnly;
    }
    else
    {
        index = 2;
    }

    if (strcmp(argv[index], "avg") == 0)
    {
        if (argc != index + 1)
        {
            printf("invalid number of arguments for 'avg'");
            fclose(f);
            return EXIT_FAILURE;
        }
        heightAverage(f, filter);
    }
    else if (strcmp(argv[index], "higher") == 0)
    {
        if (argc != index  + 2)
        {
            printf("invalid number of arguments for 'higher'");
            fclose(f);
            return EXIT_FAILURE;
        }
        float lim = atof(argv[index + 1]);
        higherThan(f, filter, lim);
    }
    else if (strcmp(argv[index], "list") == 0)
    {
        if (argc != index + 4)
        {
            printf("invalid number of arguments for 'list'");
            fclose(f);
            return EXIT_FAILURE;
        }
        FILE* inall = fopen(argv[index + 1], "w");
        if (!inall)
        {
            fclose(f);
            printf("couldn't write to file '%s'", argv[index + 1]);
            return EXIT_FAILURE;
        }
        FILE* iny = fopen(argv[index + 2], "w");
        if (!iny)
        {
            fclose(f);
            fclose(inall);
            printf("couldn't write to file '%s'", argv[index + 2]);
            return EXIT_FAILURE;
        }
        FILE* inn = fopen(argv[index + 3], "w");
        if (!inn)
        {
            fclose(f);
            fclose(inall);
            fclose(iny);
            printf("couldn't write to file '%s'", argv[index + 3]);
            return EXIT_FAILURE;
        }
        list(f, filter, inall, iny, inn);
        fclose(inall);
        fclose(iny);
        fclose(inn);
    }
    else
    {
        printf("invalid argument '%s'\n", argv[2]);
        fclose(f);
        return EXIT_FAILURE;
    }

    fclose(f);

    return EXIT_SUCCESS;
}

bool readData(FILE* in, char* name, const int nameSize, float* height, bool* active)
{
    if (!fgets(name, nameSize, in))
    {
        return false;
    }

    char a = 'n';

    if (fscanf(in, " %f", height) < 0 || fscanf(in, " %c", &a) < 0)
    {
        return false;
    }
    *active = a == 'y';
    fscanf(in, "%*[^\n]");
    fscanf(in ,"%*c");

    return true;
}

void heightAverage(FILE* in, FFilter filter)
{
    const int nameSize = 21;
    char name[nameSize];
    float height = 0.0f;
    bool active = false;

    int count = 0;
    float sum = 0.0f;

    while (readData(in, name, nameSize, &height, &active))
    {
        if (filter(active))
        {
            sum += height;
            count++;
        }
    }

    printf("average height: %f", sum / (float)count);
}

void higherThan(FILE* in, FFilter filter, float lim)
{
    const int nameSize = 21;
    char name[nameSize];
    float height = 0.0f;
    bool active = false;

    while (readData(in, name, nameSize, &height, &active))
    {
        if (filter(active))
        {
            if (height > lim)
            {
                printf("%s %f ", name, height);
                if (active)
                {
                    printf("yes\n");
                }
                else
                {
                    printf("no\n");
                }
            }
        }
    }
}

void list(FILE* in, FFilter filter, FILE* inAll, FILE* inY, FILE* inN)
{
    const int nameSize = 21;
    char name[nameSize];
    float height = 0.0f;
    bool active = false;

    while (readData(in, name, nameSize, &height, &active))
    {
        if (filter(active))
        {
            fprintf(inAll, "%s %f ", name, height);
            if (active)
            {
                fprintf(inAll, "yes\n");
            }
            else
            {
                fprintf(inAll, "no\n");
            }
        }
        if (active)
        {
            fprintf(inY, "%s %f yes\n", name, height);
        }
        else
        {
            fprintf(inN, "%s %f no\n", name, height);
        }
    }
}
