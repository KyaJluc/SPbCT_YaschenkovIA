#include "stroka.h"

stroka::stroka(int** tab, int n, int m, int sto, int* s): table(tab, n, m)
{
	//int *s = new int[m];
	for (int j = 0; j < m; j++)
		s[j] = tab[sto-1][j];
}

int stroka::fillstroka(int* s)
{
	return* s;
}

stroka::stroka(): table()
{

}

stroka::~stroka()
{
	delete[] s;
}
