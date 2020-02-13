#include "pch.h"
#include "function.h"
#include <iomanip> // setprecision

void function(double a, double b, double c, double xBegin, double xEnd, double dX) {
	ofstream out;          // поток для записи
	out.open("result.txt"); // окрываем файл для записи
	int aC, bC, cC;
	double result;
	aC = a;
	bC = b;
	cC = c;
	if (out.is_open()) {
		out << "Функция №1" << endl;
		out << "a = " << a << endl;
		out << "b = " << b << endl;
		out << "c = " << c << endl;
		out << "X начальное = " << xBegin << endl;
		out << "X конечное = " << xEnd << endl;
		out << "Dx шаг = " << dX << endl;
		out << "Результат : " << endl;
		for (double x = xBegin; x <= xEnd; x += dX) {
			if (x < 0 && b != 0) {
				result = a * pow(x, 2) + b;
			}
			else
				if (x > 0 && b == 0) {
					result = (x - a) / (x - c);
				}
				else {
					result = x / c;
				}
			if (((aC || bC) && (aC || cC)) != 0) {
				out << setprecision(3);
				out << x << " | " << result << endl;
				cout << setprecision(3);
				cout << x << " | " << result << endl;
			}
			else {
				out << setprecision(3);
				out << x << " | " << int(result) << endl;
				cout << setprecision(3);
				cout << x << " | " << int(result) << endl;
			}
		}
	}
}

void function_f(double a, double b, double c, double xBegin, double xEnd, double dX) {
	ofstream out;          // поток для записи
	out.open("result.txt"); // окрываем файл для записи
	int aC, bC, cC;
	double result;
	aC = a;
	bC = b;
	cC = c;
	for (double x = xBegin; x <= xEnd; x += dX) {
		if (x < 0 && b != 0) {
			result = -(2 * x - c) / (c*x - a);
		}
		else
			if (x > 0 && b == 0) {
				result = (x - a) / (x - c);
			}
			else {
				result = -x / c + (-c / (2 * x));
			}
		if (((aC || bC) && (aC || cC)) != 0) {
			cout << setprecision(3);
			cout << x << " | " << result << endl;
		}
		else {
			cout << setprecision(3);
			cout << x << " | " << int(result) << endl;
		}
	}
}
