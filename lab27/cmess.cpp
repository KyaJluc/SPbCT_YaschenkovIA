/* Сервер работы с сообщениями */
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <locale>
#include <sys/stat.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	key_t key;
	struct mybuf 
	{
		long mtype;
		char mtext[81];
	};
	struct mybuf buf;
	int fd;
	char text[81];
	int textLen;
	if ((key = ftok("smess.cpp", 0)) == -1) 
	{
		perror("Ошибка создания ключа");
		return 1;
	}
	if ((fd = msgget(key, 0)) == -1) 
	{
		perror("Ошибка создания очереди");
		return 1;
	} 
	if ((fd = msgrcv(fd, &buf, 80, 0, 0)) == -1) 
	{
		perror("Ошибка приема сообщения");
		return 1;
	} 
	chmod (buf.mtext, 644);
	printf("Set permision Write for %s", buf.mtext); 
	return 0;
}