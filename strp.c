/*------------------------------------------------------------*/
/* strp.c                                                     */
/* Author: Vicky Feng                                         */
/*------------------------------------------------------------*/
#include "str.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h> // DELETE AFTER STRSEARCH IS COMPLETE

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

char *Str_copy(char *pcDst, const char *pcSrc)
{
    char *p = pcDst;

    assert(pcDst != NULL);
    assert(pcSrc != NULL);

    while (*pcSrc != '\0')
    {
        *p = *pcSrc;
        p++;
        pcSrc++;
    }

    *p = '\0';

    return pcDst;
}

char *Str_concat(char *pcDst, const char *pcSrc)
{

    char *p = pcDst;
    assert(pcDst != NULL);
    assert(pcSrc != NULL);

    while (*p != '\0')
        p++;

    while (*pcSrc != '\0')
    {
        *p = *pcSrc;
        p++;
        pcSrc++;
    }

    *p = '\0';
    return pcDst;
}

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

    /* return 0;  this return statement will never be reached, but this is to remove the warning */
}

char *Str_search(const char *haystack, const char *needle)
{
    return strstr(haystack, needle);
}