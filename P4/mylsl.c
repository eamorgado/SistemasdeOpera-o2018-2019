#include <stdio.h> 
#include <stdlib.h> 
#include <dirent.h>
#include <sys/stat.h>

int main (int argc, char** argv) { int len; struct dirent *p; DIR *q;
    if (argc != 2) { 
        fprintf (stderr, "usage: %s dirname\n", argv[0]);
        return EXIT_FAILURE;
    } 
    q = opendir (argv[1]); 
    if (q == NULL) { 
        //file
        struct stat info;
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
    printf ("%s/\n", argv[1]); 
    p = readdir(q); 
    while (p != NULL) { 
        printf ("\t%s\n", p->d_name); p = readdir(q); 
    } closedir (q);
    return EXIT_SUCCESS;
}