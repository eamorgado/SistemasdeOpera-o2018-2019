#include <stdio.h>
int main(){
    printf("Hello World!\n");
    return 0;
    /*
        gcc -E hello.c --pre-processor
        gcc -S --inspect assembly
        gcc -Wall --warnings
        Debugger:
            gcc -g -o hello hello.c
            gdb hello
                gbd> break main
                gdb> run.....
        
    */
}
