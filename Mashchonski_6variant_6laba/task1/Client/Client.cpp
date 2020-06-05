#include<sys/mman.h>
#include<iostream>
#include<unistd.h> 
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>        
#include<fcntl.h>           
#include<string.h>
#include<errno.h>
#include<semaphore.h>
using namespace std;

#define semaphore "/task1"
int main(){
	sem_t *sem;
	int file, msg_size = 256;
    
        const char* name = "/message";
	file = shm_open(name, O_RDWR, 0666); 
	if(file == -1){
		cout << "error :" << errno <<"\n";
		return 1;
	}	
	if((sem = sem_open(semaphore, 0)) == SEM_FAILED) {
		cout << "Don't open semaphore\n";
		return 2;
	}
	
    ftruncate(file,msg_size);
	void* mem_ptr = mmap(0, msg_size, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);
	char message[256];
	
     while(true){
		cout << "You:";
		cin.getline(message, msg_size);
		memcpy(mem_ptr, message, msg_size);
		if(!strcmp(message,"close"))
		{
		   cout << "Close\n";
		   break;
		}
		sem_post(sem);
		sleep(0);
		cout << "Server:";
		sem_wait(sem);
		sleep(0);
		memcpy(message, mem_ptr, msg_size);
		cout << message << "\n";
		if(!strcmp(message,"close"))
		{
		   cout << "Close\n";
		   break;
		}
	}
    sem_post(sem);
  	munmap(mem_ptr, msg_size);
	sem_close(sem);
	return 0;
}