#include<stdio.h>

/*------------------------------------------------------------------------------
Main
------------------------------------------------------------------------------*/
int main(int argc, char *argv[]) {
    int i=1;
    while(i<argc){
        FILE *fdados = fopen(argv[i],"r");
        char *d;
        char ch=fgetc(fdados);
        while (ch!=EOF) {
            printf("%c",ch);
            ch=fgetc(fdados);
        }
        fclose(fdados);
        i++;
    }
    return 0;
}
