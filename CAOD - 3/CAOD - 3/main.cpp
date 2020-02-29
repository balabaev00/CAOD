

#include "pch.h"
#include "function.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	string filename = "result.txt";
	ofstream out;
	out.open(filename);
	int n, m;
	cout << "Введите n : ";
	cin >> n;
	cout << "Введите m : ";
	cin >> m;
	out << "Матрица размера " << n << "x" << m << endl;
	int **massive = createArray(n, m);
	cout << "Вывод начального массива" << endl;
	out << "Вывод начального массива" << endl;
	randomArray(massive, n, m, -10, 50);
	toString(massive, n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			out << massive[i][j] << " ";
		}
		out << endl;
	}
	cout << "Кол  ичество строк, не содержащих ни одного нулевого элемента : " << countNotNull(massive, n, m) << endl;
	out << "Количество строк, не содержащих ни одного нулевого элемента : " << countNotNull(massive, n, m) << endl;
	cout << "Количество элементов (максимальное число) > 1 : " << maxCount(massive, n, m) << endl;
	out << "Количество элементов (максимальное число) > 1 : " << maxCount(massive, n, m) << endl;
	cout << "Количество отрицательных элементов в тех строках, которые содержат хотя бы один нулевой элемент : " << countNegative(massive, n, m); 
	out << "Количество отрицательных элементов в тех строках, которые содержат хотя бы один нулевой элемент : " << countNegative(massive, n, m); 
	deleteArray(massive, n);
}
