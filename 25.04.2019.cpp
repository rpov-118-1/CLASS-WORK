#include <fstream>
#include <iostream>

int main()
{
	std::ifstream fin("ok.txt");

	int p = 0; //количество пробелов
	int s = 0; //количество символов
	int t = 1; //количство строк
	while (!fin.eof())
	{
		char c;
		fin.get(c);
		if (c == ' ')  p++;
		if (c == '\n') t++;
		s++;
	}
	std::cout << t << " " << p << " " << s << std::endl;
	std::cout << t << " " << p << " " << s - t << std::endl;

	return 0;
}
