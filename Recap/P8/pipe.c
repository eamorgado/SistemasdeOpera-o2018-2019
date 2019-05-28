#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define READ 0
#define WRITE 1
#define LINESIZE BUFSIZ

int main(int argc, char* argv[]) {
    int n, r, fd[2];
    pid_t pid;
    char line[LINESIZE];
    if (pipe(fd) < 0) {
        perror("pipe error");
        exit(EXIT_FAILURE);
    }
    if ((pid = fork()) < 0) {
        perror("fork error");
        exit(EXIT_FAILURE);
    }
    else if (pid > 0) {
        /* parent */
        
        close(fd[WRITE]);
        if ((n = read(fd[READ], line, LINESIZE)) < 0 ) {
        fprintf(stderr, "Unable to read from pipe: %s\n", strerror(errno));
        }
        close(fd[READ]);
        /* write message from parent */
        write(STDOUT_FILENO, line, n);
        exit(EXIT_SUCCESS);
    }
    else {
        /* child */
        FILE* fp = fopen(argv[1],"r");
        if(!fp){
            fprintf(stderr, "Unable to open file\n");
            exit(EXIT_FAILURE);
        }
        
        fseek(fp,0,SEEK_END);
        long fsize = ftell(fp);
        fseek(fp,0,SEEK_SET);

        fread(line,1,fsize,fp);

        close(fd[READ]);
        
        if ((r = write(fd[WRITE], line, strlen(line))) < 0){
        fprintf(stderr, "Unable to write to pipe: %s\n", strerror(errno));
        }
        close(fd[WRITE]);
        /* exit gracefully */
        exit(EXIT_SUCCESS);
    }
}