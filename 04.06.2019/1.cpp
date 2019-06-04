#include <iostream>
#include "string"
class Student{ private:
	std::string name;
	std::string birth;
	std::string phone;
	std::string city;
	std::string country;
	std::string school;
	std::string city_school;
	std::string country_school;
	std::string group;

public:
	Student(std::string namex, std::string birthx, std::string phonex,
		std::string cityx, std::string countryx, std::string schoolx,
		std::string city_schoolx, std::string country_schoolx, std::string groupx) {
		name = namex;
		birth = birthx;
		phone = phonex;
		city = cityx;
		country = countryx;
		school = schoolx;
		city_school = city_schoolx;
		country_school = country_schoolx;
		group = groupx;
	}

	void input(){
		std::cout << "\nEnter name ";
		std::getline(std::cin, name);
		std::cout << "\nEnter birth ";
		std::getline(std::cin, birth);
		std::cout << "\nEnter phone ";
		std::getline(std::cin, phone);
		std::cout << "\nEnter city ";
		std::getline(std::cin, city);
		std::cout << "\nEnter country ";
		std::getline(std::cin, country);
		std::cout << "\nEnter school ";
		std::getline(std::cin, school);
		std::cout << "\nEnter city school ";
		std::getline(std::cin, city_school);
		std::cout << "\nEnter country school ";
		std::getline(std::cin, country_school);
		std::cout << "\nEnter group ";
		std::getline(std::cin, group);
	}

	void print() {
		std::cout << "Name " << name << std::endl;
		std::cout << "Birth " << birth << std::endl;
		std::cout << "Phone " << phone << std::endl;
		std::cout << "City " << city << std::endl;
		std::cout << "Country " << country << std::endl;
		std::cout << "School " << school << std::endl;
		std::cout << "City school " << city_school << std::endl;
		std::cout << "Country school " << country_school << std::endl;
		std::cout << "Group " << group << std::endl;
	}


};

int main(){
	std::string namex;
	std::string birthx;
	std::string phonex;
	std::string cityx;
	std::string countryx;
	std::string schoolx;
	std::string city_schoolx;
	std::string country_schoolx;
	std::string groupx;
	Student ivanov = Student(namex, birthx, phonex,
		cityx, countryx, schoolx, city_schoolx, 
		country_schoolx, groupx);
	ivanov.input();
	ivanov.print();

	return 0;
}
