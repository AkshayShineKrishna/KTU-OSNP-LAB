#include<stdio.h>

int main(){
    int x = 1;
    int k = fork();
    if(k < 0){
        printf("error\n");
    }else if(k == 0){
        printf("child has x = %d\n",++x);
    }else{
        printf("parent has x = %d\n",--x);
    }
    return(0);
}