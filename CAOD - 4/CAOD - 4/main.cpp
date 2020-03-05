

#include "pch.h"
#include "function.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const string filename = "result.txt";

int main()
{
	ofstream out;
	out.open(filename);
	setlocale(LC_ALL, "");
	int size;
	cout << "Введите размер массива : ";
	cin >> size;
	double *massive = new double[size];
	randomMassive(massive, size);
	toString(massive, size);
	cout << endl;
	cout << "Произведение элементов массива = " << mul(massive, size) << endl;
	out << "Размер массива = " << size << endl;
	out << "Заданный массив : ";
	for (int i = 0; i < size; i++) {
		out << massive[i] << "  ";
	}
	out << endl;
	out << "Произведение элементов массива = " << mul(massive, size) << endl;
	delete[] massive;
}
