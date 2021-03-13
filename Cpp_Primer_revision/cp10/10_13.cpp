#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool longerThanFive(const std::string &);

int main () {
	std::vector<std::string> vs;
	std::string word;
	
	while (std::cin >> word)
		vs.push_back(word);
	
	auto end_it = partition(vs.begin(), vs.end(), longerThanFive);
	vs.erase(end_it, vs.end());
	
	for (auto &s : vs)
		std::cout << s << " " << std::endl;
	std::cout << std::endl;
}

bool longerThanFive(const std::string &s){
	return s.size() >= 5;
}