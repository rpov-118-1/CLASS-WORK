/*Напишите функцию умножения матриц. Матрица представляет собой таблицу чисел. Произведением матрицы A размером M x N (M строк, N столбцов) на матрицу B размером N x K является матрица C размером N x K такая, что 
cij= ai1b1j + ai2b2j + … + aiNbNj, для 1 <= i <= M и 1 <= j <= K, где 
axy – элемент, находящийся на пересечении строки x и столбца y матрицы A;
bxy – элемент, находящийся на пересечении строки x и столбца y матрицы B;
cxy – элемент, находящийся на пересечении строки x и столбца y матрицы C.
*/

#include <iostream>
#include <time.h>

using namespace std;
void shape(int** x, int n, int m, int** y, int** c);
void mult(int** x, int n, int m, int** y, int** mt);
int main()
{
	int n = 3;
	int m = 3;
	srand(time(NULL));
	int **a = new int*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}
	cout << "The array A is" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = rand() % 10;
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	int z = 3;
	int w = 3;
	
	int **b = new int*[z];
	for (int i = 0; i < z; i++)
	{
		b[i] = new int[w];
	}
	cout << "The array B is" << endl;
	for (int i = 0; i < z; i++)
	{
		for (int j = 0; j < w; j++)
		{
			b[i][j] = rand() % 10;
			cout << b[i][j] << ' ';
		}
		cout << endl;
	}
	int l = z;
	int k = w;
	int **add = new int*[l];
	for (int i = 0; i < l; i++)
	{
		add[i] = new int[k];
	}
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < k; j++)
		{
			add[i][j] = 0;
		}
		cout << endl;
	}
	if (n == z && m == w)
		shape(a, n, m, b, add);
	cout << " The addition is" << endl;
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << add[i][j] << ' ';
		}
		cout << endl;
	}
	int **mt = new int*[l];
	for (int i = 0; i < l; i++)
	{
		mt[i] = new int[k];
	}
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < k; j++)
		{
			mt[i][j] = 0;
		}
		cout << endl;
	}
	if (m == z)
		mult(a, n, m, b, mt);
	else cout << "Error in mult" << endl;
	cout << " The mult is is" << endl;
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << mt[i][j] << ' ';
		}
		cout << endl;
	}
	system("PAUSE");
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	for (int i = 0; i < z; i++)
		delete[] b[i];
	delete[] b;
	for (int i = 0; i < l; i++)
		delete[] add[i];
	delete[] add;
	for (int i = 0; i < l; i++)
		delete[] mt[i];
	delete[] mt;
	return 0;
}
void shape(int** x, int n, int m, int** y, int** add)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			add[i][j] = x[i][j] + y[i][j];
		}
	}
}
void mult(int** x, int n, int m, int** y, int** mt)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			{
				mt[i][j] = x[i][i] * y[i][j];
			}
		}
	}

}
