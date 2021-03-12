#include <vector>
#include <list>
#include <iostream>

int main () {
	int ia[] = {0,1,1,2,3,5,8,13, 21, 55, 89};
	int n = sizeof(ia) / sizeof(ia[0]);
	std::vector<int> v (ia, ia + n);
	std::list<int> lst (ia, ia + n);
	
	auto vit = v.begin();
	auto lit = lst.begin();
	
	while (vit != v.end()) {
		if (*vit % 2 == 1)
			vit = v.erase(vit);
		else 
			++vit;
	}
	
	while (lit != lst.end()) {
		if (*lit % 2 == 0)
			lit = lst.erase(lit);
		else
			++lit;
	}
	
	return 0;
}