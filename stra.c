/*------------------------------------------------------------*/
/* stra.c                                                     */
/* Author: Vicky Feng                                         */
/*------------------------------------------------------------*/
#include "str.h"
#include <stdio.h>
#include <stdlib.h>
// #include <ctype.h>
#include <assert.h>

/*------------------------------------------------------------*/

size_t Str_getLength(const char pcSrc[])
{
    size_t uLength = 0;
    assert(pcSrc != NULL);
    while (pcSrc[uLength] != '\0')
        uLength++;
    return uLength;
}

char *Str_copy(char pcDst[], const char pcSrc[])
{
    assert(pcSrc != NULL);
    pcDst = (char *)calloc(Str_getLength(pcSrc), sizeof(char));
    assert(pcDst != NULL);
    for (int i = 0; i < Str_getLength(pcSrc); i++)
        pcDst[i] = pcSrc[i];
    return pcDst;
}

char *Str_concat(char s1[], const char s2[])
{
    assert(s1 != NULL);
    assert(s2 != NULL);

    if (sizeof(s1) / sizeof(char) < (Str_getLength(s2) + Str_getLength(s1) + 1))
        return s1;

    else
    {
        for (int i = 0; i <= Str_getLength(s2); i++)
            s1[Str_getLength(s1)] = s2[i]; /* starting with the null char element, replace each subsequent 
        element in s1 with an element from s2 */
        return s1;
    }
}

int Str_compare(char s1[], const char s2[])
{
    assert(s1 != NULL);
    assert(s2 != NULL);

    for (int i = 0; i < Str_getLength(s1); i++)
    {
        /*
        if (s1[i] == '\0' && s2[i] == '\0')
            return 0;
        else if (s2[i] == '\0')
            return 1;
        else if (s1[i] == s2[i])
            continue;
        else if (s1[i] == '\0')
            return -1;
        else if (s2[i] == '\0')
            return 1;
        */
        if (s1[i] == s2[i])
            continue;
        else if (s1[i] < s2[i])
            return -1;
        else
            return 1;
    }
    return 0;
}

char *Str_search(const char haystack[], const char needle[])
{
    assert(haystack != NULL);
    assert(needle != NULL);
    int matchIndex = -1;

    if (needle[0] == '\0')
        return haystack;

    for (int i = 0; i < Str_getLength(haystack); i++)
    {
        if (haystack[i] == needle[0])
        {
            for (int j = 0; j <= Str_getLength(needle); j++)
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
        return haystack[matchIndex];
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

    // while (i < Str_getLength(haystack))
    // {
    //     if (haystack[i] == needle[0])
    //     {
    //     }
    //     else
    //         continue;
    // }
    // for (int i = 0; i < Str_getLength(haystack); i++) {
    //     if haystack[i]
    // }
    // else if
    // {
    //     return
    // }
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
