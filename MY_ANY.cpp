#include<iostream>
#include<string>
#include<any>
#include<map>
#include<string>

template<typename T> struct AAA {
	T aaa(T&& v) { return v + v; }
};

template<typename T> struct BBB {
	template<typename W> W bbb(T&& v, W&& w) { return v + w; }
};


int main() {
	AAA<int> a = {};
	BBB<int> b = {};
	a.aaa(10);
	b.bbb(10, 10.0f);


	std::map<std::string, std::any> qqq = {};

	qqq.insert(std::make_pair("AAA", std::string("============")));

	qqq.insert(std::make_pair("BBB", std::string("############")));

	std::map<int, int> www = {};
	www.insert(std::make_pair(1, 2));
	www.insert(std::make_pair(3, 4));

	qqq.insert(std::make_pair("WWW", www));

	auto res = qqq.find("WWW")->second;

	std::cout << std::any_cast<std::map<int, int>>(res).find(1)->second << std::endl;

	std::cout << std::any_cast<std::map<int, int>>(res).find(3)->second << std::endl;

	system("pause");

	return 0;
}
