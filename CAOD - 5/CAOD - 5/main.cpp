
#include "pch.h"
#include "student.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int n = 3;
const string filename = "result.txt";

int main()
{
	ofstream out;
	out.open(filename);
	setlocale(LC_ALL, "");
	Student student[n];
	readStudent(student, n);
	cout << "-----------------------------" << endl;
	cout << "Список до сортировки : " << endl;
	cout << "-----------------------------" << endl;
	out << "-----------------------------" << endl;
	out << "Список до сортировки : " << endl;
	out << "-----------------------------" << endl;
	writeStudent(student, n);
	writeStudentFile(student, n, out);
	sortStudent(student, n);
	cout << "-----------------------------" << endl;
	cout << "Список после сортировки : " << endl;
	cout << "-----------------------------" << endl;
	out << "-----------------------------" << endl;
	out << "Список после сортировки : " << endl;
	out << "-----------------------------" << endl;
	writeStudent(student, n);
	writeStudentFile(student, n, out);
	cout << "-----------------------------" << endl;
	cout << "Студенты чей балл > 4 : " << endl;
	cout << "-----------------------------" << endl;
	out << "-----------------------------" << endl;
	out << "Студенты чей балл > 4 : " << endl;
	out << "-----------------------------" << endl;
	writeGoodStudent(student, n);
	writeGoodStudentFile(student, n, out);
	system("pause");
}

