/*Написать программу, которая поэлементно суммирует два  массива,
заполненных случайными числами и сохраняет результат в третьем массиве. 
Размеры исходных массивов задаются пользователем.
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

int main()
{
	

	int arrSize;
	std::cout << "N: ";
	std::cin >> arrSize;

	int arrCol = 2;
	
	auto firstArray = new int[arrSize];
	std::cout << "First array : ";
	for (int i = 0; i < arrSize; i++) 
	{
		std::cout << " " << (firstArray[i] = std::rand() % 10 + 1);
	}
	std::cout << std::endl;


	int *secondArray = new int[arrSize];
	std::cout << "Second array: ";
	for (int i = 0; i < arrSize; i++) {
		std::cout << " " << (secondArray[i] = std::rand() % 10 + 1);
	}
	std::cout << std::endl;

	int *thirdArray = new int[arrSize];
	std::cout << "Third array : ";
	for (int i = 0; i < arrSize; i++) {
		std::cout <<  " " << (thirdArray[i] = firstArray[i] + secondArray[i]);
	}
	std::cout << std::endl;

	delete[] firstArray;
	firstArray = nullptr;

	delete[] secondArray;
	secondArray = nullptr;

	delete[] thirdArray;
	thirdArray = nullptr;

	std::system("pause");
	return 0;
}
