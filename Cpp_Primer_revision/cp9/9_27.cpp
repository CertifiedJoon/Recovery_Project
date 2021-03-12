#include <iostream>
#include <forward_list>

int main() {
	std::forward_list<int> fl {1,2,3,4,5,6,7,8,9};
	
	auto flit = fl.begin();
	auto flit2 = fl.begin();
	++flit2;
	
	flit = fl.erase_after(flit2);
	
	std::cout << *flit << std::endl;
	
	return 0;
}