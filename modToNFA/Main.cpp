#include<iostream>
#include"FA.h"
int main() {
	std::cout<<"input regular expression"<<std::endl;
	std::string s;
	std::cin >> s;
	FA f(s);
	auto p = f.creatNFA();
	std::cout << "start " <<p.first.getID() << ' ' << "end "<<p.second.getID() << std::endl;
	f.printEdge();
	return 0;
}