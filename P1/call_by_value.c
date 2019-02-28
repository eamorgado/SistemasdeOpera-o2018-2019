#include <stdio.h>
//if it is by value, the values will only be altered in the function memmory
//Once we leave it the actual values will never have been changed
    void swap(int n1, int n2) {
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
int main() {
    int n1 = 1;
    int n2 = 2;
    swap(n1, n2);
    printf("n1: %d n2: %d\n", n1, n2);
    return 0;
}
