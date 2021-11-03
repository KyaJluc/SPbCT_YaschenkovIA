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
	char text[80];
	int fd;
	cout << "Enter command:" << endl;
	cin >> text;
	mkfifo(NAME, S_IFIFO | S_IRWXU | S_IRWXG | S_IRWXO);
	if ((fd = open(NAME, O_WRONLY)) == -1) {
		perror("Ошибка открытия клиента");
		return 1;
	}
	write(fd, text, strlen(text));
	cout << "Записано в file.txt";
	system(text);
	close(fd);
	return 0;
}