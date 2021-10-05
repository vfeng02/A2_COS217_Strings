/*--------------------------------------------------------------------*/
/* str.h                                              */
/* Author: Vicky Feng                                             */
/*--------------------------------------------------------------------*/

#ifndef STR_INCLUDED
#define STR_INCLUDED
#include <stddef.h>

/*--------------------------------------------------------------------*/
/* Return the length of string acSrc */

size_t Str_getLength(const char acSrc[]);

/*--------------------------------------------------------------------*/
/* Copy string acSrc and return a pointer to acDst */

char *Str_copy(char acDst[], const char acSrc[]);

/*--------------------------------------------------------------------*/
/* Append string acSrc to acDst and return a pointer to acDst */

char *Str_concat(char acDst[], const char acSrc[]);

/*--------------------------------------------------------------------*/
/* Lexicographically compare string s1 and string s2,
returning -1, 1 or 0 if s1 is less than, greater than or equal to s2 
respectively. */

int Str_compare(const char s1[], const char s2[]);

/*--------------------------------------------------------------------*/
/* Return a pointer to the first occurence of the string needle 
in the string haystack, or NULL if needle does not occur in haystack */

char *Str_search(const char haystack[], const char needle[]);

#endif