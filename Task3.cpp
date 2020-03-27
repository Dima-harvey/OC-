#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <signal.h>

using namespace std;
int main(int argc,char const *argv[])
{
	cout<<"Enter pid for stop process: ";
	pid_t pid;
	cin>>pid;

	if(kill(pid,0)!=-1){
	  cout<<"Yes"<<endl;
 	}else{
         cout<<"Dont process";
         return -1;
        }
	if(kill(pid,SIGINT) !=0){
	  cout<<"Not SIGTSTP"<<endl;
        return -1;
 	}
}
