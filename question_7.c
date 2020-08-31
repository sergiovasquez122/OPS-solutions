#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	int rc = fork();
	if(rc < 0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if(rc == 0){
		open("./question7.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
		close(STDOUT_FILENO);
		printf("something\n");
	} else{
		int rc_wait = wait(NULL);
	}
	return 0;
}
