/*------------------------------------------------------------*/
/* strp.c                                                     */
/* Author: Vicky Feng                                         */
/*------------------------------------------------------------*/
#include "str.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*------------------------------------------------------------*/

size_t Str_getLength(const char *pcSrc)
{
    const char *pcEnd;
    assert(pcSrc != NULL);
    pcEnd = pcSrc;
    while (*pcEnd != '\0')
        pcEnd++;
    return (size_t)(pcEnd - pcSrc);
}

/*------------------------------------------------------------*/

char *Str_copy(char *pcDst, const char *pcSrc)
{
    char *current = pcDst; /* char pointer for current position */

    assert(pcDst != NULL);
    assert(pcSrc != NULL);

    /* copy each char of source string to destination string and 
    increment pointer until end of source string is reached */
    while (*pcSrc != '\0')
    {
        *current = *pcSrc;
        current++;
        pcSrc++;
    }

    *current = '\0';

    return pcDst;
}

/*------------------------------------------------------------*/

char *Str_concat(char *pcDst, const char *pcSrc)
{

    char *current = pcDst;
    assert(pcDst != NULL);
    assert(pcSrc != NULL);

    /* find the end of string acDst and append 
    string acSrc starting at that position */
    while (*current != '\0')
        current++;

    while (*pcSrc != '\0')
    {
        *current = *pcSrc;
        current++;
        pcSrc++;
    }

    *current = '\0';
    return pcDst;
}

/*------------------------------------------------------------*/

int Str_compare(const char *s1, const char *s2)
{
    assert(s1 != NULL);
    assert(s2 != NULL);

    while (*s1 == *s2)
    {
        if (*s1 == '\0')
            return 0;
        s1++;
        s2++;
    }

    if (*s1 < *s2)
        return -1;
    else
        return 1;
}

/*------------------------------------------------------------*/

char *Str_search(const char *haystack, const char *needle)
{
    const char *firstOccur = NULL;
    const char *startNeedle = needle;
    assert(haystack != NULL);
    assert(needle != NULL);

    if (*needle == '\0')
    {
        return (char *)haystack;
    }

    /* If a char in haystack matches the first char of needle,
    maintain a pointer to that char in haystack and compare every
    subsequent char. */

    while (*haystack != '\0')
    {
        if (*haystack == *needle)
        {
            firstOccur = haystack;

            while (*needle != '\0')
            {
                if (*haystack == *needle)
                {
                    haystack++;
                    needle++;
                }
                else
                {
                    /* if char in haystack differs from needle, reset 
                    pointers to haystack, needle and first occurrence 
                    of needle */
                    haystack = firstOccur;
                    needle = startNeedle;
                    firstOccur = NULL;
                    break;
                }
            }
        }

        haystack++;

        if (*needle == '\0')
        {
            return (char *)firstOccur;
        }
    }
    return NULL; /* if the end of haystack is reached, 
    needle was not found */
}
