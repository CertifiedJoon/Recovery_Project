#include <iostream>
#include <vector>

int main(){
	typedef std::vector<int>::size_type st;
	
	std::vector<int> iv;
	int i;
	
	while (std::cin >> i)
		iv.push_back(i);
	
	for (st i = 0, j = iv.size() - 1; i <= j; ++i , --j)
		std::cout << iv[i] + iv[j] << std::endl;
}