#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

void cat(char*);
void cat(char* filename){
    if(access(filename, F_OK)==-1){
        perror("No file included");
        exit(EXIT_FAILURE);
    }
    FILE* fp = fopen(filename,"r");
    if(!fp){
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *string = malloc(fsize + 1);
    fread(string, 1, fsize, fp);
    printf("%s",string);
    free(string);
    fclose(fp);
}
int main(int argc, char* argv[]){
    if(argc==1){
        printf("Too few arguments\nUsage: %s file [file ..]\n",argv[0]);
        return EXIT_SUCCESS;
    }
    int i=1;
    while(i<argc) cat(argv[i++]);
    return EXIT_SUCCESS;
}
