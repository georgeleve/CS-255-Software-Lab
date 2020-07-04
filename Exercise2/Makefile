# csd4152  Georgios Gerasimos Leventopoulos
# Assignment 3     hy255   Software Lab

CFLAGS=-Wall -ansi -pedantic 
CC=gcc
 
pointer: mystring.h mystring_ptrs.o
	$(CC) $(CFLAGS) -o exe main.c mystring_ptrs.o

mystring_ptrs.o: mystring.h mystring_ptrs.c
	$(CC) -c mystring_ptrs.c


hash: symtable.h mystring_arc.o
	$(CC) $(CFLAGS) -o exe main.c mystring_arc.o

symtablehash.o: mystring.h mystring_arc.c
	$(CC) -c mystring_arc.c


clean:
	rm -rf *.o
	rm -rf exe
  

