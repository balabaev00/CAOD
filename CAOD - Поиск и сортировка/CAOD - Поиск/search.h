#pragma once
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

/*������� ��������� �������� [min,max]*/
void random(int *array, int n, int min, int max); 
/*���������������� ����� �� �����*/
/*���� ��������� : ������, ����������� �������, ����*/
/*����� ��������� : ������ ���������� ��� �������� ������� ��������������� �����*/
string search(int *array, int n, int key);
/*����� � �������� ����*/
/*���� ���������: ������������� �� ����������� ������, ����� ������� ������, ������ ������� ������;*/
/*����� ���������: ����� ���������� �������� ��� -1.*/
int binarySearch(int val, int a[], int left, int right);
/*�������� ���������������� �������*/
int * prepare(int a[], int N, int *min, int *max);
/*�����*/
int distributedSearch(int a[], int N, int key);
/*������� ���� ������*/
void read(int *array, int n);
/*��������������� �����*/
void write(int *array, int n);