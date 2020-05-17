#pragma once
#include "pch.h"
#include <random>
#include <iostream>
#include <fstream>

using namespace std;

int * createRandomArray(int min, int max, int n); // �������� ���������� �������
void printArray(int* &array, int n); // ����� ������� �� �����
void quickSort(int* array, int n); // ������� ���������� �������
void binarySearch(int *array, int key, int left, int right); // �������� �����
void writeBinaryFile(int* array, int n); // ������ � �������� ����
int* readBinaryFile(int n); // ������ �� ��������� �����
int * naturalMerging(int * a, int * b, int n, int m); // ���������� ������������ ��������
void arrayToFile(int *array, int n); // ������ ������� � ����