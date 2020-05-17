#pragma once
#include "pch.h"
#include <iostream>

const unsigned MAX_STACK_SIZE = 50; // максимальна§ длина стека

template <typename T>

/*–еализаци€ функций в header потому что возникают ошибки если раздел€ть реализацию и объ€вление*/

class Stack
{	

private: 
	int top;
	T stack_list[MAX_STACK_SIZE]; // массив из данных стека
public:
	enum ERRORS {
		stack_overflow = -1, // переполнение стека
		stack_isEmpty = -2, // стеку пуст
	};

	// конструктор инициализирует вершину стека
	Stack() : top(-1) { }

	// добавить элемент в вершину
	void push(T item) {
		// если стек полный, завершить выполнение программы
		if (top == MAX_STACK_SIZE - 1)
			throw stack_overflow;
		// иначе, увеличить вершину на 1
		top++;
		//добавить элемент в массив
		stack_list[top] = item;
	}

	// изъ§ть элемент из вершины
	T pop(void) {
		T temp;
		// если стек пуст
		if (top == -1)
			throw stack_isEmpty;
		temp = stack_list[top];
		// уменьшить длину стека на 1
		top--;
		// вернуть элемент из вершины стека
		return temp;
	}

	// очистить стек
	void clear(void) {
		top = -1;
	}

	// вернуть элемент, не удал§§ из вершины
	T peek(void) const {
		if (top == -1)
			throw stack_isEmpty;
		return stack_list[top];
	}

	// проверка на пустоту
	bool isEmpty() const {
		// если стек пуст, вернуть true, иначе false
		return top == -1 ? true : false;
	}
};

