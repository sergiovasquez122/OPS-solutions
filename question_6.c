#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	int rc = fork();
	if(rc < 0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if(rc == 0){
		printf("hello ");
	} else {
		int rc_wait = waitpid(rc, NULL, 0);
		printf("world\n");
		printf("value of rc_wait: (%d)\n", rc_wait); 
		printf("value of child pid: (%d)\n", rc);
	}
	return 0;
}
