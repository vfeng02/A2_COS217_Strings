/*--------------------------------------------------------------------*/
/* str.h                                              */
/* Author: Vicky Feng                                             */
/*--------------------------------------------------------------------*/

#ifndef STR_INCLUDED
#define STR_INCLUDED
#include <stddef.h>

/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/

/*  */

size_t Str_getLength(const char acSrc[]);

char *Str_copy(char acDst[], const char acSrc[]);

char *Str_concat(char acDst[], const char acSrc[]);

int Str_compare(const char s1[], const char s2[]);

char *Str_search(const char haystack[], const char needle[]);

#endif