#include "pch.h"
#include "function.h"

double mul(double *massive, int i)
{
	if (i == 1)
		return massive[0];
		return massive[i-1]*mul(massive, i-1);
}

double sum(double n, double m)
{
	if (m == 1)
		return n;
	return n + sum(n, m - 1);
}

void toString(double * massive, int size)
{
	for (int i = 0; i < size; i++) {
		cout << massive[i] << "  ";
	}
}

void randomMassive(double * massive, int size)
{
	for (int i = 0; i < size; i++)
		massive[i] = rand() % 50 + 20;
}
