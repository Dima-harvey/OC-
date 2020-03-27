#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>
using namespace std;

int main(int argc, char const *argv[])
{

        pid_t r;
	 char * leafpad_args[] = {
		"gedit",
		"file",
		NULL
	};
	

	int *ret;
	r = fork();
	if(r==0){
	execvp("gedit",leafpad_args);
	cout << "Process start\n";
	}

	r = wait(ret);


	sleep(600);
	return 0;
}
