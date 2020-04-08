#include "pch.h"
#include "sort.h"

void bubbleSort(int * array, int n)
{
	int temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i + 1; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j + 1];
				array[j] = array[j+1];
				array[j + 1] = temp;
			}
		}
	}
}

void selectionSort(int * array, int n)
{
	int min, temp; // для поиска минимального элемента и для обмена
	for (int i = 0; i < n - 1; i++)
	{
		min = i; // запоминаем индекс текущего элемента
		// ищем минимальный элемент чтобы поместить на место i-ого
		for (int j = i + 1; j < n; j++)  // для остальных элементов после i-ого
		{
			if (array[j] < array[min]) // если элемент меньше минимального,
				min = j;       // запоминаем его индекс в min
		}
		temp = array[i];      // меняем местами i-ый и минимальный элементы
		array[i] = array[min];
		array[min] = temp;
	}
}

void insertion(int *array, int n) 
{
	for (int i = n - 1; i > 0; i--) {
		if (array[i - 1] > array[i]) {
			int temp = array[i - 1];
			array[i - 1] = array[i];
			array[i] = temp;
		}
	}
	for (int i = 2; i < n; i++) {
		int j = i;
		int temp = array[i];
		while (temp < array[j - 1]) {
			array[j] = array[j - 1]; 
			j--;
		}
		array[j] = temp;
	}
}void quickSort(int* array, int n) 
{
	int i = 0, j = n - 1; 		// поставить указатели на исходные места
	int p;
	int temp;
	p = array[n >> 1];		// центральный элемент сдвиг в право
	// процедура разделения
	do {
		while (array[i] < p) i++;
		while (array[j] > p) j--;

		if (i <= j) {
			temp = array[i]; 
			array[i] = array[j]; 
			array[j] = temp;
			i++; 
			j--;
		}
	} while (i <= j);
	// рекурсивные вызовы, если есть, что сортировать 
	if (j > 0) quickSort(array, j);
	if (n > i) quickSort(array + i, n - i);
}
void shellSort(int *array, int n)
{
	int h;
	for (h = 1; h <= n / 9; h = 3 * h + 1);
	for (; h > 0; h /= 3) {
		for (int i = h; i < n; i++) {
			int j = i;
			int tmp = array[i];
			while (j >= h && tmp < array[j - h]) {
				array[j] = array[j - h];
				j -= h;
			}
			array[j] = tmp;
		}
	}
}