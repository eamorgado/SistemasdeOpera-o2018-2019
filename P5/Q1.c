#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    /* fork a child process */
    //pid_t pid;
    //pid=
    fork(); //2 processos

    printf("PID1:\nParent %ld , Son %ld\n",(long)getpid(),(long)getppid());
    /* fork another child process */
    fork(); //4
    printf("PID2:\nParent %ld , Son %ld\n",(long)getpid(),(long)getppid());

    /* and fork another */
    fork();//8
    printf("PID3:\nParent %ld , Son %ld\n",(long)getpid(),(long)getppid());
    return EXIT_SUCCESS;
}
