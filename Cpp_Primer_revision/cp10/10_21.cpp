#include <iostream>

int main () {
	int i = 9;
	auto f = [i]() mutable -> bool {while (i) {--i;} return (!i);};
	
	std::cout << f() << std::endl;
}