#include <iostream>

unsigned absoluteof(int);	

int main() {
	int i;
	
	while(std::cin >> i) {
		std::cout << absoluteof(i) <<std::endl;
	}
}

unsigned absoluteof(int i){
	return i < 0 ? -i : i;
}