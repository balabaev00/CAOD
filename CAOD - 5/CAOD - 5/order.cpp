
#include "pch.h"
#include "order.h"
#include <string>
using namespace std;

void readOrder(Order order[], short n)
{
	for (int i = 0; i < n; i++) {
		cout << "¬ведите номер счета плательщика : ";
		cin >> order[i].payer;
		cout << "¬ведите номер счета получател€  : ";
		cin >> order[i].recipient;
		cout << "¬ведите сумму  : ";
		cin >> order[i].sum;
	}
}

void sortOrder(Order order[], short n)
{
	for (int i = 1; i < n; ++i)
	{
		for (int r = 0; r < n - i; r++)
		{
			if (order[r].payer > order[r + 1].payer)
			{
				Order temp = order[r];
				order[r] = order[r + 1];
				order[r + 1] = temp;
			}
		}
	}
}

void writeOrder(Order order[], short n)
{
	for (int i = 0; i < n; i++) {
		cout << i << " —чЄт" << endl;
		cout << "—чет плательщика : " << order[i].payer << endl;
		cout << "—чет получател€  : " << order[i].recipient << endl;
	}
	cout << endl;
}

void writeGoodOrder(Order order[], short n)
{
	for (int i = 0; i < n; i++) {
		if (order[i].sum > 0) {
			cout << "—чет плательщика : " << order[i].payer << endl;
			cout << "—чет получател€  : " << order[i].recipient << endl;
			cout << "—умма сн€ти€ : " << order[i].sum << endl;
		}
	}
}
