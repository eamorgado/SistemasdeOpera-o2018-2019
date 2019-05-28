#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int nextBlockSize(int count,int buffer_size){
    return (count>= buffer_size)? buffer_size: count%buffer_size;
}

void cat(char* file){
    //check file if it can be opened and is readable
    int fd = open(file,O_RDONLY);
    if(fd==-1){
        perror("Cannot open file");
        exit(EXIT_FAILURE);
    }

    //get file size
    struct stat info;
    int ret = lstat(file,&info);
    if(ret==-1){
        perror("Cannot stat");
        exit(EXIT_FAILURE);
    }

    //print contents of blocks
    int count = info.st_size;
    char buffer[BUFFER_SIZE];
    while(count!=0){
        int bytesin = read(fd,buffer,nextBlockSize(count,BUFFER_SIZE));
        count-=bytesin;
        write(STDOUT_FILENO,buffer,bytesin);
    }
    close(fd);
}
int main(int argc, char* argv[]){
    if(argc<2){
        //one element
        printf("Usage: %s file [files]\n",argv[0]);
        return EXIT_FAILURE;
    }
    int i=1;
    while(i<argc)
        cat(argv[i++]);
    return EXIT_SUCCESS;
}
