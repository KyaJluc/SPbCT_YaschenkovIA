#pragma once

ref class table
{
public:
	table(int** , int, int);
	table();
	~table();
	int filltable(int**);
private:
	int** tab;
	int n, m;
};

