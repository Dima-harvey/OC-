
#include<sys/mman.h>
#include<iostream>
#include<unistd.h> 
#include<stdio.h>
#include<sys/stat.h>       
#include<fcntl.h>          
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<semaphore.h>
using namespace std;
#define semaphore "/task1"


int main(){
	sem_t *sem ;
	int file, SIZE = 256;
  	const char* name = "/message";	  
	file = shm_open(name, O_RDWR | O_CREAT, 0666); 
	if(file == -1){
		cout << "error :" << errno <<"\n";
		return 1;
	}
	if((sem= sem_open(semaphore, O_CREAT, 0660, 0)) == SEM_FAILED){
		cout << "Don't open semaphore\n";
		return 2;
	}
	void* mem = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);
	char message[256];

	cout << "I wait...\n";

        while(true){
		cout << "Client:";
		sem_wait(sem);
		memcpy(message, mem, SIZE);
		cout << message << "\n";
		if(!strcmp(message,"close"))
		{
		   cout << "Close\n";
		   break;
		}
		else {
			cout << "Server:";
			cin >> message;
			if(!strcmp(message,"close"))
		    {
		       cout << "Close\n";
		       break;
		    }
			memcpy(mem, message, SIZE);
			sem_post(sem);
			sleep(0);
		}
		
	}
	if(shm_unlink(name) != 0){
    	cout << "memory don't delete: " << errno << endl;
    	return 1;
  	}
	sem_unlink(semaphore);
	if(sem_close(sem) != 0){
	  	return 2;
	}
	return 0;
}