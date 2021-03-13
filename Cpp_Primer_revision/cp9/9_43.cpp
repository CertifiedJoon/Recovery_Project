#include <string>
#include <iostream>

void replace_all(std::string &passage, const std::string &oldv, const std::string &newv);

int main() {
	std::string s, oldv, newv;
	
	std::cin >> s >> oldv >> newv;
	
	replace_all(s, oldv, newv);
	
	for (const auto & word : s) {
		std::cout << word  << " "<< std::endl;
	}
	
}

void replace_all(std::string &passage, const std::string &oldv, const std::string &newv) {
	if (oldv ==  newv) 
		return;
	
	using siz = std::string::size_type;
	
	siz sz = 0;
	
	while ((sz = passage.find(oldv, sz)) != std::string::npos )
		passage.replace(sz, oldv.size(), newv);
	
	return;
}