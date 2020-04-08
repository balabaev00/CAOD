
#include "pch.h"
#include "search.h"
#include "sort.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

const int n = 10000;
const string filename = "result.txt";

int main()
{
	setlocale(LC_ALL, "Rus");
	ofstream out;
	out.open(filename);
	int *array = new int[n];
	int *array1 = new int[n];
	int *array2 = new int[n];
	int *array3 = new int[n];
	int *array4 = new int[n];
	int min = 0;
	int max = 1000;
	random(array, n, min, max);
	random(array1, n, min, max);
	random(array2, n, min, max);
	random(array3, n, min, max);
	random(array4, n, min, max);
	/*cout << "Введенный массив : " << endl;
	write(array, n);*/
	unsigned int start_time = clock(); // начальное время
	cout << search(array, n, min + rand() % max) << endl;
	unsigned int end_time = clock(); // конечное время
	cout << "Время поиска по ключу : " << ((float)end_time - start_time) / CLOCKS_PER_SEC << " секунды " << endl;
	out << "Время поиска по ключу : " << ((float)end_time - start_time) / CLOCKS_PER_SEC << " секунды " << endl;
	/*Проверка сортировок*/
	start_time = clock();
	bubbleSort(array, n);
	end_time = clock();
	cout << "Время сортировки пузырьком : " << ((float)end_time - start_time) / CLOCKS_PER_SEC << " секунды " << endl;
	out << "Время сортировки пузырьком : " << ((float)end_time - start_time) / CLOCKS_PER_SEC << " секунды " << endl;
	start_time = clock();
	quickSort(array1, n);
	end_time = clock();
	cout << "Время быстрой сортировки : " << ((float)end_time - start_time) / CLOCKS_PER_SEC << " секунды " << endl;
	out << "Время быстрой сортировки : " << ((float)end_time - start_time) / CLOCKS_PER_SEC << " секунды " << endl;
	start_time = clock();
	selectionSort(array2, n);
	end_time = clock();
	cout << "Время сортировки выбором : " << ((float)end_time - start_time) / CLOCKS_PER_SEC << " секунды " << endl;
	out << "Время сортировки выбором : " << ((float)end_time - start_time) / CLOCKS_PER_SEC << " секунды " << endl;
	start_time = clock();
	shellSort(array3, n);
	end_time = clock();
	cout << "Время сортировки Шелла : " << ((float)end_time - start_time) / CLOCKS_PER_SEC << " секунды " << endl;
	out << "Время сортировки Шелла : " << ((float)end_time - start_time) / CLOCKS_PER_SEC << " секунды " << endl;
	start_time = clock();
	insertion(array4, n);
	end_time = clock();
	cout << "Время сортировки вставками : " << ((float)end_time - start_time) / CLOCKS_PER_SEC << " секунды " << endl;
	out << "Время сортировки вставками : " << ((float)end_time - start_time) / CLOCKS_PER_SEC << " секунды " << endl;
	delete(array);
	delete(array1);
	delete(array2);
	delete(array3);
	delete(array4);
	out.close();
	system("pause");
}


