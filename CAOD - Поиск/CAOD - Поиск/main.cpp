
#include "pch.h"
#include "search.h"
#include <iostream>
#include <ctime>

using namespace std;

const int n = 10000;

int main()
{
	setlocale(LC_ALL, "Rus");
	int *array = new int[n];
	int min = 0;
	int max = 1000;
	random(array, n, min, max);
	cout << "Введенный массив : " << endl;
	write(array, n);
	unsigned int start_time = clock(); // начальное время
	cout << search(array, n, min + rand() % max) << endl;
	unsigned int end_time = clock(); // конечное время
	cout << "Время поиска по ключу : " << ((float)end_time - start_time) / CLOCKS_PER_SEC << " секунды " << endl;
	/*read(array, n);
	cout << "Введенный массив : ";
	write(array, n);
	cout << search(array, n, 5) << endl;*/
	delete(array);
	system("pause");
}


