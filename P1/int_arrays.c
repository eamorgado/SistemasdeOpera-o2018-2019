#include <stdio.h>
    int main() {
        int i;
        int primes[] = {2, 3, 5, 7, 11};
        for (i = 0; i < sizeof(primes)/sizeof(int); i++) {
            printf("%d <--> %d\n", primes[i], *(primes + i)); //because primes is an int pointer, each value is 4 bytes in distance
        }
        return 0;
    }
