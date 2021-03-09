#include <iostream>
#include <vector>
int add(int i, int j) {
	return i + j;
}

int subtract(int i, int j) {
	return i - j;
}

int multiply(int i, int j) {
	return i * j;
}

int divide(int i, int j) {
	return i / j;
}

int main() {
	
	int (*addf) (int, int);
	addf = add;
	int (*subf) (int, int);
	subf = subtract;
	int (*mulf) (int, int);
	mulf = multiply;
	int (*divf) (int, int);
	divf = divide;
	
	std::vector<decltype(addf)> vf {addf, subf, mulf, divf};
	
	std::cout << vf[0](1,1) << std::endl;
	std::cout << vf[1](1,1) << std::endl;
	std::cout << vf[2](1,1) << std::endl;
	std::cout << vf[3](1,1) << std::endl;
}