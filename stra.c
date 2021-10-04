/*------------------------------------------------------------*/
/* stra.c                                                     */
/* Author: Vicky Feng                                         */
/*------------------------------------------------------------*/
#include "str.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/*------------------------------------------------------------*/

size_t Str_getLength(const char acSrc[])
{
    size_t uLength = 0;
    assert(acSrc != NULL);
    while (acSrc[uLength] != '\0')
        uLength++;
    return uLength;
}

char *Str_copy(char acDst[], const char acSrc[])
{
    int i = 0;
    assert(acSrc != NULL);
    assert(acDst != NULL);

    while (acSrc[i] != '\0')
    {
        acDst[i] = acSrc[i];
        i++;
    }

    acDst[i] = '\0';

    return acDst;
}

char *Str_concat(char acDst[], const char acSrc[])
{
    size_t i = 0;
    size_t j = 0;
    assert(acDst != NULL);
    assert(acSrc != NULL);

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

char *Str_search(const char haystack[], const char needle[])
{
    assert(haystack != NULL);
    assert(needle != NULL);

    /* return strstr(haystack, needle); */
    
    size_t i;
    size_t j;
    size_t sizeHaystack = Str_getLength(haystack);
    size_t sizeNeedle = Str_getLength(needle);
    size_t matchIndex = -1;

    assert(haystack != NULL);
    assert(needle != NULL);

    if (needle[0] == '\0')
        return (char *)haystack;

    for (i = 0; i < sizeHaystack; i++)
    {
        if (haystack[i] == needle[0])
        {
            for (j = 0; j <= sizeNeedle; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    i = i + j;
                    break;
                }

                if (needle[j] == '\0')
                    return (char *) &haystack[matchIndex];
            }
        }
    }

    return NULL;


    /*
    else
    return (char *) &haystack[matchIndex];
    */
}
