/*           mystring.h                */
/* Georgios Gerasimos Leventopoulos    */
/* csd 4152  Assignment2     hy255     */
#pragma once
#include <assert.h>
#include <stddef.h>
/*
 * Function: ms_length
 * ----------------------------
 * -Return the length of string s.
 * -It is a checked runtime error for s to be NULL.
 *
 * s: the string that we are searching its length.
 * 
 * returns : the size of the input string
 */
size_t ms_length(const char *s);
size_t ms_length(const char s[]);
/*
 * Function: ms_copy
 * ----------------------------
 *  -Copies the string pointed to, by s to ct (including '\0')
 *  -Return a pointer to the destination string s.
 *  -It is a checked runtime error for ct to be NULL.
 *   
 *  s: A pointer to the array position where the ct is to be copied. 
 *  ct: The string to be copied.
 *
 *  returns: a pointer to the destination string s.
 */
char *ms_copy(char *s, const char *ct);
char *ms_copy(char s[], const char ct[]);
/*
 * Function: ms_ncopy
 * ----------------------------
 *  -Copies up to n characters from the string pointed to, by s to ct.
 *   In the case where the length of s is less that of n, 
 *   the remaining parts of s will be filled with null.
 *  -Return a pointer to the destination string s
 *  -It is a checked runtime error for ct to be NULL.
 *
 *   s: A pointer to the array position where the ct is to be copied. 
 *   ct: The string to be copied.
 *   num: the number of characters to be copied from source.
 *
 *   returns: a pointer to the array cell where the ct is to be copied. 
 */
char *ms_ncopy(char *s, const char *ct, size_t num);
char *ms_ncopy(char s[], const char ct[], size_t num);
/*
 * Function: ms_concat
 * ----------------------------
 *   -Appends the string pointed to by s to the end of 
 *   the string pointed to by ct.
 *   -Returns a pointer to the resulting string dest.
 *   -It is a checked runtime error for ct to be NULL.
 *
 *   s: A pointer to the destination array. This pointer contains a string
 *   that is large enough to keep the resulting string.
 *   ct: The string to be appended
 *
 *   returns: a pointer to the resulting string s.
 */
char *ms_concat(char *s, const char *ct);
char *ms_concat(char s[], const char ct[]);
/*
 * Function: ms_nconcat
 * ----------------------------
 *  -Appends the string pointed to by s to the end of the string 
 *  pointed to by ct up to num characters long.
 *  -Returns a pointer to the resulting string dest.
 *  -It is a checked runtime error for ct to be NULL.
 *
 *   s: This is a pointer to the destination array.This pointer contains
 *   a string that is large enough to keep the resulting string.
 *   ct: The string to be appended
 *   num: The maximum number of characters to be appended.
 *
 *   returns: a pointer to the resulting string s.
 */
char *ms_nconcat(char *s, const char *ct, size_t num);
char *ms_nconcat(char s[], const char ct[], size_t num);
/*
 * Function: ms_compare
 * ----------------------------
 * -Compares the string pointed to, by cs to the string pointed to by ct.
 * -Returns a value: if cs < ct then value < 0, if cs > ct then value > 0
 *  if cs == ct then value == 0   
 * 
 *  cs: The 1st string to be compared.
 *  ct: The 2nd string to be compared.
 *
 *  returns: value < 0 or value == 0 or value > 1
 */
int ms_compare(const char *cs, const char *ct);
int ms_compare(const char cs[], const char ct[]);
/*
 * Function: ms_ncompare
 * ----------------------------
 * -Compares at most the first n bytes of cs and ct.
 * -Returns a value: if cs < ct then value < 0, if cs > ct then value > 0
 *  if cs == ct then value == 0  
 *
 *  cs: The 1st string to be compared.
 *  ct: The 2nd string to be compared.
 *  num: Max number of characters to be compared.
 *
 *  returns: value < 0 or value == 0 or value > 1
 */
int ms_ncompare(const char *cs, const char *ct, size_t num);
int ms_ncompare(const char cs[], const char ct[], size_t num);
/*
 * Function:  ms_search
 * ----------------------------
 *  Finds the first occurrence of the substring cs in the string ct.
 *
 *  cs: The main string to be scanned.
 *  ct: The small string to be searched inside string cs.
 *
 *  returns: pointer to the 1st element of cs that the ct is included or NULL
 *  if the order is not present in cs.
 */
const char *ms_search(const char *cs, const char *ct);
const char *ms_search(const char cs[], const char ct[]);
