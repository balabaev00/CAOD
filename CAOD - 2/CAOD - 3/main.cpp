

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "pch.h"
#include "function.h"
#include <locale.h>

using namespace std;

const int n = 10;

int main()
{

	setlocale(LC_ALL, "Rus");
	ofstream out; // поток для записи
	string filename = "result.txt"; // Название файла
	out.open(filename);
	double massive[n];
	rand_massive(massive, n, -15, 31);
	cout << "Начальный массив : ";
	out << "Начальный массив : ";
	sout(massive, n);
	for (int i = 0; i < n; i++) {
		out << massive[i] << " ";
	}
	cout << endl;
	out << endl;
	cout << "Сумма неотрицательных элементов = " << sum_negative(massive, n) << endl;
	out << "Сумма неотрицательных элементов = " << sum_negative(massive, n) << endl;
	cout << "Произведение элементов массива, расположенных между максимальным и минимальным элементами = " << mul_min_max(massive, n) << endl;
	out << "Произведение элементов массива, расположенных между максимальным и минимальным элементами = " << mul_min_max(massive, n) << endl;
	cout << endl;
	out << endl;
	cout << "Произведение положительных элементов массива : " << mul_plus(massive, n) << endl;
	out << "Произведение положительных элементов массива : " << mul_plus(massive, n) << endl;
	cout << "Сумма элементов массива, расположенных до минимального элемента : " << sum_min(massive, n) << endl;
	out << "Сумма элементов массива, расположенных до минимального элемента : " << sum_min(massive, n) << endl;
	sort(massive, n);
	cout << "Отсортированный массив ";
	out << "Отсортированный массив ";
	for (int i = 0; i < n; i++) {
		out << massive[i] << " ";
	}
	sout(massive, n);
	out.close();
	system("pause");
}


