#pragma once
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

/*Задание рандомных значений [min,max]*/
void random(int *array, int n, int min, int max); 
/*Поиск по ключу*/
string search(int *array, int n, int key);
/*Руччной ввод данных*/
void read(int *array, int n);
/*Форматированный вывод*/
void write(int *array, int n);