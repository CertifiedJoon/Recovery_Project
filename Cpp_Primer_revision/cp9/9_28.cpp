#include <iostream>
#include <forward_list>
#include <string>
#include <iterator>

int main () {
	std::forward_list<std::string> fl {"word", "is", "short", "so", "is", "life"};
	std::string word = "is";
	
	auto flit = fl.begin();
	
	while( flit + 1!= fl.end()) {
		std::cout << *flit << std::endl;
		if (*flit == word)
			flit = fl.insert_after(flit, word);

		++flit;
	}
	
	fl.insert_after(flit, word);
	
	for (auto it = fl.begin(); it != fl.end(); ++it) {
		std::cout << *it << std::endl;
	}
}