#include "pch.h"
#include "student.h"
#include <string>
#include <fstream>
using namespace std;

void readStudent(Student student[], short n)
{
	for (int i = 0; i < n; i++) {
		cout << "Введите фамилию и инициалы : ";
		cin >> student[i].secondName;
		cout << "Введите номер группы : ";
		cin >> student[i].number;
		for (int j = 0; j < 5; j++) {
			cout << "Введите оценку номер " << j << " : ";
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
		cout << i << " Студент" << endl;
		cout << "Фамилия ИО : " << student[i].secondName << endl;
		cout << "Группа : " << student[i].number << endl;
		cout << "Оценки : ";
		for (int j = 0; j < 5; j++) {
			cout << student[i].rating[j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void writeStudentFile(Student student[], short n, ofstream &out)
{
	for (int i = 0; i < n; i++) {
		out << i << " Студент" << endl;
		out << "Фамилия ИО : " << student[i].secondName << endl;
		out << "Группа : " << student[i].number << endl;
		out << "Оценки : ";
		for (int j = 0; j < 5; j++) {
			out << student[i].rating[j] << " ";
		}
		out << endl;
	}
	out << endl;
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
			cout << "Фамилия ИО : " << student[i].secondName << endl;
			cout << "Группа : " << student[i].number << endl;
			cout << "Средний балл студента = " << temp[i] << endl;
			cout << endl;
			count++;
		}
	}
	if (count == 0) {
		cout << "Студентов с баллов > 4 нет!" << endl;
	}
	delete[] temp;
}

void writeGoodStudentFile(Student student[], short n, ofstream &out)
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
			out << endl;
			out << "Фамилия ИО : " << student[i].secondName << endl;
			out << "Группа : " << student[i].number << endl;
			out << "Средний балл студента = " << temp[i] << endl;
			out << endl;
			count++;
		}
	}
	if (count == 0) {
		out << "Студентов с баллов > 4 нет!" << endl;
	}
	delete[] temp;
}