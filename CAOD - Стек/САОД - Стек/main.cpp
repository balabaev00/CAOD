
#include "pch.h"
#include "Stack.h"
#include "Calculator.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

ofstream out;

// удалить пробелы из строки
void deleteSpaces(string &s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			s.erase(i, 1);
			i--;
		}
	}
}

// печать целого числа по основанию B
void multibaseOutput(long num, int B) {
	long temp = num;
	Stack<float> S;
	// извлечение чисел с основанием В справа налево
	//и помещение их в стек S
	do
	{
		S.push(int(num % B));
		num /= B;
	} while (num != 0);
	cout << "Число " << temp << " в " << B << "-чной СС: ";
	out << "Число " << temp << " в " << B << "-чной СС: ";
	while (!S.isEmpty()) {
		long temp = S.pop();
		cout << temp;
		out << temp;
	}
}

const string filename = "result.txt";

int main()
{
	setlocale(0, "");
	out.open(filename, std::ios::app);
	Stack<char> stack;
	bool isPalindrome = true;
	string str;
	char symbol;
	float number;
	int base;

	cout << "Введите строку: ";
	getline(cin, str);
	out << "Введенная строка " << str << endl;
	deleteSpaces(str); // очистить строку от пробелов
	try
	{
		// поместить символы выражения без пробелов в стек
		int i = 0;
		while (str[i] != 0)
		{
			stack.push(str[i]);
			i++;
		}

		i = 0;
		while (!stack.isEmpty()) {
			symbol = stack.pop();
			if (symbol != str[i]) {
				isPalindrome = false;
				break;
			}
			i++;
		}

		if (isPalindrome) {
			cout << "Строка \"" << str << "\" является палиндромом\n\n";
			out << "Строка \"" << str << "\" является палиндромом\n\n";
		}
		else {
			cout << "Строка \"" << str << "\" не является палиндромом\n\n";
			out << "Строка \"" << str << "\" не является палиндромом\n\n";
		}

	}
	catch (Stack<char>::ERRORS e)
	{
		if (e == Stack<char>::stack_isEmpty)
		{
			cout << "Стек пуст!" << endl;
		}
		if (e == Stack<char>::stack_overflow)
		{
			cout << "Стек перполнен! Добавить данные невозможно." << endl;
		}
	}

	cout << "Введите число и его основание через пробел:" << endl;
	cin >> number >> base;
	out << "Введенное число " << number << " ,основание " << base << endl;
	multibaseOutput(number, base);
	cout << "\n\n";
	out << "\n\n";

	Calculator calc;
	calc.Run();
	cout << endl;
	out << endl;
	out.close();
	system("pause");
	return 0;
}