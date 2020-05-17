
#include "pch.h"
#include "function.h"
#include <iostream>
#include <fstream> 
#include <ctime>

using namespace std;

const int n = 1000000;
const int m = 1000000;

int main()
{
	setlocale(LC_ALL, "Rus");
	ofstream out;
	out.open("result.txt", std::ios_base::app);
	int *aa = createRandomArray(0,100,n);
	int *bb = createRandomArray(0,100,m);
	quickSort(aa, n);
	quickSort(bb, m);
	//cout << "Начальный массив A " << endl;
	//out << "Начальный массив A " << endl;
	//printArray(aa, n);
	//cout << "Начальный массив B " << endl;
	//out << "Начальный массив B " << endl;
	//printArray(bb, m);
	out << "Размер первого массива = " << n << endl;
	out << "Размер второго массива = " << m << endl;
	unsigned int start_time = clock(); // начальное время
	int *cc = naturalMerging(aa, bb, n, m);
	unsigned int end_time = clock(); // конечное время
	cout << "Время естественного слияния : " << ((float)end_time - start_time) / CLOCKS_PER_SEC << " секунды " << endl;
	out << "Время слияния  : " << ((float)end_time - start_time) / CLOCKS_PER_SEC << " секунды " << endl;
	//cout << "Результат естественного слияния " << endl;
	//out << "Результат естественного слияния " << endl;
	//printArray(cc, n+m);
	//arrayToFile(cc, n+m);
	delete[] aa;
	delete[] bb;
	delete[] cc;
	system("pause");

}


