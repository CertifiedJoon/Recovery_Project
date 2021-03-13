#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

bool isShorter (const std::string &, const std::string &);
void elimDups (std::vector<std::string> &);

int main () {
	std::vector<std::string> vs;
	std::string word;
	while (std::cin >> word)
		vs.push_back(word);
	
	elimDups(vs);
	stable_sort(vs.begin(), vs.end(), isShorter);
	
	for (auto &s : vs)
		std::cout << s << " " << std::endl;
	std::cout << std::endl;
}

bool isShorter (const std::string &s1, const std::string &s2){
	return s1.size() < s2.size();
}

void elimDups (std::vector<std::string> &vs) {
	sort(vs.begin(), vs.end());
	auto uniq_end_it = unique(vs.begin(), vs.end());
	vs.erase(uniq_end_it, vs.end());
}