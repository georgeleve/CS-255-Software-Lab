/*           mystring_ptrs.c               */
/* Georgios Gerasimos Leventopoulos        */
/*   csd 4152  Assignment2   hy255         */
/* unsigned int or unsigned long == size_t */

/* DO IT USING POINTERS */

#include "mystring.h"
#include <assert.h>
#include <stddef.h>

size_t ms_length(const char *s) {
    const char *pcStrEnd = s;
    assert(s);
    while (*pcStrEnd != '\0') pcStrEnd++;
    return pcStrEnd - s; 
}

char *ms_copy(char *s, const char *ct) {
    assert(s && ct); 
    char *temp = s;
    while (*ct != '\0') {
        *s++ = *ct++;
    }
    *s = '\0';
    return temp;
}

char *ms_ncopy(char *s, const char *ct, size_t num) {
    assert(s && ct);
    assert((signed)num >= 0);
    size_t i;
    char *temp = s;
    for(i = 0; i < num; i++){
        if (*ct != '\0') {
            *s++ = *ct++;
        }
        else {
            *s++ = '\0';
        }
    }
    *s = '\0';
    return temp;
}

char *ms_concat(char *s, const char *ct) {
    assert(s && ct);
    char *temp = s;
    while (*s != '\0') {
        *s++;
    }
    while (*ct != '\0') {
        *s++ = *ct++;
    }
    *s = '\0';
    return temp;
}

char *ms_nconcat(char *s, const char *ct, size_t num) {
    assert(s && ct);
    assert((signed)num >= 0);
    char* temp = s;
    size_t i;
    while (*s != '\0') {
        *s++;
    }
    for (i = 0; i < num; i++) {
        *s++ = *ct++;
    }
    *s = '\0';
    return temp;
}

int ms_compare(const char *cs, const char *ct) {
    assert(cs && ct);
    while (*cs == *ct && *ct != '\0') {
        *cs++;
        *ct++;
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

int ms_ncompare(const char *cs, const char *ct, size_t num) {
    assert(cs && ct);
    assert((signed)num >= 0);
    size_t i;
    for(i = 0; i < num; i++){
        *cs++;
        *ct++;
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

char *ms_search(const char *cs, const char *ct) {
    assert(cs && ct);


    return NULL;
}
