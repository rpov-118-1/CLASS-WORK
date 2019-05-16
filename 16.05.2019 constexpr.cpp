#include <iostream>

constexpr double cabs(double x) {
	return x >= 0 ? x : -x;
}

constexpr double simpson(double a, double b)
{
	double result = (b - a) / 6;
	result *= 1/a + 4 * 1/((a + b) / 2) + 1/b;
	return result;
}
constexpr double my_ln(double x)
{
	if (x == 1)
		return 0;
	if (x <= 0)
		return NAN;
	double result = 0;
	double step = (x - 1) / 100;
	for (double a = 1; a < x; a += step)
		result += simpson(a, a + step);
	return result;
}
constexpr double my_exp(double x, double epsilon)
{
	double result = 1;
	double m = x;
	for (int i = 2; cabs(m) >= epsilon; i++)
	{
		result += m;
		m *= x / i;
	}
	return result;
}
constexpr double my_pow(double a, double b, double epsilon)
{
	if (b < 0)
		return my_pow(1 / a, -b, epsilon);
	int div = (int)b;
	double integerPart = 1;
	for (int i = 0; i < div; i++)
		integerPart *= a;
	return integerPart * my_exp((b - div) * my_ln(a), epsilon);
}

int main()
{
	constexpr double X = my_pow(2.5, 3.3, 0.001);
	std::cout << X << std::endl;
	system("pause");
}
