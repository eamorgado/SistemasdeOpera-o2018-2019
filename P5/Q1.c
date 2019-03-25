#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h>

int main(int argc, char* argv[]) { 
    /* fork a child process */ 
    fork();
    printf("PID 1:\nParent %ld , Son %ld\n",(long)getpid(),(long)getppid());
    /* fork another child process */ 
    fork();
    printf("PID 1:\nParent %ld , Son %ld\n",(long)getpid(),(long)getppid());
    
    /* and fork another */ 
    fork();
    printf("PID 1:\nParent %ld , Son %ld\n",(long)getpid(),(long)getppid());
    return EXIT_SUCCESS;
}
