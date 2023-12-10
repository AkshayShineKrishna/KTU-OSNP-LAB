#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main() {
    int fd = open("foo.txt",O_RDONLY|O_CREAT);
    printf("fd =%d\n",fd);
    if(fd==1){
        printf("error\n");
    }else{
        printf("file opened\n");
    }
    if(close(fd) == -1){
        printf("error\n");
    }else{
        printf("file closed\n");
    }
    return(0);
}