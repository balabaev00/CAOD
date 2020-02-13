
#include "pch.h"
#include "function.h"
#include <iostream>
#include <ctime>


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
	unsigned int start_time = clock(); // начальное время
	function(a, b, c, xBegin, xEnd, dX);
	unsigned int end_time = clock(); // конечное время
	cout << "Время выполнения функции 1 = " << (double)(end_time - start_time) / CLOCKS_PER_SEC << endl;
	start_time = clock(); // начальное время
	function_f(a, b, c, xBegin, xEnd, dX);
	end_time = clock(); // конечное время
	cout << "Время выполнения функции 2 = " << (double) (end_time - start_time) / CLOCKS_PER_SEC << endl;
	system("pause");
	return 0;
}


