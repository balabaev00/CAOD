#define _CRT_SECURE_NO_WARNINGS


#include "pch.h"
#include "String.h"
#include <iostream>
#include <fstream>

using namespace std;
const string filename = "result.txt";

int main()
{
	setlocale(LC_ALL, "Rus");
	ofstream out(filename, ios::app);
	String a;
	a.SetStr();
	out << "Первая строка = " << a.GetStr() << " , длина = " << a.GetLen() << endl;
	cout << "Первая строка = " << a.GetStr() << " , длина = " << a.GetLen() << endl;
	String b;
	b.SetStr();
	out << "Вторая строка = " << b.GetStr() << " , длина = " << b.GetLen() << endl;
	cout << "Вторая строка = " << b.GetStr() << " , длина = " << b.GetLen() << endl;
	String c = a + b;
	out << "Первая строка + вторая строка  = " << c.GetStr() << " , длина = " << c.GetLen() << endl;
	cout << "Первая строка + вторая строка  = " << c.GetStr() << " , длина = " << c.GetLen() << endl;
	system("pause");
}

