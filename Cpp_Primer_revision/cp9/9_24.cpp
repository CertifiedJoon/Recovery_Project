#include <vector>
#include <iostream>

int main () {
	std::vector<int> v ;
	
	//std::cout << v.front() << std::endl;
	//std::cout << v.at(0) << std::endl;
	std::cout << *v.begin() << std::endl;
	
	return 0;
}