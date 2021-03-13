#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main () {
	std::vector<std::string> vs;
	std::string word;
	
	while(std::cin>>word) {
		vs.push_back(word);
	}
	
	std::cout << count_if(vs.cbegin(), vs.cend(), [](const std::string &s) {return s.size() > 6;}) << std::endl;
	
}