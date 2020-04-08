#pragma once
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

/*Задание рандомных значений [min,max]*/
void random(int *array, int n, int min, int max); 
/*Последовательный поиск по ключу*/
/*Вход алгоритма : массив, размерность массива, ключ*/
/*Выход алгоритма : строка содержащая все элементы массива соответствующие ключу*/
string search(int *array, int n, int key);
/*Поиск с сужением зоны*/
/*Вход алгоритма: упорядоченный по возрастанию массив, левая граница поиска, правая граница поиска;*/
/*Выход алгоритма: номер найденного элемента или -1.*/
int binarySearch(int val, int a[], int left, int right);
/*Создании инвертированного массива*/
int * prepare(int a[], int N, int *min, int *max);
/*Поиск*/
int distributedSearch(int a[], int N, int key);
/*Руччной ввод данных*/
void read(int *array, int n);
/*Форматированный вывод*/
void write(int *array, int n);