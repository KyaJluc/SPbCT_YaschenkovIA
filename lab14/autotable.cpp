#include "autotable.h"

autotable::autotable(int** tab, int n, int m, int** atab)//: table(tab, n, m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m-1; j++)
		{
			atab[i][j] = tab[i][j];
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m-1; j++)
		{
			sum += tab[i][j];
		}
		atab[i][m-1] = sum;
		sum = 0;
	}
}

autotable::autotable():table()
{

}

int autotable::fillautotable(int** atab)
{
	return **atab;
}

autotable::~autotable()
{
	delete[] atab;
}