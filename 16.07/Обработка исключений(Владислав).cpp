#include <iostream>
#include <string>
#include <exception>
#include <time.h>

struct strtonum_exception : public std::exception {
	strtonum_exception(std::string message) : std::exception(message.c_str()) {}
};

int strtonum(std::string&& str) {
	if (rand() % 2 == 0) {
		throw std::exception("Fatality");
	}

	size_t badpos = -1;
	for (int i = 0; i < str.length(); i++) {
		if (!isdigit(str[i])) {
			badpos = i;
			break;
		}
	}	
	if (badpos == (size_t)(-1)) {
		return std::stoi(str);
	}
	else {
		char buf[128] = {};
		_itoa_s(badpos, buf, 10);
		throw strtonum_exception(std::string("Bad character at ") + std::string(buf));
	}
}

int main(){
	srand(time(NULL));
	std::string asd = {};
	std::cin >> asd;

	try {
		int qqq = strtonum(std::move(asd));
		std::cout << qqq << std::endl;
	}
	catch (const strtonum_exception& e) {
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Fatal error" << std::endl;
	}
		

    return 0; 
}
