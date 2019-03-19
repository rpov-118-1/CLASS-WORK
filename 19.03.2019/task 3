//Создать библиотеку следующих функций:
//char * mystrcat (char * str1, const char * str2); - функция присоединяет строку str2 к строке str1. 
//Функция возвращает указатель на первую строку str1.
#include <iostream> 
#include <stdio.h> 
using namespace std;
 
char *myStrcat(char *str1, char *str2)
{
	char* res = str1;
	while (*str1)
	{
		str1++;
	}
	while (*str2)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return res;
}
int main()
{
	char str1[100000]{ 0 };
	char str2[100000]{ 0 };
	printf("Enter a string: ");
	gets_s(str1);
	gets_s(str2);
	cout << myStrcat(str1, str2);
	return 0;
}
