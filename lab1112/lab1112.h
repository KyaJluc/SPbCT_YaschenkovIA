#pragma once
#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
class Atd {
	class Spisok
	{
	public:
		char simv; //������
		Spisok* next; //��������� �� ��������� ����
		Spisok(char x = NULL) //�����������
		{
			simv = x; next = NULL;
		}
	};
	Spisok* begin, * end; //��������� �� ������, ����� ������
public:
	Atd(); //����������� �� ���������
	Atd(const char* str); //����������� � �����������
	~Atd(); //����������
	Atd& operator [](int index); //���������� �������� []-������ � �������� � �������� �������
	Atd& operator +(const Atd&); //���������� �������� + - ���������� ��� ������
	bool operator ==(const Atd&); //���������� �������� == - �������� �� ���������
	void Print(); //������� ������ �� �����
};
//����������� � �����������
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
	cout << "������ ����������� � �����������\n";
}
//����������
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
	cout << endl << "������ ����������.\n";
}
//���������� �������� [] - ������ � �������� � �������� �������
Atd& Atd::operator [](int x)
{
	cout << "������� ���������� ��������� '[]'.\n" << "������� ������ � �������� � ������� "<<x;
	return (*this);
};
//���������� �������� + - ���������� ��� ������
Atd& Atd::operator +(const Atd&)
{
	cout << "������� ���������� ��������� '+'.\n";
	cout << "����������� first � second\n";
	return (*this);
};
//���������� �������� == - �������� �� ���������
bool Atd::operator ==(const Atd& x)
{
	cout << "������� ���������� ��������� '=='.\n";
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
//������� ��������� ����� ������
void Atd::Print()
{
	Spisok* pv = begin;
	cout << endl << "�������:\n";
	while (pv)
	{
		cout << pv->simv << ' ';
		pv = pv->next;
	}
	cout << endl;
}