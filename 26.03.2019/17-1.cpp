//Задание 1:
//Написать функцию, добавляющую строку двухмерному массиву в конец.
#include "pch.h"
#include <iostream>
using namespace std;
void insert_str(char***arr, char* str);
void print_arr(char***arr);
const size_t N = 100;
int main()
{
	char str[100] = { };
	cout << "\nVvedite one str   ";
	gets_s(str);
	char str1[100] = { };
	cout << "\nVvedite two str  ";
	gets_s(str1);
	char **arr = (char**)malloc(1);
	insert_str(&arr, str);
	insert_str(&arr, str1);
	print_arr(&arr);
	return 0;
}

void insert_str(char***arr, char* str)
{
	int size = _msize(*arr)/ sizeof(char*);
	char** new_arr = (char**)malloc(sizeof(char*)*(size + 1));
	memcpy(new_arr, *arr, sizeof(char*)*size);
	new_arr[size] = str;
	free(*arr);
	*arr = new_arr;
}
void print_arr(char***arr)
{
	int size = _msize(*arr) / sizeof(char*);
	for (int i = 0; i < size; i++)
	{
	        cout<<(*arr)[i]<<endl;
	}
}
