#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	int x = 10;
	int rc = fork();
	printf("x value: %d\n", x);
	if(rc < 0){
		// fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if(rc == 0){
		printf("value of x on child process: %d\n", x);
		printf("changing value of x\n");
		x = 50;
		printf("x is now %d on child process: %d\n", x);
	} else{
		printf("value of x on parent process: %d\n",x );
		printf("changing value of x\n");
		x = 100;
		printf("x is now %d on parent process: %d\n", x);
	}
	return 0;

}
