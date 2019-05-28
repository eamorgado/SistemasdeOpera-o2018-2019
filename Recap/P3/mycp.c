#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <unistd.h>

void cp(char* filename,char* file){
    FILE* fp;
    FILE* fc;      
    if(access(filename, F_OK)==-1){
        perror("No file included");
        exit(EXIT_FAILURE);
    }
    if(access(file,F_OK)==-1)
        fc = fopen(file,"a");
    else 
        fc = fopen(file,"w");
    fp = fopen(filename,"r");
    
    if(!fp){
        perror("Unable to open file to copy");
        exit(EXIT_FAILURE);
    }
    if(!fc){
        perror("Unable to open destination file");
        exit(EXIT_FAILURE);
    }

    fseek(fp,0,SEEK_END);
    long fsize = ftell(fp);
    fseek(fp,0,SEEK_SET);

    char* string = (char*)malloc(fsize+1);
    fread(string,1,fsize,fp);
    fwrite(string,1,fsize,fc);
    free(string);
    fclose(fp);
    fclose(fc);
}
int main(int argc, char* argv[]){
    if(argc==2||argc==3){
        if(argc==3) cp(argv[1],argv[2]);
        else{
            char* p = (char*)malloc((strlen("copy_")+strlen(argv[1]))*sizeof(char));
            strcpy(p,"copy_");
            strcat(p,argv[1]);
            cp(argv[1],p);
        }
        return EXIT_SUCCESS;
    }
    printf("Too many/few arguments\nUsage: %s file_to_copy [file]\n",argv[0]);
    return EXIT_SUCCESS;
}