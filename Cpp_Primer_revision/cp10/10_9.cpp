#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

void elimDups(std::vector<std::string> &);

int main () {
	std::vector<std::string> vs;
	std::string word;
	while (std::cin >> word)
		vs.push_back(word);
	
	elimDups(vs);
	
	for (auto &s : vs)
		std::cout << s << " " << std::endl;
}

void elimDups (std::vector<std::string> &vs) {
	sort(vs.begin(), vs.end());
	auto uniq_end_it = unique(vs.begin(), vs.end());
	vs.erase(uniq_end_it, vs.end());
}