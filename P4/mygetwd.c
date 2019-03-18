#include <unistd.h>
#include <stdio.h>


int main(int argc, char const *argv[]) {
    char cwd[1000];
    if(getcwd(cwd,sizeof(cwd))!=NULL){
        printf("Current Working directory: %s\n",cwd);
    }
    return 0;
}
