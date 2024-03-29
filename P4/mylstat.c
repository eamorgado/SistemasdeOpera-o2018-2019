#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    struct stat info;
    if (argc <= 2) {
        fprintf(stderr, "usage: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }
    int i=1;
    int m_blocks=0, m_bytes=0;
    while(i<argc){
        if (lstat(argv[i], &info) == -1) {
            fprintf(stderr, "fsize: Can’t stat %s\n", argv[i]);
            return EXIT_FAILURE;
        }
        printf("%s size: %d bytes, disk_blocks: %d, last updated: %s, user: %d\n",
        argv[i], (int)info.st_size, (int)info.st_blocks,(int)info.st_uid,ctime((int)info.st_mtime));
        m_blocks+=(int)info.st_blocks;
        m_bytes+=(int)info.st_size;
        i++;
    }
    printf("Total byte size: %d\nTotal Blocks: %d\n",m_bytes,m_blocks);
    return EXIT_SUCCESS;
}
