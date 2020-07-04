/* 
 *   Author: Georgios Gerasimos Leventopoulos csd4152  
 *   testsymtab.c   Assignment 3  Software Lab
 */         
     #include "symtable.h"
/* pfApply method */
void pfApply(const char* pcKey, void* pvValue, void* pvExtra) {
	printf("SymTable_map():  key = %s  and  pvExtra = %d \n", pcKey, (int)pvExtra);
}

/* Main method in order to check .c files */
int main(void) {
	SymTable_T symTable;
	char key[2];
	void (*pointer)(const char*, void*, void*);
	const char keys[] = "abcdefghijklmnopqrstvwxyz";
	int values[] = {5,34,5,4,112,64,7,8,9,1206,8,1,9,72,5,4,345,3,25,43,356,7,98,98,65,413,21};
	int pvExtra = 50;
	int i = 0;
	key[1] = '\0';
	pointer = &pfApply;

	/* SymTable_new() */
	symTable = SymTable_new();
	printf("\nSymTable_new() successfully called.\n\n");

	/* SymTable_put() */
	for (i = 0; i < 22; i++) {
		key[0] = keys[i];
		printf("SymTable_put() = %d   key = %s , value = %d\n", SymTable_put(symTable, key, (int*)values[i]), key, values[i]);
	}
	/* Trying to put key = w twice */
	printf("SymTable_put() = %d ", SymTable_put(symTable, key, (int*)values[10]));
	printf("  key = %s,  value = %d    Can not put key = w twice\n\n", key, values[10]);

	/* SymTable_remove()  */
	printf("SymTable_remove() = %d   key = e successfully removed.\n", SymTable_remove(symTable, "e"));
	printf("SymTable_remove() = %d   key = h successfully removed.\n", SymTable_remove(symTable, "h"));
	printf("SymTable_remove() = %d   key = k successfully removed.\n", SymTable_remove(symTable, "k"));
	printf("SymTable_remove() = %d   key = d successfully removed.\n", SymTable_remove(symTable, "d"));
	printf("SymTable_remove() = %d   key = e  Can't remove something that doesn't exist.\n\n", SymTable_remove(symTable, "e"));  
	
	/* SymTable_contains() */
	for (i = 0; i < 24; i++) {
		key[0] = keys[i];
		printf("SymTable_contains() = %d   key = %s\n", SymTable_contains(symTable, key), key);
	}
	printf("\n");

	/* SymTable_get() */
	for (i = 0; i < 24; i++) {
		key[0] = keys[i];
		if (SymTable_contains(symTable, key), key)
			printf("SymTable_get() = %d         and      key = %s\n", (int)SymTable_get(symTable, key), key);
	}

	/* SymTable_getLength() */
	printf("\nSymTable_getLength = %d blings\n\n", SymTable_getLength(symTable)); 

	/* SymTable_map() */
	SymTable_map(symTable, pointer, (int*)pvExtra);

	/* SymTable_free() */
	SymTable_free(symTable);
	printf("\nSymTable_free() successfully called.");
	return 0;
}
