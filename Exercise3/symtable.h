/*  Author: Georgios Gerasimos Leventopoulos csd4152                      */
/*  symtable.h (A header file contains the ADT declaration) Assignment 3  */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include <string.h>

/* The ADT in C is usually defined as a pointer to a structure */
typedef struct SymTable_S* SymTable_T; /* Define the abstract data type */

/* Returns a new SymTable object that contains no binding
   or NULL if insufficient memory is available.*/
SymTable_T SymTable_new(void);

/* Free all the memory occupied by oSymTable. */
void SymTable_free(SymTable_T oSymTable);

/* Return the number of bindings in oSymTable. */
unsigned int SymTable_getLength(SymTable_T oSymTable);

/*If oSymTable does not contain a binding with key pcKey, add a new binding 
to oSymTable consisting of key pcKey and value pvValueand return 1 (TRUE). 
Otherwise, leave oSymTable unchanged and return 0 (FALSE). */
int SymTable_put(SymTable_T oSymTable, const char* pcKey, const void* pvValue);

/* If oSymTable contains a binding with key pcKey, then SymTable_remove
   must remove that binding from oSymTable and return the binding's value. 
   Otherwise the function must not change oSymTable and return NULL.*/
int SymTable_remove(SymTable_T oSymTable, const char* pcKey);

/* Return 1 (TRUE) if oSymTable containsa binding
   whose key is pcKey. Otherwise returns 0 (FALSE) */
int SymTable_contains(SymTable_T oSymTable, const char* pcKey);

/* Return the value of the binding within oSymTable whose key is
   pcKey, or NULL if no such binding exists. */
void* SymTable_get(SymTable_T oSymTable, const char* pcKey);

/* Apply function* pfApply to each binding in oSymTable, passing 
   pvExtra as an extra parameter. That is, the function must call
   (*pfApply)(pcKey, pvValue, pvExtra) for each pcKey/pvValue binding in oSymTable. */
void SymTable_map(SymTable_T oSymTable,
	void (*pfApply)(const char* pcKey, void* pvValue, void* pvExtra), const void* pvExtra);

