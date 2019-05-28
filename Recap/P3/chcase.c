#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <unistd.h>

void chcase(char* filename,char* option){        
    if(access(filename, F_OK)==-1){
        perror("No file included");
        exit(EXIT_FAILURE);
    }
    FILE* fp = fopen(filename,"r");
    if(!fp){
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
    char c = fgetc(fp);
    while(c!=EOF){
        if(strcmp(option,"-u")==0) c = toupper(c);
        else if(strcmp(option,"-l")==0) c = tolower(c);
        printf("%c",c);
        c = fgetc(fp);
    }
    fclose(fp);
}
int main(int argc, char* argv[]){
    if(argc==2||argc==3){
        if(argc==3) chcase(argv[2],argv[1]);
        else chcase(argv[1],"");
        return EXIT_SUCCESS;
    }
    printf("Too many/few arguments\nUsage: %s [flag] file\n",argv[0]);
    return EXIT_SUCCESS;
}