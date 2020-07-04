/*
 *  Author: Georgios Gerasimos Leventopoulos csd4152
 *  symtablelist.c  Assignment 3
 *  Create SymTableADT using a single linked list
 */
#define HASH_TABLE_SIZE 509
#include "symtable.h"
int SymTable_contains(SymTable_T oSymTable, const char* pcKey);

 /*A struct that holds key, value and next of every node. */
struct node {
	char* key;
	void* value;
	struct node* next;
};

struct SymTable_S {
	struct node* list_head; /* Address of the list head */
	unsigned int size_of_bindings;
};

/* Returns a new SymTable object that contains no binding
   or NULL if insufficient memory is available.*/
SymTable_T SymTable_new(void) {
	SymTable_T newNode = malloc(sizeof(SymTable_T));
	if (!newNode) return NULL;    /* Check if malloc succeded */
	newNode->list_head = NULL;
	newNode->size_of_bindings = 0;
	return newNode;
}

/* Free all the memory that is occupied by SymTable.
   It's a checked runtime error for oSymTable to be NULL */
void SymTable_free(SymTable_T oSymTable) {
	struct node* next_node;
	struct node* temp = oSymTable->list_head;
	assert(oSymTable); /* Checked RTE */
	while (temp) {
		next_node = temp->next;
		free(temp->key);
		free(temp);
		temp = next_node;
	}
	free(oSymTable);
}

/* Returns the number of bindings in the oSymTable */
unsigned int SymTable_getLength(SymTable_T oSymTable) {
	assert(oSymTable); /* Checked RTE */
	return oSymTable->size_of_bindings;
}

/*If oSymTable does not contain a binding with key pcKey, add a new binding 
to oSymTable consisting of key pcKey and value pvValueand return 1 (TRUE). 
Otherwise, leave oSymTable unchanged and return 0 (FALSE). */
int SymTable_put(SymTable_T oSymTable, const char* pcKey, const void* pvValue) {
	struct node* newNode;
	struct node* head = oSymTable->list_head;
	assert(oSymTable && pcKey); /* Checked RTE */
	
	/* If the pcKey already exists, return 0 */
	if (SymTable_contains(oSymTable, pcKey)) return 0;

	newNode = (struct node*)malloc(sizeof(struct node));
	if (!newNode)return 0; /* Check if malloc succeded. */

	newNode->key = malloc((strlen(pcKey) + 1) * sizeof(char));
	if (!newNode->key)return 0; /* Check if malloc succeded. */
	strcpy(newNode->key, pcKey);

	newNode->value = (void*)pvValue;
	newNode->next = head;         /* Point to the current list_head */
	head = newNode;               /* Become a head */
	oSymTable->list_head = head;  /* Connect it with linked list */
	oSymTable->size_of_bindings++;  /* Increase SymTable length */
	return 1;
}

/* If oSymTable contains a binding with key pcKey, then SymTable_remove
   must remove that binding from oSymTable and return the binding's value. 
   Otherwise the function must not change oSymTable and return NULL.*/
int SymTable_remove(SymTable_T oSymTable, const char* pcKey) {
	struct node* temp = oSymTable->list_head;
	struct node* prev = NULL;
	assert(oSymTable && pcKey); /* Checked RTE */

	/* Check if the list contains the node that we want to remove. */
	if (!SymTable_contains(oSymTable, pcKey)) return 0;
	oSymTable->size_of_bindings--; /* Reduce SymTable size */

	/* So, linked list contains the node that we want to delete */
	/* If it is the head node */
	if (!strcmp(pcKey, temp->key)) {
		oSymTable->list_head = temp->next;
		free(temp->key);
		free(temp);
		return 1;
	}
	/* If the node is in the middle or in the end. */
	while (temp && strcmp(pcKey, temp->key)) {
		prev = temp; /* keep previous node */
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
	struct node* temp = oSymTable->list_head;
	assert(oSymTable && pcKey); /* Checked RTE */
	while (temp) {
		if (!strcmp(pcKey, temp->key)) {
			return 1;             /* If we find pcKey */
		}
		else {
			temp = temp->next; /* Else move to the next node */
		}
	}
	return 0;  /* If the node with pcKey is not in the linked list */
}

/* Return the value of the binding within oSymTable whose key is
   pcKey, or NULL if no such binding exists. */
void* SymTable_get(SymTable_T oSymTable, const char* pcKey) {
	struct node* temp = oSymTable->list_head;
	assert(oSymTable && pcKey); /* Checked RTE */
	while (temp) {
		if (!strcmp(pcKey, temp->key)) { /* Once we find the key, we return it */
			return (void*)temp->value;
		}
		else {
			temp = temp->next; /* We move to the next node */
		}
	}
	return NULL; /*  If the node with pcKey is not in the linked list * */
}

/* Apply function* pfApply to each binding in oSymTable, passing 
   pvExtra as an extra parameter. That is, the function must call
   (*pfApply)(pcKey, pvValue, pvExtra) for each pcKey/pvValue binding in oSymTable. */
void SymTable_map(SymTable_T oSymTable, void (*pfApply)(const char*
	pcKey, void* pvValue, void* pvExtra), const void* pvExtra) {
	struct node* temp = oSymTable->list_head;
	assert(oSymTable);
	while (temp) {
		if (temp->value)
			pfApply((const char*)temp->key, (void*)(temp->value), (void*)pvExtra);
		temp = temp->next;
	}
}

