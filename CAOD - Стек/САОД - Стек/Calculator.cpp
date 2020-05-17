#include "pch.h"
#include "Calculator.h"
#include <iostream>

void Calculator::addTop(double num) {
	S.push(num);
}

bool Calculator::getTwoOperands(double& opndl, double& opnd2) {
	if (S.isEmpty()) // проверить наличие первого операнда
	{
		std::cout << "Отсутствует операнд 1!";
		return false;
	}
	opndl = S.pop(); // извлечь правый операнд

	if (S.isEmpty()) // проверить наличие второго операнда 
	{
		std::cout << "Отсутствует операнд 2!";
		return false;
	}
	opnd2 = S.pop(); // извлечь левый операнд

	return true;
}

void Calculator::compute(char op) {
	bool res = false;
	double num1, num2;

	res = getTwoOperands(num1, num2);

	if (res) {
		switch (op)
		{
		case '+': S.push(num1 + num2);
			break;
		case '-': S.push(num2 - num1);
			break;
		case '*': S.push(num1 * num2);
			break;
		case '/':
			if (num1 == 0.0) {
				S.clear();
				std::cout << "Ошибка: деление на ноль!" << std::endl;
				return;
			}
			else {
				S.push(num2 / num1);
				break;
			}
		}
	}
	else
		S.clear();
}

Calculator::Calculator() {

}

void Calculator::Run(void) {
	char c;
	double newoperand;
	std::cout << "Введите выражение: ";
	while (std::cin >> c, c != '=') // читать до символа '=' (Выход)
	{
		switch (c)
		{
		case '+': // определение нужного оператора
		case '-':
		case '*':
		case '/':
			compute(c); // имеется оператор; вычислить его
			break;
		default:
			//не оператор, возможно, операнд; вернуть символ
			std::cin.putback(c);
			// читать операнд и передавать его в стек
			std::cin >> newoperand;
			addTop(newoperand);
			break;
		}
	}
	// ответ, сохраняемый в вершине стека печатать с использованием Peek
	if (!S.isEmpty()) {
		long temp = S.peek();
		std::cout << temp << std::endl;
		out << temp << std::endl;
	}
}

void Calculator::Clear(void) {
	S.clear();
}