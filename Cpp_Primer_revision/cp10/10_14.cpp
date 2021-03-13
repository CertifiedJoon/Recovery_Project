#include <iostream>

int main() {
	auto f = [](int i, int j) -> int{return i + j;};
	
	std::cout << f(1,3) << std::endl;
}