#include<sys/stat.h>
#include<sys/types.h>
#include<sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
using namespace std;
#define SIZE 128

int main(){

    int mas[128];
	char *buf = new char[1024];
    char str[33];
	int kol=1;
    int p=0;
	char *buf1 = new char[1024];
    int fd;
    cout<< "Enter file(file.txt)->";
    char file[20];
    cin.getline(file, 20);
    fd = open(file, O_RDWR, S_IRUSR) ;
	if(fd==-1){ 
        cout<< "Error " <<endl;
        system("pause");
        return 1;
    }
	void* myFile; 
    myFile = mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(myFile==MAP_FAILED){ 
        cout<< "Error " <<endl;
        system("pause");
        return 1;
    }
	memcpy(buf, myFile, SIZE); 
 
	cout<< "Start (input):" << endl;
    cout<< buf <<endl;

      for(int i=0;i<strlen(buf);i++){
	    for(int j=1;j<strlen(buf);j++){
		    if(buf[i]==buf[j]&& i!=j){
		         kol++;
                }
		     mas[i]=kol;
	    }
	   kol=1;
       int b=mas[i]*100/strlen(buf);
       buf1[p]=buf[i];
	   ++p;
       buf1[p]='-';
       ++p;
        buf1[p]='-';
        ++p;
        buf1[p]='>';
        ++p;
        sprintf(str,"%d",b);
        buf1[p]=str[0];
         ++p;
	    buf1[p]=str[1];
           ++p;
	   buf1[p]='%';
           ++p;
           buf1[p]='\n';
           ++p;
    }
	cout<< "End file for output:" <<endl; 
        cout<< buf1 << endl;
	memcpy(myFile, buf1, SIZE); 
  	if(close(fd) != 0){ 
        cout<< "Error " <<endl;
        system("pause");
        return 1;
	}
	if(munmap(myFile, SIZE) != 0){
		cout<< "Error " <<endl;
        system("pause");
        return 1;
	}else{
        cout<<"Mapping in memory is good"<<endl;
    }
    
 
    return 0;
}