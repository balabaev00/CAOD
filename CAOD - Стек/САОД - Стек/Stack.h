#pragma once
#include "pch.h"
#include <iostream>

const unsigned MAX_STACK_SIZE = 50; // ����������� ����� �����

template <typename T>

/*���������� ������� � header ������ ��� ��������� ������ ���� ��������� ���������� � ����������*/

class Stack
{	

private: 
	int top;
	T stack_list[MAX_STACK_SIZE]; // ������ �� ������ �����
public:
	enum ERRORS {
		stack_overflow = -1, // ������������ �����
		stack_isEmpty = -2, // ����� ����
	};

	// ����������� �������������� ������� �����
	Stack() : top(-1) { }

	// �������� ������� � �������
	void push(T item) {
		// ���� ���� ������, ��������� ���������� ���������
		if (top == MAX_STACK_SIZE - 1)
			throw stack_overflow;
		// �����, ��������� ������� �� 1
		top++;
		//�������� ������� � ������
		stack_list[top] = item;
	}

	// ������ ������� �� �������
	T pop(void) {
		T temp;
		// ���� ���� ����
		if (top == -1)
			throw stack_isEmpty;
		temp = stack_list[top];
		// ��������� ����� ����� �� 1
		top--;
		// ������� ������� �� ������� �����
		return temp;
	}

	// �������� ����
	void clear(void) {
		top = -1;
	}

	// ������� �������, �� ���뤤 �� �������
	T peek(void) const {
		if (top == -1)
			throw stack_isEmpty;
		return stack_list[top];
	}

	// �������� �� �������
	bool isEmpty() const {
		// ���� ���� ����, ������� true, ����� false
		return top == -1 ? true : false;
	}
};

