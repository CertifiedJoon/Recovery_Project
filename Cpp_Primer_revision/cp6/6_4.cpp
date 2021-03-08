#include <iostream>

unsigned long fact(int);

int main() {
	int i;
	
	std::cin >> i;
	
	std::cout << "factorial of " << i << " is " << fact(i) << std::endl;
}

unsigned long fact (int n){
	if (n == 0) return 1;
	
	return n * fact(n-1);
}