#include<stdlib.h>
#include<stdio.h>

int main(){
    int x = 1;
    int k = fork();
    if(k < 0){
        printf("error\n");
    }
    if(k == 0){
        printf("child has x = %d\n",++x);
    }else{
        wait(1000);
        printf("parent has x = %d\n",--x);
    }
    
    return(0);
}