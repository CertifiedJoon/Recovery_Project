#include <iostream>

int main(){
	int i, j;
	
	std::cin >> i >> j;
	
	while (i < j)
		std::cout << i++ << std::endl;
	
	return 0;
}