#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	int descriptor = open("./question4.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	int rc = fork();
	if(rc < 0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if(rc == 0){
		int descriptor2 = open("./question4.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
		printf("descriptor2: (%d)\n", descriptor2);
		char *myargs[3];
		myargs[0] = strdup("wc");
		myargs[1] = strdup("README.md"); // arg: file to count
		 myargs[2] = NULL;
		 execvp(myargs[0], myargs); // runs word count
	} else{
		printf("descriptor: (%d)\n", descriptor);
	}
	close(STDOUT_FILENO);
	return 0;
}
