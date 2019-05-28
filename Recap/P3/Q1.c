#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include <stdlib.h>

#define MAX_STR_SIZE 64

int main(int argc, char* argv[]) {
    if(argc==2){
        char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
        printf("====ToLower====\n");
        strcpy(p1,argv[1]);
        printf("Opriginal: %s\n",p1);

        int i=0;
        while(*(p1+i) != '\0') *(p1+i++) = tolower(*(p1+i));

        printf("The new string: %s\n",p1);
    }
    else if(argc==3){
        printf("====Counter====\n");
        char* token;
        token = strstr(argv[2],argv[1]);
        if(token!=NULL){
            int i=0;
            while(token!=NULL){
                i++;
                token = strstr(token+1,argv[1]);
            }
            printf("Times: %d\n",i);
        }
        else printf("Does not occur\n");
    }
    else{
        if(argc>3)
            printf("Error, too many arguments\n");
        else
            printf("Error, too few arguments\n");
        printf("Usage: %s String [String]\n",argv[0]);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}