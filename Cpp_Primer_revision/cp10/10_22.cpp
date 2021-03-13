#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std::placeholders;

bool isShorter(const std::string &word, int sz){
	return word.size() < sz;
}

int main () {
	std::vector<std::string> vs;
	std::string word;
	int size = 6;
	while(std::cin>>word) {
		vs.push_back(word);
	}
	
	std::cout << std::count_if(vs.cbegin(), vs.cend(), std::bind(isShorter, _1, size)) << std::endl;
	
}