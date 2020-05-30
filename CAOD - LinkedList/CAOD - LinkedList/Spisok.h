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
//Построение двунаправленного списка с заглавным звеном:
// nsp - указатель на начало списка,
// ksp - указатель на конец списка.
{
	node *rsp;
	int el;

	nsp = new(node);
	rsp = nsp;
	(*nsp).pred = NULL; (*nsp).sled = NULL;
	cout << "Вводите последовательность:\n";
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
//Вывод содержимого двунаправленного списка от его начала.
// nsp - указатель на начало списка, ksp - указатель на конец списка.
{
	node *rsp;
	rsp = (*nsp).sled;
	cout << "Двунаправленный список содержит: ";
	out << "Двунаправленный список содержит: ";
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
//Вывод содержимого двунаправленного списка от его конца.
// nsp - указатель на начало списка, ksp - указатель на конец списка.
{
	node *rsp;

	rsp = ksp;
	cout << "Двунаправленный список в обратном порядке: ";
	out << "Двунаправленный список в обратном порядке: ";
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
//Функция возвращает указатель на найденный элемент el
//двунаправленного списка, заданного указателями  nsp
// и ksp, или NULL, если элемент в списке не найден.
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
//Функция возвращает указатель на найденный элемент el
//двунаправленного списка, заданного указателями  nsp
// и ksp, или NULL, если элемент в списке не найден.
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
//Вставка звена с информационным полем el в
//в двунаправленный список, заданный указателями
// nsp и ksp, после звена, на которое указывает Res.
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
//Вставка звена с информационным полем el в
//в двунаправленный список, заданный указателями
// nsp и ksp, перед звеном, на которое указывает Res.
{
	node *q;
	q = new(node);
	(*q).elem = el;
	(*q).sled = (*(*Res).pred).sled;
	(*q).pred = (*Res).pred;
	(*(*Res).pred).sled = q; (*Res).pred = q;
}

void Spisok::Delete(node *Res)
//Удаление звена из двунаправленного списка.
// nsp - указатель на начало списка,
// ksp - указатель на конец списка,
// Res - указатель на удаляемое звено.
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
//Удаление звена из двунаправленного списка.
// nsp - указатель на начало списка,
// ksp - указатель на конец списка,
// Res - указатель на звено, предыдущее удаляемому.
{
	node *q;

	if ((*Res).sled == NULL) cout << "Указано последнее звено!\n";
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
// Удаление одинаковых элементов
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
//Удаление двунаправленного списка из памяти.
// nsp - указатель на заглавное звено списка,
// ksp - указатель на последнее звено списка.
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
	node *left = nsp;                 //Первый элемент — это пусть будет голова
	node *right = nsp->sled;          //Второй элемент — это пусть будет следующий за головой элемент
	node *temp = new node;              //Временное звено для хранения переставляемого всех значений переставляемого звена
	while (left) {                 //Обходим по всем звеньям, за исключением крайнего правого
		while (right) {              //Обходим по всем звеньям, включая крайний правый (по всем относительно первого левого на текущий момент)
			if ((left->elem) < (right->elem)) {        //Проверяем необходимость перестановки
				temp->elem = left->elem;              //И переставляем все внутренние элементы, за исключением указателей связи, местами
				left->elem = right->elem;             //Сейчас у нас имеется только x, поэтому только его
				right->elem = temp->elem;             //иначе бы  нужно было это проделывать для каждого несвязующего элемента
			}
			right = right->sled;                    //не забываем направлять указатель на следующий элемент (по подобию инкремента), иначе цикл зависнет
		}
		left = left->sled;                              //не забываем направлять указатель на следующий элемент (по подобию инкремента), иначе цикл зависнет
		right = nsp;                             //Поскольку второй указатель убежал немного вперёд, обязательно возвращаем его назад, это следующий элемент относительно текущего первого
	}
}