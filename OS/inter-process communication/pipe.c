#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

#define BS 25
#define RE 0
#define WE 1

int main(){
	system("clear");
	printf("Enter the message : ");
	gets(wrm);
	char rm[BS];
	int fd[2],pid;
	if (pipe(fd) == -1){
		fprintf(stderr,"Pipe failed"); 
	}
	pid = fork();
	if(pid == -1){
	fprintf(stderr,"Fork failed");
	}
	if(pid > 0){
		close(fd[RE]);
		write(fd[WE],wrm,strlen(wrm) + 1);
		close(fd[WE]);	
	}else{
		close(fd[WE]);
		read(fd[RE],rm,BS);
		printf("%s\n",rm);
		close(fd[RE]);
	}
}
