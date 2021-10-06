#include <iostream>
#include "Car.h"
#include "Lorry.h"

using namespace std; 

void f1(Car& c)
{
	c.Setmark("Opel");
	cout << c;
}

Car f2()
{
	Lorry l("KIA", 1, 2, 3);
	return l;
}

int main()
{
	Car a;
	cin >> a;
	cout << a;
	Car b("Ford", 4, 115);
	cout << b;
	a = b;
	cout << a;
	a = f2();
	cout << a;
	Lorry c;
	cin >> c;
	cout << c;
	system("pause");
}