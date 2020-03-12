#include "pch.h"
#include "student.h"
#include <string>
using namespace std;

void readStudent(Student student[], short n)
{
	for (int i = 0; i < n; i++) {
		cout << "������� ������� � �������� : ";
		cin >> student[i].secondName;
		cout << "������� ����� ������ : ";
		cin >> student[i].number;
		for (int j = 0; j < 5; j++) {
			cout << "������� ������ ����� " << j << " : ";
			cin >> student[i].rating[j];
		}
	}
}

void sortStudent(Student student[], short n)
{
	for (int i = 1; i < n; ++i)
	{
		for (int r = 0; r < n - i; r++)
		{
			if (student[r].number > student[r + 1].number)
			{
				Student temp = student[r];
				student[r] = student[r + 1];
				student[r + 1] = temp;
			}
		}
	}
}

void writeStudent(Student student[], short n)
{
	for (int i = 0; i < n; i++) {
		cout << i << " �������" << endl;
		cout << "������� �� : " << student[i].secondName << endl;
		cout << "������ : " << student[i].number << endl;
		cout << "������ : ";
		for (int j = 0; j < 5; j++) {
			cout << student[i].rating[j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void writeGoodStudent(Student student[], short n)
{
	double *temp = new double[n];
	double sr;
	int count = 0;
	for (int i = 0; i < n; i++) {
		sr = 0;
		for (int j = 0; j < 5; j++) {
			sr += student[i].rating[j];
		}
		temp[i] = sr / 5;
		if (temp[i] > 4) {
			cout << endl;
			cout << "������� �� : " << student[i].secondName << endl;
			cout << "������ : " << student[i].number << endl;
			cout << "������� ���� �������� = " << temp[i] << endl;
			cout << endl;
			count++;
		}
	}
	if (count == 0) {
		cout << "��������� � ������ > 4 ���!" << endl;
	}
	delete[] temp;
}
