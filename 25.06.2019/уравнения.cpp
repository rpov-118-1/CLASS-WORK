/*
#include <iostream>
#include "ctime"

template<typename T, size_t N>
T avr(T (&arr)[N]) {
	T res = { };
	for (int i = 0; i < N; i++) {
		res += arr[i];
	}
	return res /= N;
}

template<typename T, size_t N>
void print(T(&arr)[N]) {
	for (int i = 0; i < N; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main(){
	srand(time(NULL));
	//const int size= 10;
	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 10;
	}
	print(arr);
	int result = avr(arr);

	std::cout << avr(arr) << std::endl;


   return 0; 
}
*/

#include <array>
#include <stdio.h>
#include <math.h>
#define eps 0.000001

template<typename T, size_t N> T solve(std::array<T, N> arr) {
	auto fx = [&](T x) {
		T result = 0;
		for (size_t i = 0; i < N; i++) {
			T factor = 1;
			for (size_t k = 0; k < N - i - 1; k++) {
				factor = factor * x;
			}
			result += arr[i] * factor;
		}
		return result;
	};
	auto dfx = [&](T x){
		T result = 0;
		for (size_t i = 0; i < N - 1; i++) {
			size_t degree = N - i - 2;
			T factor = 1;
			for (size_t k = 0; k < degree; k++) {
				factor = factor * x;
			}
			T dg = (T)((int)(degree + 1));
			result += arr[i] * factor * dg;
		}
		return result;
	};

	T x0 = (T)0;

	T x1 = x0 - fx(x0) / dfx(x0); // первое приблжение

	while (true) { // пока не достигнута точность 0.000001
		auto diff = x1 > x0 ? x1 - x0 : x0 - x1;
		if (diff < eps) { break; }

		x0 = x1;
		x1 = x1 - fx(x1) / dfx(x1); // последующие приближения
	}
	return x1;
}

///////////////


#ifndef RATIONAL_NUM
#define RATIONAL_NUM

#include <iostream>

#include <string>

#include <cmath>

#include <vector>

using namespace std;

class RationalNum {
	friend RationalNum operator+(const RationalNum& left, const RationalNum& right);
	friend RationalNum operator-(const RationalNum& left, const RationalNum& right);
	friend RationalNum operator*(const RationalNum& left, const RationalNum& right);
	friend RationalNum operator/(const RationalNum& left, const RationalNum& right);
	friend bool operator==(const RationalNum& left, const RationalNum& right);
	friend bool operator!=(const RationalNum& left, const RationalNum& right);
	friend bool operator<(const RationalNum& left, const RationalNum& right);
	friend bool operator>(const RationalNum& left, const RationalNum& right);
	friend bool operator<=(const RationalNum& left, const RationalNum& right);
	friend bool operator>=(const RationalNum& left, const RationalNum& right);
	   	 

public:
	RationalNum();
	RationalNum(double x);
	RationalNum(int numerator_, int denominator_ = 1);
	   
	RationalNum& operator=(const RationalNum& obj);

	RationalNum& operator+=(const RationalNum& obj);

	RationalNum& operator-=(const RationalNum& obj);

	RationalNum& operator*=(const RationalNum& obj);

	RationalNum& operator/=(const RationalNum& obj);

	RationalNum& operator++();

	RationalNum operator++(int);

	RationalNum& operator--();

	RationalNum operator--(int);

	RationalNum operator+() const;

	RationalNum operator-() const;



	void setNumerator(int numerator_);

	int getNumerator() const;

	void setDenominator(int denominator_);

	int getDenominator() const;



private:
	int numerator;

	int denominator;

	void simplify();

};




int absInt(int x) {

	if (x >= 0) {

		return x;

	}

	else {

		return -x;

	}

}



void getFactors(int num, vector<int>& factorSet) {

	if (num != 1) {

		factorSet.push_back(num);

	}

	for (int i = 2; i <= sqrt(static_cast<double>(num)); i++) {

		if (num%i == 0) {

			factorSet.push_back(i);

			factorSet.push_back(num / i);

		}

	}

}



void simplifyFun(int& a, int& b) {

	int tempN = a;

	int tempD = b;

	int small, temp;

	vector<int> factorSet;

	if (tempN == tempD) {

		a = 1;

		b = 1;

		return;

	}

	else if (tempN == -tempD) {

		a = -1;

		b = 1;

		return;

	}

	else if (tempN == 0) {

		b = 1;

		return;

	}





	if (absInt(tempN) < absInt(tempD)) {

		small = absInt(tempN);

	}

	else {

		small = absInt(tempD);

	}



	getFactors(small, factorSet);

	for (int i = 0; i < factorSet.size(); i++) {

		temp = factorSet[i];

		while (tempN%temp == 0 && tempD%temp == 0) {

			tempN /= temp;

			tempD /= temp;

		}

	}

	a = tempN;

	b = tempD;

}





//friend functions definitions

RationalNum operator+(const RationalNum& left, const RationalNum& right) {

	RationalNum temp;

	int tempLD = left.getDenominator();

	int tempRD = right.getDenominator();

	simplifyFun(tempLD, tempRD);

	temp.setDenominator(left.getDenominator()*tempRD);

	temp.setNumerator(left.getNumerator()*tempRD + right.getNumerator()*tempLD);

	temp.simplify();

	return temp;

}



RationalNum operator-(const RationalNum& left, const RationalNum& right) {

	return left + (-right);

}



RationalNum operator*(const RationalNum& left, const RationalNum& right) {

	RationalNum temp;

	RationalNum temp_2(right.getNumerator(), left.getDenominator());

	RationalNum temp_3(left.getNumerator(), right.getDenominator());

	int a = temp_2.getDenominator();

	int b = temp_2.getNumerator();

	int c = temp_3.getDenominator();

	int d = temp_3.getNumerator();

	temp.setNumerator(b*d);

	temp.setDenominator(a*c);

	return temp;

}



RationalNum operator/(const RationalNum& left, const RationalNum& right) {

	RationalNum temp_1(left.getNumerator(), left.getDenominator());

	RationalNum temp_2(right.getDenominator(), right.getNumerator());

	return temp_1 * temp_2;

}



bool operator==(const RationalNum& left, const RationalNum& right) {

	return (left.numerator == right.numerator && left.denominator == right.denominator);

}



bool operator!=(const RationalNum& left, const RationalNum& right) {

	return !(left == right);

}



bool operator<(const RationalNum& left, const RationalNum& right) {

	int lside = left.getNumerator()*right.getDenominator();

	int rside = left.getDenominator()*right.getNumerator();

	return (lside < rside);

}



bool operator>(const RationalNum& left, const RationalNum& right) {

	int lside = left.getNumerator()*right.getDenominator();

	int rside = left.getDenominator()*right.getNumerator();

	return (lside > rside);

}



bool operator<=(const RationalNum& left, const RationalNum& right) {

	return ((left < right) || (left == right));

}



bool operator>=(const RationalNum& left, const RationalNum& right) {

	return ((left > right) || (left == right));

}



//member function definition

RationalNum::RationalNum() {

	setNumerator(0);

	setDenominator(1);

}



RationalNum::RationalNum(double x) {

	int i = 1;

	while (x*i - static_cast<int>(x*i) != 0) {

		if (i > INT_MAX / 10) {

			cout << "this frational number : " << x << " can not be transfer to rational number, it's too long, now set it 0." << endl;

			setNumerator(0);

			setDenominator(1);

			return;

		}

		else {

			i *= 10;

		}

	}

	setNumerator(x*i);

	setDenominator(i);

	simplify();

}



RationalNum::RationalNum(int numerator_, int denominator_) {

	setNumerator(numerator_);

	setDenominator(denominator_);

	simplify();

}



RationalNum& RationalNum::operator=(const RationalNum& obj) {

	setNumerator(obj.getNumerator());

	setDenominator(obj.getDenominator());

	return *this;

}



RationalNum& RationalNum::operator+=(const RationalNum& obj) {

	*this = *this + obj;

	return *this;

}



RationalNum& RationalNum::operator-=(const RationalNum& obj) {

	*this = *this - obj;

	return *this;

}



RationalNum& RationalNum::operator*=(const RationalNum& obj) {

	*this = *this*obj;

	return *this;

}



RationalNum& RationalNum::operator/=(const RationalNum& obj) {

	*this = *this / obj;

	return *this;

}

RationalNum& RationalNum::operator++() {

	*this = *this + 1;

	return *this;

}



RationalNum RationalNum::operator++(int) {

	RationalNum before = *this;

	*this = *this + 1;

	return before;

}



RationalNum& RationalNum::operator--() {

	*this = *this - 1;

	return *this;

}



RationalNum RationalNum::operator--(int) {

	RationalNum before = *this;

	*this = *this - 1;

	return before;

}



RationalNum RationalNum::operator+() const {

	return *this;

}



RationalNum RationalNum::operator-() const {

	RationalNum temp;

	temp.setNumerator(-getNumerator());

	temp.setDenominator(getDenominator());

	return temp;

}



void RationalNum::setNumerator(int numerator_) {

	numerator = numerator_;

}



int RationalNum::getNumerator() const {

	return numerator;

}



void RationalNum::setDenominator(int denominator_) {

	if (denominator_ == 0) {

		denominator = 1;

		numerator = 0;

		cout << "Denominator is 0! Not good! THe whole is set to 0." << endl;

	}

	else {

		denominator = denominator_;

	}

}



int RationalNum::getDenominator() const {

	return denominator;

}




void RationalNum::simplify() {

	int tempN = numerator;

	int tempD = denominator;

	simplifyFun(tempN, tempD);

	setNumerator(tempN);

	setDenominator(tempD);

}

#endif




////////////////









int main() {
	std::array<float, 4> coefs1 = { 10.0, 5.0, 4.0, 3.0 };
	printf("%f\n", solve(coefs1)); // вывод на экран

	std::array<RationalNum, 4> coefs2 = { RationalNum{10, 5}, RationalNum{ 3,4 }, RationalNum{7,8}, RationalNum{12,10} };
	auto res = solve(coefs2);
	printf("%d/%d\n", res.getNumerator(), res.getDenominator());

	//auto res = solve(10.0, 5.0, 4.0, 3.0);


	return 0;
}

