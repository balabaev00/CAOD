#pragma once
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

struct Student {
	string secondName;
	short number;
	short rating[5];
};


void readStudent(Student student[], short n);
void sortStudent(Student student[], short n);
void writeStudent(Student student[], short n);
void writeGoodStudent(Student student[], short n);
void writeGoodStudentFile(Student student[], short n, ofstream &out);
void writeStudentFile(Student student[], short n, ofstream &out);