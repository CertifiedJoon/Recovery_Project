#include <iostream>
#include <stdexcept>

int main () {
	int i, j;
	
	try{
		std::cin >> i >> j;
		if (j == 0)
			throw std::runtime_error("division by zero");
	} catch (std::runtime_error err){
		std::cout << err.what() << " --> input divisor again: ";
		std::cin >> j;
		
		
	}
}