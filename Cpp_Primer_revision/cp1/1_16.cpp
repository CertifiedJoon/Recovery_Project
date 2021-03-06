#include <iostream>

int main(){
	int sum = 0;
	int i;
	
	while(std::cin >> i){
		sum += i;
	}
	
	std::cout << sum;
}