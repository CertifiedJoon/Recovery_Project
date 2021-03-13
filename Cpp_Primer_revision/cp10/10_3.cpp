#include <iostream>
#include <vector>
#include <numeric>

int main () {
	std::vector<double> v {1.0,2.5,3.5,4.5,5.5,6.5,7.5,8.5,9.5};
	std::cout << accumulate(v.cbegin(), v.cend(), 0.0) <<std::endl;
	
	return 0;
}