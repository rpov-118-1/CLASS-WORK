//char * mystrcpy (char * str1, const char * str2); - функция копирует строку str2 в буфер, адресуемый через str1. Функция возвращает указатель на первую строку str1.

#include "stdio.h"
#include "iostream"

char* mysrtcpy(char* str1, const char* str2) {
	int i = 0;
	int lenght = 0;
	while (true) {
		if (str2[i] != '\0') {
			lenght++;
			i++;
		}
		else break;
	}
	for (i = 0; i < lenght; i++) {
		str1[i] = str2[i];
	}
	return str1;
}

int main() {
	char str1[1024] = { 0 };
	char str2[1024] = { 0 };
	printf("Enter a string: ");
	gets_s(str2);
	mysrtcpy(str1, str2);
	std::cout << str1 << std::endl;

	return 0;
}
