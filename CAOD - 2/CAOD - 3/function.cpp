#include "function.h"
#include "pch.h"
#include <iostream>;
#include <fstream>

using namespace std;

double sum_negative(double massive[], int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++) {
		if (massive[i] < 0)
			sum += massive[i];
	}
	return sum;
}

double mul_plus(double massive[], int n)
{
	double mul = 1;
	for (int i = 0; i < n; i++) {
		if (massive[i] > 0)
			mul *= massive[i];
	}
	return mul;
}

double sum_min(double massive[], int n)
{
	int imin=0;
	double min = massive[0];
	double sum = 0;
	for (int i = 0; i < n; i++) {
		if (min > massive[i]) {
			min = massive[i];
			imin = i;
		}
	}
	for (int i = 0; i < imin; i++)
		sum += massive[i];
	return sum;
}

double mul_min_max(double massive[], int n)
{
	double min = massive[0], max = massive[0];
	int imax, imin;
	double mul = 1;
	for (int i = 0; i < n; i++) {
		if (min > massive[i]) {
			min = massive[i];
			imin = i;
		}
		if (max < massive[i]) {
			max = massive[i];
			imax = i;
		}
	}
	for (int i = imax+1; i < imin; i++) {
		mul *= massive[i];
	}
	return mul;
}

void sort(double massive[], int n)
{
	double temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (massive[j] > massive[j + 1]) {
				// меняем элементы местами
				temp = massive[j];
				massive[j] = massive[j + 1];
				massive[j + 1] = temp;
			}
		}
	}
}

void sout(double massive[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << massive[i] << " ";
	}
}

void out_file(double massive[], int n, ofstream out)
{
	for (int i = 0; i < n; i++) {
		out << massive[i] << " ";
	}
}

void rand_massive(double massive[], int n, int min, int max)
{
	for (int i = 0; i < n; i++) {
		massive[i] = rand() % max + min;
	}
}

