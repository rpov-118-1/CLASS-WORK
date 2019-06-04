#include <iostream>
#include <string>

using namespace std;
/*

class Student { public:
	string fio;
	int Birth;
	int num;
	string city;
	string country;
	string institution;
	string CityInstitution;
	string countryInstitution;
	int group;

	//Student() : fio(string{}), Birth(int{}), num(int{}), city(string{}), country(string{}), institution(string{}), CityInstitution(string{}), countryInstitution(string{}), group(int{}) {}

	void input() // определяем функцию-член
	{
		cin >> fio >> Birth >> num >> city >> country >> institution >> CityInstitution >> countryInstitution >> group;
	}

	void print() // определяем функцию-член
	{
		cout << endl << fio << endl << Birth << endl << num << endl << city << endl << country << endl << institution << endl << CityInstitution << endl << countryInstitution << endl << group << endl;
	}
};

int main()
{
	Student student1 = Student();
	student1.input();
	student1.print();

	return 0;
}
*/

class point {
private:
	int x;
	int y;
	int z;

	public:
		int&& get_x()
	{
		return std::move(x);
	}
	
		void set_x(int&& value)
	{
			x = std::move(value);
	}
		int&& get_y()
	{
			return std::move(y);
	} 
		void set_y(int&& value)
	{
			y = std::move(value);
	}
		int&& get_z()
	{
			return std::move(z);
	}
		void set_z(int&& value)
	{
			z = std::move(value);
	}
};

int main()
{
	point point1 = point();
	point1.get_x();
	point1.set_x(54);
	point1.get_y();
	point1.set_y(54);
	point1.get_z();
	point1.set_z(54);

	return 0;
}
