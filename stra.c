/*------------------------------------------------------------*/
/* stra.c                                                     */
/* Author: Vicky Feng                                         */
/*------------------------------------------------------------*/
#include "str.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*------------------------------------------------------------*/

size_t Str_getLength(const char acSrc[])
{
    size_t uLength = 0;
    assert(acSrc != NULL);
    while (acSrc[uLength] != '\0')
        uLength++;
    return uLength;
}

/*------------------------------------------------------------*/

char *Str_copy(char acDst[], const char acSrc[])
{
    size_t i = 0;
    assert(acSrc != NULL);
    assert(acDst != NULL);

    /* copy each char of source string to destination string and 
    increment array index until end of soruce string is reached*/

    while (acSrc[i] != '\0')
    {
        acDst[i] = acSrc[i];
        i++;
    }

    acDst[i] = '\0';

    return acDst;
}

/*------------------------------------------------------------*/

char *Str_concat(char acDst[], const char acSrc[])
{
    size_t i = 0;
    size_t j = 0;
    assert(acDst != NULL);
    assert(acSrc != NULL);

    /* find the index of the end of string acDst and append 
    string acSrc starting at that index */
    while (acDst[i] != '\0')
    {
        i++;
    }

    while (acSrc[j] != '\0')
    {
        acDst[i] = acSrc[j];
        i++;
        j++;
    }

    acDst[i] = '\0';
    return acDst;
}
/*------------------------------------------------------------*/

int Str_compare(const char s1[], const char s2[])
{
    size_t i = 0;
    assert(s1 != NULL);
    assert(s2 != NULL);

    while (s1[i] == s2[i])
    {
        if (s1[i] == '\0')
            return 0;
        i++;
    }

    if (s1[i] < s2[i])
        return -1;
    else
        return 1;
}

/*------------------------------------------------------------*/

char *Str_search(const char haystack[], const char needle[])
{

    size_t i;
    size_t j;
    size_t sizeHaystack = Str_getLength(haystack);
    size_t sizeNeedle = Str_getLength(needle);
    size_t matchIndex = NULL;

    assert(haystack != NULL);
    assert(needle != NULL);

    if (needle[0] == '\0')
        return (char *)haystack;

    /* If a char in haystack matches the first char of needle,
    compare every subsequent char. If the end of needle is reached,
    return the index of the first char of needle, otherwise if a char 
    in haystack differs from needle, break out of the for loop */
    for (i = 0; i <= sizeHaystack; i++)
    {
        if (haystack[i] == needle[0])
        {
            for (j = 0; j <= sizeNeedle; j++)
            {
                if (needle[j] == '\0')
                {
                    matchIndex = i;
                    return (char *)&haystack[matchIndex];
                }

                else if (haystack[i + j] != needle[j])
                {
                    break;
                }
            }
        }
    }

    return NULL; /* if the end of haystack is reached and return
     condition has not been executed, then no needle was found */
}
