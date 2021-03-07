#include <string>
#include <iostream>

int main(){
	std::string from;
	
	std::cin >> from;
	
	for (auto &c : from)
		c = 'X';
	
	std::cout << from;
}