

#include "pch.h"
#include "function.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int n, m;
	cout << "Введите n : ";
	cin >> n;
	cout << "Введите m : ";
	cin >> m;
	int **massive = createArray(n, m);
	cout << "Вывод начального массива" << endl;
	randomArray(massive, n, m, -10, 50);
	toString(massive, n, m);
	cout << "Количество строк, не содержащих ни одного нулевого элемента : " << countNotNull(massive, n, m) << endl;
	cout << "Количество элементов (максимальное число) > 1 : " << maxCount(massive, n, m) << endl;
	cout << "Количество отрицательных элементов в тех строках, которые содержат хотя бы один нулевой элемент : " << countNegative(massive, n, m); 
	deleteArray(massive, n);
}
