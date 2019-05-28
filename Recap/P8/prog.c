#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void wc(char* filename){
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("annot open %s\n",filename);
        exit(EXIT_FAILURE);
    }
    char c = fgetc(fp);
    int lines=0,count=0;
    while(c!=EOF){
        count++;
        if(c=='\n') lines++;
        c=fgetc(fp);
    }
    printf("lines:%d chars:%d",lines,count);
    fclose(fp);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("usage: %s file\n",argv[0]);
        return EXIT_FAILURE;
    }
    wc(argv[1]);
    return EXIT_SUCCESS;
}