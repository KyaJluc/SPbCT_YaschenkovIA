#pragma once
#include "table.h"

ref class autotable:table
{
public:
	autotable(int**, int , int, int**);
	autotable();
	int fillautotable(int**);
	~autotable();
private:
	int** atab;
};

