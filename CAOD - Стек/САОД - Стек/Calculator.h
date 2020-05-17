#pragma once

#include "pch.h"
#include "Stack.h"
#include <iostream>
#include <fstream>

using namespace std;

class Calculator
{
private:
	Stack<double> S;
	ofstream out;
	void addTop(double num);
	bool getTwoOperands(double &sopndl, double &sopnd2);
	void compute(char op);

public:
	// конструктор
	Calculator();
	// вычислить выражение и очистить калькулятор
	void Run(void);
	void Clear(void);
};

