#include "table.h"
#include <ctime>
#include <iostream>

table::table(int** tab,int n, int m)
{
	//throw gcnew System::NotImplementedException();
	/*int** tab = new int* [n];
	for (int i = 0; i < n; i++)
		tab[i] = new int [m];*/
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tab[i][j] = rand() % 10;
}

table::table()
{
	//throw gcnew System::NotImplementedException();
	n = 0;
	m = 0;
	int **tab = new int* [n];
	for (int i = 0; i < n; i++)
		tab[i] = new int[m];
}

int table::filltable(int** tab)
{
	//srand(time(NULL));

	//for (int i = 0; i < n; i++)
		//for (int j = 0; j < m; j++)
			//tab[i][j] = rand()%10;
	return** tab;
}

table::~table()
{
	//throw gcnew System::NotImplementedException();
	//delete[] tab;
}
