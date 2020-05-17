#pragma once
#include "pch.h"
#include <random>
#include <iostream>
#include <fstream>

using namespace std;

int * createRandomArray(int min, int max, int n); // Создание рандомного массива
void printArray(int* &array, int n); // Вывод массива на экран
void quickSort(int* array, int n); // Быстрая сортировка массива
void binarySearch(int *array, int key, int left, int right); // Бинарный поиск
void writeBinaryFile(int* array, int n); // Запись в бинарный файл
int* readBinaryFile(int n); // Чтение из бинарного файла
int * naturalMerging(int * a, int * b, int n, int m); // Сортировка естественным слиянием
void arrayToFile(int *array, int n); // Запись массива в файл