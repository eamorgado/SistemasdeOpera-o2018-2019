#include <sys/wait.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SOCK0 0
#define SOCK1 1
#define DATA0 "In every walk with nature..."
#define DATA1 "...one receives far more than he seeks."
/* by John Muir */

int main(int argc, char* argv[]) {
    int sockets[2];
    char buf[BUFSIZ];
    //char line[BUFSIZ];
    FILE *fp;
    pid_t pid;
    //AF_UNIX => in this computer, not in network
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockets) < 0) {
        perror("opening stream socket pair");
        exit(1);
    }
    if ((pid = fork()) < 0) {
        perror("fork");
        return EXIT_FAILURE;
    }
    else if (pid == 0) {
        /* this is the child */
        close(sockets[SOCK0]); //close parent socket
        if (read(sockets[SOCK1], buf, sizeof(buf)) < 0)
          //reade form socket child error
            perror("reading stream message");
        int i=0;
        while(buf[i]!='\0'){
          *(buf+i) = toupper(*(buf+i));
          i++;
        }
        printf("message from %d-->%s\n", getppid(), buf);
        /*if (write(sockets[SOCK1], buf, sizeof(buf)) < 0)
        //Writting to aparent error
            perror("writing stream message");
          */
        close(sockets[SOCK1]);
        /* leave gracefully */
        return EXIT_SUCCESS;
    }
    else {
        /* this is the parent */
        close(sockets[SOCK1]);
        if(argc != 2)
            perror("No file given");
        if(access(argv[1],F_OK)==-1)
            perror("No file exists");
        fp = fopen(argv[1],"r");
        if(!fp)
            perror("Error Opening file");

        fseek(fp, 0, SEEK_END);
        long fsize = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        char *string = malloc(fsize + 1);
        fread(string, 1, fsize, fp);
        fclose(fp);
        string[fsize] = '\0';
        strcpy(buf,string);
        if (write(sockets[SOCK0], buf, sizeof(buf)) < 0)
            perror("writing stream message");
        if (read(sockets[SOCK0], buf, sizeof(buf)) < 0)
            perror("reading stream message");
        printf("message from %d-->%s\n", pid, buf);
        close(sockets[SOCK0]);
        if (waitpid(pid, NULL, 0) < 0) {
        /* wait for child and exit */
            perror("did not catch child exiting");
            return EXIT_FAILURE;
        }
        printf("end\n");
        return EXIT_SUCCESS;
    }
}
