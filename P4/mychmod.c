#include <sys/types.h>
/* ... */
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

/*
#define S_IRWXU 0000700    //RWX mask for owner
#define S_IRUSR 0000400    // R for owner
#define S_IWUSR 0000200    // W for owner
#define S_IXUSR 0000100    // X for owner

#define S_IRWXG 0000070    // RWX mask for group
#define S_IRGRP 0000040    // R for group
#define S_IWGRP 0000020    // W for group
#define S_IXGRP 0000010    // X for group

#define S_IRWXO 0000007    // RWX mask for other
#define S_IROTH 0000004    // R for other
#define S_IWOTH 0000002    // W for other
#define S_IXOTH 0000001    // X for other

#define S_ISUID 0004000    // set user id on execution
#define S_ISGID 0002000    // set group id on execution
#define S_ISVTX 0001000    //save swapped text even after use
*/


int main(int argc, char* argv[]) {
    if (argc != 3 ) {
        (void)fprintf(stderr, "usage: %s perms file\n", argv[0]);
        return EXIT_FAILURE;
    }
    int perms = atoi(argv[1]); //convert string to int
    int operms = perms % 10;
    perms = perms / 10;
    int gperms = perms % 10;
    perms = perms / 10;
    int uperms = perms;
    mode_t newperms = (mode_t)0;

    switch (uperms) { //user permitions/group permissions
        case 0: break; //---------
        case 1: newperms |= S_IXUSR; break; //x permition
        case 2: newperms |= S_IWUSR; break; //w perm
        case 3: newperms |= S_IWUSR | S_IXUSR; break; //wx perm
        case 4: newperms |= S_IRUSR; break; //r
        case 5: newperms |= S_IRUSR | S_IXUSR; break;//rx
        case 6: newperms |= S_IRUSR | S_IWUSR; break;//rw
        case 7: newperms |= S_IRWXU;//rwx
        default:
        (void)fprintf(stderr, "%s: illegal permission value\n", argv[0]);
        /* ... */
        return EXIT_FAILURE;
    }
    switch (gperms) {//group permitions
        case 0: break;
        case 1: newperms |= S_IXGRP; break; //x
        case 2: newperms |= S_IWGRP; break;//w
        case 3: newperms |= S_IWGRP | S_IXGRP; break;//wx
        case 4: newperms |= S_IRGRP; break;//r
        case 5: newperms |= S_IRGRP | S_IXGRP; break; //rx
        case 6: newperms |= S_IRGRP | S_IWGRP; break;//rw
        case 7: newperms |= S_IRGRP | S_IWGRP | S_IXGRP; break;//rwx
        default:
        /* ... */
        return EXIT_FAILURE;
    }
    switch (operms) { //other
        case 0: break;
        case 1: newperms |= S_IXOTH; break; //x
        case 2: newperms |= S_IWOTH; break;//w
        case 3: newperms |= S_IWOTH | S_IXOTH; break;//wx
        case 4: newperms |= S_IROTH; break;//r
        case 5: newperms |= S_IROTH | S_IXOTH; break;//rx
        case 6: newperms |= S_IROTH | S_IWOTH; break;//rw
        case 7: newperms |= S_IRWXO; break;//rwx
        default:
            (void)fprintf(stderr, "%s: illegal permission value\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (chmod(argv[2], newperms) == -1) {
        (void)fprintf(stderr, "%s: cannot chmod %s\n", argv[0], argv[2]);
        return EXIT_FAILURE;
    }
    /* ... */
}
