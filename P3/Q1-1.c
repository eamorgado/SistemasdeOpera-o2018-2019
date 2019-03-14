#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STR_SIZE 64

int main(int argc, char* argv[]) {
    if(argc==2){//Creates new string where everything is lowercase
        char* p = (char*)malloc(MAX_STR_SIZE * sizeof(char));
        strcpy(p,argv[1]);
        int i=0;
        while(*p != '\0'){
            *p=tolower(*p);
            putchar(*p);
            p++;
        }
    }
    else if(argc==3){//return if argv[1] is in argv[2], if so, return number of times
        printf("Counting number of times:\n");
        char* sub_string;
        //copy strings
        sub_string=strstr(argv[2],argv[1]);
        if(sub_string!=NULL){
            int i=1;
            while(sub_string!=NULL) {
                sub_string=strstr(sub_string+1,argv[1]);
                i++;
            }
            printf("Ocorre %d vezes\n",i-1);
        }
        else printf("Não ocorre\n");
    }
    else{
        printf("Error, too many argumens\n");
        printf("Usage: %s String String\n",argv[0]);
        return EXIT_FAILURE;
    }
    return 0;
}
