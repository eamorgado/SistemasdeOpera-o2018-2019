#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

void pwd(){
    char cwd[PATH_MAX];
    if(getcwd(cwd,sizeof(cwd))!=NULL){
        printf("Current Working dir: %s\n",cwd);
    }
    else{
        perror("getcwd() error");
        exit(EXIT_FAILURE);
    }
}
int main(int argc, char* argv[]){
    pwd();
    return EXIT_SUCCESS;
}