#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int pid = getpid();
	int ppid = getppid();

	printf("%d pid\n", pid);
	printf("%d ppid\n", ppid);
	sleep(100);
	return 0;
}
