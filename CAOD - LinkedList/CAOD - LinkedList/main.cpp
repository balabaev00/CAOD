

#include "pch.h"
#include <iostream>
#include "Spisok.h"
#include <fstream>

using namespace std;

const string filename = "result.txt";

int main() {

	setlocale(LC_ALL, "RUSSIAN");
	ofstream out(filename, ios::app);
	Spisok A;
	A.Postroenie();
	A.VyvodForward(out);
	A.VyvodBack(out);
	A.Sort();
	out << "После сортировки элементов" << endl;
	cout << "После сортировки элементов" << endl;
	A.VyvodForward(out);
	A.DelSim();
	out << "После удаления одинаковых элементов" << endl;
	cout << "После удаления одинаковых элементов" << endl;
	A.VyvodForward(out);
	
	/*cout << "Введите элемент звена, после которого ";
	cout << "осуществляется вставка: ";
	cin >> el;
	cout << "Введите элемент вставляемого звена: ";
	cin >> el1;
	Res = A.PoiskForward(el);
	if (Res != NULL)
	{
		A.InsAfter(el1, Res);
		A.VyvodForward(); A.VyvodBack();
	}
	else  cout << "Звена с заданным элементом в списке нет!\n";

	cout << "Введите элемент звена, перед которым ";
	cout << "осуществляется вставка: ";
	cin >> el;
	cout << "Введите элемент вставляемого звена: ";
	cin >> el1;
	Res = A.PoiskBack(el);
	if (Res != NULL)
	{
		A.InsBefore(el1, Res);
		A.VyvodForward(); A.VyvodBack();
	}
	else  cout << "Звена с заданным элементом в списке нет!\n";

	cout << "Введите элемент звена, после которого ";
	cout << "осуществляется удаление: ";
	cin >> el;
	Res = A.PoiskForward(el);
	if (Res != NULL)
	{
		A.DelAfter(Res);
		A.VyvodForward(); A.VyvodBack();
	}
	else  cout << "Звена с заданным элементом в списке нет!\n";

	cout << "Введите элемент звена, которое ";
	cout << "надо удалить: ";
	cin >> el;
	Res = A.PoiskForward(el);
	if (Res != NULL)
	{
		A.Delete(Res);
		A.VyvodForward(); A.VyvodBack();
	}
	else  cout << "Звена с заданным элементом в списке нет!\n";*/

	A.Ochistka();
	out.close();
}


