#include<stdio.h>

int main() {
    int i, j, *p, *q; //allocate space
    i = 5; //val(i)=5
    p = &i; //p--->i
    *p = 7;  //val(i)=7
    j = 3; //val(j)=3
    p = &j; // p-->j
    q = p; // val(q)=val(p) => p-->j && q-->j
    p = &i; // p-->i q-->j
    *q = 2; //val(j)=2
    return 0;
}
