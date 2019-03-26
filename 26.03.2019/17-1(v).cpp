/*
Задание 1:
Написать функцию, добавляющую строку двухмерному массиву в конец.
*/
#include <iostream>
#include <cstring>
#include <cstdlib>

void insert_str(char*** arr, char* str);
void print_arr(char*** arr);

int main()
{
	char** arr = (char**)malloc(1);
	char Str[100] = { };
	std::cout << "Enter string 1 " << std::endl;
	gets_s(Str);
	char Str1[100] = { };
	std::cout << "Enter string 2 " << std::endl;
	gets_s(Str1);
	insert_str(&arr, Str);
	insert_str(&arr, Str1);
	print_arr(&arr);

	system("pause");
	return 0;
}
void insert_str(char*** arr, char* str)
{
	int size = _msize(*arr)/sizeof(char*);
	char** new_arr = (char**)malloc(sizeof(char*)*(size + 1));
	memcpy(new_arr, *arr, sizeof(char*)*size);
	new_arr[size] = str;
	free(*arr);
	*arr = new_arr;
}
void print_arr(char*** arr)
{
	int size = _msize(*arr) / sizeof(char*);
	for (int i = 0; i < size; i++)
	{
		std::cout << (*arr)[i] << std::endl;
	}
}
