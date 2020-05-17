#include "pch.h"
#include "function.h"

int * createRandomArray(int min, int max, int n)
{
	int* array = new int[n];
	for (int i = 0; i < n; i++) {
		array[i]= min + rand() % max;
	}
	return array;
}

void printArray(int * &array, int n)
{
	int count = 1;
	for (int i = 0; i < n; i++) {
		cout << array[i] << "\t";
		if (count == 10) {
			cout << endl;
			count = 0;
		}
		count++;
	}
	cout << endl;
}

void quickSort(int* array, int n)
{
	int i = 0, j = n - 1; 		// ��������� ��������� �� �������� �����
	int p;
	int temp;
	p = array[n >> 1];		// ����������� ������� ����� � �����
	// ��������� ����������
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
	// ����������� ������, ���� ����, ��� ����������� 
	if (j > 0) quickSort(array, j);
	if (n > i) quickSort(array + i, n - i);
}

void binarySearch(int * array, int key, int left, int right)
{
	int search = -1; // ��������� ������ �������� ����� -1 (������� �� ������)
	while (left <= right) // ���� ����� ������� �� "����������" ������
	{
		int mid = (left + right) / 2; // ���� �������� �������
		if (key == array[mid]) {  // ���� �������� ���� ����� ��������
			search = mid;     // �� ����� ��������� �������,
			break;            // ������� �� �����
		}
		if (key < array[mid])     // ���� ������� �������� ���� ������ ��������� ��������
			right = mid - 1;  // ������� ������ �������, ��������� ����� � ����� �����
		else                  // �����
			left = mid + 1;   // ������� ����� �������, ��������� ����� � ������ �����
	}
	if (search == -1)     // ���� ������ �������� ��-�������� -1, ������� �� ������
		cout << "������� �� ������!" << endl;
	else          // ����� ������� �������, ��� ���� � ��������
		cout << "����� �������� - " << array[search] << endl;
}

void writeBinaryFile(int * array, int n)
{
	ofstream file;
	file.open("file.bin", ios::out | ios::app | ios::binary | std::ios_base::app);
	if (file.is_open()) {
		file.write((char*)array, n * sizeof(int));
		file.close();
	}
	else 
		cout << "�� ����� �������� ����� ��������� ������";
}

int * readBinaryFile(int n)
{
	int *array = new int[n];
	ifstream file;
	file.open("file.bin", ios::out | ios::app | ios::binary);
	if (file.is_open()) {
		file.read(reinterpret_cast<char*>(array), n * sizeof(int));
		file.close();
	}
	else 
		cout << "�� ����� �������� ����� ��������� ������";
	return array;
}

int * naturalMerging(int * a, int * b, int n, int m)
{
	const int alength = n;
	const int blength = m;
	int aindex = 0;
	int bindex = 0;
	int cindex = 0;
	// �������� ������� ��� ��������������� ������������������
	int* c = new int[alength + blength];
	// ����������
	while ((aindex < alength) && (bindex < blength))
	{
		if (a[aindex] < b[bindex])
		{
			c[cindex] = a[aindex];
			aindex++;
		}
		else
		{
			c[cindex] = b[bindex];
			bindex++;
		}
		cindex++;
	}
	// ��������� ������� ����� (�������� ����� ������ ������ ���� �� ���� ������)
	while (aindex < alength)
		c[cindex++] = a[aindex++];
	while (bindex < blength) // ��������� ������� �����
		c[cindex++] = b[bindex++];
	return c;
}

void arrayToFile(int * array, int n)
{
	ofstream out;
	out.open("result.txt", std::ios_base::app);
	if (out.is_open()) {
		int count = 1;
		for (int i = 0; i < n; i++) {
			out << array[i] << "\t";
			if (count == 10) {
				out << endl;
				count = 0;
			}
			count++;
		}
		out << endl;
	}
	out.close();
}
