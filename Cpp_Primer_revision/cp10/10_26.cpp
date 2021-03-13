#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

int main () {
	std::vector<int> v {11,1,1,1,1,2,3,4,5,6,6,7,8,77,4,34,1};
	std::list<int> lst;
	
	unique_copy(v.cbegin(), v.cend(), front_inserter(lst));
	
	for (auto i : lst) {
		std::cout << i<<  std::endl;
	}
}