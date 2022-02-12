/*
 * Projekt: Bank-11
 * Autor:   Jakub Antonín Štigler
 * Datum:   2/12/2022
 */

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "queue.h"

bool printLastN(int count);
bool matchBraces(char* str);
void clearIn();

int main(void)
{
    printf("======<<STACK>>=====\n");
    printf("Enter braces to check: ");
    char str[1024];
    scanf("%1023s", str);
    clearIn();
    if (matchBraces(str))
    {
        printf("braces matched succesfully\n");
    }
    else
    {
        printf("failed to match braces\n");
    }

    printf("======<<QUEUE>>=====\n");
    printf("Enter number of last characters to print: ");
    int num = -1;
    scanf("%d", &num);
    clearIn();
    if (num < 0)
    {
        printf("invalid input\n");
        return EXIT_FAILURE;
    }
    printf("Enter the characters: ");
    printLastN(num);

    return EXIT_SUCCESS;
}

bool printLastN(int count)
{
    TQueue* q = queueCreate();
    if (!q)
    {
        return false;
    }

    int readed;
    char r;
    for (readed = 0; scanf("%c", &r) == 1 && r != '\n'; readed++)
    {
        if (!queuePush(q, r))
        {
            return false;
        }
    }

    int prePop = readed - count;

    for (int i = 0; i < prePop && queuePop(q, &r); i++) ;

    while (queuePop(q, &r))
    {
        printf("%c", r);
    }

    queueDelete(&q);

    return true;
}

bool matchBraces(char* str)
{
    TStack* s = stackCreate();
    if (!s)
    {
        return false;
    }

    for (; *str; str++)
    {
        char c;
        switch (*str)
        {
        case '(':
            if (!stackPush(s, '('))
            {
                return false;
            }
            break;
        case '[':
            if (!stackPush(s, '['))
            {
                return false;
            }
            break;
        case '{':
            if (!stackPush(s, '{'))
            {
                return false;
            }
            break;
        case ')':
            stackPop(s, &c);
            if (c != '(')
            {
                return false;
            }
            break;
        case ']':
            stackPop(s, &c);
            if (c != '[')
            {
                return false;
            }
            break;
        case '}':
            stackPop(s, &c);
            if (c != '{')
            {
                return false;
            }
            break;
        }
    }

    int len;
    stackDelete(&s, &len);

    return len == 0;
}

void clearIn()
{
    scanf("%*[^\n]");
    scanf("%*c");
}
