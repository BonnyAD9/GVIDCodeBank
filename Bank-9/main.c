/*
 * Projekt: Bank-9
 * Autor:   Jakub Antonín Štigler
 * Datum:   2/12/2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool generateSentace(char** rules, int ruleCount, int depth, char first);
int indexOfAnyStartsWith(char** strs, int strCount, char c);
int ruleType(char* rule, char* nonterminals);
int countAny(char* str, char* chars);
bool containsAny(char* str, char* chars);
bool contains(char* str, char c);
void clearIn();

int main()
{
    printf("====<<RULE TYPE>>===\n");
    printf("Enter grammar rule: ");
    char rule[1024];
    scanf("%1023[^\n]", rule);
    clearIn();
    printf("Enter nonterminals: ");
    char nonterminals[1024];
    scanf("%1023[^\n]", nonterminals);
    clearIn();
    switch (ruleType(rule, nonterminals))
    {
    case 0:
        printf("Recursively enumerable or Context-sensitive grammar\n");
        break;
    case 2:
        printf("Context insensitive grammar\n");
        break;
    case 3:
        printf("Regular grammar\n");
        break;
    default:
        printf("Invalid grammar");
        break;
    }

    printf("=====<<SENTANCE>>====\n");
    const int ruleCount = 4;
    char* rules[] = {
        "SaA",
        "AbB",
        "BcA",
        "Bc",
    };
    char s = 'S';
    printf("rules: \n");
    for (int i = 0; i < ruleCount; i++)
    {
        printf("%c->%s\n", rules[i][0], &rules[i][1]);
    }
    printf("generation:\n");
    const int depth = 5;
    for (int i = 1; i <= depth; i++)
    {
        printf("%d: ", i);
        if (!generateSentace(rules, ruleCount, i, s))
        {
            printf("failed");
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}

bool generateSentace(char** rules, int ruleCount, int depth, char first)
{
    if (depth <= 0)
    {
        printf("%c", first);
        return true;
    }

    int index = indexOfAnyStartsWith(rules, ruleCount, first);
    if (index == -1)
    {
        return false;
    }

    for (char* str = &rules[index][1]; *str; str++)
    {
        if (indexOfAnyStartsWith(rules, ruleCount, *str) >= 0)
        {
            generateSentace(rules, ruleCount, depth - 1, *str);
            continue;
        }
        printf("%c", *str);
    }
    return true;
}

int indexOfAnyStartsWith(char** strs, int strCount, char c)
{
    for (int i = 0; i < strCount; i++)
    {
        if (strs[i][0] == c)
        {
            return i;
        }
    }

    return -1;
}

int ruleType(char* rule, char* nonterminals)
{
    char part1[1024];
    char part2[1024];

    if (sscanf(rule, "%1023[^-]->%1023s", part1, part2) != 2)
    {
        return -1;
    }

    if (!containsAny(part1, nonterminals))
    {
        return -1;
    }

    if (part1[1] != 0 || part2[0] == 0)
    {
        return 0;
    }

    switch (countAny(part2, nonterminals))
    {
    case 0:
        return 3;
    case 1:
        if (contains(nonterminals, part2[0]) || contains(nonterminals, part2[strlen(part2) - 1]))
        {
            return 3;
        }
        return 2;
    default:
        return 2;
    }
}

int countAny(char* str, char* chars)
{
    int count = 0;

    for (; *str; str++)
    {
        if (contains(chars, *str))
        {
            count++;
        }
    }

    return count;
}

bool containsAny(char* str, char* chars)
{
    for (; *str; str++)
    {
        if (contains(chars, *str))
        {
            return true;
        }
    }

    return false;
}

bool contains(char* str, char c)
{
    for (; *str; str++)
    {
        if (*str == c)
        {
            return true;
        }
    }

    return false;
}

void clearIn()
{
    scanf("%*[^\n]");
    scanf("%*c");
}
