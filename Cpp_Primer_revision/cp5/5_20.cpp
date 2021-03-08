#include <iostream>
#include <string>

int main () {
	std::string word;
	std::string prev;
	
	while(std::cin >> word){
		if (prev == word){
			std::cout << word<< std::endl;
			break;
		}
		prev= word;
	}
	
	if (!std::cin)
		std::cout << "all strings read" << std::endl;
}