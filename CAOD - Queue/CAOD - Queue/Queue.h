#pragma once
#include "pch.h"
#include <iostream>

const unsigned MAX_QUEUE_SIZE = 50; // ������������ ����� �������

template <typename T>
class Queue
{
private:
	int front, // ������� ������� �������� � �������
		rear, // ������� ���������� �������� � �������
		count; // ���-�� ��������� �������
	T qlist[MAX_QUEUE_SIZE]; // ������ �� ������ �������

public:
	// ����������
	enum ERRORS {
		queue_overflow = -1, // ������������ �������
		queue_isEmpty = -2, // ������� �����
	};

	Queue() : front(0), rear(0), count(0)
	{}

	// ������� ���-�� ��������� � �������
	int QLength() const {
		return count;
	}

	// �������� ������� �� �������
	bool QEmpty() const {
		return (QLength() == 0) ? true : false;
	}

	void QInsert(T item) {
		// ������� ����������, ���� ������� ���������
		if (count == MAX_QUEUE_SIZE)
			throw queue_overflow;
		// ��������� count, ��������� �������� item �������� �������
		// �������� �������� rear
		count++;
		qlist[rear] = item;
		rear = (rear + 1) % MAX_QUEUE_SIZE;
	}

	T QDelete() {
		T temp;
		// ���� ������� �����, ������� ����������
		if (QEmpty())
			throw queue_isEmpty;
		// �������� �������� � ������ �������
		temp = qlist[front];
		// ��������� count �� �������
		// ���������� ������ ������� � ���������� ������� ��������
		// �� ������
		count--;
		front = (front + 1) % MAX_QUEUE_SIZE;
		return temp;
	}

	// ������� ������ ������� � �������
	T QFront() const {
		// ���� ������� �����, ������� ����������
		if (QEmpty())
			throw queue_isEmpty;
		return qlist[front];
	}

	void QClear() {
		front = 0;
		rear = 0;
		count = 0;
	}

};