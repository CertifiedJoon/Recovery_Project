#include <list>
#include <iostream>

int main () {
	std::list<int> lst {0,1,2,3,4,5,6,7,8,9};
	std::list<int>::iterator elem1 = lst.begin();
	std::list<int>::iterator elem2 = lst.end();
	
	elem1 = lst.erase(elem1, elem2);
	
	std::cout << *elem1 << std::endl;
	
	return 0;
}