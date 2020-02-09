
#include "pch.h"
#include "function.h"
#include <iostream>


using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int aC, bC, cC;
	double a, b, c;
	double xBegin, xEnd, dX;
	cout << "Введите a : ";
	cin >> a;
	cout << "Введите b : ";
	cin >> b;
	cout << "Введите c : ";
	cin >> c;
	cout << "Введите X начальное : ";
	cin >> xBegin;
	cout << "Введите X конечное : ";
	cin >> xEnd;
	cout << "Введите шаг : ";
	cin >> dX;
	function(a, b, c, xBegin, xEnd, dX);
	return 0;
}


