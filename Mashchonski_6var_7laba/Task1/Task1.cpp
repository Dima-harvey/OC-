#include<unistd.h>
#include<iostream>
#include <stdio.h>
using namespace std;


int main(){
    cout << "Размер страницы (в байтах): " << sysconf(_SC_PAGE_SIZE) <<endl;
    cout << "Количество страниц физической памяти: " << sysconf(_SC_PHYS_PAGES) <<endl;
    cout << "Количество доступных страниц физической памяти в данный момент: " << sysconf(_SC_AVPHYS_PAGES) <<endl;
return 0;
}