#pragma once
#include "table.h"

ref class stroka:table
{
public:
	stroka(int**, int, int, int , int*);
	stroka();
	int fillstroka(int*);
	~stroka();
private:
	int* s;
	int sto;
};

