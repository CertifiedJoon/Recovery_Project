#include <iostream>
#include <initializer_list>

int sum (std::initializer_list<int>);

int main() {
	std::cout << sum({1,2,3,4,5,6,7,8,9}) << std::endl;
}

int sum (std::initializer_list<int> nums){
	int sum = 0;
	for (const int i : nums)
		sum += i;
	
	return sum;
}