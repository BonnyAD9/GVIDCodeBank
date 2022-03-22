#include "Validator.h"

#include <stdbool.h>
#include <stdio.h>

bool _validMAC(char* str);
bool _validIPv4(char* str);
bool _validIPv6(char* str, bool sb);
bool _validEmail(char* str);
bool _validLocal(char* str, int* index);
bool _validLocalChar(char c);
bool _validLocalQuoted(char* str, int* index);
bool _validLocalQuotedChar(char c);
bool _validDomain(char* str);
bool _validDomainChar(char c);
bool _validNum(char c);
bool _validHex(char c);
bool _contains(char* str, char c);

bool validMAC(char* str)
{
    if (!str)
    {
        return false;
    }

    return _validMAC(str);
}

bool _validMAC(char* str)
{
    int nums = 0;
    bool useSep = false;
    char sep;
    for (int i = 0; *str && i < 17; str++, i++)
    {
        if (!_validHex(*str))
        {
            if (i == 2)
            {
                switch (*str)
                {
                case '-':
                    sep = '-';
                    useSep = true;
                    continue;
                case ':':
                    sep = ':';
                    useSep = true;
                    continue;
                default:
                    return false;
                }
            }

            if (useSep && (i + 1) % 3 == 0 && *str == sep)
            {
                continue;
            }

            return false;
        }

        if (useSep && (i + 1) % 3 == 0)
        {
            return false;
        }

        nums++;
    }

    return !*str && nums == 12;
}

bool validIPv4(char* str)
{
    if (!str)
    {
        return false;
    }

    return _validIPv4(str);
}

bool _validIPv4(char* str)
{
    unsigned int i1, i2, i3, i4;
    if (sscanf(str, "%u.%u.%u.%u", &i1, &i2, &i3, &i4) != 4)
    {
        return false;
    }

    return i1 < 256 && i2 < 256 && i3 < 256 && i4 < 256;
}

bool validIPv6(char* str)
{
    if (!str)
    {
        return false;
    }

    return _validIPv6(str, false);
}

bool _validIPv6(char* str, bool allowSb)
{
    int c = 0;
    for (; *str; str++)
    {
        if (allowSb && *str == ']' && str[1] == 0)
        {
            str++;
            break;
        }

        int i;
        for (i = 0; *str && _validHex(*str); str++, i++) ;

        if (i > 4)
        {
            return false;
        }

        if (*str == ':')
        {
            c++;
        }
        else
        {
            break;
        }
    }

    return !*str && c == 7;
}

bool validEmail(char* str)
{
    if (!str)
    {
        return false;
    }

    return _validEmail(str);
}

bool _validEmail(char* str)
{
    int index;
    return _validLocal(str, &index) &&
           _validDomain(&str[index + 1]);
}

bool _validLocal(char* str, int* index)
{
    if (*str == '"')
    {
        return _validLocalQuoted(str, index);
    }

    if (*str == '@' || *str == '.')
    {
        return false;
    }

    bool lastDot = false;
    int i;
    for (i = 0; *str && *str != '@'; str++, i++)
    {
        if (i > 64)
        {
            return false;
        }

        if (*str == '.')
        {
            if (lastDot)
            {
                return false;
            }

            lastDot = true;
            continue;
        }

        if (!_validLocalChar(*str))
        {
            return false;
        }
        lastDot = false;
    }

    *index = i;
    return !lastDot && i <= 64;
}

bool _validLocalChar(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || _contains("!#$%&'*+-/=?^_`{|}~", c);
}

bool _validLocalQuoted(char* str, int* index)
{
    str++;
    if (*str == '@')
    {
        return false;
    }

    for (int i = 0; *str; str++, i++)
    {
        if (i + 1 > 64)
        {
            return false;
        }

        if (*str == '"')
        {
            *index = i + 2;
            return str[1] == '@';
        }

        if (!_validLocalQuotedChar(*str))
        {
            return false;
        }
    }

    return false;
}

bool _validLocalQuotedChar(char c)
{
    return (c >= 32 || c == '\t') && c != '\127';
}

bool _validDomain(char* str)
{
    if (*str == '[')
    {
        str++;
        if (_validIPv6(str, true))
        {
            return true;
        }
        unsigned int i1, i2, i3, i4;
        if (sscanf(str, "%u.%u.%u.%u]", &i1, &i2, &i3, &i4) != 4)
        {
            return false;
        }

        return (i1 < 256 && i2 < 256 && i3 < 256 && i4 < 256);
    }

    if (*str == '.' || *str == '-')
    {
        return false;
    }

    int lastDot = 0;
    bool allnum = true;
    int i;
    for (i = 0; *str; str++, i++)
    {
        if (i > 255 || lastDot > 63 || !_validDomainChar(*str))
        {
            return false;
        }

        if ((*str == '.' || *str == '-') && ((lastDot == 0) || str[1] == 0))
        {
            return false;
        }

        if (*str == '.' && str[-1] == '-')
        {
            return false;
        }

        if (*str == '.')
        {
            lastDot = 0;
            allnum = true;
            continue;
        }

        lastDot++;

        if (!_validNum(*str))
        {
            allnum = false;
        }
    }

    return !allnum;
}

bool _validDomainChar(char c)
{
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '-' || c == '.';
}

bool _validNum(char c)
{
    return c >= '0' && c <= '9';
}

bool _validHex(char c)
{
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

bool _contains(char* str, char c)
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
