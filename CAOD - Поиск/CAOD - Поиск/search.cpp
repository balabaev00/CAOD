#include "pch.h"
#include "search.h"

void random(int * array, int n, int min, int max) {
	for (int i = 0; i < n; i++) {
		array[i]= min + rand() % max;
	}
}

string search(int * array, int n, int key) {
	string result = "������� ��������� ������ ����� (" + to_string(key) + ") : ";
	for (int i = 0; i < n; i++) {
		if (array[i] == key) {
			result += to_string(i) + "  ";
		}
	}
	return result;
}

void read(int * array, int n) {
	for (int i = 0; i < n; i++) {
		cout << "������� " << i << " ������� : ";
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
