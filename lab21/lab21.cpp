﻿#include <iostream>
#include <Windows.h>
#include <process.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <wchar.h>
#include <mbstring.h>
#define BUF_SIZE 256
static void cat(LPTSTR, LPTSTR);

int main(DWORD argc, LPTSTR argv[])
/* Создает отдельный процесс для каждого файла из командной строки.
результатов предоставляется временный файл в текущем каталоге. */
{
	HANDLE hTempFile;
	BOOL prov;
	TCHAR outFile[MAX_PATH + 100];
	SECURITY_ATTRIBUTES StdOutSA =
		/* права доступа для наследуемого дескриптора. */
	{ sizeof
	(SECURITY_ATTRIBUTES), NULL, TRUE };
	TCHAR CommandLine[MAX_PATH + 100];
	STARTUPINFO StartUpSearch, StartUp;
	PROCESS_INFORMATION ProcessInfo;
	DWORD iProc, ExCode;
	HANDLE* hProc;
	/* Указатель на массив дескрипторов процессов. */
	typedef struct
	{
		TCHAR TempFile[MAX_PATH];
	}
	PROCFILE;
	PROCFILE* ProcFile;
	/* Указатель на массив имен временных файлов. */
/* Информация запуска для каждого дочернего процесса поиска и для
процесса, который будет выводить результаты. */
	GetStartupInfo(&StartUpSearch);
	GetStartupInfo(&StartUp);
	/* Зарезервировать место для массива структур данных процессов,
содержащих дескриптор процесса и имя временного файла. */
	ProcFile = (PROCFILE*)malloc((argc - 2) * sizeof(PROCFILE));
	hProc = (HANDLE*)malloc((argc - 2) * sizeof(HANDLE));
	/* Создать отдельный процесс "grep" для каждого файла из командной
строки*/
	for (iProc = 0; iProc < argc - 2; iProc++)
	{
		/* Создать командную строку вида grep argv [1] argv [iProc + 2] */
		printf_s(("%s"), ("grep "), argv[1], argv[iProc + 2]);
		printf(("%s\n"), CommandLine);
		/* Указываем стандартный вывод для процесса поиска. */
		hTempFile = CreateFile(ProcFile[iProc].TempFile, GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, &StdOutSA, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		StartUpSearch.dwFlags = STARTF_USESTDHANDLES;
		StartUpSearch.hStdOutput = hTempFile;
		StartUpSearch.hStdError = hTempFile;
		StartUpSearch.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
		/* Создаем процесс для выполнения командной строки. */
		CreateProcess(NULL, CommandLine, NULL, NULL,
			TRUE, 0, NULL, NULL, &StartUpSearch, &ProcessInfo);
		/* Закрываем ненужные дескрипторы */
		CloseHandle(hTempFile);
		CloseHandle(ProcessInfo.hThread);
		/* Сохраняем дескриптор процесса. */
		hProc[iProc] = ProcessInfo.hProcess;
	}
	/* Все процессы выполняются, подождем их завершения. */
	for (iProc = 0; iProc < argc - 2; iProc += MAXIMUM_WAIT_OBJECTS)
		WaitForMultipleObjects(min(MAXIMUM_WAIT_OBJECTS, argc - 2 -
			iProc), &hProc[iProc], TRUE, INFINITE);
	/* Результирующие файлы отсылаются на стандартный вывод с помощью "cat". */
	for (iProc = 0; iProc < argc - 2; iProc++)
	{
		printf("Proc= %d\n", iProc);
		prov = GetExitCodeProcess(hProc[iProc], &ExCode);
		if (ExCode != 0) DeleteFile(ProcFile[iProc].TempFile);
		if (GetExitCodeProcess(hProc[iProc], &ExCode) && ExCode == 0)
		{
			/* Образец найден - показать результаты. */
			if (argc > 3) printf(("%s : \n"), argv[iProc + 2]);
			fflush(stdout);
			/* требуется для использования стандартного вывода несколькими процессами */
			printf_s(("%s"), ProcFile[iProc].TempFile);
			cat(argv[iProc + 2], (LPTSTR)outFile);
			printf_s(("%s%s"), ("cat "), ProcFile[iProc].TempFile);
			printf(("%s\n"), CommandLine);
			CreateProcess(NULL, CommandLine, NULL, NULL, TRUE, 0, NULL, NULL, &StartUp, &ProcessInfo);
			WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
			CloseHandle(ProcessInfo.hProcess);
			CloseHandle(ProcessInfo.hThread);
		}
		CloseHandle(hProc[iProc]);
		/*DeleteFile (ProcFile [iProc].TempFile); */
	}
	free(ProcFile);
	free(hProc);
	return 0;
}
static VOID cat(LPTSTR hInFile, LPTSTR hOutFile)
{
	CopyFile(hInFile, hOutFile, FALSE);
	return;
}