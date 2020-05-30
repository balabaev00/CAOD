#pragma once;
#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

struct node
{
	int elem;
	node *sled;
	node *pred;
};
class Spisok
{
private:
	node *nsp, *ksp;
public:
	Spisok() { nsp = ksp = NULL; }
	void Postroenie();
	void VyvodForward(ofstream &out);
	void VyvodBack(ofstream &out);
	void Ochistka();
	void InsAfter(int, node*);
	void InsBefore(int, node*);
	void Delete(node*);
	void DelAfter(node*);
	void DelSim();
	void Sort();
	node *PoiskForward(int);
	node *PoiskBack(int);
};

void Spisok::Postroenie()
//���������� ���������������� ������ � ��������� ������:
// nsp - ��������� �� ������ ������,
// ksp - ��������� �� ����� ������.
{
	node *rsp;
	int el;

	nsp = new(node);
	rsp = nsp;
	(*nsp).pred = NULL; (*nsp).sled = NULL;
	cout << "������� ������������������:\n";
	cin >> el;
	while (el != 0)
	{
		(*rsp).sled = new(node);
		(*((*rsp).sled)).pred = rsp; rsp = (*rsp).sled;
		(*rsp).sled = NULL; (*rsp).elem = el;
		cin >> el;
	}
	ksp = rsp;
}

void Spisok::VyvodForward(ofstream &out)
//����� ����������� ���������������� ������ �� ��� ������.
// nsp - ��������� �� ������ ������, ksp - ��������� �� ����� ������.
{
	node *rsp;
	rsp = (*nsp).sled;
	cout << "��������������� ������ ��������: ";
	out << "��������������� ������ ��������: ";
	while (rsp != NULL)
	{
		int x = rsp->elem;
		cout << x << " "; rsp = (*rsp).sled;
		out << x << " "; 
	}
	cout << endl;
	out << endl;
}

void Spisok::VyvodBack(ofstream &out)
//����� ����������� ���������������� ������ �� ��� �����.
// nsp - ��������� �� ������ ������, ksp - ��������� �� ����� ������.
{
	node *rsp;

	rsp = ksp;
	cout << "��������������� ������ � �������� �������: ";
	out << "��������������� ������ � �������� �������: ";
	while ((*rsp).pred != NULL)
	{
		int x = rsp->elem;
		cout << x << " "; rsp = (*rsp).pred;
		out << x << " ";
	}
	cout << endl;
	out << endl;
}

node *Spisok::PoiskForward(int el)
//������� ���������� ��������� �� ��������� ������� el
//���������������� ������, ��������� �����������  nsp
// � ksp, ��� NULL, ���� ������� � ������ �� ������.
{
	node   *q;
	node *Res;

	Res = NULL; q = (*nsp).sled;
	while (q != NULL && Res == NULL)
		if ((*q).elem == el) Res = q;
		else  q = (*q).sled;
	return Res;
}

node *Spisok::PoiskBack(int el)
//������� ���������� ��������� �� ��������� ������� el
//���������������� ������, ��������� �����������  nsp
// � ksp, ��� NULL, ���� ������� � ������ �� ������.
{
	node   *q;
	node *Res;

	Res = NULL; q = ksp;
	while (q != NULL && Res == NULL)
		if ((*q).elem == el) Res = q;
		else  q = (*q).pred;
	return Res;
}

void Spisok::InsAfter(int el, node *Res)
//������� ����� � �������������� ����� el �
//� ��������������� ������, �������� �����������
// nsp � ksp, ����� �����, �� ������� ��������� Res.
{
	node *q;

	q = new(node);
	(*q).elem = el;
	if ((*Res).sled != NULL)
	{
		(*q).sled = (*Res).sled;
		(*q).pred = (*(*Res).sled).pred;
		(*(*Res).sled).pred = q; (*Res).sled = q;
	}
	else
	{
		(*q).sled = NULL;
		(*q).pred = Res; ksp = q; (*Res).sled = q;
	}
}

void Spisok::InsBefore(int el, node *Res)
//������� ����� � �������������� ����� el �
//� ��������������� ������, �������� �����������
// nsp � ksp, ����� ������, �� ������� ��������� Res.
{
	node *q;
	q = new(node);
	(*q).elem = el;
	(*q).sled = (*(*Res).pred).sled;
	(*q).pred = (*Res).pred;
	(*(*Res).pred).sled = q; (*Res).pred = q;
}

void Spisok::Delete(node *Res)
//�������� ����� �� ���������������� ������.
// nsp - ��������� �� ������ ������,
// ksp - ��������� �� ����� ������,
// Res - ��������� �� ��������� �����.
{
	if ((*Res).sled != NULL)
	{
		(*(*Res).sled).pred = (*Res).pred;
		(*(*Res).pred).sled = (*Res).sled;
		delete Res;
	}
	else
	{
		(*(*Res).pred).sled = NULL; ksp = (*ksp).pred;
		delete Res;
	}
}

void Spisok::DelAfter(node *Res)
//�������� ����� �� ���������������� ������.
// nsp - ��������� �� ������ ������,
// ksp - ��������� �� ����� ������,
// Res - ��������� �� �����, ���������� ����������.
{
	node *q;

	if ((*Res).sled == NULL) cout << "������� ��������� �����!\n";
	else
		if ((*(*Res).sled).sled != NULL)
		{
			q = (*Res).sled;
			(*(*(*Res).sled).sled).pred = Res;
			(*Res).sled = (*(*Res).sled).sled;
			delete q;
		}
		else
		{
			q = (*Res).sled; (*Res).sled = NULL;
			ksp = (*ksp).pred; delete q;
		}
}

void Spisok::DelSim()
// �������� ���������� ���������
{
	node *i = nsp;
	node *j = nsp;
	while (i != NULL) {
		while (j != NULL) {
			if (i->elem == j->elem && i != j) {
				Delete(i);
				Delete(j);
				i = nsp;
				j = nsp;
			}
			j = j->sled;
		}
		i = i->sled;
		j = nsp;
	}
}

void Spisok::Ochistka()
//�������� ���������������� ������ �� ������.
// nsp - ��������� �� ��������� ����� ������,
// ksp - ��������� �� ��������� ����� ������.
{
	node *q, *q1;

	q = nsp; q1 = (*q).sled;
	while (q1 != NULL)
	{
		q = q1; q1 = (*q1).sled; delete q;
	}
	delete nsp; nsp = ksp = NULL;
}

void Spisok::Sort() {
	node *left = nsp;                 //������ ������� � ��� ����� ����� ������
	node *right = nsp->sled;          //������ ������� � ��� ����� ����� ��������� �� ������� �������
	node *temp = new node;              //��������� ����� ��� �������� ��������������� ���� �������� ��������������� �����
	while (left) {                 //������� �� ���� �������, �� ����������� �������� �������
		while (right) {              //������� �� ���� �������, ������� ������� ������ (�� ���� ������������ ������� ������ �� ������� ������)
			if ((left->elem) < (right->elem)) {        //��������� ������������� ������������
				temp->elem = left->elem;              //� ������������ ��� ���������� ��������, �� ����������� ���������� �����, �������
				left->elem = right->elem;             //������ � ��� ������� ������ x, ������� ������ ���
				right->elem = temp->elem;             //����� ��  ����� ���� ��� ����������� ��� ������� ������������ ��������
			}
			right = right->sled;                    //�� �������� ���������� ��������� �� ��������� ������� (�� ������� ����������), ����� ���� ��������
		}
		left = left->sled;                              //�� �������� ���������� ��������� �� ��������� ������� (�� ������� ����������), ����� ���� ��������
		right = nsp;                             //��������� ������ ��������� ������ ������� �����, ����������� ���������� ��� �����, ��� ��������� ������� ������������ �������� �������
	}
}