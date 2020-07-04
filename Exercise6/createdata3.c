/********************************************
 * Georgios Gerasimos Leventopoulos csd4152 *
 * createdata3.c   Software Lab             *
 ********************************************/
#include <stdio.h>
#include <stdlib.h>

int main(void){
        int i;
        FILE *data3;
        if((data3 = fopen("data3", "w")) == NULL){
                fprintf(stderr, "\nUnable to write in file data3\n\n");
                exit(EXIT_FAILURE);
        }
        for(i = 0; i < 3000000; i++){
                fprintf(data3, "randomtext");
        }
        fclose(data3);
        return 0;
}

