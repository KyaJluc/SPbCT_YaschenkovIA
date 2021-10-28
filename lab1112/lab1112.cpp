#include <iostream>
#include <conio.h>
#include <string.h>
#include "lab1112.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Нажмите Enter для создания объектов...\n";
	getchar();
	Atd first("Первый");
	cout << "Объект создан.\n" << "Нажмите Еnter для просмотра...";
	getchar();
	first.Print();
	cout << "Нажмите Enter, чтобы создать ещё один объект...\n";
	getchar();
	Atd second("Второй");
	cout << "Объект создан.\n" << "Нажмите enter для просмотра...";
	getchar();
	second.Print();
	cout << "Нажмите Enter, чтобы получить доступ к элементу в заданной позиции\n";
	getchar();
	first[1];
	cout << "\nНажмите Enter, чтобы объединить два списка\n";
	getchar();
	first + second;
	cout << endl << "Сравнение.\n";
	cout << "Нажмите Enter для просмотра результата.\n";
	getchar();
	if (first == second) cout << "Они равны.\n";
	else cout << "Они не равны.\n";
	cout << "Нажмите Enter для вызова деструктора";
	getchar();
}