#include <iostream>
#include <list>
#include <string>

int main () {
	std::string word;
	std::list<std::string> sentence;
	
	while(std::cin >> word) {
		sentence.push_back(word);
	}
	
	for (auto it = sentence.cbegin(); it != sentence.cend(); ++it) 
		std::cout << *it << std::endl;
	
	
}