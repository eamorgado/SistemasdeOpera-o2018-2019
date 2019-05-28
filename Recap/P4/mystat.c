#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

void mystat(char* filename){
    struct stat info;
    if(lstat(filename,&info)==-1){
        fprintf(stderr, "fsize: Can’t stat %s\n",filename);
        exit(EXIT_FAILURE);
    }
    printf("%s size: %d bytes | disk blocks: %d | last access: %d | owner: %d\n\n",filename,
        (int)info.st_size,(int)info.st_blocks,(int)info.st_atime,(int)info.st_uid);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }

    int i=1;
    while(i<argc)
        mystat(argv[i++]);
    return  EXIT_SUCCESS;
}
