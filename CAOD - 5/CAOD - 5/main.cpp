
#include "pch.h"
#include "student.h"
#include <iostream>
#include <string>

using namespace std;

const int n = 3;

int main()
{
	setlocale(LC_ALL, "");
	Student student[n];
	readStudent(student, n);
	writeStudent(student, n);
	sortStudent(student, n);
	cout << "-----------------------------" << endl;
	cout << "Список после сортировки : " << endl;
	cout << "-----------------------------" << endl;
	writeStudent(student, n);
	cout << "-----------------------------" << endl;
	cout << "Студенты чей балл > 4 : " << endl;
	cout << "-----------------------------" << endl;
	writeGoodStudent(student, n);
	delete(student);
	system("pause");
}

