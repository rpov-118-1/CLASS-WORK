#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void replaceAll(std::string& str, const std::string& from, const std::string& to)
{
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos)
	{
		size_t end_pos = start_pos + from.length();
		str.replace(start_pos, end_pos, to);
		start_pos += to.length();
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	std::string filename;
	std::cout << "Enter filename\n";
	std::getline(std::cin, filename);
	std::ifstream ifs(filename.c_str());
	ofstream output_file("result.txt");

	if (!ifs)
	{
		std::cerr << "Error. Can`t open file " << filename << '\n';
		return 1;
	}

	std::string finded, replaced;
	std::cout << "Enter string for find\n";
	std::cin >> finded;
	std::cout << "Enter string for replace\n";
	std::cin >> replaced;
	string inbuf;
	int n = {};
	while (!ifs.eof())
	{
		getline(ifs, inbuf);
		size_t foundpos = inbuf.find(finded);
		if (foundpos != std::string::npos)
		{
			string tmpstring = inbuf.substr(0,n);
			tmpstring += replaced;
			tmpstring += inbuf.substr(n + finded.length(), inbuf.length());
			inbuf = tmpstring;
		}

		output_file << inbuf << endl;
	}
}
