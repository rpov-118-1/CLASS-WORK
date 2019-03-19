// char * mystrchr (char * str, char s); - функция осуществляет поиск символа s в строке str. Функция возвращает указатель на первое вхождение символа в строку, в противном случае 0.

#include "iostream"
#include "ctime"
#include "stdlib.h"
#include "stdlib.h"
#include "stdio.h"
#include "cstdio"
#include "cstring"
using namespace std;
const size_t N = 120;
char * mystrchr (char A[N], char s);
int main()
{
	setlocale(LC_CTYPE, "rus");
	typedef char cha[N];
	cha A;
	char s;
	char *znach;
	cout << "Vvedite";
	gets_s(A);
	cout << "\nFraza\t" << A;
	cout << "Vvedite symbol";
	cin >> s;
	znach=mystrchr(A, s);
	cout << znach;
	return 0;
}

char * mystrchr(char A[N], char s)
{
	int i=0;
	char* j;
	while (A[i]!='\0')
	{
		if (A[i] == s) { j = &A[i]; return j; }
		i++;
	}
	return nullptr;
}
