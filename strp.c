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

char *Str_copy(char *s1, const char *s2)
{
    char *p = s2;

    assert(s1 != NULL);
    assert(s2 != NULL);

    while (*p != '\0')
    {
        *s1 = *p;
        p++;
        s1++;
    }
    *s1 = '\0';
    return s1;
}

char *Str_concat(char *s1, const char *s2)
{

    char *p = s1;
    assert(s1 != NULL);
    assert(s2 != NULL);

    while (*p != '\0')
        p++;

    while (*s2 != '\0')
    {
        *p = *s2;
        p++;
        s2++;
    }

    *p = '\0';
    return s1;
}

int Str_compare(char *s1, const char *s2);

char *Str_search(const char *haystack, const char *needle);