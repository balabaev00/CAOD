#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


template <typename T>

class Set
{
private:
	
	vector<T> set;

	bool checkElement(T element) { // ��� ��� set �� ����� ��������� ���������� �������� ����� ��������� �� �������
		for (int i = 0; i < size(); i++) {
			if (set[i] == element) {
				return true;
			}
		}
		return false;
	}

	void sort(vector<T> &set) {
		T temp; // ��������� ���������� ��� ������ ��������� �������
	// ���������� ������� ���������
		for (int i = 0; i < set.size() - 1; i++) {
			for (int j = 0; j < set.size() - i - 1; j++) {
				if (set[j] > set[j + 1]) {
					// ������ �������� �������
					temp = set[j];
					set[j] = set[j + 1];
					set[j + 1] = temp;
				}
			}
		}
	}
public:

	void setSet(vector<T> set) {
		this->set = set;
	}

	T getElement(int index) {
		return this->set[index];
	}
	
	void insert(T element) // �������� ������� 
	{
		if (!checkElement(element)) {
			set.push_back(element);
			sort(this->set);
		}
	}

	int size() // ���������� ������ Set'a
	{
		return set.size();
	}

	void print() // �����
	{
		for (int i = 0; i < size(); i++) {
			cout << set[i] << " ";
		}
	}

	void clear() { // ������� Set
		set.clear();
	}

	void deleteElement(T element) { // �������� ��������
		for (int i = 0; i < size(); i++) {
			if (set[i] == element) {
				set.erase(set.begin()+i);
			}
		}
	}
	
	void printFile(ofstream &out) {
		for (int i = 0; i < size(); i++) {
			out << set[i] << " ";
		}
		out << endl;
	}

	Set<T> unification(Set<T> set2) { // ����������� ��������
		Set<T> set3;
		vector<T> newSet;
		newSet.resize(set.size() + set2.size()); // �������� ������ ��� ��� ���������
		for (int i = 0; i < this->size(); i++) { // ��������� ������ ���������
			newSet[i] = this->set[i];
		}
		for (int i = this->size(); i < newSet.size(); i++) { // ��������� ������ ���������
			newSet[i] = set2.getElement(i-set.size());
		}
		sort(newSet);
		for (int i = 0; i < newSet.size(); i++) {
			for (int j = 0; j < newSet.size()-1; j++) {
				if (newSet[j] == newSet[j + 1]) {
					newSet.erase(newSet.begin() + j);
				}
			}
		}
		set3.setSet(newSet);
		return set3;
	}

	void difference(Set<T> set2) {
		for (int i = 0; i < this->set.size(); i++) {
			for (int j = 0; j < set2.size(); j++) {
				if (this->set[i] == set2.getElement(j)) {
					set.erase(set.begin() + i);
				}
			}
		}
	}
};

