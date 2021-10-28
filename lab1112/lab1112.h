#pragma once
#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
class Atd {
	class Spisok
	{
	public:
		char simv; //Данные
		Spisok* next; //Указатель на следующий узел
		Spisok(char x = NULL) //Конструктор
		{
			simv = x; next = NULL;
		}
	};
	Spisok* begin, * end; //Указатели на начало, конец списка
public:
	Atd(); //Конструктор по умолчанию
	Atd(const char* str); //Конструктор с параметрами
	~Atd(); //Деструктор
	Atd& operator [](int index); //Перегрузка операции []-доступ к элементу в заданной позиции
	Atd& operator +(const Atd&); //Перегрузка операции + - объединить два списка
	bool operator ==(const Atd&); //Перегрузка операции == - проверка на равенство
	void Print(); //Функция вывода на экран
};
//Конструктор с параметрами
Atd::Atd(const char* str)
{
	Spisok* pv = new Spisok;
	pv->simv = str[0];
	begin = end = pv;
	for (int i = 1; i <= (int)strlen(str); i++)
	{
		Spisok* pv = new Spisok;
		pv->simv = str[i];
		end->next = pv;
		end = pv;
	}
	cout << "Вызван конструктор с параметрами\n";
}
//Деструктор
Atd::~Atd()
{
	if (begin != NULL)
	{
		Spisok* pv = begin;
		while (pv)
		{
			pv = begin->next;
			delete begin;
			begin = pv;
		}
	}
	cout << endl << "Вызван деструктор.\n";
}
//Перегрузка операции [] - доступ к элементу в заданной позиции
Atd& Atd::operator [](int x)
{
	cout << "Вызвана перегрузка оператора '[]'.\n" << "Получен доступ к элементу в позиции "<<x;
	return (*this);
};
//Перегрузка операции + - объединить два списка
Atd& Atd::operator +(const Atd&)
{
	cout << "Вызвана перегрузка оператора '+'.\n";
	cout << "Объединение first и second\n";
	return (*this);
};
//Перегрузка операции == - проверка на равенство
bool Atd::operator ==(const Atd& x)
{
	cout << "Вызвана перегрузка оператора '=='.\n";
	Spisok* pv = begin;
	Spisok* dpv = x.begin;
	while ((pv) && (dpv))
	{
		if (pv->simv != dpv->simv) return false;
		pv = pv->next;
		dpv = dpv->next;
	}
	return true;
}
//Функция просмотра всего списка
void Atd::Print()
{
	Spisok* pv = begin;
	cout << endl << "Элемент:\n";
	while (pv)
	{
		cout << pv->simv << ' ';
		pv = pv->next;
	}
	cout << endl;
}