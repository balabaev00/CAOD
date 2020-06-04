
#include "pch.h"
#include "Rabin.h"
#include "AhoCorasick.h"
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;

vector<int> prefix_function(const string& s) {
	vector<int> pi(s.length(), 0);

	for (int i = 1; i < s.length(); i++) {
		int j = pi[i - 1];

		while (j > 0 && s[i] != s[j]) {
			j = pi[j - 1];
		}

		if (s[i] == s[j]) {
			pi[i] = j + 1;
		}
		else {
			pi[i] = j;
		}
	}

	return pi;
}

void print(const char* str)
{
	ofstream out("result.txt", ios::app);
	cout << "Найденая подстрока " << str << "\n";
	out << "Найденая подстрока " << str << "\n";
	out.close();
}



int main(int argc, char* argv[])
{
	ofstream out("result.txt", ios::app);
	setlocale(LC_ALL, "RUS"); 
	//Проверка
	int sovp;
	int d = 1, q = 1000;
	char T[200];
	char P[100];
	cout << "Введите текст" << endl;
	cin.getline(T,200);
	cout << "Введите строку" << endl;
	cin.getline(P, 200);
	sovp = RabinKarpMatch(T, P, d, q);
	out << "Введенный текст " << T << endl;
	out << "Введенная строка " << P << endl;
	if (sovp) {
		cout << "Слово найдено в  " << sovp << " позиции";
		out << "Слово найдено в  " << sovp << " позиции";
	}
	else {
		cout << "Совпадений не найдено!!!";
		out << "Совпадений не найдено!!!";
	}

	out.close();
	// Ахо-Корасик
	AhoCorasick ak;
	
	ak.addString("test");
	ak.addString("rok");
	ak.addString("roka");
	ak.addString("strok");
	ak.addString("t");
	ak.init();
	ak.search("testovaya_stroka!",print);
	out.open("result.txt", ios::app);
	out << "Введена <testovaya_stroka!>" << endl;
	// Алгоритм Кнута-Морриса-Пратта
	string s, t;
	cin >> s >> t;

	vector<int> pi = prefix_function(s);

	int t_len = t.length();

	for (int i = 0; i < s.length(); i++) {
		if (pi[t_len + 1 + i] == t_len) {
			cout << "s[" << i - t_len + 1 << ".." << i << "] = t" << endl;
		}
	}

	out.close();
	system("pause");
	return 0;
}


