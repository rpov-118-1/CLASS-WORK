#include <iostream>
#include <assert.h>

class Date {
private:
	int day, mounth, year;
public:
	Date() = default;

	Date(const Date& old) {
		day = old.day;
		mounth = old.mounth;
		year = old.year;
	}

	//Date(std::initializer_list<int> ints) {				//!!!!!!!!!!!!!!!инициализируем список интами, указщанными в меййне
	//	assert(ints.size() == 3);
	//	int i = 0;
	//	for (int elem : ints) {
	//		switch (i++)
	//		{
	//		case 0:
	//			day = elem;
	//			break;
	//		case 1:
	//			mounth = elem;
	//			break;
	//		case 2:
	//			year = elem;
	//			break;
	//		}
	//	}
	//}

	int operator-(const Date& old) {
		int x = 0, y = 0, g;
		int m1 = 31;
		int m2 = 28;
		int m3 = 31;
		int m4 = 30;
		int m5 = 31;
		int m6 = 30;
		int m7 = 31;
		int m8 = 31;
		int m9 = 30;
		int m10 = 31;
		int m11 = 30;
		int m12 = 31;

		if (mounth == 1) { x = this->day; }
		else if (this->mounth == 2) { x = m1 + this->day; }
		else if (this->mounth == 3) { x = m1 + m2 + this->day; }
		else if (this->mounth == 4) { x = m1 + m2 + m3 + this->day; }
		else if (this->mounth == 5) { x = m1 + m2 + m3 + m4 + this->day; }
		else if (this->mounth == 6) { x = m1 + m2 + m3 + m4 + m5 + this->day; }
		else if (this->mounth == 7) { x = m1 + m2 + m3 + m4 + m5 + m6 + this->day; }
		else if (this->mounth == 8) { x = m1 + m2 + m3 + m4 + m5 + m6 + m7 + this->day; }
		else if (this->mounth == 9) { x = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + this->day; }
		else if (this->mounth == 10) { x = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + this->day; }
		else if (this->mounth == 11) { x = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + m10 + this->day; }
		else if (this->mounth == 12) { x = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + m10 + m11 + this->day; }

		if (old.mounth == 1) { y = old.day; }
		else if (old.mounth == 2) { y = m1 + old.day; }
		else if (old.mounth == 3) { y = m1 + m2 + old.day; }
		else if (old.mounth == 4) { y = m1 + m2 + m3 + old.day; }
		else if (old.mounth == 5) { y = m1 + m2 + m3 + m4 + old.day; }
		else if (old.mounth == 6) { y = m1 + m2 + m3 + m4 + m5 + old.day; }
		else if (old.mounth == 7) { y = m1 + m2 + m3 + m4 + m5 + m6 + old.day; }
		else if (old.mounth == 8) { y = m1 + m2 + m3 + m4 + m5 + m6 + m7 + old.day; }
		else if (old.mounth == 9) { y = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + old.day; }
		else if (old.mounth == 10) { y = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + old.day; }
		else if (old.mounth == 11) { y = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + m10 + old.day; }
		g = 365 * (old.year - this->year) + ((old.year / 4 - old.year / 100 + old.year / 400) - (this->year / 4 - this->year / 100 + this->year / 400));
		g = g + (y - x);

		return g;
	}

	Date operator+(int day) {
		int d, m, y;
		Date res = Date(*this);
		y = day / 365;
		m = (day - y * 365) / 30;
		d = day - (y * 365 + m * 30);
		res.day += d;
		if (res.day > 30) {
			m++;
		}
		res.mounth += m;
		if (res.mounth > 12) {
			y++;
		}
		res.year += y;

		/*res.day += d;
		res.mounth += m;
		res.year += y;*/

		return res;



	}

	void input() {
		std::cout << "Enter a date\n";
		std::cin >> day >> mounth >> year;
	}

	void print() {
		std::cout << this->day << std::endl;
		std::cout << this->mounth << std::endl;
		std::cout << this->year << std::endl;
	}

};


int main() {
	Date first = {  };
	Date second = {  };
	first.input();
	second.input();
	int res = first - second;
	std::cout << "Result = " << res << std::endl;
	Date result = first + 5;
	//std::cout << "Result = " << result << std::endl;
	result.print();

	return 0;
}
