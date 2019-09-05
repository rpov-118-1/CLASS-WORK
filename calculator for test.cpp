#include <iostream>

int main()
{
	int a = 0, b = 0;
	while (true) {
		std::cout << "First number: ";
		std::cin >> a;
		if (std::cin.good()) {
			break;
		}

		std::cout << "Wrong number" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	while(true) {
		std::cout << "Second number: ";
		std::cin >> b;
		if (std::cin.good()) {
			break;
		}

		std::cout << "Wrong number" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	int c = a + b;

	std::cout << "Result: " << c << std::endl;

	return 0;
    
}
