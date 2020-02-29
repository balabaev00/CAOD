#include"pch.h"
#include "function.h"

int** createArray(int n, int m)
{
	int **massive;
	massive = new int *[n];
	for (int i = 0; i < n; i++) {
		massive[i] = new int[m];
	}
	return massive;
}

void toString(int **massive, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << massive[i][j]  << " ";
		}
		cout << endl;
	}
}

void randomArray(int **massive, int n, int m, int min, int max)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			massive[i][j] = rand() % max + min;
		}
	}
}

int countNotNull(int ** massive, int n, int m)
{
	int count = 0;
	int temp=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (massive[i][j] != 0) {
				temp++;
			}
			if (temp == m)
				count++;
		}
		temp = 0;
	}
	return count;
}

void deleteArray(int ** massive, int n)
{
	for (int i = 0; i < n; i++)
		delete[] massive[i];
	delete[] massive;
}

int maxCount(int ** massive, int n, int m)
{
	int count = 0;
	int countTemp = 0;
	vector<int> temp;
	vector<vector<int>> array;
	array.resize(n);
	for (int i = 0; i < array.size(); i++) {
		array[i].resize(m);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			array[i][j] = massive[i][j];
		}
	}

	int max = array[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (max < array[i][j])
				max = array[i][j];
		}
	}

	// Ищем повторения
	while (true)
	{
		count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (max == array[i][j])
					count++;
			}
		}

		countTemp = 0;
		if (count > 1) {
			return max;
		}
		else {
			temp.push_back(max);
			max = array[0][0];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (max < array[i][j]) {
						for (int k = 0; k < temp.size(); k++) {
							if (temp[k] != array[i][j]) {
								countTemp++;
							}
							if (countTemp == temp.size()) {
								max = array[i][j];
							}
						}
						countTemp = 0;
					}
				}
			}
		}
	}
	//delete index temp.erase(temp.begin + index);
	return 0;
}

int countNegative(int ** massive, int n, int m)
{
	int count = 0;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (massive[i][j] == 0 && flag == false) {
				flag = true;
				for (int k = 0; k < m; k++) {
					if (massive[i][k] < 0) {
						count++;
					}
				}
			}
		}
		flag = false;
	}
	return count;
}
