#pragma once

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int** createArray(int n, int m);
void toString(int **massive, int n, int m);
void randomArray(int **massive, int n, int m, int min, int max);
int countNotNull(int **massive, int n, int m);
void deleteArray(int **massive, int n);
int maxCount(int **massive, int n, int m);
int countNegative(int **massive, int n, int m);
