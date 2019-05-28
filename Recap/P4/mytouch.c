#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <utime.h>
#include <time.h>

int exist(char* filename){
    return ((access(filename,F_OK)!=-1)? 1 : 0);
}
void touch(char* filename){
    if(!exist(filename)) creat(filename,644);
    else{
        struct stat info;
        time_t mtime;
        struct utimbuf new_time;
        if(lstat(filename,&info)==-1){
            fprintf(stderr, "fsize: Can’t stat %s\n",filename);
            exit(EXIT_FAILURE);
        } 
        mtime = info.st_mtime;
        new_time.actime = info.st_atime; //keep kast access
        new_time.modtime = time(NULL); //current time
        utime(filename,&new_time);
    }

}

int main(int argc, char* argv[]){
    if(argc<2){
        printf("Usage: %s file\n",argv[0]);
        return EXIT_FAILURE;
    }
    int i=1;
    while(i<argc)
        touch(argv[i++]);
    return EXIT_SUCCESS;
}
