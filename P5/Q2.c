#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//creates 16 processes
int main(int argc, char* argv[]) {
    for (int i = 0; i < 4; i++)
    fork();
    return EXIT_SUCCESS;
}
