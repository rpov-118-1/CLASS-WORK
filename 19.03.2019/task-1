//int mystrlen(const char * str); - функция определяет длину строки.

#include <iostream>
#include <cstdio>
#include <string.h>
#include <stdio.h>
using namespace std;

int mystrlen(char* string)
{
	int i = 0;
	while (string[i])
		i++;
	return i;
}

int main()
{
	char str[100];
	char* strPointer;
	strPointer = &str[0];

	cout << "Enter some string\n";
	gets_s(str, 100);
	cout << "The length of your string is " << mystrlen(strPointer) << "\n";

	return 0;
}
