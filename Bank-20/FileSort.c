#include "FileSort.h"

#include <stdbool.h>
#include <stdio.h>

void _fsCombine(FILE* in1, FILE* in2, FILE* out);
void _fsCombineTuples(FILE* in1, FILE* in2, FILE* out);
void _fsInOrder(FILE* out, char c1, char c2);
void _fsSplit(FILE* in, FILE* out1, FILE* out2, int tupC);
void _fsCopy(FILE* in, FILE* out);

bool fsCombine(FILE* in1, FILE* in2, FILE* out)
{
    if (!in1 || !in2 || !out)
    {
        return false;
    }

    _fsCombine(in1, in2, out);

    return true;
}

void _fsCombine(FILE* in1, FILE* in2, FILE* out)
{
    char c1, c2;

    bool r1 = fscanf(in1, "%c", &c1) == 1;
    bool r2 = fscanf(in2, "%c", &c2) == 1;

    while (r1 && r2)
    {
        if (c1 < c2)
        {
            fprintf(out, "%c", c1);
            r1 = fscanf(in1, "%c", &c1) == 1;
            continue;
        }
        fprintf(out, "%c", c2);
        r2 = fscanf(in2, "%c", &c2) == 1;
    }

    if (r1 ^ r2)
    {
        FILE* in;
        if (r1)
        {
            fprintf(out, "%c", c1);
            in = in1;
        }
        else
        {
            fprintf(out, "%c", c2);
            in = in2;
        }

        while (fscanf(in, "%c", &c1) == 1)
        {
            fprintf(out, "%c", c1);
        }
    }
}

bool fsCombineTuples(FILE* in1, FILE* in2, FILE* out)
{
    if (!in1 || !in2 || !out)
    {
        return false;
    }

    _fsCombineTuples(in1, in2, out);

    return true;
}

void _fsCombineTuples(FILE* in1, FILE* in2, FILE* out)
{
    char c1, c2;

    bool r1 = fscanf(in1, "%c", &c1) == 1;
    bool r2 = fscanf(in2, "%c", &c2) == 1;

    while (r1 && r2)
    {
        _fsInOrder(out, c1, c2);

        r1 = fscanf(in1, "%c", &c1) == 1;
        r2 = fscanf(in2, "%c", &c2) == 1;
    }

    if (r1 ^ r2)
    {
        FILE* in;
        if (r1)
        {
            in = in1;
        }
        else
        {
            in = in2;
            c1 = c2;
        }

        _fsInOrder(out, c1, c2);

        for (;;)
        {
            switch (fscanf(in, "%c%c", &c1, &c2))
            {
            case 1:
                fprintf(out, "%c", c1);
                return;
            case 2:
                _fsInOrder(out, c1, c2);
                return;
            default:
                return;
            }
        }
    }
}

void _fsInOrder(FILE* out, char c1, char c2)
{
    if (c1 < c2)
    {
        fprintf(out, "%c%c", c1, c2);
    }
    else
    {
        fprintf(out, "%c%c", c2, c1);
    }
}

bool fsSplit(FILE* in, FILE* out1, FILE* out2, int tupC)
{
    if (!in || !out1 || !out2 || tupC <= 0)
    {
        return false;
    }

    _fsSplit(in, out1, out2, tupC);

    return true;
}

void _fsSplit(FILE* in, FILE* out1, FILE* out2, int tupC)
{
    FILE* out[] = { out1, out2 };
    char c;
    bool sec = true;

    for (int i = 0; fscanf(in, "%c", &c) == 1; i++)
    {
        if (i % tupC == 0)
        {
            sec = !sec;
        }

        fprintf(out[sec], "%c", c);
    }
}
