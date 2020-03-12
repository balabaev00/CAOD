#pragma once
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

struct Order {
	short payer;
	short recipient;
	double sum;
};

void readOrder(Order order[], short n);
void sortOrder(Order order[], short n);
void writeOrder(Order order[], short n);
void writeGoodOrder(Order order[], short n);