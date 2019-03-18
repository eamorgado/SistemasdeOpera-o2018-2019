#include <sys/stat.h>
#include <sys/time.h>
//#include <time.h>
#include <fcntl.h>
#include <unistd.h> //to get access()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int exists(const char *fname){
    FILE *file;
    if(access(fname,F_OK)!=-1)
        //File exists
        return 1;

    else
        //File does not exist
        return 0;
}
int create(char *name){
    //the mode is rw-r--r-- (644)
    int fl;
    fl=creat(name,644);
    if(fl>0)
        return 1;
    return 0;
}

int main(int argc, char const *argv[]) {
    if(argc != 3){
        printf("Error incomplete number of arguments\n");
        return EXIT_FAILURE;
    }
    if(exists(argv[1])==1){
        utimestat(0,argv[1],NULL,0);
    }
    else{
        //File does not exist, creat file;
        int fp;
        fp=create(argv[1]);
        if(fp==1){
            printf("File successfully created\n");
            return EXIT_SUCCESS;
        }
        printf("Failed Creation\n");
        return EXIT_FAILURE;
    }
    return 0;
}
