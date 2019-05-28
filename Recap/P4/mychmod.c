#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mod(char* option,char* file){
    int perms = atoi(option); //convert option into int
    int operms = perms%10; //get others permition
    perms /= 10; //decrease number;
    int gperms = perms%10; //get group permitions;
    perms /=10;
    int uperms = perms%10;

    mode_t newperms = (mode_t)0;

    /**
     * permitions = r-w-x  others-group-user
     * S_IRWXU -> r-w-x for user (7)
     * S_IXUSR -> --x for user (1)
     * S_IWUSR -> -w- for user (2)
     * (3) -> --wx for user
     * S_IRUSR -> r-- for user (4)
     * (5) -> r-x for user
     * (6) -> rw- for user
     * --------
     * S_I[R,W,X][USR,GRP,OTH]
    **/
   switch(uperms){
       case 0: break;
       case 1: newperms |= S_IXUSR; break;
       case 2: newperms |= S_IWUSR;break;
       case 3: newperms |= S_IWUSR | S_IXUSR; break;
       case 4: newperms |= S_IRUSR; break;
       case 5: newperms |= S_IRUSR | S_IXUSR; break;
       case 6: newperms |= S_IRUSR | S_IWUSR; break;
       case 7: newperms |= S_IRWXU; break;
       default: (void)fprintf(stderr, "%s: illegal permission value\n",option); 
            exit(EXIT_FAILURE); 
        break;
   }
   switch(gperms){
       case 1: newperms |= S_IXGRP; break;
       case 2: newperms |= S_IWGRP;break;
       case 3: newperms |= S_IWGRP | S_IXGRP; break;
       case 4: newperms |= S_IRGRP; break;
       case 5: newperms |= S_IRGRP | S_IXGRP; break;
       case 6: newperms |= S_IRGRP | S_IWGRP; break;
       case 7: newperms |= S_IRGRP | S_IWGRP | S_IXGRP; break;
       default: (void)fprintf(stderr, "%s: illegal permission value\n",option); 
            exit(EXIT_FAILURE); 
        break;
   }
   switch(operms){
       case 1: newperms |= S_IXOTH; break;
       case 2: newperms |= S_IWOTH;break;
       case 3: newperms |= S_IWOTH | S_IXOTH; break;
       case 4: newperms |= S_IROTH; break;
       case 5: newperms |= S_IROTH | S_IXOTH; break;
       case 6: newperms |= S_IROTH | S_IWOTH; break;
       case 7: newperms |= S_IROTH  | S_IWOTH  | S_IXOTH ; break;
       default: (void)fprintf(stderr, "%s: illegal permission value\n",option); 
            exit(EXIT_FAILURE); 
        break;
   }
   if(chmod(file,newperms)==-1){
       (void)fprintf(stderr, "%s: cannot chmod %s\n", option, file);
        exit(EXIT_FAILURE);
   }   
}

int main(int argc, char *argv[]){
    if(argc!=3){
        (void)fprintf(stderr, "usage: %s perms file\n", argv[0]);
        return EXIT_FAILURE;
    }
    mod(argv[1],argv[2]);
    return EXIT_SUCCESS;
}
