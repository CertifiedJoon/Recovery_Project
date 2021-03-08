#include <iostream>
#include <vector>

int main () {
	std::vector<int> smaller{0,1,1,2};
	std::vector<int> larger{0,1,1,2,3,4,5,6};
	
	auto sit = smaller.cbegin();
	auto lit = larger.cbegin();
	
	while(sit != smaller.cend() && *sit++ == *lit++)
		;

	if (sit == smaller.cend()){
		std::cout << "yes, smaller is a prefix of larger" << std::endl;
	} else {
		std::cout << "no" << std::endl;
		
	}
}