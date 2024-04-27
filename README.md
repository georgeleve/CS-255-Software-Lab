# Software-Technology-Laboratory 
https://www.csd.uoc.gr/~hy255/assignments.html

These are the exercises during the second year of University.

Exercise 1 - Translate Program:
-Translates input from iso8859-7 characters (English and Greek characters) to iso8859-1 (English characters).

Exercise 2 - A String Module:
-Created "MyString" module, which includes implementation of the most used string methods. Specifically the module "MyString" includes the methods below which have the same behavior as the original standard C library.  

-ms_length <--> strlen  
-ms_copy <--> strcpy  
-ms_ncopy <--> strncpy  
-ms_concat <--> strcat  
-ms_nconcat <--> strncat  
-ms_compare <--> strcmp  
-ms_ncompare <--> strncmp  
-ms_search <--> strstr  

Exercise 3 - Abstract Data Type - Symbol Table:
-Created an abstract data type (ADT) called SymTable. Each instance of the SymTable ADT is a symbol table.
Design the SymTable ADT to be "generic", meaning that the values ​​are void pointers, and therefore cannot point to data of any type.
-Created two implementations of the SymTable ADT: one using pointers and a list that contains a hash table.

Exercise 5: Check Assembly in a C Program  
-The goal of this exercise was to help introduce me to (1) assembly to x86 architecture processors, (2) representing assembly language to machine code in system memory, and (3) using gdb.   

Exercise 6: Systems Security: Buffer Overrun Attack  
- Wrote a program called createdata3.c that creates a file called data3, as simple as possible, that causes the hello program to terminate with a segmentation fault (crash).  
- Wrote a C program called createdata6.c that produces a data6 file, as simple as possible, that causes the hello program to print a name and suggest "6" as the grade (instead of 0).
  The way that I forced the program into this behavior was to overrun the readString's buffer (buf) and write over the readString's return address (on the stack) another (appropriate)
  address inside the main function.  
- Wrote a C program called createdata9.c that produces a data9 file, as simple as possible, that causes the hello program to print my name and suggest "9" as the grade instead of 0.
  The way I forced the program into this behavior was to overrun the buffer (buf) with a sequence of three things:
  (1) my name, (2) a return address that points into the buffer, and (3) a very short machine language program that stores 9
  in the correct location in memory and then jumps to the correct point.
