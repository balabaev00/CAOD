#include "pch.h"
#include "search.h"

void random(int * array, int n, int min, int max) {
	for (int i = 0; i < n; i++) {
		array[i] = min + rand() % max;
	}
}

string search(int * array, int n, int key) {
	string result = "Индексы элементов равных ключу (" + to_string(key) + ") : ";
	for (int i = 0; i < n; i++) {
		if (array[i] == key) {
			result += to_string(i) + "  ";
		}
	}
	return result;
}

int binarySearch(int val, int a[], int left, int right) 
{
	if (left >= right) return a[left] == val ? left : -1;
	int mid = (left + right) / 2;
	if (a[mid] == val) return mid;
	if (a[mid] < val) {
		return binarySearch(val, a, left, mid - 1);
	}
	else {
		return binarySearch(val, a, mid + 1, right);
	}}
int * prepare(int a[], int N, int *min, int *max) 
{
	*min = *max = a[0];
	for (int i = 1; i < N; i++) {
			if (a[i] > *max) *max = a[i];
		if (a[i] < *min) *min = a[i];
	}
	if (*max - *min > N) return nullptr;
	int *ret = new int[*max - *min + 1];
	for (int i = *min; i <= *max; i++) {
		ret[i] = -1;
	}
	for (int i = 0; i < N; i++) {
		ret[a[i] - *min] = i;
	}
	return ret;
}int distributedSearch(int a[], int N, int key){	int result;	int min, max;
	int *ainv = prepare(a, N, &min, &max);
	if (ainv != nullptr) {
		result = -1;
		if (key >= min && key <= max) 
			result = ainv[key - min];
			delete[] ainv;
	}
	else {
		return binarySearch(key, a, min, max);
	}}

void read(int * array, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Введите " << i << " элемент : ";
		cin >> array[i];
	}
}

void write(int * array, int n) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		cout << array[i] << " \t";
		k++;
		if (k == 10) {
			cout << endl;
			k = 0;
		}
	}
	cout << endl;
}