#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>



int main(int argc, char* argv[]) {
    int value = 5;
    pid_t pid;
    if ((pid = fork()) < 0 ) {
        printf("%s: cannot fork()\n", argv[0]);
        return EXIT_FAILURE;
    }
    else if (pid == 0) {
        /* child process */
        value += 15;
        printf("CHILD: value = %d\nAddress %p\n",value,&value);
        return EXIT_SUCCESS;
    }
    else {
        /* parent process */
        if (waitpid(pid, NULL, 0) < 0) {//while child doesn't change state wait
            printf("%s: cannot wait for child\n", argv[0]);
            return EXIT_FAILURE;
        }
        printf("PARENT: value = %d\nAddress %p\n",value,&value);
        return EXIT_SUCCESS;
    }
}
