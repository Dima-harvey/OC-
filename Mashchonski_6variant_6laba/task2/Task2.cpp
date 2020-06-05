#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

using namespace std;

#define MESSAGE_LEN 64

int main() {
    const char* fifo = "/home/dima/Общедоступные/myfifo";
    int file;
    bool flag = true;

    if (mkfifo(fifo, 0666) == -1) {
        if (errno == 17) flag = false;
        else {
            perror("mkfifo error");
            return 1;
        }
    }

    char* Read = new char[MESSAGE_LEN];
    char* Write= new char[MESSAGE_LEN];

    if (flag) {
        while (true) {
            file = open(fifo, O_WRONLY);
            cout << "Boss 1: ";
            cin.getline(Write, MESSAGE_LEN);
            write(file, Write, strlen(Write) + 1);
            close(file);

            file = open(fifo, O_RDONLY);
            read(file, Read, MESSAGE_LEN);
            cout << "Boss 2: " << Read << endl;
            close(file);
        }
    }
    else {
        while (true) {
            file = open(fifo, O_RDONLY);
            read(file, Read, MESSAGE_LEN);
            cout << "Boss 1: " << Read << endl;
            close(file);

            file = open(fifo, O_WRONLY);
            cout << "Boss 2: ";
            cin.getline(Write, MESSAGE_LEN);
            write(file, Write, strlen(Write) + 1);
            close(file);
        }
    }

    unlink(fifo);
}
