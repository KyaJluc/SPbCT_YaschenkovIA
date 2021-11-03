#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define NAME "sfifo.cc"
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int fd;
	char buf[80];
	read(open(NAME, 0), buf, sizeof(buf));
	cout << "Получено->" << buf << endl;
	close(fd);
	unlink(NAME); return 0;
}