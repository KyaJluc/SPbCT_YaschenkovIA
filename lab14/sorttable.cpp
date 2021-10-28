#include "sorttable.h"

sorttable::sorttable(int **tab, int n, int m, int** stab)//:table(tab, n, m)
{
	int c;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			stab[i][j] = tab[i][j];

	for(int g=0;g<n;g++)
	for (int i = 0; i < m - 1; i++)
		for (int j = 0; j < m - i - 1; j++)
			if (stab[g][j] > stab[g][j+1])
			{
				c = stab[g][j];
				stab[g][j] = stab[g][j + 1];
				stab[g][j + 1] = c;
			}
}

sorttable::sorttable()
{

}

int sorttable::fillsorttable(int **stab)
{
	return **stab;
}

sorttable::~sorttable()
{
	delete[] stab;
}