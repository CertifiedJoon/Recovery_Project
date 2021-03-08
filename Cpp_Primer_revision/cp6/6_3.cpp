#include <iostream>

unsigned long fact(int);

int main(){
	
	auto res = fact(10);
	
	std::cout << res << std::endl;
}

unsigned long fact(int n){
	if (n == 0) return 1;
	
	return n * fact(n-1);
}