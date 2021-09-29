#include <iostream>
using namespace std;

class Time
{
public:
	Time();
	void setTime(int, int, int);
	void printMilitary();
	void printStandard();
private:
	int hour; 
	int minute;
	int second;
};
Time::Time() { hour = minute = second = 0; }
void Time::setTime(int h, int m, int s)
{
	hour = (h >= 0 && h < 24) ? h : 0;
	minute = (m >= 0 && m < 60) ? m : 0;
	second = (s >= 0 && s < 60) ? s : 0;
}
void Time::printMilitary()
{
	cout << (hour < 1 ? "0" : "") << hour << ":" << (minute < 1 ? "0" : "") << minute <<
		":" << (second < 1 ? "0" : "") << second;
}
void Time::printStandard()
{
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":" << (minute < 1 ? "0"
		: "") << minute << ":" << (second < 1 ? "0" : "") << second << (hour < 12 ? "AM" : " PM");
}
int main()
{
	setlocale(LC_ALL, "rus");
	Time t;
	cout << "Начальное значение военного времени равно ";
	t.printMilitary();
	cout << endl << "Начальное значение стандартного времени равно ";
	t.printStandard();
	t.setTime(13, 27, 6);
	cout << endl << endl << "Военное время после setTime равно ";
	t.printMilitary();
	cout << endl << "Стандартное время после setTime равно ";
	t.printStandard();
	t.setTime(99, 99, 99);
	cout << endl << endl << "После попытки неправильной установки: " << endl << "Военное время: ";
	t.printMilitary();
	cout << endl << "Стандартное время: ";
	t.printStandard();
	cout << endl;
	return 0;
}