#include <vector>
#include <iostream>

int main() {
	std::vector<int> iv (10, 3);
	
	for (auto it = iv.begin(); it != iv.end(); ++ it)
		*it *= 2;
	
	for (auto it = iv.cbegin(); it != iv.cend(); ++it)
		std::cout << *it << std::endl;
	
	return 0;
}