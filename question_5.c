#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	int rc = fork();
	if(rc < 0){
		// fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if(rc == 0){

	} else {
		int rc_wait = wait(NULL);
		printf("value of wait: (%d)\n", rc_wait);
		printf("value of child pid: (%d)\n", rc)
	}
	return 0;
}
