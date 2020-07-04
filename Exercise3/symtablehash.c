/*
 *   Author: Georgios Gerasimos Leventopoulos csd4152
 *  symtablehash.c  Assignment 3
 *  Create SymTableADT using a hash table
 */
#define HASH_TABLE_SIZE 509
#define HASH_MULTIPLIER 65599
 /* Use symtable as a hash table using 
    Open Addresing method (Seperate Chaining) */

#include "symtable.h"
int SymTable_contains(SymTable_T oSymTable, const char* pcKey);

struct node {
	char* key;
	void* value;
	struct node* next;
};

struct SymTable_S {
	unsigned int size_of_bindings;
	struct node* array[HASH_TABLE_SIZE];
};

/* Return a hash code for pcKey. (0 < code < HASH_TABLE_SIZE = 509) */
static unsigned int SymTable_hash(const char* pcKey) {
	size_t ui;
	unsigned int uiHash = 0U;
	for (ui = 0U; pcKey[ui] != '\0'; ui++)
		uiHash = uiHash * HASH_MULTIPLIER + pcKey[ui];
	return uiHash%HASH_TABLE_SIZE;
}

/* Returns a new SymTable object that contains no bindings
   or NULL if insufficient memory is available.*/
SymTable_T SymTable_new(void) {
	size_t i = 0U;
	SymTable_T oSymTable = (SymTable_T)malloc(sizeof(struct SymTable_S));
	if (!oSymTable) return NULL;
	oSymTable->size_of_bindings = 0;
	/* Initialize the array */
	for (i = 0U; i < HASH_TABLE_SIZE; i++)
		oSymTable->array[i] = NULL;
	return oSymTable;
}

/* Free all the memory occupied by oSymTable. */
void SymTable_free(SymTable_T oSymTable) {
	size_t i = 0U;
	struct node* temp;
	struct node* next;
	assert(oSymTable); /* Checked RTE */
	oSymTable->size_of_bindings = 0;
	for (i = 0; i < HASH_TABLE_SIZE; i++) {
		temp = oSymTable->array[i];
		while (temp) {
			next = temp->next; /* Keep next node */
			free(temp->key);
			free(temp);
			temp = next;      /* Go to the next node */
		}
	}
	free(oSymTable);
	return;
}

/* Return the number of bindings in oSymTable. */
unsigned int SymTable_getLength(SymTable_T oSymTable) {
	assert(oSymTable); /* Checked RTE */
	return oSymTable->size_of_bindings;
}

/*If oSymTable does not contain a binding with key pcKey, add a new binding 
to oSymTable consisting of key pcKey and value pvValueand return 1 (TRUE). 
Otherwise, leave oSymTable unchanged and return 0 (FALSE). */
int SymTable_put(SymTable_T oSymTable, const char* pcKey, const void* pvValue) {
	struct node* newNode;
	struct node* temp;
	struct node* prev = NULL;
	size_t hashNumber = SymTable_hash(pcKey);  /* Find hash number */
	assert(oSymTable && pcKey);                /* Checked RTE */
	temp = oSymTable->array[hashNumber];
	if (SymTable_contains(oSymTable, pcKey))return 0; 
	while (temp) {
		prev = temp;
		temp = temp->next;
	}
	newNode = (struct node*)malloc(sizeof(struct node));
	if (!newNode)return 0;

	newNode->key = malloc((strlen(pcKey) + 1) * sizeof(char));
	if (!newNode->key)return 0;
	strcpy(newNode->key, pcKey);

	newNode->value = (void*)pvValue;
	newNode->next = NULL;
	/* If it is the 1st element in the array cell */
	if (!prev) {
		oSymTable->array[hashNumber] = newNode;
	}
	else {
		prev->next = newNode;
	}
	oSymTable->size_of_bindings++;
	return 1;
}

/* If oSymTable contains a binding with key pcKey, then SymTable_remove
   must remove that binding from oSymTable and return the binding's value. 
   Otherwise the function must not change oSymTable and return NULL.*/
int SymTable_remove(SymTable_T oSymTable, const char* pcKey) {
	struct node* temp;
	struct node* prev = NULL;
	size_t hashNumber = SymTable_hash(pcKey);
	assert(oSymTable && pcKey); /* Checked RTE */
	//if(!SymTable_contains(oSymTable,pcKey))return 0;
	temp = oSymTable->array[hashNumber];

	/* Check if the list contains the node that we want to remove. */
	if (!SymTable_contains(oSymTable, pcKey)) return 0;
	oSymTable->size_of_bindings--; /* Reduce size of blings */
	/* If it is the head node */
	if (!strcmp(temp->key, pcKey)) {
		oSymTable->array[hashNumber] = temp->next;
		free(temp->key);
		free(temp);
		return 1;
	}
	/* If the node is in the middle or in the end. */
	while (temp && strcmp(temp->key, pcKey)) { 
		prev = temp; /* Keep previous pointer */
		temp = temp->next;
	}
	/* Unlink the node from the linked list */
	prev->next = temp->next;
	free(temp->key); /* Delete node */
	free(temp);
	return 1;
}

/* Return 1 (TRUE) if oSymTable containsa binding
   whose key is pcKey. Otherwise returns 0 (FALSE) */
int SymTable_contains(SymTable_T oSymTable, const char* pcKey) {
	struct node* temp;
	size_t hashNumber = SymTable_hash(pcKey);
	assert(oSymTable && pcKey); /* Checked RTE */
	temp = oSymTable->array[hashNumber];
	while (temp) {
		if (!strcmp(temp->key, pcKey))
			return 1;
		temp = temp->next;
	}
	return 0; /* If node is NULL or does not exist */
}

/* Return the value of the binding within oSymTable whose key is
   pcKey, or NULL if no such binding exists. */
void* SymTable_get(SymTable_T oSymTable, const char* pcKey) {
	struct node* temp;
	size_t hashNumber = SymTable_hash(pcKey);
	assert(pcKey && oSymTable); /* Checked RTE */
	temp = oSymTable->array[hashNumber];
	if (!temp) return NULL;
	/* Else find the node and return it's value */
	while (temp) {
		if(!strcmp(pcKey, temp->key))
			return (void*)temp->value;
		temp = temp->next;
	}
	return NULL; /* Return NULL if does not exist or if node is NULL */
}

/* Apply function* pfApply to each binding in oSymTable, passing 
   pvExtra as an extra parameter. That is, the function must call
   (*pfApply)(pcKey, pvValue, pvExtra) for each pcKey/pvValue binding in oSymTable. */
void SymTable_map(SymTable_T oSymTable, void (*pfApply)(const char
	*pcKey, void* pvValue, void* pvExtra), const void* pvExtra){
	struct node* temp;
	size_t i = 0U;
	assert(oSymTable && pfApply); /* Checked RTE */
	for (i = 0; i < HASH_TABLE_SIZE; i++) {
		temp = oSymTable->array[i];        
		while (temp) {
		    if(SymTable_contains(oSymTable, temp->key))
		        pfApply((const char*)temp->key, (void*)temp->value, (void*)pvExtra);
		    temp = temp->next;
		}
	}
	return;
}


