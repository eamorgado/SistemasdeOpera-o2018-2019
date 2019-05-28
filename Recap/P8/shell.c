#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>


void execute(char* command){
    if (execlp(command,command,NULL) < 0) {
        printf("bummer, did not exec %s\n", command);
        exit(EXIT_FAILURE);
    }
}

int main() {
    char command[50];
    pid_t pid;
    while(1){
        scanf("%s",command);
        if(strcmp(command,"quit")==0) break;
        if((pid = fork())<0){
            printf("Cannot fork\n");
            return EXIT_FAILURE;
        }
        if(pid==0)
            execute(command);
        else{
            if(waitpid(pid,NULL,0)<0){
                printf("Cannot wait for child\n");
                return EXIT_FAILURE;
            }
        }
    }
    return EXIT_SUCCESS;
}