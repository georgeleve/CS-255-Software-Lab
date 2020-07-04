/*           mystring_arc.c            */
/* Georgios Gerasimos Leventopoulos    */
/* csd 4152  Assignment2   hy255       */

/* unsigned int or unsigned long == size_t */
/* DO IT USING ARRAYS */

#include "mystring.h"
#include <string.h>
#include <assert.h>
#include <stddef.h>
#include <stdbool.h>
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
size_t ms_length(const char s[]) {
    size_t uiLength = 0U;
    assert(s);
    while (s[uiLength] != '\0')
        uiLength++;
    return uiLength;
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
char *ms_copy(char s[], const char ct[]) {
    size_t s1 = 0;
    size_t ct1 = 0;
    char *temp = s;
    assert(s && ct);
    while (ct[ct1] != '\0') {
        s[s1++] = ct[ct1++];
    }
    s[s1] = '\0';
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
char *ms_ncopy(char s[], const char ct[], size_t num) {\
    size_t i = 0;
    size_t s1 = 0;
    size_t ct1 = 0;
    char* temp = s;
    assert(s && ct);
    for (i = 0; i < num; i++) {
        if (ct[ct1] != '\0') {
            s[s1++] = ct1[ct++];
        }
        else {
            s[s1++] = '\0';
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
char *ms_concat(char s[], const char ct[]) {
    char* temp = s;
    size_t s1 = 0;
    size_t ct1 = 0;
    assert(s && ct);
    while (s[s1] != '\0') {
        s1++;
    }
    while (ct[ct1] != '\0') {
        s[s1++] = ct[ct1++];
    }
    s[s1] = '\0';
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
char* ms_nconcat(char s[], const char ct[], size_t num) {
    char *temp = s;
    size_t i;
    size_t s1 = 0;
    size_t ct1 = 0;
    assert(s && ct);
    while (s[s1] != '\0') {
        s++;
    }
    for (i = 0; i < num; i++) {
        s[s1++] = ct[ct1++];
    }
    s[s1] = '\0';
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
int ms_compare(const char cs[], const char ct[]) {
    size_t cs1 = 0;
    size_t ct1 = 0;
    assert(cs && ct);
    while (cs[cs1] == ct[ct1] && ct[ct1] != '\0') {
        cs1++;
        ct1++;
    }
    if (cs[cs1] > ct[ct1]) {
        return 1;
    }
    else if (cs[cs1] < ct[ct1]) {
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
int ms_ncompare(const char cs[], const char ct[], size_t num) {
    size_t i = 0U;
    size_t length1 = ms_length(cs);
    size_t length2 = ms_length(ct);
    size_t max_value = (int)cs;
    assert(cs && ct);
    if (length1 <= length2)
        max_value = length1;
    while (i < num && cs != '\0' && i < max_value) {
        if (cs[i] > ct[i]) return 1;
        if (cs[i] < ct[i]) return -1;
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
const char *ms_search(const char cs[], const char ct[]) {
    const char *temp;
    int i = 0;
    int j = 0;
    int cs_length = ms_length(cs);
    int ct_length = ms_length(ct);
    assert(cs && ct);
    while (i < cs_length) {
        if (cs[i] == ct[j]) {
            temp = (cs+i);
            while (j < ct_length) {
                j++;
                i++;
                if (cs[i] == ct[j]){
                    if (j == ct_length-1) return temp;
                }
                else {
                    break;
                }
            }
        }
        j = 0;
        i++;
    }
    return NULL;
}

