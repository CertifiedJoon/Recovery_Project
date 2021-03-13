#include <iostream>

int main() {
	int i = 10;
	
	auto f = [i](int j) -> int{return i + j;};
	
	std::cout << f(3) << std::endl;
}