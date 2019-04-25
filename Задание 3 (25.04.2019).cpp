//Дан текстовый файл.Необходимо переписать его строки в другой файл. Порядок строк во втором файле должен совпадать с порядком строк в заданном файлею


#include "stdio.h"
#include "tchar.h"
#include <iostream>
#include <fstream>
#include <string>

int main() 
{
	std::ifstream Reading1("Reading1.txt");
	std::ofstream Writing1("Writing1.txt");
	std::string buffer;
	if (Reading1.is_open()) 
	{
		while (!Reading1.eof()) 
		{
			std::getline(Reading1, buffer);
			Writing1 << buffer << std::endl;
		}
		Reading1.close();
		Writing1.close();
	}
	else std::cout << "Couldn't open the file!\n";
	
	system("pause");
	return 0;
}
