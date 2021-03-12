#include <list>
#include <vector>
#include <iostream>

int main () {
	std::vector<int> vi {1,2,3,4,5};
	std::list<int> li {1,2,3,4,5};
	
	auto vit = vi.cbegin();
	auto lit = li.cbegin();
	
	while(vit != vi.cend() && lit != li.cend()){
		if (*vit != * lit)
			
	}
}