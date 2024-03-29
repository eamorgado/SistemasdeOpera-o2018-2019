#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PP_RD 0  //Read
#define PP_WR 1 //Write

int main(int argc, char* argv[]) {
    int n, r, fd[2];
    pid_t pid;
    char line[BUFSIZ];
    FILE *fp;
    if(argc!=2){
        perror("No file included");
        exit(EXIT_FAILURE);
    }

    if(access(argv[1], F_OK)==-1){
        perror("No file included");
        exit(EXIT_FAILURE);
    }
    fp=fopen(argv[1],"r");
    if(!fp){
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *string = malloc(fsize + 1);
    fread(string, 1, fsize, fp);
    fclose(fp);

    string[fsize] = 0;
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
        close(fd[PP_RD]);
        printf("P=> Parent process with pid %d\n", getpid());
        printf("P=> Messaging the child process (pid %d):\n", pid);
        snprintf(line, BUFSIZ, string, getpid());
        if ((r = write(fd[PP_WR], line, strlen(line))) < 0) {
            fprintf(stderr, "Unable to write to pipe: %s\n", strerror(errno));
        }
        close(fd[PP_WR]);
        /* wait for child and exit */
        if ( waitpid(pid, NULL, 0) < 0) {
            fprintf(stderr, "Cannot wait for child: %s\n", strerror(errno));
        }
        exit(EXIT_SUCCESS);
    }
    else {
    /* child */
        close(fd[PP_WR]);
        printf("C=> Child process with pid %d\n", getpid());
        printf("C=> Receiving message from parent (pid %d):\n", getppid());
        if ((n = read(fd[PP_RD], line, BUFSIZ)) < 0 ) {
            fprintf(stderr, "Unable to read from pipe: %s\n", strerror(errno));
        }
        close(fd[PP_RD]);
        /* write message from parent */
        write(STDOUT_FILENO, line, n);
        /* exit gracefully */
        exit(EXIT_SUCCESS);
    }
}
