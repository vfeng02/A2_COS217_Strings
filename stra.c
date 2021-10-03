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

char *Str_copy(char acDst[], const char acSrc[])
{ /*

    int i;
    assert(pcSrc != NULL);
    assert(pcDst != NULL);

    for (i = 0; i < (int)Str_getLength(pcSrc); i++)
        pcDst[i] = pcSrc[i];
    return pcDst;
    */
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

char *Str_concat(char s1[], const char s2[])
{
    int i, j = 0;
    assert(s1 != NULL);
    assert(s2 != NULL);

    while (s1[i] != '\0')
    {
        i++;
    }

    while (i < (int)Str_getLength(s1) && s2[j] != '\0')
    {
        s1[i] = s2[j];
        i++;
        j++;
    }

    s1[i] = '\0';
    return s1;

    /*
    if (sizeof(s1) / sizeof(char) < (int)(Str_getLength(s2) + Str_getLength(s1) + 1))
        return s1;

    else
    {
        for (i = 0; i <= (int)Str_getLength(s2); i++)
            s1[(int)Str_getLength(s1)] = s2[i]; // starting with the null char element, replace each subsequent 
        element in s1 with an element from s2
        return s1;
    }
    */
}

int Str_compare(char s1[], const char s2[])
{
    int i;
    assert(s1 != NULL);
    assert(s2 != NULL);

    /*
    while (s1[i] != 0)
    {
        if (s1[i] == s2[i])
            continue;
        else if (s1[i] < s2[i])
            return -1;
        else
            return 1;
        i++;
    }

    if (s2[i] == '\0')
        return 0;
    else
        return -1;
        */

    for (i = 0; i < (int)Str_getLength(s1); i++)
    {

        if (s1[i] == '\0' && s2[i] == '\0')
            return 0;
        else if (s2[i] == '\0')
            return 1;
        else if (s1[i] == '\0')
            return -1;
        else if (s1[i] == s2[i])
            continue;
        else if (s1[i] < s2[i])
            return -1;
        else
            return 1;
        /*
        if (s1[i] == s2[i])
            continue;
        else if (s1[i] < s2[i])
            return -1;
        else
            return 1;
            */
    }
}

char *Str_search(const char haystack[], const char needle[])
{
    int i, j;
    int matchIndex = -1;

    assert(haystack != NULL);
    assert(needle != NULL);

    if (needle[0] == '\0')
        return (char *)haystack;

    for (i = 0; i < (int)Str_getLength(haystack); i++)
    {
        if (haystack[i] == needle[0])
        {
            for (j = 0; j <= (int)Str_getLength(needle); j++)
            {
                if (haystack[i + j] != needle[j])
                    break;
                if (needle[j] == '\0')
                    matchIndex = i;
            }
        }
    }
    if (matchIndex == -1)
        return NULL;

    else
        return (char *)&haystack[matchIndex];
}

/* Str_Search version 1 */
/*
char *Str_search(const char haystack[], const char needle[])
{
    enum Statetype state = STARTMATCH;

    assert(haystack != NULL);
    assert(needle != NULL);
    int i = 0;
    int matchIndex = NULL;

    if (needle[0] == '\0')
        return haystack;

    while (i < Str_getLength(haystack))
    {
        switch (state)
        {
        case STARTMATCH:
            state = handleStartMatchState(haystack, needle, i);
            break;
        case NONMATCH:
            state = handleNonMatchState(haystack, needle, i);
            break;
        }
    }
    else return NULL;
}

enum Statetype
{
    STARTMATCH,
    INMATCH,
    NONMATCH,
    FOUNDMATCH
};

enum Statetype handleStartMatchState(const char haystack[], const char needle[], const int index, int matchIndex)
{
    enum Statetype state;
    if (haystack[index] == needle[0])
    {
        state = INMATCH;
        matchIndex = index;
    }
    else
        state = NONMATCH;
    return state;
}

enum Statetype handleInMatchState(const char haystack[], const char needle[], const int index, int matchIndex)
{
    enum Statetype state;
    if (needle[matchIndex - index] == '\0')
    state = FOUNDMATCH;
    if (haystack[index] == needle[matchIndex - index])
        state = INMATCH;
    else
        state = NONMATCH;
    return state;
}

enum Statetype handleNonMatchState(const char haystack[], const char needle[], const int index, int matchIndex)
{
    enum Statetype state;
    if (haystack[index] != needle[index])
        state = NONMATCH;
    else
        state = ;
    return state;
}
*/
