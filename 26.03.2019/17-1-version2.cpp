#include <iostream>
#include <cstring>
#include <cstdlib>

void insert_str(char*** arr, char* str);
void print_arr(char*** arr);

int main()
{
	bool flag = true;
	int a;
	char** arr = (char**)malloc(1);

	do
	{
		std::cout << "For exit press - 0 or enter next string" << std::endl;
		std::cin >> a;
		if (a == 0) flag = false;
		char* buf = (char*)malloc(1024);
		gets_s(buf, 1024);
		insert_str(&arr, buf);
		print_arr(&arr);

	} while (true);

	

	system("pause");
	return 0;
}
void insert_str(char*** arr, char* str)
{
	int size = _msize(*arr) / sizeof(char*);
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
