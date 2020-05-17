#include "pch.h"
#include "Calculator.h"
#include <iostream>

void Calculator::addTop(double num) {
	S.push(num);
}

bool Calculator::getTwoOperands(double& opndl, double& opnd2) {
	if (S.isEmpty()) // ��������� ������� ������� ��������
	{
		std::cout << "����������� ������� 1!";
		return false;
	}
	opndl = S.pop(); // ������� ������ �������

	if (S.isEmpty()) // ��������� ������� ������� �������� 
	{
		std::cout << "����������� ������� 2!";
		return false;
	}
	opnd2 = S.pop(); // ������� ����� �������

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
				std::cout << "������: ������� �� ����!" << std::endl;
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
	std::cout << "������� ���������: ";
	while (std::cin >> c, c != '=') // ������ �� ������� '=' (�����)
	{
		switch (c)
		{
		case '+': // ����������� ������� ���������
		case '-':
		case '*':
		case '/':
			compute(c); // ������� ��������; ��������� ���
			break;
		default:
			//�� ��������, ��������, �������; ������� ������
			std::cin.putback(c);
			// ������ ������� � ���������� ��� � ����
			std::cin >> newoperand;
			addTop(newoperand);
			break;
		}
	}
	// �����, ����������� � ������� ����� �������� � �������������� Peek
	if (!S.isEmpty()) {
		long temp = S.peek();
		std::cout << temp << std::endl;
		out << temp << std::endl;
	}
}

void Calculator::Clear(void) {
	S.clear();
}