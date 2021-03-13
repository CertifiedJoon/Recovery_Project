#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

void elimDups (std::vector<std::string> &);

int main () {
	std::vector<std::string> vs;
	std::string word;
	int size = 0;
	
	std::cin >>size;
	
	while (std::cin >> word)
		vs.push_back(word);
	
	elimDups(vs);
	stable_sort(vs.begin(), vs.end(), [](const std::string &s1, const std::string &s2) ->bool {return s1.size() < s2.size();});
	find_if(vs.begin(), vs.end(), [size](const std::string &s) -> bool {return s.size() >= size;});
	
	for_each(vs.begin(), vs.end(), [](const std::string &s){std::cout << s << " ";});
	std::cout << std::endl;
}


void elimDups (std::vector<std::string> &vs) {
	sort(vs.begin(), vs.end());
	auto uniq_end_it = unique(vs.begin(), vs.end());
	vs.erase(uniq_end_it, vs.end());
}