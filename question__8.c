#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	int fd[2];
	pipe(fd);
	chdir("/home/sergio/OPS-solutions");

	int pid = fork();
	if(pid == 0){
		close(fd[1]);
		int ret = dup2(fd[0], 0);
		if(ret < 0) perror("dup2");
		char* argv[10];
		argv[0] = "more"; argv[1] = NULL;
		execvp("more", argv);
	}

	int pid2 = fork();
	if(pid2 == 0){
		int ret = dup2(fd[1], 1);
		if(ret < 0) perror("dup2");
		char* argv[10];
		argv[0] = "ls"; argv[1] = "-l";
		argv[2]= NULL;
		execvp("ls", argv);
	}

	close(fd[0]);
	close(fd[1]);

	int status;
	waitpid(pid, &status, 0);
	printf("Done!\n");
	return 0;
}
