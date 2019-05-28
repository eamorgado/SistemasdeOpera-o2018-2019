#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <unistd.h>

void wc(char* filename,char* flag){
    if(access(filename, F_OK)==-1){
        perror("No file included");
        exit(EXIT_FAILURE);
    }
    FILE* fp = fopen(filename,"r");
    
    if(!fp){
        perror("Unable to open file to copy");
        exit(EXIT_FAILURE);
    }
    int c,w,l;
    c=w=l=0;
    char ch = fgetc(fp);
    while(ch!=EOF){
        c++;
        if(c>=1 && ch==' ') w++;
        if(c=='\n') l++;
        ch = fgetc(fp);
    }
    int v=c;
    if(strcmp(flag,"-w")==0) v=w;
    else if(strcmp(flag,"-l")==0) v=l;
    printf("%d\n",v);
    fclose(fp);
}
int main(int argc, char* argv[]){
    if(argc==2||argc==3){
        if(argc==3) wc(argv[2],argv[1]);
        else wc(argv[1],"");
        return EXIT_SUCCESS;
    }
    printf("Too many/few arguments\nUsage: %s [flag] file\n",argv[0]);
    return EXIT_SUCCESS;
}