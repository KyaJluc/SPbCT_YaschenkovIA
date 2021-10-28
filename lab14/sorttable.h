#pragma once
#include "table.h"

ref class sorttable:table
{
public:
	sorttable(int**, int, int, int**);
	sorttable();
	int fillsorttable(int**);
	~sorttable();
private:
	int** stab;
};
