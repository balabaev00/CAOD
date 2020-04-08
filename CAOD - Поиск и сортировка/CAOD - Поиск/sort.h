#pragma once
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

/*Сортировка массива пузырьком*/
void bubbleSort(int *array, int n);
/*Сортировка массива выбором*/
void selectionSort(int *array, int n);
/*Сортировка массива вставками*/
void insertion(int *array, int n);
/*Быстрая сортировка*/
void quickSort(int* array, int n);
/*Сортировка массива Шелла*/
void shellSort(int *array, int n);