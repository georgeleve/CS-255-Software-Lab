/*           mystring_ptrs.c               */
/* Georgios Gerasimos Leventopoulos        */
/*   csd 4152  Assignment2   hy255         */
/* unsigned int or unsigned long == size_t */

/* DO IT USING POINTERS */

#include "mystring.h"
#include <string.h>
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
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
size_t ms_length(const char *s) {
    const char *pcStrEnd = s;
    assert(s);
    while (*pcStrEnd != '\0') pcStrEnd++;
    return pcStrEnd - s; 
}
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
char *ms_copy(char *s, const char *ct) {
    char *temp = s;
    assert(s && ct);
    while (*ct != '\0') {
        *s++ = *ct++;
    }
    *s = '\0';
    return temp;
}
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
char *ms_ncopy(char *s, const char *ct, size_t num) {
    size_t i;
    char *temp = s;
    assert(s && ct);
    if (num == 0)return s;
    for(i = 0; i < num; i++){
        if (*ct != '\0') {
            *s++ = *ct++;
        }
        else {
            *s++ = '\0';
        }
    }
    return temp;
}
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
char *ms_concat(char *s, const char *ct) {
    char *temp = s;
    assert(s && ct);
    while (*s != '\0') {
        s = s + 1;
    }
    while (*ct != '\0') {
        *s++ = *ct++;
    }
    *s = '\0';
    return temp;
}
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
char *ms_nconcat(char *s, const char *ct, size_t num) {
    char* temp = s;
    size_t i = 0;
    assert(s && ct);
    while (*s != '\0') {
        s = s + 1;
    }
    for (i = 0; i < num; i++) {
        *s++ = *ct++;
    }
    *s = '\0';
    return temp;
}
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
int ms_compare(const char *cs, const char *ct) {
    assert(cs && ct);
    while (*cs == *ct && *ct != '\0') {
        cs = cs + 1;
        ct = ct + 1;
    }
    if (*cs > *ct) {
        return 1;
    }
    else if (*cs < *ct) {
        return -1;
    }
    else {
        return 0;
    }
}
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
int ms_ncompare(const char *cs, const char *ct, size_t num) {
    size_t i = 0U;
    size_t length1 = ms_length(cs);
    size_t length2 = ms_length(ct);
    size_t max_value = *cs;
    assert(cs && ct);
    if (length1 <= length2)
        max_value = length1;
    while (i < num && *cs != '\0' && i < max_value) {
        if (*cs > *ct) return 1;
        if (*cs < *ct) return -1;
        i++;
    }
    return 0;
}
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
const char *ms_search(const char *cs, const char *ct) {
    const char *temp;
    const char *temp2 = ct;
    int i = 0, j = 0;
    int cs_length = ms_length(cs);
    int ct_length = ms_length(ct);
    assert(cs && ct);
    while (i < cs_length) {
        if (*cs == *ct) {
            temp = cs;
            while (j < ct_length) {
                j++;
                i++;
                if (*cs != *ct) {
                    break;
                }
                else {
                    if(j == ct_length)
                        return temp;
                }
                ct++;
                cs++;
            }
        }
        j = 0;
        i++;
        ct = temp2;
        cs++;
    }
    return NULL;
}

