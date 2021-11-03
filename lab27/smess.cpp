﻿/* Клиент работы с сообщениями */
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <locale>
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
	printf("Ввести имя каталога:\n");
	cin>>(text);
	textLen = strlen(text);
	if ((key = ftok("smess.cpp", 0)) == -1) 
	{
		perror("Ошибка создания ключа");
		return 1;
	} 
	if ((fd = msgget(key, IPC_CREAT | 0644)) == -1) 
	{
		perror("Ошибка создания очереди");
		return 1;
	} 
	strncpy(buf.mtext, text, textLen); 
	buf.mtype = 1L; 
	if ((fd = msgsnd(fd, &buf, textLen, 0)) == -1) 
	{
		perror("Ошибка посылки сообщения");
		return 1;
	}
	return 0;
}