#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<stdio.h>


int main(){
	char *message = NULL;
	int n = -1;
	int exit_code = -1;
	pid_t pid = fork();

	switch(pid){
		case -1:
			printf("fork failed\n");
			exit(0);
		case 0:
			n = 5;
			message = "this is child";
			break;
		default:
			n = 3;
			message = "this is parent";
			break;
	}

	for(int i = 0; i < n; i++){
		puts(message);
		sleep(1);
	}
	exit(0);
}
