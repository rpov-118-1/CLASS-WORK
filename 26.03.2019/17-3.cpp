
include <iostream>
#include <time.h>
#include <string>
#include <locale>
#include <string.h>
#include <iomanip>

using namespace std;
//3.Написать функцию, добавляющую строку двухмерному массиву в указанную позицию.
void main() {
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int n = 10;
	int m = 10;
	int pos;
	cout << "Введите позицию(после какой строки добавить новую) ";
	cin >> pos;
	int **p;
	p = new int*[n];

	for (int i = 0; i < n; i++) {
		p[i] = new int[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			p[i][j] = rand() % 20;
			cout << setw(5) << p[i][j] << " ";
		}cout << endl;
	}
	cout << "**************************************************************" << endl;

	int **t;
	t = new int*[pos];
	for (int i = 0; i < pos; i++) {
		t[i] = new int[m];
		for (int j = 0; j < m; j++)
			t[i][j] = p[i][j];
	}
	int **t2;
	t2 = new int*[n - pos];
	for (int i = 0; i < n - pos; i++) {
		t2[i] = new int[m];
		for (int j = 0; j < m; j++)
			t2[i][j] = p[i + pos][j];
	}

	for (int i = 0; i < n; i++)
		delete p[i];
	delete[] p;

	p = new int*[n + 1];
	for (int i = 0; i < n + 1; i++) {
		p[i] = new int[m];
	}
	for (int i = 0; i < m; i++) {
		p[pos][i] = 0;
	}
	
	for (int i = 0; i < pos; i++) {
		for (int j = 0; j < m; j++)
			p[i][j] = t[i][j];
	}

	for (int i = 0; i < n - pos; i++)
	{
		for (int j = 0; j < m; j++)
			p[i + pos + 1][j] = t2[i][j];
	}

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < m; j++) {

			cout << setw(5) << p[i][j] << " ";
		}cout << endl;
	}

	for (int i = 0; i < n + 1; i++) {
		delete p[i];
	}
	delete[] p;
	delete[] t;
	delete[] t2;

	system("pause");
}
