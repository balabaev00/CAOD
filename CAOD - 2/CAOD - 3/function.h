#pragma once


#include <iostream>
#include <string>
#include <fstream>
#include "pch.h"

using namespace std;


double sum_negative(double massive[], int n);
double mul_min_max(double massive[], int n);
void sort(double massive[], int n);
void sout(double massive[], int n);
void out_file(double massive[], int n, ofstream out);
void rand_massive(double massive[], int n, int min, int max);
double mul_plus(double massive[], int n);
double sum_min(double massive[], int n);