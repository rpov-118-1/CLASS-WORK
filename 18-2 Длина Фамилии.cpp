int main()
{
	std::string str1, str2, str3, str4, str5;
	std::cout << "thirst surname: " << endl;
	std::cin >> str1;
	std::cout << "Second surname: " << endl;
	std::cin >> str2;
	std::cout << "Third surname: " << endl;
	std::cin >> str3;
	std::cout << "Fourth surname: " << endl;
	std::cin >> str4;
	std::cout << "Fifth surname: " << endl;
	std::cin >> str5;
	int array[5] = { str1.length(),str2.length(),str3.length(),str4.length(),str5.length() };
	int max = array[0];
	for (int i = 0; i < 5; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	if (max == array[0]) { cout << str1; }
	else if (max == array[1]) { cout << str2; }
	else if (max == array[2]) { cout << str3; }
	else if (max == array[3]) { cout << str4; }
	else if (max == array[4]) { cout << str5; }
}
