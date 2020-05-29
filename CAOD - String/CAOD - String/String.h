#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <iostream>

using namespace std;


class String
{
private:
	char* S;
	int len;

public:
	String();
	String(char* s);
	String(const String& s);
	~String() { delete[] S; }

	const char*GetStr()const { return S; } // Получить строку
	const int GetLen()const { return len; } // Вернуть длину строки
	String operator+(const String&); // Оператор сложения
	String&operator=(const String&); // Оператор приравнивания
	operator char*() { return S; }

	void SetStr()
	{
		if (S)   delete[]S;
		char a[256];
		cout << "Введите строку\n";
		cin.getline(a, 256);
		len = strlen(a) + 1;
		S = new char[len];
		strcpy(S, a);
	}
	void SetStr2(char*str)
	{
		if (S) delete[]S;
		len = strlen(str) + 1;
		S = new char[len];
		strcpy(S, str);
	}
};

String::String()
{
	S = 0;
	len = 0;
}

String::String(char* s)
{
	len = strlen(s);
	S = new char[len + 1];
	strcpy(S, s);
}

String::String(const String& s)
{
	len = s.len;
	S = new char[len + 1];
	strcpy(S, s.S);
}

String String::operator+(const String &str)
{
	String s;
	s.len = len + str.len;
	s.S = new char[s.len + 1];
	strcpy(s.S, S);
	strcat(s.S, str.S);
	return s;
}

String& String::operator=(const String &str)
{
	if (this == &str)
		return *this;
	if (len != str.len || len == 0)
	{
		delete[] S;
		len = str.len;
		S = new char[len + 1];
	}
	strcpy(S, str.S);
	return *this;
}