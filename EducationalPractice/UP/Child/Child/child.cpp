#include "lib.h"
#include <string>
#include <fstream>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <Windows.h>
#include <process.h>
#define SIZE 26
using namespace std;

void test(void* param)
{
    Sleep(10000);
    _endthread();
}

int main()
{
   string s;
   cin >> s;
   setlocale(LC_ALL, "rus");
   vector<string> vs;
   string a = "*";
   int x = 9;
   time_t ltime;
   wchar_t buf[SIZE];
   errno_t err;
   time(&ltime);
   err = _wctime_s(buf, SIZE, &ltime);
   cout << "ФИО:\nЯщенков Иван Андреевич\n\nТекущие дата и время:\n";
   wprintf_s(buf);
   cout << "\nИтоговый результат:\n";
   for (int i = 0; i < s.length(); i += 10)
   {
       s.replace(x, 1, a);
       vs.push_back(s.substr(i, 10));
       x += 9;
   }
   for (int i = 0; i < vs.size(); i++)
       cout << vs[i] << "\n";
   cout << _beginthread(test, 0, NULL);
} 