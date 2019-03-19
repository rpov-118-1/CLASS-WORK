//Перевернуть весь текст целиком

#include <iostream>
#include <cstdio>
#include <string.h>
#include <stdio.h>
using namespace std;

void rev(const char* const c)
{
	if (*c)
	{
		rev(c + 1);
		putchar(*c);
	}
}

int main(void)
{
	rev("Hello!");
	return 0;
}
