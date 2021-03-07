#include <string>
#include <iostream>
#include <cctype>

int main(){
	std::string large;
	
	std::cin >> large;
	
	for (auto &c : large){
		if (!ispunct(c))
			std::cout << c;
	}
	std::cout << std::endl;
}
