#include "pch.h"
#include <iostream>

struct utug {
	char firma[1024];
	char model[1024];
	char color[1024];
	double MinT;
	double MaxT;
	char Steam[1024];
	double P;
};
int main()
{
	system("chcp 1251 > null");
	utug samsung{};
	std::cin >> samsung.firma;
	std::cin >> samsung.model;
	std::cin >> samsung.color;
	std::cin >> samsung.MinT;
	std::cin >> samsung.MaxT;
	std::cin >> samsung.Steam;
	std::cin >> samsung.P;

	std::cout << "Фирма утюга: " << samsung.firma << std::endl;
	std::cout << "Модель утюга: " << samsung.model << std::endl;
	std::cout << "Цвет утюга: " << samsung.color << std::endl;
	std::cout << "Минимамльная температура утюга: " << samsung.MinT << std::endl;
	std::cout << "Максимальная температура утюга: " << samsung.MaxT << std::endl;
	std::cout << "Подача пара: " << samsung.MaxT << std::endl;
	std::cout << "Мощность утюга: " << samsung.P << std::endl;
}

