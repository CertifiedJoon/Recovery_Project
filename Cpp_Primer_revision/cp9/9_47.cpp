#include <string>
#include <iostream>

int main () {
	using siz = std::string::size_type;
	std::string numeric("123456789");
	std::string alphabet("zxcvbnmasdfghjklqwertyuiop");
	std::string input;
	
	std::cin >> input;
	
	siz sz = -1;
	while ((sz = input.find_first_of(numeric, sz + 1)) != std::string::npos) {
		std::cout << input[sz];
	}
	std::cout << std::endl;
	
	sz = 0;
	while ((sz = input.find_first_of(alphabet, sz + 1)) != std::string::npos) {
		std::cout << input[sz];
	}
	std::cout << std::endl;
}