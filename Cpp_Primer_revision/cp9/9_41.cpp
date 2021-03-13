#include <string>
#include <vector>
#include <iostream>

int main () {
	std::vector<char> v {'c', 'h','a','r'};
	std::string s (v.begin(), v.end());
	
	std::cout << s<< std::endl;
}


