#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*------------------------------------------------------------------------------
Func Dec
------------------------------------------------------------------------------*/
    void toLowerFile(char* filename);
    void toUpperFile(char* filename);
    void standartFile(char*filename);


/*------------------------------------------------------------------------------
Func Imp
------------------------------------------------------------------------------*/
    void toLowerFile(char* filename){
        FILE *fdados = fopen(filename,"r");
        char *d;
        char ch=fgetc(fdados);
        while (ch!=EOF) {
            printf("%c",tolower(ch));
            ch=fgetc(fdados);
        }
        fclose(fdados);
    }
    void toUpperFile(char* filename){
        FILE *fdados = fopen(filename,"r");
        char *d;
        char ch=fgetc(fdados);
        while (ch!=EOF) {
            printf("%c",toupper(ch));
            ch=fgetc(fdados);
        }
        fclose(fdados);
    }
    void standartFile(char* filename){
        FILE *fdados = fopen(filename,"r");
        char *d;
        char ch=fgetc(fdados);
        while (ch!=EOF) {
            printf("%c",ch);
            ch=fgetc(fdados);
        }
        fclose(fdados);
    }


/*------------------------------------------------------------------------------
Main
------------------------------------------------------------------------------*/
int main(int argc, char const *argv[]) {
    char *u="-u",*l="-l";
    if(argc==1){
        printf("Wrong usage\n");
        printf("Usage: %s [-u/-l/ ] Filename\n", argv[0]);
        return EXIT_FAILURE;
    }
    if(strcmp(argv[1],u)==0){
        toUpperFile(argv[2]);
    }
    else if(strcmp(argv[1],l)==0){
        toLowerFile(argv[2]);
    }
    else{
        standartFile(argv[1]);
    }
    return 0;
}
