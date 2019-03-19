/*char * mystrstr (char * str1,  char * str2); - функция осуществляет поиск подстроки str2 в строке str1.
Функция возвращает указатель на первое вхождение подстроки str2 в строку str1, в противном случае 0.
*/
#include "iostream"
#include "tchar.h"
#include "stdio.h"
#include "stdlib.h"
#include "iomanip"
#include "ctime"
char* MyStrStr(char *str1, char *str2)
{
	char* res = str1;
	if (*str2==0)
		return 0;
	int pos = -1;
	char *a, *b;
	b = str2;
	for (; *str1 != 0; str1++)
	{
		pos++;
		if (*str1 != *b) {
			continue;
		}
		a = str1;
		while (true) 
		{
			if (*b == 0) {
				return &(res[pos]);
			}
			if (*a++ != *b++) {
				break;
			}
		}
		b = str2;

	}
	return nullptr;
}
int main()
{
	char Str1[1024] = "An incredible opportunity is waiting for you. Technology is changing the world by connecting billions of devices and improving how we live, work, play and treat our planet. No industry is immune. Are you ready to change your life, and possibly make the world a better place?";
	char Str2[1024] = "Technology";
	std::cout << MyStrStr(Str1, Str2) << std::endl;
	system("pause");
	return 0;
}
